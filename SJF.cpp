#include<iostream>

using namespace std;

struct Process
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
    int start_time;
    bool completed;
};

int main()
{
    int n;

    cout << "ENTER NUMBER OF PROCESSES : ";
    cin >> n;

    Process p[20];

    // Input
    for(int i = 0; i < n; i++)
    {
        cout << "\nENTER PROCESS ID : ";
        cin >> p[i].pid;

        cout << "ENTER ARRIVAL TIME : ";
        cin >> p[i].at;

        cout << "ENTER BURST TIME : ";
        cin >> p[i].bt;

        p[i].completed = false;
    }

    int current_time = 0;
    int completed_count = 0;

    while(completed_count < n)
    {
        int index = -1;
        int min_bt = 9999;

        // Find shortest job among arrived processes
        for(int i = 0; i < n; i++)
        {
            if(p[i].at <= current_time &&
               p[i].completed == false)
            {
                if(p[i].bt < min_bt)
                {
                    min_bt = p[i].bt;
                    index = i;
                }

                // Tie breaking
                if(p[i].bt == min_bt)
                {
                    if(p[i].at < p[index].at)
                    {
                        index = i;
                    }
                }
            }
        }

        // No process available
        if(index == -1)
        {
            current_time++;
        }

        else
        {
            p[index].start_time = current_time;

            p[index].ct =
            p[index].start_time + p[index].bt;

            p[index].tat =
            p[index].ct - p[index].at;

            p[index].wt =
            p[index].tat - p[index].bt;

            p[index].rt =
            p[index].wt;

            p[index].completed = true;

            completed_count++;

            current_time = p[index].ct;
        }
    }

    // Output
    cout << "\n\nPID\tAT\tBT\tST\tCT\tTAT\tWT\tRT\n";

    for(int i = 0; i < n; i++)
    {
        cout << p[i].pid << "\t"
             << p[i].at << "\t"
             << p[i].bt << "\t"
             << p[i].start_time << "\t"
             << p[i].ct << "\t"
             << p[i].tat << "\t"
             << p[i].wt << "\t"
             << p[i].rt << endl;
    }

    return 0;
}