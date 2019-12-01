#include <string>
#include "Employee.h"

// Constructors
Employee::Employee() {
}

Employee::Employee(string id, string fname, string lname, string email,
	int age, int daysRem[3]) {
	employeeId = id;
	firstName = fname;
	lastName = lname;
	this->email = email;
	this->age = age;
	SetDaysRemaining(daysRem);
}

// Setters
void Employee::SetEmployeeId(string id) {
	employeeId = id;
	return;
}

void Employee::SetFirstName(string name) {
	firstName = name;
	return;
}

void Employee::SetLastName(string name) {
	lastName = name;
	return;
}

void Employee::SetEmail(string employeeEmail) {
	email = employeeEmail;
	return;
}

void Employee::SetAge(int employeeAge) {
	age = employeeAge;
	return;
}

void Employee::SetDaysRemaining(int daysRem[3]) {
	for (int i = 0; i < 3; i++) {
		numDays[i] = daysRem[i];
	}
}

// Getters
string Employee::GetEmployeeId() const {
	return string(employeeId);
}

string Employee::GetFirstName() const {
	return string(firstName);
}

string Employee::GetLastName() const {
	return string(lastName);
}

string Employee::GetEmail() const {
	return string(email);
}

int Employee::GetAge() const {
	return age;
}

int* Employee::GetDaysRemaining() {
	return numDays;
}

Department Employee::GetDepartment() {
	return Department::NETWORK;
}

void Employee::print() {
}

// Deconstructor
Employee::~Employee() {
}


