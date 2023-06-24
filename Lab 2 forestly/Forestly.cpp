#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	auto CarbonEmmissionYear1 = 0, CarbonEmmissionYear2 = 0, Year1 = 0, Year2 = 0, Year1Total = 0, Year2Total = 0;
	double CarbonDifference;
	std::cout << "Enter the first year: ";
	std::cin >> Year1;
	std::cout << "Enter the acres consumed by forest fire that year: ";
	std::cin >> CarbonEmmissionYear1;
	std::cout << "Enter the second year: ";
	std::cin >> Year2;
	std::cout << "Enter the acres consumed by forest fire that year: ";
	std::cin >> CarbonEmmissionYear2;
	Year1Total = CarbonEmmissionYear1 * 26.7;
	Year2Total = CarbonEmmissionYear2 * 26.7;
	CarbonDifference = (((static_cast<double>(Year2Total) / static_cast<double>(Year1Total)) - 1) * 100);
	std::cout << "In year " << Year1 << ", forest fires generated " << Year1Total << " tons of carbon dioxide." << endl;
	std::cout << "In year " << Year2 << ", forest fires generated " << Year2Total << " tons of carbon dioxide." << endl;
	std::cout << "Between " << Year1 << " and " << Year2 << ", there was a " << CarbonDifference << "% increase in acres consumed by forest fires." << endl;
	return 0;
}