//
// Created by Avery Lee on 3/24/22.
//

#ifndef FORMATTER_TABLE_H
#define FORMATTER_TABLE_H

#include <vector>
#include <string>

namespace Formatter {
    using std::vector, std::array, std::string;

    template <int n> // Number of columns
    class Table {
        vector<array<string,n>> data;
        array<string,n> header;
    public:
        Table(array<string,n> const&);
        Table(vector<array<string,n>> const&);
        void setHeader(array<string,n> const &newHeader);
        void append(array<string,n> const &newData);
        void append(vector<array<string,n>> const &newData);
        void append(string const (&newData)[n]);
        template<int m> // Use this parameter for the number of rows you're adding, doesn't compile without this
        void append(string const (&newData)[n][m]);
        string render();
    };
}

#endif //FORMATTER_TABLE_H
