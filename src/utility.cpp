//
// Created by Avery Lee on 3/24/22.
//

#include "../include/utility.h"
#include <sstream>
#include <iomanip>

std::string centered(int width, std::string str) {
    std::stringstream ss;
    ss << std::setw((width - str.length()) / 2) << str;
    return ss.str();
}
