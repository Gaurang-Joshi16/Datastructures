#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void insertathead(Node* &head, int data){
    Node* newnode = new Node(data);
    newnode->next=head;
    head=newnode;
}

void insertattail(Node* &tail, int data){
    Node* newnode = new Node(data);
    tail->next=newnode;
    tail=newnode;
}

void insertatposition(Node* &head, int data  , int position){
    if(position<=0){
        cout<<"Invalid position to enter"<<endl;
        return;
    }
    if(position==1){
        insertathead(head,data);
        return;
    }
    Node* newnode=new Node(data);
    Node* temp=head;
    for(int i=1;i<position-1&&temp!=NULL;i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

void deleteatposition(Node* &head,int position){
    if(position<=0){
        cout<<"invalid position";
        return;
    }
    if(position==1){
        Node* temp = head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        return;
    }
    Node* prev=NULL;
    Node* curr=head;
    for(int i=1;i<position;i++){
        prev=curr;
        curr=curr->next;
    }
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
    return;
}

void print(Node* &head){
    Node* temp =head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* newnode= new Node(10);
    Node* head=newnode;
    Node* Tail= newnode;
    insertathead(head,20);
    print(head);
    insertattail(Tail,30);
    print(head);
    insertatposition(head,40,2);
    print(head);
    deleteatposition(head,2);
    print(head);
}