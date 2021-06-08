#pragma once

#include <fstream>
#include <vector>
#include <string>

#include "Macros.h"

using constIterToVecStr = std::vector<std::string>::const_iterator;

class HousesFile {
public:
    HousesFile(const std::string &);

    std::string readLine();
    std::pair<constIterToVecStr ,constIterToVecStr> getHouse();
    bool eof() const;

private:
    int m_currLine;
    std::vector<std::string> m_fileContent;
};