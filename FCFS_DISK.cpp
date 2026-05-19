#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, initial, time, THM = 0, seektime;
    
    cout << "Enter number of requests: ";
    cin >> n;

    int RQ[n];

    cout << "Enter request queue: ";
    for(int i = 0; i < n; i++)
    {
        cin >> RQ[i];
    }

    cout << "Enter initial head position: ";
    cin >> initial;

    cout << "Enter time to move one track: ";
    cin >> time;

    // FCFS Disk Scheduling
    for(int i = 0; i < n; i++)
    {
        THM = THM + abs(initial - RQ[i]);
        initial = RQ[i];
    }

    seektime = THM * time;

    cout << "\nTotal Head Movement (THM) = " << THM;
    cout << "\nSeek Time = " << seektime << endl;

    return 0;
}