#include<iostream>
using namespace std;

class Stack{
    public: 
        int size;
        int *arr;
        int top;

    Stack(int size){
        this->size=size;
        arr = new int[size];
        this->top=-1;
    }

    //to push any element
    void push(int element){
        if(top==size-1){
            cout<<"Stack is full no space to fill"<<endl;
            return;
        }
        // top ek aage jayega aur element aayega usme 
        top++;
        arr[top]=element;
    }

    void pop(){
        if(top==-1){
            cout<<"stack underflow"<<endl;
            return;
        }
        top--;
    }

    int peek(){
        if(top==-1){
            cout<<"no peek present";
        }
        return arr[top];
    }

    void display(){
        if(top==-1){
            cout<<"no elements to display"<<endl;
            return;
        }
        for(int i = top ; i >=0 ; i --){
            cout<<arr[i]<<"\n";
        }
     // cout<<endl;
    }
};

int main(){
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    cout<<"Peak element of the array is "<<s.peek()<<endl;
    
    s.pop();
    s.display();

}