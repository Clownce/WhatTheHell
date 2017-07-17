#pragma once
#include "Element.h"
class CHidenBrick4 :
	public CElement
{
public:
	CHidenBrick4();
	CHidenBrick4(int x, int y);
	virtual ~CHidenBrick4();
	int m_suport[1][1];
	int F;//反作用力
	void Init();
	int CollideJudge(CMan* man);
	void Function_stopjump(CMan* man);
};

