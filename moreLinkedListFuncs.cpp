#include <cassert>
#include "linkedList.h"
#include "linkedListFuncs.h"

Node * pointerToMax(LinkedList *list) {

  assert(list!=NULL);
  assert(list->head != NULL);

  Node *p=list->head; //declare a new pointer p to iterate the list
  int maxValue=p->data; //declare max value to the first data
  Node *max=list->head; //declare a new pointer max to point to the node with max value
  while(p){ //iterate through the list
      if(p->data>maxValue){ 
          max=p;    //set pointer max point to the new node with max value
      }
      p=p->next;
  }
  return max; 
}

Node * pointerToMin(LinkedList *list) {


  assert(list!=NULL);
  assert(list->head != NULL);

  Node *p=list->head; //declare a new pointer p to iterate the list
  int minValue=p->data; //declare min value to the first data
  Node *min=list->head; //declare a new pointer min to point to the node with min value
  while(p){ //iterate through the list
      if((p->data)<minValue){ 
          min=p;    //set pointer min point to the new node with min value
      }
      p=p->next;
  }
  return min;
}

int largestValue(LinkedList *list) {

  assert(list!=NULL);
  assert(list->head != NULL);

  Node *p=list->head; //declare a new pointer p to iterate the list
  int maxValue=p->data; //declare max value to the first data
  while(p){ //iterate through the list
      if((p->data)>maxValue){ 
          maxValue=p->data;    //set max value to the new max value
      }
      p=p->next;
  }
  return maxValue; 
}

int smallestValue(LinkedList *list) {
 
  assert(list!=NULL);
  assert(list->head != NULL);

  Node *p=list->head; //declare a new pointer p to iterate the list
  int minValue=p->data; //declare min value to the first data
  while(p){ //iterate through the list
      if((p->data)<minValue){ 
          minValue=p->data;    //set min value to the new min value
      }
      p=p->next;
  }
  return minValue; 
}

int sum(LinkedList * list) {

  assert(list!=NULL);

  int sum=0; //declare and initialize the sum to 0
  Node *p=list->head; //declare a new pointer p to iterate the list
  if(list->head==NULL){ //empty list
      return sum;
  }else if(list->head->next==NULL){  //one node situation
      return list->head->data;
  }else{
      while(p){
          sum=sum+p->data;
          p=p->next;
      }
  }
  return sum;
}


void deleteNodeInteratively(LinkedList* list, int value){
    if(list->head==NULL){   //empty list
        return;
    }else if(list->head == list->tail){    //one node
        if(list->head->data == value){
            delete list->head;
        }
        return;
    }else{          //more than one node
        Node *next = NULL;
        Node *curr = NULL;
        Node *prev = NULL;
        while(list->head->data ==value){  //when the head of the list has data equal to value
            next=list->head->next;
            delete list->head;
            list->head =next;
        }

        prev=list->head;        //  when a node in the middle has its data equal to value
        curr=list->head->next;
        while(curr->next){
            if(curr->data == value){
                curr=curr->next;
                delete prev->next;
                prev->next=curr;
            }else{
                curr=curr->next;
                prev=prev->next;
            }
        }

        if(curr->data == value){     //when the tail of the list has data equal to value
            delete curr;
            list->tail = prev;
        }
    }
}




void deleteNodeRecursively(LinkedList* list, int value){     
    return;

}

Node* deleteNodeHelper (Node* head, int value){
    if(head==NULL){
        return head;
    }
    Node *p = head;
    Node *q = head->next;
    if(p->data == value){
        delete p;
        head=q;
        p=q;
        q=q->next;
    }
    deleteNodeHelper (head->next, value);
}

void insertNodeToSortedList(LinkedList* list, int value){
    Node *newNode = new Node;  //declare a new Node object
    newNode->data= value;  //assign the data to value
    newNode->next= NULL;

    if(list->head ==NULL){      //empty list
        list->head=newNode;
        list->tail=newNode;
        return;
    }else if(list->head == list->tail){     //one node
        if(list->head->data > value){
            newNode->next=list->head;
            list->head=newNode;
        }else{
            list->head->next=newNode;
            list->tail=newNode;
        }
        return;
    }else{
        if(list->head->data > value){    //when value is less than data in the first node
            newNode->next=list->head;
            list->head=newNode;
            return;
        }

        Node* curr=list->head->next;    //when value should be placed to a position inside of the list
        Node* prev=list->head;
        while(curr){
            if(curr->data > value){
                newNode->next=curr;
                prev->next=newNode;
                return;
            }
            curr=curr->next;
            prev=prev->next;
        }

        prev->next=newNode;     //when value is greater than data in the last node
        newNode->next=NULL;
        list->tail=newNode;
        return;
    }
}



