#include "Font.h"

Font::Font(){
    if(!m_font.loadFromFile("impact.ttf"))
        throw std::runtime_error("impact.ttf is missing");
}
//=============================================================================
Font & Font::FontObject() {
    static Font fontObject;
    return fontObject;
}
//=============================================================================
const sf::Font & Font::getFont() const {
    return m_font;
}
//=============================================================================