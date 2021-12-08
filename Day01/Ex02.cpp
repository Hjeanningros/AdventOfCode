#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>

std::vector<int> readFile()
{
    std::vector<int> array;
    std::string line;
    std::ifstream myfile;
    myfile.open("Ex02.txt");
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
    int topSumValue = -1;
    int count = 0;

    std::vector<int> vectorToSumm;
    std::vector<int> vectorInt = readFile();
    for (int i = 0;  i < vectorInt.size(); i++) {
        if (i + 3 > vectorInt.size())
            break;
        else {
            for (int y = 0; y < 3; y++) {
                vectorToSumm.push_back(vectorInt[i + y]);
            }
            int total = std::accumulate(std::begin(vectorToSumm), std::end(vectorToSumm), 0, std::plus<int>());
            if (topSumValue < total && topSumValue != -1) {
                count++;
            }
            topSumValue = total;
            vectorToSumm.clear();
        }
    }

    std::cout << "Count = " << count << std::endl;
    return 1;
}

int main()
{
    dayO1();
    return 1;
}