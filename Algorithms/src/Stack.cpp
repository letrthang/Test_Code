/*
 * ============================================================================
 * Name        : Stack.cpp
 * Author      : Thang Le
 * Version     : Mar, 2015
 * Copyright   : www.letrungthang.blogspot.com
 * Description : Stack implementation
 * ============================================================================
*/

#include <iostream>
#include <cstdlib>
#define MAX_SIZE	5

enum
{
	RET_OK,
	RET_STACK_EMPTY,
	RET_STACK_FULL
};

using namespace std;

class Stack
{
private:
	int item[MAX_SIZE];
	int top ;
public:
	Stack();
	int push(int data);
	int pop(int *n);
	int size();
	void clear();
private:
	bool isEmpty();
	bool isFull();
};

Stack::Stack()
{
	top   = -1;
}

int Stack::push(int data)
{
	int ret = RET_STACK_FULL;

	if(isFull() == false)
	{
		item[++top] = data;
		ret =  RET_OK;
	}

	return ret;

}

int Stack::pop(int *n)
{
	int ret = RET_STACK_EMPTY;

	if(isEmpty() == false)
	{
		*n = item[top--];
		ret =  RET_OK;
	}

	return ret;
}

int Stack::size()
{
	return top +1;
}

bool Stack::isEmpty()
{
	bool ret = false;

	if(size() == 0)
	{
		ret = true;
	}

	return ret;
}


bool Stack::isFull()
{
	bool ret = false;

	if(size() == MAX_SIZE)
	{
		ret = true;
	}

	return ret ;
}

int main_stack()
{
	int arr[5] = {1,2,3,4,5};
	Stack myStack ;
	int n = 0;

	cout << "Push stack \n" ;
	for(int i=0; i< 5; i++)
	{
		myStack.push(arr[i]);
		cout << "size= " << myStack.size() << " ";
	}

	cout << "\npop stack \n" ;
	for(int i=0; i< 5; i++)
	{
		myStack.pop(&n);
		cout << n << " ";
	}

}
