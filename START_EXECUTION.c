#include <stdio.h>
#include <string.h>

char M[100][4], IR[4], R[4];
int IC;
int C; // Toggle (0 or 1)

// Function prototypes
void Start_Execution();
void ExecuteUserProgram();
void MOS();  // Monitor service routine

// For GD and PD
char data[40];
int SI; // Service Interrupt

void Start_Execution() {
    IC = 0;
    ExecuteUserProgram();
}

void ExecuteUserProgram() {
    while(1) {
        // Load instruction into IR
        for(int i = 0; i < 4; i++) {
            IR[i] = M[IC][i];
        }
        IC++;

        if(IR[0]=='L' && IR[1]=='R') {
            int addr = (IR[2]-'0')*10 + (IR[3]-'0');
            for(int i = 0; i < 4; i++)
                R[i] = M[addr][i];
        }
        else if(IR[0]=='S' && IR[1]=='R') {
            int addr = (IR[2]-'0')*10 + (IR[3]-'0');
            for(int i = 0; i < 4; i++)
                M[addr][i] = R[i];
        }
        else if(IR[0]=='C' && IR[1]=='R') {
            int addr = (IR[2]-'0')*10 + (IR[3]-'0');
            C = 1;
            for(int i = 0; i < 4; i++) {
                if(R[i] != M[addr][i]) {
                    C = 0;
                    break;
                }
            }
        }
        else if(IR[0]=='B' && IR[1]=='T') {
            int addr = (IR[2]-'0')*10 + (IR[3]-'0');
            if(C == 1)
                IC = addr;
        }
        else if(IR[0]=='G' && IR[1]=='D') {
            SI = 1;
            MOS();
        }
        else if(IR[0]=='P' && IR[1]=='D') {
            SI = 2;
            MOS();
        }
        else if(IR[0]=='H') {
            SI = 3;
            MOS();
            break;
        }
    }
}

void MOS() {
    int addr;

    if(SI == 1) { // GD
        addr = (IR[2]-'0')*10 + (IR[3]-'0');
        printf("Enter Data: ");
        fgets(data, 40, stdin);

        int k = 0;
        for(int i = addr; i < addr + 10; i++) {
            for(int j = 0; j < 4 && data[k] != '\0'; j++) {
                M[i][j] = data[k++];
            }
        }
    }
    else if(SI == 2) { // PD
        addr = (IR[2]-'0')*10 + (IR[3]-'0');
        printf("Output: ");

        for(int i = addr; i < addr + 10; i++) {
            for(int j = 0; j < 4; j++) {
                printf("%c", M[i][j]);
            }
        }
        printf("\n");
    }
    else if(SI == 3) { // H
        printf("\nProgram Halted\n");
    }
}
