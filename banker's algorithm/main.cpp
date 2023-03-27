#include <iostream>
using namespace::std;
void checksafety(int **allocation,int **need,int *available,int r,bool *finish,int n){
    int *sequence=new int(r);
    for(int i=0;i<n;i++){
        finish[i]=false;
    }
    
    for(int m=0;m<n;m++){
        for(int i=0;i<n;i++){
            int check=1;
            for(int j=0;j<r;j++)
            {
                if (need[i][j]>available[j]||(finish[i]==true)) {
                    check=0;
                    break;
                }
            }
            if (check==0||(finish[i]==true)) {
                continue;
            } else {
                finish[i]=true;
                for(int k=0;k<r;k++){
                    available[i]=available[i]+allocation[i][k];
                    sequence[m]=i;
                }
            }
        }
    }
    int check1=1;
    for(int i=0;i<n;i++){
        if (finish[i]==false) {
            check1=0;
            break;
        }
    }
    if (check1==0) {
        cout<<"system is not in safe state\n";
    }
    else{
        cout<<"safe sequence is :";
        for(int i=0;i<n;i++){
            cout<<sequence[i]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int r;//no. of resources
    int n;//no. of processes
    cout<<"enter no. of resources to be used:"<<endl;
    cin>>r;
    cout<<"enter no. of processes:"<<endl;
    cin>>n;
    int **allocation=new int*[n];
    for(int i=0;i<n;i++){
        allocation[i]=new int[r];
    }
    int **max;
   max=new int*[n];
    for(int i=0;i<n;i++){
        max[i]=new int[r];
    }
    int **need=new int*[n];
    for(int i=0;i<n;i++){
        need[i]=new int[r];
    }
    int *available=new int[r];
    bool *finish=new bool[n];
    for(int i=0;i<n;i++){
        cout<<"enter allocated resources of process "<<i+1<<endl;
        for(int j=0;j<r;j++){
            cin>>allocation[i][j];
        }
    }
    for(int i=0;i<n;i++){
        cout<<"enter max resources of process "<<i+1<<endl;
        for(int j=0;j<r;j++){
            cin>>max[i][j];
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }
    cout<<"enter the no. of resources available\n";
    for(int i=0;i<r;i++){
        cin>>available[i];
    }
    checksafety(allocation, need, available, r, finish, n);
    return 0;
}

