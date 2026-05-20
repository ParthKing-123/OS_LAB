#include<iostream>
using namespace std;

int main()
{
    struct process
    {
        int pid, at, bt, tat, wt, rbt;
    } p[10];

    int np, tq;
    int completed = 0;
    int time = 0;

    cout << "Enter number of Processes: ";
    cin >> np;

    cout << "Enter Time Quantum: ";
    cin >> tq;

    // Input
    for(int i = 0; i < np; i++)
    {
        cout << "\nEnter PID: ";
        cin >> p[i].pid;

        cout << "Enter Arrival Time: ";
        cin >> p[i].at;

        cout << "Enter Burst Time: ";
        cin >> p[i].bt;

        p[i].rbt = p[i].bt; // Remaining BT
    }

    int i = 0;

    while(completed != np)
    {
        if(p[i].rbt > 0)
        {
            // If remaining burst time is greater than time quantum
            if(p[i].rbt > tq)
            {
                time += tq;
                p[i].rbt -= tq;
            }
            else
            {
                // Process completes
                time += p[i].rbt;
                p[i].rbt = 0;

                completed++;

                p[i].tat = time - p[i].at;
                p[i].wt = p[i].tat - p[i].bt;
            }
        }

        i = (i + 1) % np;
    }

    // Output
    cout << "\nPID\tAT\tBT\tTAT\tWT\n";

    for(int i = 0; i < np; i++)
    {
        cout << p[i].pid << "\t"
             << p[i].at << "\t"
             << p[i].bt << "\t"
             << p[i].tat << "\t"
             << p[i].wt << "\n";
    }

    return 0;
}