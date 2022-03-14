#include "Ex01.h"

std::vector<int> Ex01::ParseLine(std::string str, std::string separator) {
    size_t pos = 0;
    int number;
    std::vector<int> array;
    while ((pos = str.find(separator)) != std::string::npos) {
        std::string newStr = str.substr(0, pos);
        number = atoi(newStr.c_str());
        array.push_back(number);
        str.erase(0, pos + 1);
    }
    array.push_back(atoi(str.c_str()));
    return array;
}


void Ex01::ReadFileAndInit() {

    std::ifstream myfile;
    std::string line;
    std::vector<std::vector<int>> OneBingo;
    myfile.open("Ex01.txt");
    if (myfile.is_open()) {
        for (int index = 0; getline(myfile, line);) {
            index = line.find(" -> ");
            std::string cleanStr = line.replace(index, 4, ",");
            std::cout << cleanStr << std::endl;
            _instruction.push_back(ParseLine(line, ","));
        }
    }
}

void Ex01::fillMap() {
    _map[0][10] = 1;
    std::cout << _map[0][10]<<_map[0][0];
}

int main()
{
    Ex01 exo;
    exo.ReadFileAndInit();
    exo.fillMap();
    return 1;
}


