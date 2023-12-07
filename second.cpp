#include <iostream>
#include <fstream>
#include <string>

int main() {

    std::ifstream fin;
    std::string line;

    size_t total = 0;
    size_t digPosition = 0;
    size_t currentWordposiA = 0, currentWordposiB = 0;
    size_t valueSpellletter = 0;
    size_t first = 0, last = 0;

    std::string spellDig[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    fin.open("C:/Users/caiom/Documents/advent of code/test2.txt");   
    while (getline(fin, line)) {
        
        digPosition = line.find_first_of("1234567890");
        currentWordposiA = 100;
        for (auto i=0; i < 9; i++) {
            currentWordposiB = line.find(spellDig[i]);
            if (currentWordposiB != std::string::npos && currentWordposiB <= currentWordposiA) {
                currentWordposiA = currentWordposiB;
                valueSpellletter = i;
            }
        }
        
        if (digPosition != std::string::npos && currentWordposiA > digPosition ) {
            first = line[digPosition] - '0';
        }else {
            first = valueSpellletter + 1;
        }
       
        digPosition = line.find_last_of("1234567890");
        currentWordposiA = 0;
        for (auto i=0; i < 9; i++) {
            currentWordposiB = line.rfind(spellDig[i]);
            if (currentWordposiB != std::string::npos && currentWordposiB > currentWordposiA) {
                currentWordposiA = currentWordposiB;
                valueSpellletter = i;
            }
        }
        
        if (digPosition != std::string::npos && currentWordposiA <= digPosition ) {
            last = line[digPosition] - '0';
        }else {
            last = valueSpellletter + 1;
        }

        total += (first * 10) + last;
    }
        
    std::cout << total;
    fin.close();

    return 0;
}