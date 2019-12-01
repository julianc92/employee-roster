#pragma once
#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include <string>
#include "Employee.h"

class Roster {
public:
	Roster();
	~Roster();

	void add(string employeeID, string firstName, string lastName, string emailAddress,
		int age, int daysInProject1, int daysInProject2, int daysInProject3,
		Department department);
	void remove(string employeeID);
	void printAll();
	void printDaysInProject(string employeeID);
	void printInvalidEmails();
	void printByDepartment(int department);

private:
	Employee* employeeRosterArray[5];
};

#endif
