//
// Created by andrey on 7/25/21.
//

#include "utils.h"
#include <fstream>
#include <sstream>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "LoopDoesntUseConditionVariableInspection"
std::vector<std::string> makePile(const std::string &name, char delimeter) {
    ulong pos = 0;
    std::vector<std::string> result;
    for (auto newpos = name.find(delimeter, pos); newpos != std::string::npos; pos = newpos + 1)
        result.push_back(name.substr(0, newpos));
    return result;
}

std::string readFile(const std::string &f) {
    auto ss = std::ostringstream{};
    std::ifstream input_file(f);
    if (!input_file.is_open()) {
        return "";
    }
    ss << input_file.rdbuf();
    return ss.str();
}

#pragma clang diagnostic pop

