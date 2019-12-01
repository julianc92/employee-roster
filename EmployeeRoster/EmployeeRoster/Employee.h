#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include "Department.h"
using namespace std;

class Employee {
public:
	Employee();
	Employee(string, string, string, string, int, int*);
	~Employee();

	void SetEmployeeId(string id);
	void SetFirstName(string name);
	void SetLastName(string name);
	void SetEmail(string employeeEmail);
	void SetAge(int employeeAge);
	void SetDaysRemaining(int daysRem[3]);

	string GetEmployeeId() const;
	string GetFirstName() const;
	string GetLastName() const;
	string GetEmail() const;
	int GetAge() const;
	int* GetDaysRemaining();
	virtual Department GetDepartment();
	virtual void print();

private:
	string employeeId;
	string firstName;
	string lastName;
	string email;
	int age;
	int numDays[3];
};

#endif


