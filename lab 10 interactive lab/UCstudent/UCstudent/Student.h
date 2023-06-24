#ifndef __Student_H
#define __Student_H

#include <string>
#include <iostream>

class Student {
public:
	Student(int mnumber,
		std::string firstname,
		std::string lastname,
		double gpa);
	
	void print();

	double getGPA() const;
	void setGPA(double newGPA);

private:
	int mMNumber;
	double mGpa;
	std::string mFirstname, mLastname;
};
#endif