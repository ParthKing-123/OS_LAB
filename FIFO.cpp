#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

int main() {
    
    int n, frameSize;

    cout << "Enter number of pages: ";
    cin >> n;

    vector<int> pages(n);

    cout << "Enter page reference string: ";
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    cout << "Enter number of frames: ";
    cin >> frameSize;

    vector<int> frames(frameSize, -1);
    queue<int> order;

    int hits = 0, misses = 0;

    cout << "\nFIFO Page Replacement Process:\n\n";

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        bool found = false;

        // Check HIT
        for (int j = 0; j < frameSize; j++) {
            if (frames[j] == page) {
                found = true;
                hits++;
                cout << "Page " << page << " -> HIT\n";
                break;
            }
        }

        // MISS
        if (!found) {
            misses++;

            bool placed = false;

            // Empty frame available
            for (int j = 0; j < frameSize; j++) {
                if (frames[j] == -1) {
                    frames[j] = page;
                    order.push(page);
                    placed = true;
                    break;
                }
            }

            // Replace oldest page
            if (!placed) {
                int oldest = order.front();
                order.pop();

                // Replace in same frame position
                for (int j = 0; j < frameSize; j++) {
                    if (frames[j] == oldest) {
                        frames[j] = page;
                        break;
                    }
                }

                order.push(page);
            }

            cout << "Page " << page << " -> MISS\n";
        }

        // Display frames
        cout << "Frames: ";
        for (int j = 0; j < frameSize; j++) {
            if (frames[j] != -1)
                cout << frames[j] << " ";
        }

        cout << "\n\n";
    }

    // Ratios
    float hitRatio = (float)hits / n;
    float missRatio = (float)misses / n;

    cout << "=============================\n";
    cout << "Total Hits      : " << hits << endl;
    cout << "Total Misses    : " << misses << endl;

    cout << fixed << setprecision(2);

    cout << "Hit Ratio       : " << hitRatio << endl;
    cout << "Miss Ratio      : " << missRatio << endl;

    cout << "Hit Percentage  : " << hitRatio * 100 << "%\n";
    cout << "Miss Percentage : " << missRatio * 100 << "%\n";

    return 0;
}