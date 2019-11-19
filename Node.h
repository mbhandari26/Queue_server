#pragma once
//*****************************************************************************************************
//
//		File:			    Node.h
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

#ifndef  NODE_H
#define  NODE_H

//*****************************************************************************************************

template<typename TYPE>
struct Node
{
	TYPE data;
	Node<TYPE> * next;

	Node();
	Node(const TYPE & d, Node<TYPE> * n = nullptr);
};

//*****************************************************************************************************

template<typename TYPE>
Node<TYPE>::Node()
{
	data = 0;
	next = nullptr;
}

//*****************************************************************************************************

template<typename TYPE>
Node<TYPE>::Node(const TYPE & d, Node<TYPE> * n)
{
	data = d;
	next = n;
}

//*****************************************************************************************************

#endif

#pragma once
