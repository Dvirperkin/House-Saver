#pragma once
#include "Mission.h"

class CollectMisson : public Mission {
public:
	CollectMisson(const int, const int);
private:
	int m_toCollect;
};