#pragma once
#include "Element.h"
class CBrick :
	public CElement
{
public:
	CBrick();
	CBrick(int x,int y,int flag);

	virtual ~CBrick();
	int m_suport[1][1];
	int F;//反作用力

	void Init(int Level);
	int CollideJudge(CMan* man,int Level);
	void Function_stopjump(CMan* man);

	CBrick(int x, int y);
	void Init();
	int CollideJudge(CMan* man);
};

