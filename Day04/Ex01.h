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
    std::vector<int> GetLineBingo();
    std::vector<int> CheckBingoLine(std::vector<std::vector<int>> bingo, int i);
    std::vector<int> CheckBingoColumns(std::vector<std::vector<int>> bingo, int index);
    int CalculateUnmarked(std::vector<int> markedNumberArray);


    std::vector<std::vector<std::vector<int>>> _bingoArray;
    std::vector<int> _arrayRandom;
    std::vector<int> _arrayMarked;
    std::vector<std::vector<int>> _goodBingo;
    int _indexFound;
};

#endif //ADVENTOFCODE_EX01_H
