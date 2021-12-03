#include <string>
#include <iostream>
#include <vector>
#include <fstream>

std::vector<int> readFile()
{
    std::vector<int> array;
    std::string line;
    std::ifstream myfile;
    myfile.open("input.txt");
    if (myfile.is_open()) {
        while (getline(myfile,line) ) {
            array.push_back(atoi(line.c_str()));
        }
        myfile.close();
    } else
        std::cout << "Unable to open file";
    return array;
}

int dayO1()
{
    int topValue = -1;
    int count = 0;
    std::vector<int> vectorInt = readFile();
    for(const int &value : vectorInt) {
        if (topValue < value && topValue != -1) {
            topValue = value;
            count++;
        }
        topValue = value;
    }
    std::cout << "Count = " << count << std::endl;
    return 1;
}

int main()
{
    dayO1();
    return 1;
}