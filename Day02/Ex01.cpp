#include <string>
#include <iostream>
#include <vector>
#include <fstream>

std::vector<std::pair<std::string, int>> readFile()
{
    std::vector<std::pair<std::string, int>> array;
    std::string line;
    std::ifstream myfile;
    myfile.open("Ex01.txt");
    if (myfile.is_open()) {
        while (getline(myfile,line) ) {
            int posSpace = line.find(" ");
            std::string word = line.substr(0, posSpace);
            int value = atoi(line.substr(posSpace, line.length()).c_str());
            array.push_back(make_pair (word,value));
        }
        myfile.close();
    } else {
        std::cout << "Unable to open file";
    }
    return array;
}

int dayO2()
{
    int horizontal = 0;
    int depth = 0;

    std::vector<std::pair<std::string, int>> vectorInt = readFile();

    for (const std::pair<std::string, int> &myPair: vectorInt) {
        if (myPair.first.compare("forward") == 0) {
            horizontal += myPair.second;
        } else if (myPair.first.compare("down") == 0) {
            depth += myPair.second;
        } else if (myPair.first.compare("up") == 0) {
            depth -= myPair.second;
        }
    }
    std::cout << "Result == " << horizontal * depth << std::endl;
    return 1;
}

int main()
{
    dayO2();
    return 1;
}