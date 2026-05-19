#include <iostream>
using namespace std;

int main() {
    int n, m;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resource types: ";
    cin >> m;

    int alloc[n][m], max[n][m], need[n][m], avail[m];

    // Input Allocation matrix
    cout << "\nEnter Allocation Matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> alloc[i][j];
        }
    }

    // Input Max matrix
    cout << "\nEnter Maximum Matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> max[i][j];
        }
    }

    // Input Available resources
    cout << "\nEnter Available Resources:\n";
    for(int j = 0; j < m; j++) {
        cin >> avail[j];
    }

    // Calculate Need matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    bool finish[n] = {false};
    int safeSeq[n];
    int work[m];

    // Initialize work = available
    for(int i = 0; i < m; i++)
        work[i] = avail[i];

    int count = 0;

    while(count < n) {
        bool found = false;

        for(int i = 0; i < n; i++) {
            if(!finish[i]) {
                bool safe = true;

                for(int j = 0; j < m; j++) {
                    if(need[i][j] > work[j]) {
                        safe = false;
                        break;
                    }
                }

                if(safe) {
                    // Process can be executed
                    for(int j = 0; j < m; j++) {
                        work[j] += alloc[i][j];
                    }

                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                    break;
                }
            }
        }

        // If no process found → unsafe state
        if(!found) {
            cout << "\nSystem is NOT in a safe state (Deadlock possible)\n";
            return 0;
        }
    }

    // Safe state
    cout << "\nSystem is in SAFE state.\nSafe sequence: ";
    for(int i = 0; i < n; i++) {
        cout << "P" << safeSeq[i];
        if(i != n-1) cout << " -> ";
    }

    return 0;
}
