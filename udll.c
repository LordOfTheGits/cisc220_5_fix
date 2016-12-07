# include <stdlib.h>
# include "udll.h"

typedef struct Node Node;

Node *head = NULL; //initialize pointer to the head node
Node *last = NULL; //initialize pointer to the last node

void insert(int position, union Data data) { //instert function
   Node *ptr = head; 
   Node *newNode = (Node*) malloc(sizeof(Node));

   if (position == 0){
      newNode->data = data;
      
      if(head == NULL) {
         newNode->length = 1;
         last = newNode;
      } else {
         newNode->length = head->length + 1;
         head->length = 1;
         head->prev = newNode;
      }
      newNode->next = head;
      head = newNode;
      return;
   }
   
   if(head == NULL) {
      return;
   }

   int a;
   for(a=0; a < position - 1; a=a+1 ){
   
      if(ptr == NULL) {
         return;
      } else {           
         ptr = ptr->next;
      }
   }
   newNode->data = data;

   if(ptr->next == NULL) {
      newNode->next = NULL; 
      last = newNode; 
   } else {
      newNode->next = ptr->next;         
      ptr->next->prev = newNode;
   }
   
   head->length = head->length+1;
   newNode->prev = ptr; 
   ptr->next = newNode; 
}

int length(){ //return the length value stored in the head node
   return head->length;
}

void removeNode(int index) {
   int i = 0;
   Node *ptr = head;
   Node *ptr2 = NULL;

   if (index == 0){
      head->next->length = head->length;
      head = head->next;
      head->prev = NULL;
   }
	
   else if (index == 1){
       head->next = head->next->next;
       head->next->prev = head;
   }
	
   else if (index == (length()-1)){
      last = last->prev;
      last->next = NULL;
   }

   else {
      while((i < index - 1) && (ptr->next != NULL)){
         ptr = ptr->next;
         i++;
      }
      ptr2 = ptr->next;
      ptr->next = ptr2->next;
      ptr2 = ptr->prev;
      ptr->prev = ptr2->prev;
   } 
   
   head -> length = head -> length - 1;
}

union Data get (int index)
{
   //finds length to see if it should traverse through the list forawds or backwards
   int len = length();
   int half = len/2;
   
   //if the index is in the first half, go through forwards
   if (index < half)
   {
      Node *ptr = head;
      for (int x = 0; x < index; x++)
      {
         ptr = ptr->next; //snce first node is actually the length, go to next one
      }

      return ptr->data;
   }

   //else, go through backwards
   else
   {
      Node *ptrr = last;

      for (int y = len; y > index; y--)
      {
         ptrr = ptrr->prev;  //**
      }
      ptrr = ptrr->next; //**the last node is actually the last node so this will go
                         //one too many previously
      return ptrr->data;
   }

}
