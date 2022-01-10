//
// Created by hugo on 12/7/21.
//

#ifndef ADVENTOFCODE_EX01_H
#define ADVENTOFCODE_EX01_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <bitset>

class Ex01 {
    public:
    void ReadFileAndInit();
    std::vector<int> ParseLine(std::string str, std::string separator);
    void fillMap();

        std::vector<std::vector<int>> _instruction;

    std::vector<std::vector<int>> _map;
};

#endif //ADVENTOFCODE_EX01_H
