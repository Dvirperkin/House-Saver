#include "Exit.h"

Exit::Exit(const int pos,  bool & ret): Command(pos, "Exit"), m_return(ret){}
//=============================================================================
bool Exit::execute(sf::RenderWindow &){
	m_return = true;
	return false;
}
