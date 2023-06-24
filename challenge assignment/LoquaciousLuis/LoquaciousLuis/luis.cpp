#include <cassert>
#include <iostream>
#include <vector>

int get_index_from_name(std::string name, const std::vector<std::string>& chatters_map) {
    // Use a for loop to find the index of the vector that retrieves a name from
    // map that is equal to the name that the caller requested.
    bool checker = false;
    std::string Word{ name };
    std::vector<std::string> list{ chatters_map };
    int counter = 0;
    for (const auto& item : list) {
        if (item == Word) {
            checker = true;
            return(counter);
        }
        counter++;
    }
    if (checker == false) {
        assert(("Error: Attempting to determine the index of a name that is not in "
            "the map.",
            false));
        return -1;
    }
}

std::string get_name_from_index(int index,
    const std::vector<std::string>& chatters_map) {
    // Once we check whether the index that the caller gave is valid, use it
    // to reach in to the map vector and get the name of the appropriate chatter.
    int find = index;
    int counter = 0;
    std::vector<std::string> list{ chatters_map };
    if (index < chatters_map.size()) {
        for (const auto& item : list) {
            if (find == counter) {
                std::string out = list[counter];
                return(out);
            }
            counter++;
        }
    }
    else {
        assert(("Error: Attempting to determine the name of a index that is not in "
            "the map.",
            false));
    }
}

/*
 * generate_communication_grid
 *
 * This function generates a vector of vector of bools. In other words,
 * this function generates a 2d vector of bools. In even other words, it
 * generates a grid of bools. The vector of vectors of bools (2d vector of
 * bools, grid of bools) is square -- the number of rows is the same as the
 * number of columns. The number of rows and columns is equal to
 * number_of_communicators. The initial value of every grid entry is false.
 *
 * Input: The l (or w, they are equal after all) of the 2d vector of bools to
 * create. Output: A square 2d vector of bools with l/w =
 * number_of_communicators where all values are false.
 */
std::vector<std::vector<bool>>
generate_communication_grid(int number_of_communicators) {
    auto inner_vector = std::vector<bool>(number_of_communicators, false);
    auto outer_vector = std::vector<std::vector<bool>>(number_of_communicators,inner_vector);
    return outer_vector;
}

int main() {

    std::vector<std::string> chatters{ "Will",  "Ben",  "Jenn", "Kevin", "Lily", "Ali" };
    std::vector<std::vector<bool>> can_communicate{
        generate_communication_grid(chatters.size()) };
    can_communicate[get_index_from_name("Will", chatters)]
        [get_index_from_name("Kevin", chatters)] = true;
    can_communicate[get_index_from_name("Jenn", chatters)]
        [get_index_from_name("Ben", chatters)] = true;
    can_communicate[get_index_from_name("Jenn", chatters)]
        [get_index_from_name("Kevin", chatters)] = true;
    can_communicate[get_index_from_name("Ali", chatters)]
        [get_index_from_name("Will", chatters)] = true;

    for (int talker_index{ 0 }; talker_index < chatters.size(); talker_index++) {
        for (int listener_index{ 0 }; listener_index < chatters.size(); listener_index++) {
            if (can_communicate[talker_index][listener_index] == true) {
                std::string first = get_name_from_index(talker_index, chatters);
                std::string second = get_name_from_index(listener_index, chatters);
                std::cout << first << " can WhatsApp to " << second << "\n";
            }
        }
    }
    return 0;
}