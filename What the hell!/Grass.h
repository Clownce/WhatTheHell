#pragma once
#include "Element.h"
class CGrass :
	public CElement
{
public:
	CGrass(int x,int y);
	~CGrass();
	void Init();
	int CollideJudge(CMan* man);
	void Function_death(CMan* man);
};

