#include <iostream>
#include <string>
#include "NetworkEmployee.h"
using namespace std;

//	Constructors 
NetworkEmployee::NetworkEmployee() {
}

NetworkEmployee::NetworkEmployee(string id, string fname, string lname, string email,
	int age, int daysRem[3], Department deg) : Employee(id,
		fname, lname, email, age, daysRem) {
	this->department = deg;
}

//	Getter
Department NetworkEmployee::GetDepartment() {
	return department;
}

//	Prints all stored information relevant to this employee
void NetworkEmployee::print() {
	cout << "Employee ID     : " << GetEmployeeId() << "\n"
		 << "First Name      : " << GetFirstName() << "\n"
		 << "Last Name       : " << GetLastName() << "\n"
		 << "Email address   : " << GetEmail() << "\n"
		 << "Employee's Age  : " << GetAge() << "\n"
		 << "Days Remaining  : " << GetDaysRemaining()[0] << ", " << GetDaysRemaining()[1]
		 << ", " << GetDaysRemaining()[2] << "\n"
		 << "Department      : " << "Network" << "\n" << endl;
}