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

    // Input memory blocks
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

    // Initially no process allocated
    for(int i = 0; i < np; i++)
    {
        allocation[i] = -1;
    }

    // BEST FIT ALGORITHM
    for(int i = 0; i < np; i++)
    {
        int bestIndex = -1;

        for(int j = 0; j < nb; j++)
        {
            // Check if block can fit process
            if(block[j] >= process[i])
            {
                // First suitable block
                if(bestIndex == -1)
                {
                    bestIndex = j;
                }

                // Find smaller suitable block
                else if(block[j] < block[bestIndex])
                {
                    bestIndex = j;
                }
            }
        }

        // Allocate block if found
        if(bestIndex != -1)
        {
            allocation[i] = bestIndex;

            // Reduce remaining memory
            block[bestIndex] -= process[i];
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