#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <bitset>

std::vector<std::string> readFile()
{
    std::vector<std::string> array;
    std::string line;
    std::ifstream myfile;
    myfile.open("Ex02.txt");
    if (myfile.is_open()) {
        while (getline(myfile,line) ) {
             array.push_back(line);
        }
        myfile.close();
    } else
        std::cout << "Unable to open file";
    return array;
}

std::string getOxygeneGeneratorRating(std::vector<std::string> vectorBinary) {
    int numberZero = 0;
    int numberOne = 0;

    for (int i = 0; i < 12 || vectorBinary.size() == 1; i++) {
        numberZero = 0;
        numberOne = 0;
        for (const std::string &str : vectorBinary) {
            str[i] == '1' ? numberOne += 1 : numberZero += 1;
        }
        int y = 0;
        while ( y < vectorBinary.size() || vectorBinary.size() == 1) {
            if (numberZero > numberOne && vectorBinary[y][i] == '1') {
                vectorBinary.erase(vectorBinary.begin() + y);
            } else if (numberZero <= numberOne && vectorBinary[y][i] == '0') {
                vectorBinary.erase(vectorBinary.begin() + y);
            } else {
                y++;
            }
        }
    }
    return vectorBinary[0];
}


std::string getScrubberRating(std::vector<std::string> vectorBinary) {
    int numberZero = 0;
    int numberOne = 0;
    for (int i = 0; i < 12 || vectorBinary.size() == 1; i++) {
        numberZero = 0;
        numberOne = 0;
        for (const std::string &str : vectorBinary) {
            str[i] == '1' ? numberOne += 1 : numberZero += 1;
        }
        int y = 0;
        while ( y < vectorBinary.size()) {
            if (numberZero > numberOne && vectorBinary[y][i] == '0') {
                vectorBinary.erase(vectorBinary.begin() + y);
            } else if (numberZero <= numberOne && vectorBinary[y][i] == '1') {
                vectorBinary.erase(vectorBinary.begin() + y);
            } else {
                y ++;
            }
        }
        std::cout << std::endl;
    }
    std::cout << vectorBinary[0] << std::endl;
    return vectorBinary[0];
}

int dayO1()
{
    std::vector<std::string> vectorBinary = readFile();

    std::string oxygeneRate = getOxygeneGeneratorRating(vectorBinary);
    std::string scrubberRate = getScrubberRating(vectorBinary);

    unsigned long oxygeneRateDecimal = std::bitset<64>(oxygeneRate).to_ulong();
    unsigned long scrubberRateDecimal = std::bitset<64>(scrubberRate).to_ulong();
    std::cout << oxygeneRateDecimal << "  " << scrubberRateDecimal << std::endl;

    std::cout << oxygeneRateDecimal * scrubberRateDecimal << std::endl;
    return 1;
}

int main()
{
    dayO1();
    return 1;
}
