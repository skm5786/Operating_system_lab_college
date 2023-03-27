#include <iostream>
using namespace::std;
class process{
public:
    int p_id;
    int AT;
    int BT;
    int CT;
    int TAT;
    int WT;
    int RT;
    void operator = (const process &obj){
        p_id=obj.p_id;
        AT=obj.AT;
        BT=obj.BT;
        CT=obj.CT;
        TAT=obj.TAT;
        RT=obj.RT;
    }
};
void bubblesort(process p[],int n){
    int i,j;
    process temp;
    int issort=0;
    for (i=0; i<n-1; i++) {//operation number for loop
         issort=1;
        for (j=0; j<n-1-i; j++) {//element checking and swapping for loop
            if (p[j].AT>p[j+1].AT) {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
                issort=0;
            }
        }
            if (issort==1) {
                return ;
            }
        
    }
}
int main(){
    process p[30];
    int x,k=0;
    int i=0;
    int n=0;
    while (1) {
        cout<<"press 1 to enter process"<<endl;
        cout<<"press 2 to exit"<<endl;
        cin>>x;
        if (x==1) {
            cout<<"enter p_id: ";
            cin>>p[i].p_id;
            cout<<"enter AT: ";
            cin>>p[i].AT;
            cout<<"enter BT: ";
            cin>>p[i].BT;
            n++;
            i++;
        } else {
            break;
        }
        }
    bubblesort(p, n);
    p[0].WT=0;
    for(i=1;i<n;i++){
        k=k+(p[i-1].BT);
        p[i].WT=(k)-p[i].AT;
    }
    for(i=0;i<n;i++){
        p[i].TAT=p[i].WT+p[i].BT;
    }
    for(i=0;i<n;i++){
        p[i].CT=p[i].TAT+p[i].AT;
    }
        cout<<"p_id    "<<"AT   "<<"BT   "<<"CT   "<<"WT   "<<"TAT    "<<endl;
    for(i=0;i<n;i++){
        cout<<p[i].p_id<<"     "<<p[i].AT<<"     "<<p[i].BT<<"     "<<p[i].CT<<"     "<<p[i].WT<<"     "<<p[i].TAT<<endl;
    }
    return 0;
}
