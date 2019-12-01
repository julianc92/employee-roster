#pragma once
#ifndef NETWORKEMPLOYEE_H
#define NETWORKEMPLOYEE_H

#include <iostream>
#include <string>
#include "Employee.h"

class NetworkEmployee : public Employee {
public:
	NetworkEmployee();
	NetworkEmployee(string, string, string, string, int, int*, Department);

	Department GetDepartment() override;
	void print() override;

private:
	Department department;
};

#endif
