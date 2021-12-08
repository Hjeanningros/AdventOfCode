#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <bitset>

std::vector<std::string> readFile()
{
    std::vector<std::string> array(12);
    std::string line;
    std::ifstream myfile;
    myfile.open("Ex01.txt");
    if (myfile.is_open()) {
        while (getline(myfile,line) ) {
            for (int i = 0; i < 12; i++) {
                array[i] += line.c_str()[i];
            }
        }
        myfile.close();
    } else
        std::cout << "Unable to open file";
    return array;
}

int dayO1()
{
    std::vector<std::string> vectorBinary = readFile();
    std::string GammaRate;
    std::string EpsilonRate;

    for(const std::string &str : vectorBinary) {
        size_t numberZero = std::count(str.begin(), str.end(), '0');
        size_t numberOne = std::count(str.begin(), str.end(), '1');
        GammaRate += numberZero > numberOne ? "0" : "1";
    }
    EpsilonRate = GammaRate;
    std::replace( EpsilonRate.begin(), EpsilonRate.end(), '1', '2');
    std::replace( EpsilonRate.begin(), EpsilonRate.end(), '0', '1');
    std::replace( EpsilonRate.begin(), EpsilonRate.end(), '2', '0');

    unsigned long Gamma = std::bitset<64>(GammaRate).to_ulong();
    unsigned long Epsilon = std::bitset<64>(EpsilonRate).to_ulong();

    std::cout << "Value  = " << Gamma * Epsilon << std::endl;

    return 1;
}

int main()
{
    dayO1();
    return 1;
}
