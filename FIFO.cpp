#include <iostream>
using namespace std;

int main() {
    int n, frames;

    cout << "Enter number of pages: ";
    cin >> n;

    int pages[n];
    cout << "Enter page reference string:\n";
    for(int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    cout << "Enter number of frames: ";
    cin >> frames;

    int frame[frames];
    for(int i = 0; i < frames; i++)
        frame[i] = -1;

    int pageFaults = 0, hits = 0;
    int index = 0; // FIFO pointer

    for(int i = 0; i < n; i++) {
        bool found = false;

        // Check hit
        for(int j = 0; j < frames; j++) {
            if(frame[j] == pages[i]) {
                found = true;
                hits++;
                break;
            }
        }

        // If miss (page fault)
        if(!found) {
            frame[index] = pages[i];
            index = (index + 1) % frames;
            pageFaults++;
        }

        // Display frames
        cout << "After page " << pages[i] << ": ";
        for(int j = 0; j < frames; j++) {
            if(frame[j] == -1) cout << "- ";
            else cout << frame[j] << " ";
        }

        if(found) cout << " (Hit)";
        else cout << " (Miss)";
        cout << endl;
    }

    // Ratios
    float hitRatio = (float)hits / n;
    float missRatio = (float)pageFaults / n;

    cout << "\nTotal Hits = " << hits;
    cout << "\nTotal Page Faults (Misses) = " << pageFaults;

    cout << "\nHit Ratio = " << hitRatio;
    cout << "\nMiss Ratio = " << missRatio;

    return 0;
}
