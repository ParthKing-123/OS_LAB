#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
    int n, head, disk_size;

    cout << "ENTER NUMBER OF REQUESTS : ";
    cin >> n;

    int req[20];

    cout << "ENTER REQUEST QUEUE:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> req[i];
    }

    cout << "ENTER INITIAL HEAD POSITION : ";
    cin >> head;

    cout << "ENTER DISK SIZE : ";
    cin >> disk_size;

    // Sort requests
    sort(req, req + n);

    int total_seek = 0;

    cout << "\nSEEK SEQUENCE:\n";

    // Move RIGHT first
    for(int i = 0; i < n; i++)
    {
        if(req[i] >= head)
        {
            cout << head << " -> " << req[i] << endl;

            total_seek += abs(req[i] - head);

            head = req[i];
        }
    }

    // Move till end of disk
    total_seek += abs((disk_size - 1) - head);

    head = disk_size - 1;

    // Jump to beginning
    total_seek += (disk_size - 1);

    head = 0;

    // Continue servicing
    for(int i = 0; i < n; i++)
    {
        if(req[i] < head)
        {
            cout << head << " -> " << req[i] << endl;

            total_seek += abs(req[i] - head);

            head = req[i];
        }
    }

    // Service remaining left-side requests
    for(int i = 0; i < n; i++)
    {
        if(req[i] < 53)
        {
            cout << head << " -> " << req[i] << endl;

            total_seek += abs(req[i] - head);

            head = req[i];
        }
    }

    cout << "\nTOTAL SEEK TIME : " << total_seek;

    return 0;
}