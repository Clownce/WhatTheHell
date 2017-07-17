#pragma once
#include "Element.h"
class CBomb4 :
	public CElement
{
public:
	CBomb4();
	CBomb4(int x, int y, int num);
	virtual ~CBomb4();
	void Init();
	bool move;
	int nub;
	int CollideJudge(CMan* man);
	void Function_death(CMan* man);
	void Move(CMan* man);
};

