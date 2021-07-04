#include "Continue.h"

Continue::Continue(const int pos) : Command(pos, "Continue"){}
//=============================================================================
bool Continue::execute(sf::RenderWindow &) {
    return false;
}
//=============================================================================