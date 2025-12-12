#include<bits/stdc++.h>
using namespace std;
template<class t>
class Doublylinkedlist{
struct node
{
    t item;
    node *next;
    node *prev;
};
node *head,*tail;
int count;
public:
Doublylinkedlist(){
head=NULL;
tail=NULL;
count=0;
}
void isempty(){
return(head==NULL);
}
void insertionathead(t element){
node *newnode=new node;
newnode->item=element;
if(count==0){
    head=tail=newnode;
    newnode->next=newnode->prev=NULL;
}else{
    newnode->next=head;
    newnode->prev=NULL;
    head->prev=newnode;
    head=newnode;
}
count++;
}
void insertionattail(t element){
node *newnode=new node;
newnode->item=element;
if(count==0){
head=tail=newnode;
newnode->next=newnode->prev=NULL;
}else{
newnode->prev=tail;
newnode->next=NULL;
tail->next=newnode;
tail=newnode;
}
count++;
}
void insertionatpostion(int pos,t element){
if(pos<0||pos>count){
cout<<"Out Of Range...!";
} 
else if(pos==0){
insertionathead(element);
}else if(pos==count){
insertionattail(element);
}else{
    node *newnode=new node;
    newnode->item=element;
    node *curr=head;
    for(int i=1;i<pos;i++){
    curr=curr->next;
    }
    newnode->next=curr->next;
    newnode->prev=curr;
    curr->next=newnode;
    curr->next->prev=newnode;
}
count++;
}
void removalathead(){
if(count==0){
cout<<"Doublylinkedlist is empty...!";
}else if(count==1){
    free(head);
    head=tail=NULL;
}else{
    node *curr=head;
    head=head->next;
    head->prev=NULL;
    free(curr);
}
count--;
}
void removalattail(){
if(count==0){
cout<<"Doublylinkedlist is empty...!";
}else if(count==1){
delete head;
tail=head=NULL;
}else{
    node *curr=tail;
    tail=tail->prev;
    tail->next=NULL;
    delete curr;
}
count--;
}
void removeatpostion(t element){
if(count==0){
cout<<"Doublylinked is empty...!";
}else if(head->item==element){
removalathead();
}else{
node *curr=head->next;
while(curr!=NULL&&curr->item!=element){
    curr=curr->next;
}
if(curr->next==NULL){
removalattail();
}
curr->prev->next=curr->next;
curr->next->prev=curr->prev;
delete curr;
}
count--;
}
void display(){
cout<<"the elements are : ";
node *curr=head;
while(curr!=NULL){
cout<<curr->item<<" ";
curr=curr->next;
}
cout<<endl;
}
void displayreverse(){
cout<<"the elementreverse are : ";
node *curr=tail;
while(curr!=NULL){
    cout<<curr->item<<" ";
    curr=curr->prev;
}
cout<<endl;
}
~Doublylinkedlist(){
node *temp;
while(head!=NULL){
temp=head;
head=head->next;
delete temp;
}
tail=NULL;
count=0;
}
};
int main(){
Doublylinkedlist<int>d;
d.insertionathead(9);
d.insertionatpostion(1,6);
d.insertionatpostion(2,0);
d.insertionattail(10);
d.insertionatpostion(3,5);
d.insertionatpostion(4,13);
d.display();
d.displayreverse();
}