#pragma once
#include "Element.h"
class CMonster :
	public CElement
{
public:
	CMonster();
	CMonster(int x,int y,int jump);
	virtual ~CMonster();
	void Init(int Level);
	int v;
	int jumptime;
	int CollideJudge(CMan* man,int Level);
	void Function_death(CMan* man);
	void Move(CMan* man);
};

