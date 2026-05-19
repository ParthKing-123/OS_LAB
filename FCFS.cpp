#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    vector<int> bt(n), wt(n), tat(n);

    // Input Burst Time
    for (int i = 0; i < n; i++) {
        cout << "Enter Burst Time for Process P" << i + 1 << ": ";
        cin >> bt[i];
    }

    // FCFS Waiting Time Calculation
    wt[0] = 0;

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Turnaround Time Calculation
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    // Display Table
    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";

    float totalWT = 0, totalTAT = 0;

    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t\t"
             << bt[i] << "\t\t"
             << wt[i] << "\t\t"
             << tat[i] << endl;

        totalWT += wt[i];
        totalTAT += tat[i];
    }

    // Average Times
    cout << "\nAverage Waiting Time = " << totalWT / n;
    cout << "\nAverage Turnaround Time = " << totalTAT / n;

    return 0;
}