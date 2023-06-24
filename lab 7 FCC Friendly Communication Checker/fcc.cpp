#include <fstream>
#include <iostream>
#include <vector>

bool more_to_read(std::ifstream& file) {
    file >> std::noskipws;
    while (file.peek() == ' ') {
        char discard;
        file >> discard;
    }
    return !(file.eof() || std::iscntrl(file.peek()));
}

int fcc(const std::string& fixme_filename, const std::string& typo_filename,
    const std::string& fixo_filename, std::string& fixed_sentence) {

    std::vector<std::string>fixmein{};
    std::vector<std::string>typosin{};
    std::vector<std::string>fixosin{};

    std::string output;
    std::string finale{ fixed_sentence };
    
    std::ifstream fixo{ fixo_filename };
    std::ifstream typo{ typo_filename };
    std::ifstream fixme{ fixme_filename };

    /* this loop reads all the inputs from both the fixo file and the typo file 
    * and adds them both to their own vectors to use later
    * 
    * input: file, output, vector
    */
    while (more_to_read(fixo) == true && more_to_read(typo) == true) {
        std::string extract = " ";
        fixo >> extract;
        fixosin.push_back(extract);
        typo >> extract;
        typosin.push_back(extract);
    }
    /* this peice of code checks the typos and fixos files
    * to find leftovers in the system given by the infile
    * 
    * input: more to red(file), output: return -1/terminate
    */
    if (more_to_read(fixo) == true || more_to_read(typo) == true) {
        return -1;
    }
    /* this peice of code extracts all inputs for the file
    *  that needs to be fixed
    * 
    * input: more to red(file), output: vector
    */
    while (more_to_read(fixme) == true) {
        std::string extract = " ";
        fixme >> extract;
        fixmein.push_back(extract);
    }
    /*this loops both the fixme file anf the typo file to 
    * cross examin the input vector to see if it needs auto 
    * corrected or not and saves it to a string
    * 
    * input: vectors, output: string
    */
    int counter = 0;
    int counter2 = 0;
    for (int count = 0; count < fixmein.size(); count++) {
        bool fixed = false;
        for (int count2 = 0; count2 < typosin.size(); count2++) {
           
            if (fixmein[count] == typosin[count2]) {
                if (counter2 < 1) {
                    output = fixosin[count2];
                    counter += 1;
                    counter2 += 1;
                    fixed = true;
                } else {
                    output = output + " " + fixosin[count2];
                    counter += 1;
                    counter2 += 1;
                    fixed = true;
                }
            }
        }
        if (fixed == false) {
            if (counter2 < 1) {
                output = fixmein[count];
                counter2 += 1;
            } else {
                output = output + " " + fixmein[count];
                counter2 += 1;
            }
        } 
    }
    output = output + ".";
    fixed_sentence = output;
    return(counter);
}