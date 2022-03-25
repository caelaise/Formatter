//
// Created by Avery Lee on 3/24/22.
//

#include "../include/Table.h"
#include <sstream>
#include <iomanip>
#include <algorithm>

template<int n>
std::string Formatter::Table<n>::render() {
    std::array<int,n> longestRow = {};
    std::stringstream ss;
    ss << std::left;

    for(int i = 0; i < n; ++i) {
        for(auto row : data) {
            if(row[i].length() > longestRow[i]) {
                longestRow[i] = row[i].length();
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        ss << std::setw(longestRow[i] + 5) << header[i];
    }
    ss << std::endl;
    for(auto row : data) {
        for(int i = 0; i < n; ++i) {
            ss << std::setw(longestRow[i] + 5) << row[i];
        }
        ss << std::endl;
    }
    return ss.str();
}

template<int n>
void Formatter::Table<n>::setHeader(std::array<std::string, n> const &newHeader) {
    header = newHeader;
}

template<int n>
void Formatter::Table<n>::append(std::array<std::string, n> const &newData) {
    data.push_back(newData);
}

template<int n>
void Formatter::Table<n>::append(std::vector<std::array<std::string, n>> const &newData) {
    for(auto dat : newData) {
        append(dat);
    }
}

template<int n>
Formatter::Table<n>::Table(std::array<std::string, n> const &dat) {
    append(dat);
}

template<int n>
Formatter::Table<n>::Table(std::vector<std::array<std::string, n>> const &dat) {
    append(dat);
}

template<int n>
void Formatter::Table<n>::append(std::string const (&newData)[n]) {
    std::array<std::string,n> newDat;
    std::copy(std::begin(newData),std::end(newData),newDat.begin());
    append(newDat);
}

template<int n>
template<int m>
void Formatter::Table<n>::append(std::string const (&newData)[n][m]) {
    for(auto dat : newData) {
        append(dat);
    }
}


