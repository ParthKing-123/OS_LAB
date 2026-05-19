#include<iostream>
using namespace std;
int main()
{
   struct process{
       int pid,at,bt,tat,wt,rbt;
   }p[3];
   int i=0,np,tq=2,x=0,y=0;
   cout<<"Enter number of Processes:-";
   cin>>np;
 
   for(int i=0;i<3;i++)
   {
       cout<<"Enter PID";
       cin>>p[i].pid;
       cout<<"Enter at";
       cin>>p[i].at;
       cout<<"Enter bt";
       cin>>p[i].bt;
   }
    for(int i=0;i<np;i++)
   {
       p[i].rbt=p[i].bt;
   }
   while(1)
   {
       if(p[i].bt>0)
       {
           if(p[i].bt>tq)
           {
               x=x+tq;
               p[i].bt=p[i].bt-tq;
           }
           else{
               x=x+p[i].bt;
               p[i].rbt=0;
               y++;
               p[i].tat=x;
               p[i].wt=p[i].tat-p[i].bt;
               if(y==np)
               {
                   break;
               }
           }

       }
       if(y==np-1)
       {
           i=0;
       }
       else{
           i++;
       }
   }
cout << "\nPID\tAT\tBT\tTAT\tWT\n";
for(int i = 0; i < np; i++)
{
   cout << p[i].pid << "\t"
        << p[i].at << "\t"
        << p[i].bt << "\t"
        << p[i].tat << "\t"
        << p[i].wt << "\n";
}

return 0;
}