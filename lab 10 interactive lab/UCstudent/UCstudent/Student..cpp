#include "Student.h"

#include <iostream>
#include <string>

Student::Student(
	int mnumber,
	std::string firstname,
	std::string lastname,
	double gpa) {
	mMNumber = mnumber;
	mFirstname = firstname;
	mLastname = lastname;
	mGpa = 0;
	if (gpa >= 0 && gpa <= 4.0) {
		mGpa = gpa;
	}
}

double Student::getGPA() const{
	return mGpa;
}

void Student::setGPA(double newGpa) {
	if (newGpa >= 0 && newGpa <= 4.0) {
		mGpa = newGpa;
	}
}

void Student::print() {
	std::cout << "M #" << mMNumber << "\n";
	std::cout << "Name: " << mFirstname << " " << mLastname << "\n";
	std::cout << "GPA: " << mGpa << "\n";
}