#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int memorySize, processSize;

    cout << "ENTER TOTAL MEMORY SIZE : ";
    cin >> memorySize;

    cout << "ENTER PROCESS SIZE : ";
    cin >> processSize;

    int blockSize = 1;

    // Find smallest power of 2
    while(blockSize < processSize)
    {
        blockSize *= 2;
    }

    // Check memory availability
    if(blockSize > memorySize)
    {
        cout << "\nMEMORY CANNOT BE ALLOCATED";
        return 0;
    }

    cout << "\nINITIAL MEMORY BLOCK : "
         << memorySize << " KB";

    int currentSize = memorySize;

    // Split memory until suitable block obtained
    while(currentSize > blockSize)
    {
        currentSize /= 2;

        cout << "\nMEMORY SPLIT INTO : "
             << currentSize
             << " KB + "
             << currentSize
             << " KB";
    }

    cout << "\n\nPROCESS OF "
         << processSize
         << " KB ALLOCATED TO BLOCK OF "
         << blockSize
         << " KB";

    cout << "\nINTERNAL FRAGMENTATION : "
         << blockSize - processSize
         << " KB";

    return 0;
}