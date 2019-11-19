//*****************************************************************************************************
//
//		File:			    Queue.h
//		
//		Student:			Manish Bhandari
//
//		Assignment:	 	    Program  # 11
//
//		Course Name:		Data Structures I  
//
//		Course Number:		COSC 3050 - 01
//
//		Due:			    April 09, 2019 
//
//      This program uses builds and tests a templated linked list queue.
//     
//
//*****************************************************************************************************

#ifndef  QUEUE_H
#define  QUEUE_H

//*****************************************************************************************************

#include<new>
#include"Node.h"

//*****************************************************************************************************

template<typename TYPE>
class Queue
{
private:
	Node<TYPE> * front;
	Node<TYPE> * rear;
	int numValues;
public:
	Queue();
	~Queue();
	bool enqueue(const TYPE & dataIn);
	bool dequeue(TYPE & dataOut);
	bool viewFront(TYPE & dataOut) const;
	bool viewRear(TYPE & dataOut) const;
	int getNumValues() const;
	bool isFull() const;
	bool isEmpty() const;
};

//*****************************************************************************************************

template<typename TYPE>
Queue<TYPE>::Queue()
{
	front = nullptr;
	rear = nullptr;
	numValues = 0;
}

//*****************************************************************************************************

template<typename TYPE>
Queue<TYPE>::~Queue()
{
	Node<TYPE> * pDelete;

	while (front)
	{
		pDelete = front;
		front = front->next;
		delete pDelete;
	}

	rear = nullptr;
	numValues = 0;
}

//*****************************************************************************************************

template<typename TYPE>
bool Queue<TYPE>::enqueue(const TYPE & dataIn)
{
	bool success = false;
	Node<TYPE> * pNew;

	pNew = new (nothrow) Node<TYPE>(dataIn);

	if (pNew)
	{
		if (rear)
			rear->next = pNew;
		else
			front = pNew;
		rear = pNew;
		numValues++;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool Queue<TYPE>::dequeue(TYPE & dataOut)
{
	bool success = false;
	Node<TYPE> * pDelete = front;

	if (front)
	{
		dataOut = front->data;
		front = front->next;
		delete pDelete;
		numValues--;
		success = true;

		if (!front)
			rear = nullptr;

	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool Queue<TYPE>::viewFront(TYPE & dataOut) const
{
	bool success = false;

	if (front)
	{
		dataOut = front->data;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool Queue<TYPE>::viewRear(TYPE & dataOut) const
{
	bool success = false;

	if (rear)
	{
		dataOut = rear->data;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
int Queue<TYPE>::getNumValues() const
{
	return numValues;
}

//*****************************************************************************************************

template<typename TYPE>
bool Queue<TYPE>::isEmpty() const
{
	return(front == nullptr);
}

//*****************************************************************************************************

template<typename TYPE>
bool Queue<TYPE>::isFull() const
{
	bool full = true;
	Node<TYPE> * pNew;

	pNew = new (nothrow) Node<TYPE>;

	if (pNew)
	{
		full = false;
		delete pNew;
	}

	return full;
}

//*****************************************************************************************************

#endif
#pragma once
#pragma once
