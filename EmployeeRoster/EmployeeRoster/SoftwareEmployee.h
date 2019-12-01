#pragma once
#ifndef SOFTWAREEMPLOYEE_H
#define SOFTWAREEMPLOYEE_H

#include <iostream>
#include <string>
#include "Employee.h"

class SoftwareEmployee : public Employee {
public:
	SoftwareEmployee();
	SoftwareEmployee(string, string, string, string, int, int*, Department);

	Department GetDepartment() override;
	void print() override;

private:
	Department department;
};

#endif
