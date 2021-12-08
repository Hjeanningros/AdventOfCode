#include "Ex01.h"

std::vector<int> Ex01::ParseLine(std::string str, std::string separator) {
    size_t pos = 0;
    int number;
    std::vector<int> array;
    while ((pos = str.find(separator)) != std::string::npos) {
        std::string newStr = str.substr(0, pos);
        if (newStr != "") {
            number = atoi(newStr.c_str());
            array.push_back(number);
        }
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
        for (int i = 0; getline(myfile, line); i++) {
            if (i == 0)
                _arrayRandom = ParseLine(line, ",");
            else if (line == "" && OneBingo.size() != 0) {
                _bingoArray.push_back(OneBingo);
                OneBingo.clear();
            }
            else if (line != ""){
                OneBingo.push_back(ParseLine(line, " "));
            }
        }
        _bingoArray.push_back(OneBingo);
    }
}

std::vector<int> Ex01::CheckBingoLine(std::vector<std::vector<int>> bingo, int index) {
    std::vector<int> result;
    int same = 0;
    for (const std::vector<int> bingoLine : bingo) {
        for (int number : bingoLine) {
            for (int i = 0; i <= index; i++) {
                if (_arrayRandom[i] == number) {
                    same++;
                    result.push_back(number);
                }
            }
        }
        if (same == 5) {
            return result;
        }
        result.clear();
        same = 0;
    }
    return result;
}

std::vector<int> Ex01::CheckBingoColumns(std::vector<std::vector<int>> bingo, int index) {
    std::vector<int> result;
    int same = 0;
    for (int i = 0; i < bingo[0].size(); i++) {
        for (std::vector<int> bingoLines : bingo) {
            for (int y = 0; y <= index; y++) {
                if (_arrayRandom[y] == bingoLines[i]) {
                    same++;
                    result.push_back(bingoLines[i]);
                }
            }
        }
        if (same == 5) {
            return result;
        }
        result.clear();
        same = 0;
    }
    return result;
}

std::vector<int> Ex01::GetLineBingo() {
    std::vector<int> arrayResult;
    for (_indexFound = 0; _indexFound < _arrayRandom.size(); _indexFound++) {
        _arrayMarked.push_back(_arrayRandom[_indexFound]);
        for (const std::vector<std::vector<int>> Bingo : _bingoArray) {
            arrayResult = CheckBingoLine(Bingo, _indexFound);
            if (arrayResult.size() == 5) {
                _goodBingo = Bingo;
                return arrayResult;
            }
            arrayResult = CheckBingoColumns(Bingo, _indexFound);
            if (arrayResult.size() == 5) {
                _goodBingo = Bingo;
                return arrayResult;
            }
        }
    }
    return arrayResult;
}

int Ex01::CalculateUnmarked(std::vector<int> markedNumberArray) {
    int result = 0;

    for (const std::vector<int> &lineNumber : _goodBingo) {
        for (const int number : lineNumber) {
            if (std::find(std::begin(_arrayMarked), std::end(_arrayMarked), number) == std::end(_arrayMarked))
                result += number;

        }
    }
    return result;
}

int main()
{
    Ex01 exo;
    exo.ReadFileAndInit();
    std::vector<int> final = exo.GetLineBingo();
    int add = exo.CalculateUnmarked(final);
    std::cout << exo._arrayRandom[exo._indexFound] * add << std::endl;
    return 1;
}
