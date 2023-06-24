#include <iomanip>
#include <iostream>

/*
 * car_model_year: Takes no parameters and prompts the user to enter
 * the model year of the car they are listing. The model year of the
 * car is returned as an integer (`int`).
 *
 * returns: the model year of the code as entered by the user (`int`).
 */
int car_model_year() {
    int model_year{ 0 };
    std::cout << "What is the model year of the car? ";
    std::cin >> model_year;
    return model_year;
}

/*
 * car_accidents: Takes no parameters and prompts the user to enter
 * the number of accidents the car has been in. The number of accidents
 * is returned as an integer (`int`).
 *
 * returns: the number of accidents as entered by the user (`int`).
 */
int car_accidents() {
    int accidents{ 0 };
    std::cout << "How many accidents has the car been in? ";
    std::cin >> accidents;
    return accidents;
}

/*
 * car_msrp: Takes no parameters and prompts the user to enter
 * the car's MSRP. The car's MSRP is returned as a floating-point
 * number (`double`).
 *
 * returns: the car's MSRP as entered by the user (`double`).
 */
double car_msrp() {
    double msrp{ 0.0 };
    std::cout << "How much did you pay for the car? ";
    std::cin >> msrp;
    return msrp;
}

/*
 * car_has_premium_options: Takes no parameters and prompts the user
 * to enter whether the car has premium options. The presence of premium
 * options on the car is return as a Boolean (`bool`).
 * Prompts the user to enter yes or no depending on whether the car has premium options;
 * Generates ("returns") true if the user entered yes; or
 * Generates false if the user entered no.
 * returns: whether the car has premium option as entered by the user (`bool`).
 */
bool car_has_premium_options() {
    // makes a string
    std::string has_options_string{ "" };
    // prints text to screen
    std::cout << "Does your car have premium options (yes/no)? ";
    // takes input ofr sting
    std::cin >> has_options_string;
    // if statement to return a bool value
    if (has_options_string == "yes") {
        // true
        return true;
    }
        // else in case the if falls through
    else {
        // false
        return false;
    }
}

/*
 * print_eligible_message: Takes a single parameter (the car's resale value
 * as a floating-point number [`double`]) and prints a nice message telling
 * the user their car is eligible for sale through dappreciation and its price.
 *
 * returns: nothing
 */
void print_eligible_message(double resale_price) {
    std::cout << std::fixed << std::setprecision(2)
        << "dappreciation will list your car for $" << resale_price
        << ".\n";
}

/*
 * print_ineligible_message: Takes no parameters and prints a nice message telling
 * the user their car is ineligible for sale through dappreciation.
 *
 * returns: nothing
 */
void print_ineligible_message() {
    std::cout << "Unfortunately your car is ineligible for the dappreciation "
        "platform.\n";
}
/*
 * Car Max has decided to use a new progame to calculate depreciation in their 
 * Modern day veichles of recent years. below is the outsorced code of a company that takes the cars
 * model year, Car accidents, its premium options if avalible, and its msrp.
 * using this calculator Car Max is giving customers their best price
 */
int main() {
    int CMY = (2022 - car_model_year()), CA = car_accidents();
    auto CHPO = car_has_premium_options();
    double CMSRP = car_msrp(), Percentage = 0;
    if (CMY <= 4) {
        Percentage = Percentage + .85;
    }
    else if (CMY >= 5 && CMY <= 8) {
        Percentage = Percentage + .63;
    }
    else if (CMY >= 9 && CMY <= 10) {
        Percentage = Percentage + .45;
    }
    else {
        Percentage = Percentage - 100;
    }
    if (CA == 0) {
        Percentage = Percentage - .0;
    }
    else if (CA == 1) {
        Percentage = Percentage - .02;
    }
    else if (CA == 2) {
        Percentage = Percentage - .1;
    }
    else if (CA >= 3) {
        Percentage = Percentage - .2;
    }
    if (CHPO == true) {
        Percentage = Percentage + .05;
    }
    else {
        Percentage = Percentage + 0;
    }
    const double Price = (CMSRP * (Percentage));
    if (Percentage >= 0) {
        print_eligible_message(Price);
    }
    else {
        print_ineligible_message();
    }
    return 0;
}