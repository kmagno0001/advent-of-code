#include <iostream>
#include <fstream>
#include <string>
#include <vector>



int main() {

    std::ifstream fin;
    std::string line;
    std::vector<int> values(2);

    int total = 0;
    char a, b;

    fin.open("C:/Users/caiom/Documents/advent of code/puzzel.txt");
    while (getline(fin, line)) {
        

        for (auto chan : line ) {
            if (std::isdigit(chan)) {
                a = chan;
                break;
            }
        }

        for (auto chan = line.rbegin(); chan != line.rend(); ++chan ) {
            if (std::isdigit(*chan)) {
                b = *chan;
                break;
            }
        }

    
        total += ((a - '0') * 10) + (b - '0');
    }
    
    std::cout << total;

    fin.close();

    return 0;
}