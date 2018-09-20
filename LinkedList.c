//Linked List in C
#include <stdio.h>
#include <stdlib.h>
//Creating a node structure
struct Node{
 int data;
 struct Node* next;
};

int main()
{
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    //Creating linked List
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

    insertAfter(second->next,8);
    printList(head);
    return 0;
}
void printList(struct Node* n){
  while(n!=NULL){
    printf("%d",n->data);
    n=n->next;
  }
}
void insertAfter(struct Node* prev_node,int new_data){
 //Check if previous node is null
 if(prev_node == NULL){
    printf("Can't be null");
 }
 struct Node* new_node = NULL;
 //allocate new node
 new_node = (struct Node*)malloc(sizeof(struct Node));
 //Put in the data
 new_node->data = new_data;
 //Make the new node as next of prev_node
 new_node->next = prev_node->next;
 //Move the next of prev_node to new_node
 prev_node->next = new_node;
 }
