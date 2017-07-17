#pragma once
#include "Element.h"
class CHorse_f :
	public CElement
{
public:
	CHorse_f();
	virtual ~CHorse_f();
	void Init(int Level);
	int CollideJudge(CMan* man,int Level);
	void Function_death(CMan* man);
};

