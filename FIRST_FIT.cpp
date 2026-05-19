#include <iostream>
using namespace std;

int main() {
    int blocks[50], files[50];
    int m, n;

    cout << "Enter number of memory blocks: ";
    cin >> m;

    cout << "Enter sizes of memory blocks:\n";
    for (int i = 0; i < m; i++) {
        cin >> blocks[i];
    }

    cout << "Enter number of files/processes: ";
    cin >> n;

    cout << "Enter sizes of files/processes:\n";
    for (int i = 0; i < n; i++) {
        cin >> files[i];
    }

    int allocation[50];

    // Initialize all allocations as -1 (not allocated)
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // First Fit Allocation
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blocks[j] >= files[i]) {
                allocation[i] = j;

                // Reduce available memory in block
                blocks[j] -= files[i];
                break;
            }
        }
    }

    // Display Allocation Result
    cout << "\nFile No.\tFile Size\tBlock No.\n";

    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t\t" << files[i] << "\t\t";

        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";

        cout << endl;
    }

    return 0;
}