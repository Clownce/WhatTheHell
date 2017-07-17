#pragma once
#include "Element.h"
class CCloud :
	public CElement
{
public:
	CCloud();
	virtual ~CCloud();
	void Init(int Level);
	int CollideJudge(CMan* man,int Level);
	void Function_death(CMan* man);
};

