//*****************************************************************************************************
//
//		File:			    sim3q3s.cpp
//		
//		Student:			Manish Bhandari
//
//		Assignment:	 	    Program  #14
//
//		Course Name:		Data Structures I  
//
//		Course Number:		COSC 3050 - 01
//
//		Due:			    May 03, 2019 
//
//      This program determines how long it takes to serve all arriving customers
//		using three queue and three servers.
//
//*****************************************************************************************************

#include<iostream>
#include<fstream>
using namespace std;

#include"Queue.h"
#include"Customer.h"
#include"Server.h"

//*****************************************************************************************************

int fillCustomerArray(Customer custArray[]);
int findMinQ(Queue<Customer> qArray[], Server serverArray[]);
void processCustomers(Customer custArray[], Queue<Customer> qArray[], int time, 
					  Server serverArray[], ofstream & outfile, int & currCust);
void processServer(Server serverArray[], Customer custArray[], int  currCust,
	               int time, ofstream & outfile, Queue<Customer> qArray[]);
bool isAlldone(Server serverArray[], Queue<Customer> qArray[], int currCust,
	           int totalCustomers);

//*****************************************************************************************************

int main()
{
	int totalCustomers;
	int currCust = 0;
	int time = 0;
	Customer custArray[500];
	Server serverArray[3];
	Queue <Customer>  qArray[3];
	ofstream outfile("trace.txt");

	totalCustomers = fillCustomerArray(custArray);

	while (!isAlldone(serverArray, qArray, currCust, totalCustomers))
	{
		processCustomers(custArray, qArray, time, serverArray, outfile, currCust);
		processServer(serverArray, custArray, currCust, time, outfile, qArray);
		time++;
	}

	cout << "All customers processed in " << time - 1 << " minutes.";

	return 0;

}

//*****************************************************************************************************

int fillCustomerArray(Customer custArray[])
{
	Customer customer;
	int count = 0;
	ifstream infile;

	infile.open("customerList.txt");

	while (infile >> customer.id)
	{
		infile >> customer.arrivalTime;
		infile >> customer.serviceTime;
		custArray[count] = customer;
		count++;
	}

	infile.close();

	return count;
}

//*****************************************************************************************************

int findMinQ(Queue<Customer> qArray[], Server serverArray[])
{
	int size[3];

	size[0] = qArray[0].getNumValues();
	size[1] = qArray[1].getNumValues();
	size[2] = qArray[2].getNumValues();

	if (serverArray[0].busy)
		size[0]++;

	if (serverArray[1].busy)
		size[1]++;

	if (serverArray[2].busy)
		size[2]++;

	int bestQ = 0;

	if (size[1] < size[0])
		bestQ = 1;

	if (size[2]< size[bestQ])
		bestQ = 2;

	return bestQ;
}

//*****************************************************************************************************

void processCustomers(Customer custArray[], Queue<Customer> qArray[], int time, 
					  Server serverArray[], ofstream & outfile, int & currCust)
{
	int minQ;
	outfile << endl << "t = " << time << endl;

	
	while (custArray[currCust].arrivalTime == time)
	{
		minQ = findMinQ(qArray, serverArray);
		qArray[minQ].enqueue(custArray[currCust]);
		outfile << "cust #" << custArray[currCust].id << " added to Q"
				<< minQ << endl;
		currCust++;
	}
}

//*****************************************************************************************************

void processServer(Server serverArray[], Customer custArray[], int currCust, 
				   int time, ofstream & outfile, Queue<Customer> qArray[])
{
	Customer customer;

	for (int i = 0; i < 3; i++)
	{
		if (serverArray[i].endTime <= time)
			serverArray[i].busy = false;

		if ((!serverArray[i].busy) || (serverArray[i].endTime <= time))
		{
			if (qArray[i].dequeue(customer))
			{
				serverArray[i].custId = customer.id;
				serverArray[i].endTime = customer.serviceTime + time;
				serverArray[i].busy = true;

				outfile << "S" << i << " start serving cust#"
						<< customer.id << ", service length = "
						<< customer.serviceTime << ", service ends at t = "
						<< serverArray[i].endTime << endl;
			}
			else
				outfile << "S" << i << " not busy" << endl;
		}
		else
			outfile << "S" << i << " serving cust#" << serverArray[i].custId
					<< " until t = " << serverArray[i].endTime << endl;
	}
}

//*****************************************************************************************************

bool isAlldone(Server serverArray[], Queue<Customer> qArray[], int currCust, int totalCustomers)
{
	return((!serverArray[0].busy) && (!serverArray[1].busy) &&
		   (!serverArray[2].busy) && (qArray[0].isEmpty()) &&
		   (qArray[1].isEmpty()) && (qArray[2].isEmpty()) &&
		   (currCust == totalCustomers));
}

//*****************************************************************************************************

/*
All customers processed in 85 minutes.
*/