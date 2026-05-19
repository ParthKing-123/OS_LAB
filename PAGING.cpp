#include<iostream>
using namespace std;

int main(){

    int np,nf,LA,Pagenum,Offset,PageSize,PA,Framenum;

    cout<<"Enter no of pages: ";
    cin>>np;

    cout<<"Enter no of frames: ";
    cin>>nf;

    int PageTable[np];

    cout<<"Enter Page Table:\n";

    for(int i=0;i<np;i++){
        cin>>PageTable[i];
    }

    cout<<"Enter Page Size: ";
    cin>>PageSize;

    cout<<"Enter Logical Address(decimal): ";
    cin>>LA;

    Pagenum = LA / PageSize;

    Offset = LA % PageSize;

    if(Pagenum >= np){
        cout<<"Invalid Logical Address";
        return 0;
    }

    Framenum = PageTable[Pagenum];

    PA = Framenum * PageSize + Offset;

    cout<<"\nLogical Address: "<<LA<<endl;
    cout<<"Page Number: "<<Pagenum<<endl;
    cout<<"Offset: "<<Offset<<endl;
    cout<<"Frame Number: "<<Framenum<<endl;
    cout<<"Physical Address: "<<PA<<endl;

    return 0;
}