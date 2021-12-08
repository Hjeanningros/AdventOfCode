//
// Created by hugo on 12/7/21.
//

#ifndef ADVENTOFCODE_EX02_H
#define ADVENTOFCODE_EX02_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <bitset>

class Ex02 {
    public:
    void ReadFileAndInit();
    std::vector<int> ParseLine(std::string str, std::string separator);
    void GetLastBingo();
    void FindLineLastBingo();
    std::vector<int> CheckBingoLine(std::vector<std::vector<int>> bingo, int i);
    std::vector<int> CheckBingoColumns(std::vector<std::vector<int>> bingo, int index);
    int CalculateUnmarked();


    std::vector<std::vector<std::vector<int>>> _bingoArray;
    std::vector<int> _arrayRandom;
    std::vector<int> _arrayMarked;
    int _indexFound;
};

#endif //ADVENTOFCODE_EX01_H
