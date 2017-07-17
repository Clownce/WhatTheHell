#pragma once
#include "Element.h"
class CHidenBrick :
	public CElement
{
public:
	CHidenBrick();
	CHidenBrick(int x, int y);
	virtual ~CHidenBrick();
	int m_suport[1][1];
	int F;//反作用力
	int jihuo;
	void Init(int Level);
	int CollideJudge(CMan* man,int Level);
	void Function_stopjump(CMan* man);

	void Init();
	int CollideJudge(CMan* man);
};

