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

    // Input memory block sizes
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

    // WORST FIT ALGORITHM
    for(int i = 0; i < np; i++)
    {
        int worstIndex = -1;

        for(int j = 0; j < nb; j++)
        {
            // Block can fit process
            if(block[j] >= process[i])
            {
                // First suitable block
                if(worstIndex == -1)
                {
                    worstIndex = j;
                }

                // Find largest suitable block
                else if(block[j] > block[worstIndex])
                {
                    worstIndex = j;
                }
            }
        }

        // Allocate if block found
        if(worstIndex != -1)
        {
            allocation[i] = worstIndex;

            // Reduce remaining memory
            block[worstIndex] -= process[i];
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