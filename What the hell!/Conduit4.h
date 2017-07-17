#pragma once
#include "Element.h"
class CConduit4 :
	public CElement
{
public:
	CConduit4();
	CConduit4(int x, int y);
	virtual ~CConduit4();
	int m_suport[1][1];
	int F;//反作用力
	void Init();
	//	string function();
	int CollideJudge(CMan *man);
	void Function_stopjump(CMan* man);
};

