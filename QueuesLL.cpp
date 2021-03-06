#include "pch.h"
#include <iostream>
#include<process.h>

struct Node {
	int info;
	Node *next;
}*front,*newptr,*save,*rear,*ptr;

Node *Create_New_Node(int);
void Insert(Node*);
void Display(Node*);
void DelNode_Q();
int main()
{
	front = rear = NULL; //In the beginning Queue is NULL
	int inf; char ch = 'y';
	while (ch == 'y' || ch == 'Y') {
		std::cout << "\nEnter Information for new node:";
		std::cin >> inf;
		newptr = Create_New_Node(inf);
		if (newptr == NULL) {
			std::cout << "\nCannot create new node!!\n"; exit(1);
		}
		Insert(newptr);
		std::cout << "\nPress Y to enter more nodes,N to exit...\n";
		std::cin >> ch;
	}
	system("cls");
 
	do {
		std::cout << "\nThe Linked Queue now is(Front...to...Rear):\n";
		Display(front);
		std::cout << "Want to delete first node?(Y/N)";
		std::cin >> ch;
		if (ch == 'y' || ch == 'Y')
			DelNode_Q();
	} while (ch == 'y' || ch == 'Y');
	return 0;
}

//Function to create new node dynamically
Node *Create_New_Node(int n) {
	ptr = new Node;
	ptr->info = n;
	ptr->next = NULL; return ptr;
}
void Insert(Node *np) {
	if (front == NULL) {
		front = rear = np;
	}
	else {
		rear->next = np;
		rear = np;
	}
}
void DelNode_Q() {
	if (front == NULL) {
		std::cout << "Underflow!!\n";
	}
	else {
		ptr = front;
		front = front->next;
		delete ptr;
	}
}
void Display(Node *np) {
	while (np != NULL) {
		std::cout << np->info << "->";
		np = np->next;
	}
	std::cout << "!!!\n";
}