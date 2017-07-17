#pragma once
#include "Element.h"
class CRoadsign4 :
	public CElement
{
public:
	CRoadsign4();
	virtual ~CRoadsign4();
	int m_suport[1][1];
	int F;//反作用力
	void Init();
	//	string function();
	int CollideJudge(CMan *man);
	void Function_stopjump(CMan* man);
};

