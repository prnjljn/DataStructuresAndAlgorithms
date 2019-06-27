#include<iostream>
using namespace std;
struct linkedList{
  int data;
  struct linkedList *next;
}*head;
typedef linkedList *node;
void insertAtBegin(int value){
  node temp = new linkedList();
  temp->data=value;
  temp->next=NULL;
  if(head==NULL){
    head=temp;
    head->next=NULL;
  }
  else{
    node p;
    p=head;
    head=temp;
    head->next=p;
  }
}
void insertAtLast(int value){
  node temp=new linkedList();
  temp->data=value;
  temp->next=NULL;
  if(head==NULL){
    insertAtBegin(value);
    return;
  }
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
  int size =1;
  node p = head;
  while(p->next!=NULL){
    p=p->next;
    size++;
  }
  return size;
}
void insert(int pos,int value){
  if(pos==0){
    insertAtBegin(value);
    return;
  }
  int size = getSize();
  if(pos==size){
    insertAtLast(value);
    return;
  }
  if(pos>size || pos<0){
    cout<<"invalid position"<<endl;
    return;
  }
  node p= head;
  for(int i=0;i<pos-1;i++){
    p=p->next;
  }
  node prev = p;
  node current = p->next;
  node temp= new linkedList();
  temp->data=value;
  temp->next=NULL;
  prev->next = temp;
  temp->next = current;

}
void print(){
  node p = head;
  while(p!=NULL){
    cout<<p->data<<" ";
    p=p->next;
  }
  cout<<endl;
}
int search(int value){
  if(head==NULL){
    cout<<"EmptyList"<<endl;
  }
  node p= head;
  int position =0;
  while(p!=NULL){
    if(p->data==value){
      return position;
    }
    p=p->next;
    position++;
  }
}
void remove(int position){
  if(position==0){
    node temp =head;
    head=head->next;
    free(temp);
  }
  node p =head;
  for(int i=0;i<position-1;i++){
    p=p->next;
  }
  node prev = p;
  node curr = p->next;
  node after= p->next->next;
  prev->next=after;
  free(curr);
}



int main(){
  insertAtLast(0);
  insertAtLast(3);
  insertAtLast(4);
  insertAtLast(5);
  insertAtLast(6);
  insert(4,8);
  insert(0,2);
  insert(5,7);
  print();
  int c= search(5);
  cout<<"position of 5 is "<<c<<endl;
  remove(c);
  print();

}
