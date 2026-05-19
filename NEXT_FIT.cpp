#include<iostream>

using namespace std;

int main()
{
    int nb, np;

    cout << "ENTER NUMBER OF MEMORY BLOCKS : ";
    cin >> nb;

    cout << "ENTER NUMBER OF PROCESSES : ";
    cin >> np;

    int block[20], process[20];
    int allocation[20];

    // Input block sizes
    cout << "\nENTER MEMORY BLOCK SIZES:\n";

    for(int i = 0; i < nb; i++)
    {
        cin >> block[i];
    }

    // Input process sizes
    cout << "\nENTER PROCESS SIZES:\n";

    for(int i = 0; i < np; i++)
    {
        cin >> process[i];
    }

    // Initially no allocation
    for(int i = 0; i < np; i++)
    {
        allocation[i] = -1;
    }

    int lastIndex = 0;

    // NEXT FIT ALGORITHM
    for(int i = 0; i < np; i++)
    {
        int count = 0;

        while(count < nb)
        {
            // If block can fit process
            if(block[lastIndex] >= process[i])
            {
                allocation[i] = lastIndex;

                // Reduce remaining memory
                block[lastIndex] -= process[i];

                break;
            }

            // Move circularly
            lastIndex = (lastIndex + 1) % nb;

            count++;
        }
    }

    // Output
    cout << "\nPROCESS\tPROCESS SIZE\tBLOCK NUMBER\n";

    for(int i = 0; i < np; i++)
    {
        cout << "P" << i+1 << "\t"
             << process[i] << "\t\t";

        if(allocation[i] != -1)
        {
            cout << allocation[i] + 1;
        }
        else
        {
            cout << "NOT ALLOCATED";
        }

        cout << endl;
    }

    return 0;
}