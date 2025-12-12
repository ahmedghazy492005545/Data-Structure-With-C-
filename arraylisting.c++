#include<bits/stdc++.h>
using namespace std;

template<class t>
class arraylist{
private:
    t *arr;
    int length;
    int maxsize;

public:
        arraylist(int s){
        if(s <= 0){ 
            maxsize = 10;
        } else {
            maxsize = s; 
        }
        length = 0;
        arr = new t[maxsize];
    }

    bool isempty(){
        return length == 0;
    }

    
    bool isfull(){
        return length == maxsize;
    }

    void print(){
        for(int i=0;i<length;i++){
            cout<<arr[i]<<" ";
        }
        cout << endl; 
    }

  
    void removing(int pos){
        if(isempty()){
            cout<<"list empty...!" << endl;
        }
        else if(pos < 0 || pos >= length){ 
            cout<<"Out of range...!" << endl;
        }else{
           
            for(int i=pos;i < length - 1;i++){
                arr[i]=arr[i+1];
            }
            length--; 
        }
    }

  
    void inserting(int pos,t element){
        if(isfull()){
            cout<<"list full...!" << endl;
        }
        else if(pos < 0 || pos > length){ 
            cout<<"Out of range...!" << endl;
        }else{
     
            for(int i=length;i>pos;i--){
                arr[i]=arr[i-1];
            }
            arr[pos] = element; 
            length++; 
        }
    }

    void insertatpos(t element){
        if(isfull()){
            cout<<"it is full" << endl;
        }else{
            arr[length]=element;
            length++;
        }
    }

  
    int search(t element){
        for(int i=0;i<length;i++){
            if(arr[i]==element){
                return i; 
            }
        }
        return -1; 
    }
};
int main(){
    arraylist<int>arr(3);
    arr.inserting(0,7);
    arr.inserting(1,5);
    arr.inserting(2,9);
    arr.print();
}
