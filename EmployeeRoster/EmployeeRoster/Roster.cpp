#include <iostream>
#include <string>
#include "Roster.h"
#include "Department.h"
#include "Employee.h"
#include "SecurityEmployee.h"
#include "NetworkEmployee.h"
#include "SoftwareEmployee.h"
using namespace std;

//	Constructor
Roster::Roster() {
	for (int i = 0; i < 5; ++i) {
		employeeRosterArray[i] = 0;
	}
}

// FIXME: add bug fixes and possibly exception handling
//		  error invalid entry for wrong inputs
void Roster::add(string employeeID, string firstName, string lastName, string emailAddress,
	int age, int daysInProject1, int daysInProject2, int daysInProject3,
	Department department) {
	int i = 0;
	bool found = false;
	while ((i < 5) && (found == false)) {
		if (employeeRosterArray[i] == 0) {
			int days[3];
			days[0] = daysInProject1;
			days[1] = daysInProject2;
			days[2] = daysInProject3;

			if (department == Department::SECURITY) {
				employeeRosterArray[i] = new SecurityEmployee(employeeID, firstName, lastName,
					emailAddress, age, days, department);
			}
			else if (department == Department::NETWORK) {
				employeeRosterArray[i] = new NetworkEmployee(employeeID, firstName, lastName,
					emailAddress, age, days, department);
			}
			else if (department == Department::SOFTWARE) {
				employeeRosterArray[i] = new SoftwareEmployee(employeeID, firstName, lastName,
					emailAddress, age, days, department);
			}
			found = true;
		}
		++i;
	}
}

//	Searches the employee roster for specified employee id (string input),
//	and removes the employee if the specified id is found
void Roster::remove(string employeeID) {
	for (int i = 0; i < 5; ++i) {
		if ((employeeRosterArray[i] != 0) &&
			(employeeRosterArray[i]->GetEmployeeId().compare(employeeID) == 0)) {
			employeeRosterArray[i] = 0;
			return;
		}
	}
	cout << "Error: Employee ID \'" << employeeID << "\' not found" << endl;
}

//	Prints out all stored information for each employee in the roster
void Roster::printAll() {
	for (int i = 0; i < 5; ++i) {
		if (employeeRosterArray[i] != 0)
			employeeRosterArray[i]->print();
	}
}

//	Prints out the average days remaining in projects for each employee
//	in the roster.  Takes a string as input representing the employee's ID
void Roster::printDaysInProject(string employeeID) {
	for (int i = 0; i < 5; ++i) {
		if ((employeeRosterArray[i] != 0) &&
			(employeeRosterArray[i]->GetEmployeeId().compare(employeeID) == 0)) {
			int* daysRemaining = employeeRosterArray[i]->GetDaysRemaining();
			int averageDaysRemaining = (daysRemaining[0] + daysRemaining[1] + daysRemaining[2])
				/ 3;
			cout << "Average of Days Remaining in projects for Employee " << employeeID << ": "
				<< to_string(averageDaysRemaining) << endl;
			return;
		}
	}
	cout << "Error: Employee ID not found" << endl;
}

//	Searches the employee roster for invalid email addresses, and
//	prints out the ID's of employees with invalid email addresses
void Roster::printInvalidEmails() {
	bool foundInvalidEmail = false;
	string emailAddress;
	for (int i = 0; i < 5; ++i) {
		if (employeeRosterArray[i] == 0)
			continue;
		bool foundSpace = false;
		bool foundAtSign = false;
		bool foundPeriod = false;
		emailAddress = (*employeeRosterArray[i]).GetEmail();
		for (char& ch : emailAddress) {
			if (ch == ' ') {
				foundSpace = true;
			}
			else if (ch == '@') {
				foundAtSign = true;
			}
			else if (ch == '.') {
				foundPeriod = true;
			}
		}
		if ((foundSpace) || (!foundAtSign) || (!foundPeriod)) {
			cout << "Invalid email for employee "
				<< employeeRosterArray[i]->GetEmployeeId() << endl;
			foundInvalidEmail = true;
		}
	}
	if (!foundInvalidEmail) {
		cout << "All email addresses are valid" << endl << endl;
	}
	else {
		cout << endl;
	}
}

//	Prints information for each employee in the roster which shares
//	the specified department. Takes an int as input, however an enum
//	is used.  Input should be of the form 'DEPARTMENT::<department type>'
void Roster::printByDepartment(int department) {
	bool found = false;
	for (int i = 0; i < 5; ++i) {
		if (employeeRosterArray[i]->GetDepartment() == department) {
			employeeRosterArray[i]->print();
			found = true;
		}
	}
	if (!found)
		cout << "No employees found in department" << endl;
}

//	Deconstructor
Roster::~Roster() {
}


int main() {
	cout << "Julian Richards" << endl
		 << "Employee Roster Program, in C++" << endl << endl;


	Roster roster = Roster();

	roster.add("012345", "John", "Doe", "johnd1987@gm ail.com", 20, 30, 35, 40, Department::SECURITY);
	roster.add("649438", "Cathy", "Nguyen", "CatNguyen_1990@gmailcom", 19, 50, 30, 40, Department::NETWORK);
	roster.add("649332", "Guadalupe", "Curry", "the_lawyer99yahoo.com", 19, 20, 40, 33, Department::SOFTWARE);
	roster.add("648569", "Dan", "Mendoza", "dan.mendoza@comcast.net", 22, 50, 58, 40, Department::SECURITY);
	roster.add("649222", "Julian", "Peterson", "JPeterson@uw.edu", 27, 7, 6, 7, Department::SOFTWARE);

	roster.printAll();
	roster.printInvalidEmails();

	for (int i = 1; i < 6; ++i) {
		roster.printDaysInProject("A" + to_string(i));
	}
	cout << endl;

	roster.printByDepartment(Department::SOFTWARE);
	roster.remove("012345");
	roster.remove("012345");

	return 0;
}