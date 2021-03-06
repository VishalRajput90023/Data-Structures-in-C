#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <process.h>
using namespace std;
//Function Prototypes
int Remove(int[]);
int Insert(int[], int);
void Display(int[], int, int);
const int sizeQ = 50;
int Queue[50], front = -1, rear = -1;
int main()
{
	int item, res; char ch = 'y';
	while (ch == 'y' || ch == 'Y') {
		cout << "\n Enter item for insertion:";
		cin >> item;
		res = Insert(Queue, item);
		if (res == -1) {
			cout << "Overflow!!\n"; exit(1);
		}
		cout << "\nNow the queue(Front...to...rear) is: \n";
		Display(Queue, front, rear);
		cout << "\nWant to insert more elements?(Y/N)...";
		cin >> ch;
	}
	cout << "Now Deletion of elements begins...\n";
	ch = 'y';
	while (ch == 'y'||ch == 'Y')
	{
		res = Remove(Queue);
		if (res == -1) {
			cout << "Underflow!!\n"; exit(1);
		}
		else {
			cout << "\nElement to be deleted is:" << res << endl;
			cout << "Now the queue is:\n";
			Display(Queue, front, rear);
		}
		cout << "Want to delete more elements?(Y/N)..."; cin >> ch;
	}
	return 0;
}
int Insert(int Queue[] , int ele) {
	if (rear == sizeQ - 1) return -1;
	else if(rear == -1){
		front = rear = 0;
		Queue[rear] = ele;
	}
	else {
		rear++;
		Queue[rear] = ele;
	}
	return 0;
}

int Remove(int Queue[]) {
	int ret;
	if (front == -1) {
		return -1;
	}
	else {
		ret = Queue[front];
		if (front == rear) front = rear = -1;
		else front++;
	}
	return ret;
}

void Display(int Queue[], int front, int rear) {
	if (front == -1) return;
	for (int i = front; i < rear; i++) {
		cout << Queue[i] << "<-\t";
	}
	cout << Queue[rear] << endl;
}