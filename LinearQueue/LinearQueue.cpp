#include<iostream>
using namespace std;

#define MAX 8
int rear = -1;
int front = -1;
int queue[MAX];

void enqueue(int x)
{
	if (rear == MAX - 1)
	{
		cout << "Queue is Full" << endl;
		return;
	}
	if (front == -1)
		front = 0;
	rear++;
	queue[rear] = x;
	return;
}

int dequeue()
{
	int x;

	if (front == -1 && rear == -1)
	{
		cout << "Queue is empty" << endl;
		return -1;
	}
	x = queue[front];
	if (front == rear)
		front = rear = -1;
	else
		front++;
	return x;
}

void display()
{
	int i;
	if (front == -1)
	{
		cout << "Queue is empty" << endl;
		return;
	}
	cout << "Element of the queue is: " << endl;
	if (front <= rear)
		for (i = front; i <= rear; i++)
			cout << queue[i] << endl;
	return ;
}

int main()
{
	int value,choice;
	do
	{
		cout << "Enter 1.Enqueue 2.Dequeue 3.Display 4.Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:cout << "Enter the value in Enqueue " << endl;
			cin >> value;
			enqueue(value);
			break;
		case 2:value = dequeue();
			cout << "The value is deleted: " <<value<< endl;
			break;
		case 3:display();
			break;
		default:cout << "Exiting" << endl;
			choice = 4;
		}
	} while (choice != 4);
}