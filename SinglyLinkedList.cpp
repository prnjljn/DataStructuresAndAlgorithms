#include<bits/stdc++.h>
using namespace std;
struct linkedList{
    int value;
    struct linkedList *next;
};
typedef  linkedList *node;
node head;
void insertAtFirst(int value){
    node temp=new linkedList();
    temp->value=value;
    if(head==NULL){
       head=temp;
       head->next=NULL;
    }
    else{
        temp->next=head;
        head=temp;
    }
}
void insertAtLast(int value){
    if(head==NULL){
        insertAtFirst(value);
        return;
    }
    node temp=new linkedList();
    temp->value=value;
    temp->next=NULL;
    node p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=temp;
}
int getSize(){
    if(head==NULL){
        return 0;
    }
    node p=head;
    int size=1;
    while(p->next!=NULL){
        p=p->next;
        size++;
    }
    return size;
}
void insertAtPosition(int pos,int value){   //zero based indexing
    int size=getSize();
    if(pos>size || pos<0){
        return;
    }
    if(pos==0){
        insertAtFirst(value);
        return;
    }
    if(pos==size){
        insertAtLast(value);
        return;
    }
    node p=head;
    for(int i=0;i<pos-1;i++){
        p=p->next;
    }
    node prev = p;
    node curr = p->next;
    node temp=new linkedList();
    temp->value=value;
    prev->next=temp;
    temp->next=curr;
}
void deleteAtFirst(){
    if(head==NULL){
        return;
    }
    node p=head;
    head=head->next;
    free(p);
}
void deleteAtLast(){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        head=NULL;
        return;
    }
    node p=head;
    while(p->next->next!=NULL){
        p=p->next;
    }
    free(p->next);
    p->next=NULL;
}
void deleteAtPosition(int pos){ //Zero based Indexing
    int size = getSize();
    if(pos>size-1 || pos<0){
        return;
    }
    if(pos==0){
        deleteAtFirst();
        return;
    }
    if(pos==size-1){
        deleteAtLast();
        return;
    }
    node p=head;
    for(int i=0;i<pos-1;i++){
        p=p->next;
    }
    node prev =p;
    node next=p->next->next;
    node curr =p->next;
    prev->next=next;
    free(curr);
}
void printList(){
    node p=head;
    while(p!=NULL){
        cout<<p->value<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main(){
insertAtFirst(5);
insertAtFirst(10);
insertAtFirst(15);
printList();
insertAtPosition(1,20);
insertAtPosition(3,55);
insertAtPosition(6,78);
insertAtLast(27);
printList();
deleteAtFirst();
deleteAtLast();
deleteAtPosition(3);
printList();


}