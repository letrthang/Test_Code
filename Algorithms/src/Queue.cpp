/*
 * ============================================================================
 * Name        : Queue.cpp
 * Author      : Thang Le
 * Version     : Mar, 2015
 * Copyright   : www.letrungthang.blogspot.com
 * Description : Queue implementation
 * ============================================================================
*/

#include <iostream>
#include <cstdlib>
#define MAX_SIZE	5

enum
{
	RET_OK,
	RET_QUEUE_EMPTY,
	RET_QUEUE_FULL
};

using namespace std;

class Queue
{
private:
	int item[MAX_SIZE];
	int head;
	int tail;
	int qSize;
public:
	Queue();
	int enqueue(int data);
	int dequeue(int *n);
	int size();
	void clear();
private:
	bool isEmpty();
	bool isFull();
};

Queue::Queue()
{
	head = 0;
	tail = 0;
	qSize = 0;
};

int Queue::enqueue(int data)
{
	int ret = RET_QUEUE_FULL;

	if(isFull() == false)
	{
		item[tail] = data;
		tail = (tail + 1)%MAX_SIZE;
		qSize ++;

		ret = RET_OK;
	}
	return ret;
}

int Queue::dequeue(int *n)
{
	int ret = RET_QUEUE_EMPTY;

	if(isEmpty() == false)
	{
		*n = item[head];
		head = (head+1)%MAX_SIZE;
		qSize --;

		ret = RET_OK;
	}

	return ret;
}

void Queue::clear()
{
	head = 0;
	tail = 0;
	qSize = 0;
}

int Queue::size()
{
	return qSize;
}

bool Queue::isEmpty()
{
	bool ret = false;

	if(size() == 0)
	{
		ret = true;
	}

	return ret;
}

bool Queue::isFull()
{
	bool ret = false;

	if(size() == MAX_SIZE)
	{
		ret = true;
	}

	return ret ;
}


int main_queue()
{
	int arr[5] = {1,2,3,4,5};
	Queue myQueue ;
	int n = 0;

	cout << "enqueue \n" ;
	for(int i=0; i< 5; i++)
	{
		myQueue.enqueue(arr[i]);
		cout << "size= " << myQueue.size() << " ";
	}

	cout << "\ndequeue \n" ;
	for(int i=0; i< 5; i++)
	{
		cout << "size= " << myQueue.size() << " ";
		myQueue.dequeue(&n);

	}
}
