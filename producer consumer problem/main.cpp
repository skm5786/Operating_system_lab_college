#include <iostream>
using namespace::std;
int buffer[15];
int items=1;
class binarysemaphore{
private:
    int s;
public:
    binarysemaphore(int z){
        s=z;
    }
     void wait(){
        while (s<=0);
        s--;
    }
    void Signal(){
        s=1;
    }
};
class countingsemaphore{
private:
    int s;
public:
    countingsemaphore(int k){
        s=k;
    }
     void wait(){
         while (s<=0){
             cout<<"buffer is empty or full"<<endl;
             break;
         }
        s--;
    }
    void Signal(){
        s=s+1;
    }
};
void producer(binarysemaphore* mutex,countingsemaphore* empty,countingsemaphore* full){
    empty->wait();
    mutex->wait();
    cout<<"enter item: ";
    cin>>buffer[items+1];
    items++;
    full->Signal();
    mutex->Signal();
    
}
void consumer(binarysemaphore* mutex,countingsemaphore* empty,countingsemaphore* full){
    full->wait();
    mutex->wait();
    cout<<"item removed: "<<buffer[items]<<endl;
    items--;
    mutex->Signal();
    empty->Signal();
    
}
int main(){
    int n;
    binarysemaphore mutex(1);
    countingsemaphore empty(15);
    countingsemaphore full(0);
    while (true) {
        cout<<"press 1 to call producer"<<endl;
        cout<<"press 2 to call consumer"<<endl;
        cout<<"press 3 to exit"<<endl;
        cin>>n;
        switch (n) {
            case 1:
                producer(&mutex, &empty, &full);
                break;
            case 2:
                consumer(&mutex, &empty, &full);
                break;
            case 3:
                exit(1);
            default:
                cout<<"wrong input\n";
                break;
        }
    }
    return 0;
}
