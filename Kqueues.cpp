#include <bits/stdc++.h>
using namespace std;
class kqueues{
    
    int k, n;
    int libert;
    int *arr;
    int *top;
    int *last;
    int *next;
    
    public: 
    kqueues(int k, int n);
    bool isEmpty(int queuenum){
        return (top[queuenum] == -1);
    }
    bool isfull(){
        return libert == -1;
    }
    void enqueue(int element, int queuenum);
    int dequeue(int queuenum);

};
    
    kqueues::kqueues(int k1, int n1){
        k = k1;
        n = n1;
        
        arr = new int[n];
        top = new int[k];
        last = new int[k];
        next = new int[n];
        for(int i = 0; i < k; i++){
            top[i] = -1;
        }
        for(int i = 0; i < n-1; i++){
            next[i] = i+1;
        }
        next[n-1] = -1;
        libert = 0;
    }
    
    void  kqueues::enqueue(int element, int queuenum){
        if(isfull()){
            cout <<"Jagah Nahi" << endl;
            return;
        }
        int i = libert;
        libert = next[i];
        if(isEmpty(queuenum)){
            top[queuenum] = i;
        }
        else{
            next[last[queuenum]] = i;
        }
        next[i] = -1;
        last[queuenum] = i;
        arr[i] = element;
    }
    int  kqueues::dequeue(int queuenum){
        
        if(isEmpty(queuenum)){
            cout << "Khaali Hai" << endl;
            return INT_MAX;
        }
        int i = top[queuenum];
        top[queuenum] = next[i];
        next[i] = libert;
        libert = i;
        
        return arr[i];
    }

int main(){
    int k = 3, n = 10; 
    kqueues ks(k, n); 

    ks.enqueue(15, 2); 
    ks.enqueue(45, 2); 

    ks.enqueue(17, 1); 
    ks.enqueue(49, 1); 
    ks.enqueue(39, 1); 
  
    ks.enqueue(11, 0); 
    ks.enqueue(9, 0); 
    ks.enqueue(7, 0); 
  
    cout << "Dequeued element from queue 2 is " << ks.dequeue(2) << endl; 
    cout << "Dequeued element from queue 1 is " << ks.dequeue(1) << endl; 
    cout << "Dequeued element from queue 0 is " << ks.dequeue(0) << endl; 
  
    return 0;
}
