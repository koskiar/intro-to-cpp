#include <iostream>
#include "Student.h"
#include "Class.h"\

int main() {
	Student will{ 1239, "will", "Hawkins", 3.6 };

	will.print();
	will.setGPA(4.5);
	double willsGpa = will.getGPA();
	std::cout << "willsGpa: " << willsGpa << "\n";
	return 0;
}