#include <bits/stdc++.h>
using namespace std;
class kstacks{
    
    int k, n;
    int libert;
    int *arr;
    int *top;
    int *next;
    
    public: 
    kstacks(int k, int n);
    bool isEmpty(int stacknum){
        return (top[stacknum] == -1);
    }
    bool isfull(){
        return libert == -1;
    }
    void push(int element, int stacknum);
    int pop(int stacknum);

};
    
    kstacks::kstacks(int k1, int n1){
        k = k1;
        n = n1;
        
        arr = new int[n];
        top = new int[k];
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
    
    void  kstacks::push(int element, int stacknum){
        if(isfull()){
            cout <<"The stack is full" << endl;
            return;
        }
        int i = libert;
        libert = next[i];
        next[i] = top[stacknum];
        top[stacknum] = i;
        arr[i] = element;
        
    }
    int  kstacks::pop(int stacknum){
        
        if(isEmpty(stacknum)){
            cout << "The stack is empty" << endl;
            return INT_MAX;
        }
        int i = top[stacknum];
        top[stacknum] = next[i];
        next[i] = libert;
        libert = i;
        
        return arr[i];
    }

int main(){
    int k = 3, n = 10; 
    kstacks ks(k, n); 

    ks.push(15, 2); 
    ks.push(45, 2); 
  

    ks.push(17, 1); 
    ks.push(49, 1); 
    ks.push(39, 1); 

    ks.push(11, 0); 
    ks.push(9, 0); 
    ks.push(7, 0); 
  
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl; 
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl; 
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl; 
  
    return 0; 
}
