#include <iostream>
using namespace::std;
struct Process
{
    int at;
    int pid;
    int bt;
    int priority;
};
bool comp(Process a,Process b)
{
if(a.at == b.at)
{
return a.priority<b.priority;
}
else
{
    return a.at>b.at;
}
}
void bubblesort(Process p[],int n){
    int i,j;
    Process temp;
    int issort=0;
    for (i=0; i<n-1; i++) {//operation number for loop
         issort=1;
        for (j=0; j<n-1-i; j++) {//element checking and swapping for loop
            if (comp(p[j], p[j+1])) {
                temp.priority=p[j].priority;
                temp.at=p[j].at;
                temp.bt=p[j].bt;
                temp.pid=p[j].pid;
                p[j].priority=p[j+1].priority;
                p[j].at=p[j+1].at;
                p[j].bt=p[j+1].bt;
                p[j].pid=p[j+1].pid;
                p[j+1].priority=temp.priority;
                p[j+1].at=temp.at;
                p[j+1].bt=temp.bt;
                p[j+1].pid=temp.pid;
                issort=0;
            }
        }
            if (issort==1) {
                return ;
            }
        
    }
}

int main()
{
    Process p[30];
    int n=0,x,i=0,k=0;
    int wt[30];
    int tat[30];
    int avg_wt=0,avg_tat=0;
    int service[50];
    while (1) {
        cout<<"press 1 to enter process"<<endl;
        cout<<"press 2 to exit"<<endl;
        cin>>x;
        if (x==1) {
            cout<<"enter p_id: ";
            cin>>p[i].pid;
            cout<<"enter AT: ";
            cin>>p[i].at;
            cout<<"enter BT: ";
            cin>>p[i].bt;
            cout<<"enter priority: ";
            cin>>p[i].priority;
            n++;
            i++;
        } else {
            break;
        }
    }
    bubblesort(p, n);
    wt[0] = 0;
     
        // calculating waiting time
    k= p[0].at;
    wt[0]=0;
    
    for(i=1;i<n;i++){     
        k=p[i-1].bt+k;
        wt[i]=k-p[i].at;
    }
    if(wt[i]<0)
        {
        wt[i]=0;
        }
    // calculating turnaround time
    for(i=0;i<n;i++){
        tat[i]=wt[i]+p[i].bt;
    }
    cout<<"p_id    "<<"AT   "<<"BT   "<<"priority   "<<"WT   "<<"TAT    "<<endl;
for(i=0;i<n;i++){
    cout<<p[i].pid<<"     "<<p[i].at<<"     "<<p[i].bt<<"     "<<p[i].priority<<"     "<<wt[i]<<"     "<<tat[i]<<endl;
}
    for (int  i=0; i<n; i++)
       {
           avg_wt = avg_wt + wt[i];
           avg_tat = avg_tat + tat[i];
       }
    
       cout << "\nAverage waiting time = "
            << (float)avg_wt / (float)n;
       cout << "\nAverage turn around time = "
            << (float)avg_tat / (float)n;
    return 0;
}
