#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, initial, time;
    int THM = 0, seektime = 0;

    cout << "Enter number of requests: ";
    cin >> n;

    int RQ[n], visited[n];

    cout << "Enter request queue: ";
    for(int i = 0; i < n; i++)
    {
        cin >> RQ[i];
        visited[i] = 0;
    }

    cout << "Enter initial head position: ";
    cin >> initial;

    cout << "Enter time to move one track: ";
    cin >> time;

    // SSTF Disk Scheduling
    for(int i = 0; i < n; i++)
    {
        int min_distance = 1000;
        int index = -1;

        for(int j = 0; j < n; j++)
        {
            if(visited[j] == 0)
            {
                int distance = abs(initial - RQ[j]);

                if(distance < min_distance)
                {
                    min_distance = distance;
                    index = j;
                }
            }
        }

        visited[index] = 1;
        THM = THM + min_distance;
        initial = RQ[index];
    }

    seektime = THM * time;

    cout << "\nTotal Head Movement (THM) = " << THM;
    cout << "\nSeek Time = " << seektime << endl;

    return 0;
}
