
#include <iostream>
#include <string>
#include <iomanip>
/**
 * @brief Truncate a string to a certain length.
 *
 * @param value The string to truncate.
 * @param width The length to which to truncate \p value.
 * @return std::string The truncated string.
 */
std::string truncate_string(const std::string &value, int width) {
  return value.substr(0, width);
}
/**
 * @brief Get an integer from the user
 *
 * @return int The user's input, as an integer.
 */
int get_int() {
	int value{ 0 };
	std::cin >> value;
	return value;
}
/**
 * @brief Get a string from the user.
 *
 * @return std::string The user's input, as a string.
 */
std::string get_string() {
  std::string value{""};
  std::getline(std::cin, value);
  return value;
}

/**
 * this peice of code takes user inputs for specified items
 * and turns it into the tax that will be applied to the total
 * earned  revenue for the <enter name here> power company
 * as wel as the taxable earning per outstanding share
 */
int main() {
	std::cout << "Enter company name: ";
	std::string name{ "" };
	name = get_string();
	std::cout << "Enter the total energy generation (in kwH): ";
	int total{ 0 };
	total = get_int();
	std::cout << "Enter solar generation (in kwH): ";
	int SG{ 0 };
	SG =  get_int();
	std::cout << "Enter wind generation (in kwH): ";
	int WG{ 0 };
	WG = get_int();
	std::cout << "Enter hydro generation (in kwH): ";
	int HG{ 0 };
	HG = get_int();
	std::cout << "Enter shares outstanding: ";
	int SO{ 0 };
	SO = get_int();
	std::cout << "Earnings Per Share Report Generator\n";
	double tte = ((total * 0.0292) - ((SG * 0.018) + (WG * 0.018) + (HG * 0.018)));
	double teps = (tte / SO);
	std::cout << std::setw(80) << std::setfill('=') << "" << '\n' << std::setfill(' ');
	std::cout << std::setw(40) << std::left << "Prepared For:" << std::setw(40) << std::right << truncate_string(name, 40) << '\n';
	std::cout << std::setw(40) << std::left << "Taxable Total Earnings:" << std::setw(40) << std::right << std::setprecision(2) << std::fixed << tte << '\n';
	std::cout << std::setw(40) << std::left << "Taxable Earnings Per Share:" << std::setw(40) << std::right << std::setprecision(2) << std::fixed << teps << '\n';
	std::cout << std::setw(80) << std::setfill('=') << "" << '\n' << std::setfill(' ');
	return 0;
}
