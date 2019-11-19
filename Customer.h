#pragma once
#ifndef  CUSTOMER_H
#define  CUSTOMER_H

struct Customer
{

	Customer();
	int id;
	int arrivalTime;
	int serviceTime;
};

Customer::Customer()
{
	id = 0;
	arrivalTime = 0;
	serviceTime = 0;
}

#endif // ! CUSTOMER_H
#pragma once
