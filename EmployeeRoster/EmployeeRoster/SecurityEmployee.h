#pragma once
#ifndef SECURITYEMPLOYEE_H
#define SECURITYEMPLOYEE_H

#include <iostream>
#include <string>
#include "Employee.h"

class SecurityEmployee : public Employee {
public:
	SecurityEmployee();
	SecurityEmployee(string, string, string, string, int, int*, Department);

	Department GetDepartment() override;
	void print() override;

private:
	Department department;
};

#endif
