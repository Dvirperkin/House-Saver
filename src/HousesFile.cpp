#include "HousesFile.h"

HousesFile::HousesFile(const std::string & fileName) : m_currLine(0) {
    auto houseFile = std::fstream(fileName);
    if(!houseFile){
        throw 55;
    }
    auto line = std::string();
    while(std::getline(houseFile,line)){
        m_fileContent.emplace_back(line);
    }
}
//=============================================================================
std::string HousesFile::readLine() {
    return m_fileContent[m_currLine++];
}
//=============================================================================
bool HousesFile::eof() const {
    return m_currLine == m_fileContent.size();
}
//=============================================================================
std::pair<constIterToVecStr, constIterToVecStr> HousesFile::getHouse(){
    auto homeDeclarationRange = std::stoi(m_fileContent[m_currLine]);
    auto beginHouse = m_fileContent.cbegin() + m_currLine + 1;
    auto endHouse = m_fileContent.cbegin() + m_currLine + homeDeclarationRange + 1;
    m_currLine += homeDeclarationRange + 1;
    return {beginHouse, endHouse};
}
//=============================================================================

