#include <stdio.h>
#include <string.h>

// Memory & Registers
char M[100][4], IR[4], R[4];
int IC, SI, C;

FILE *fin, *fout;

// ================= INIT =================
void INIT() {
    for(int i=0;i<100;i++)
        for(int j=0;j<4;j++)
            M[i][j] = ' ';

    for(int i=0;i<4;i++) {
        IR[i] = ' ';
        R[i] = ' ';
    }

    IC = 0; SI = 0; C = 0;
}

// ================= MEMORY MAP =================
void printMemory() {
    for(int i=0;i<100;i++) {
        printf("%02d : ", i);
        for(int j=0;j<4;j++)
            printf("%c", M[i][j]);
        printf("\n");
    }
}

// ================= ADDRESS =================
int getAddress() {
    return (IR[2]-'0')*10 + (IR[3]-'0');
}

// ================= BUFFER → MEMORY =================
int bufferToMemory(int block, char *buffer) {
    int word = block, byte = 0;

    for(int i=0; buffer[i] != '\0' && word < block+10; i++) {

        if(buffer[i]=='\n' || buffer[i]=='\r')
            continue;

        M[word][byte++] = buffer[i];

        if(byte == 4) {
            byte = 0;
            word++;
        }
    }
    return word - block; // words used
}

// ================= READ =================
void READ() {
    char buffer[40];
    int addr = getAddress();

    if(fgets(buffer, sizeof(buffer), fin)) {
        bufferToMemory(addr, buffer);
    }
}

// ================= WRITE =================
void WRITE() {
    int addr = getAddress();

    for(int i=addr; i<addr+10; i++) {
        for(int j=0;j<4;j++) {
            fprintf(fout,"%c",M[i][j]);
        }
    }
    fprintf(fout,"\n");
}

// ================= TERMINATE =================
void TERMINATE() {
    fprintf(fout,"\n---- JOB END ----\n\n");
}

// ================= MOS =================
void MOS() {
    switch(SI) {
        case 1: READ(); break;
        case 2: WRITE(); break;
        case 3: TERMINATE(); break;
    }
}

// ================= EXECUTION =================
void EXECUTEUSERPROGRAM() {
    while(1) {

        // FETCH
        for(int i=0;i<4;i++)
            IR[i] = M[IC][i];
        IC++;

        // GD
        if(IR[0]=='G' && IR[1]=='D') {
            SI=1; MOS();
        }

        // PD
        else if(IR[0]=='P' && IR[1]=='D') {
            SI=2; MOS();
        }

        // H
        else if(IR[0]=='H') {
            SI=3; MOS();
            break;
        }

        // LR
        else if(IR[0]=='L' && IR[1]=='R') {
            int addr = getAddress();
            for(int i=0;i<4;i++)
                R[i] = M[addr][i];
        }

        // SR
        else if(IR[0]=='S' && IR[1]=='R') {
            int addr = getAddress();
            for(int i=0;i<4;i++)
                M[addr][i] = R[i];
        }

        // CR
        else if(IR[0]=='C' && IR[1]=='R') {
            int addr = getAddress();
            C = 1;
            for(int i=0;i<4;i++) {
                if(R[i] != M[addr][i]) {
                    C = 0; break;
                }
            }
        }

        // BT
        else if(IR[0]=='B' && IR[1]=='T') {
            if(C == 1)
                IC = getAddress();
        }
    }
}

// ================= START =================
void STARTEXECUTION() {
    IC = 0;
    EXECUTEUSERPROGRAM();
}

// ================= LOAD =================
void LOAD() {
    char buffer[42];
    int block = 0;

    while(fgets(buffer, sizeof(buffer), fin)) {

        // $AMJ
        if(strncmp(buffer,"$AMJ",4)==0) {
            INIT();
            block = 0;

            char jobid[5];
            strncpy(jobid, buffer+4,4);
            jobid[4]='\0';

            printf("\n===== NEW JOB =====\n");
            printf("Job ID: %s\n",jobid);
        }

        // $DTA
        else if(strncmp(buffer,"$DTA",4)==0) {

    printf("\n===== MEMORY BEFORE EXECUTION =====\n");
    printMemory();

    STARTEXECUTION();

    printf("\n===== MEMORY AFTER EXECUTION =====\n");
    printMemory();
}

        // $END
        else if(strncmp(buffer,"$END",4)==0) {
            printf("===== JOB FINISHED =====\n");
            continue;
        }

        // PROGRAM CARDS
        else {
            int used = bufferToMemory(block, buffer);
            block += used;
        }
    }
}

// ================= MAIN =================
int main() {

    fin = fopen("input.txt","r");
    fout = fopen("output.txt","w");

    if(!fin || !fout) {
        printf("File error\n");
        return 1;
    }

    LOAD();

    fclose(fin);
    fclose(fout);

    return 0;
}