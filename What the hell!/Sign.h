#pragma once
#include "Element.h"
class CSign :
	public CElement
{
public:
	CSign();
	virtual ~CSign();
	void Init(int Level);
	void Init();
	int CollideJudge(CMan* man,int Level);
	void Function_death(CMan* man);
	void Function_stopjump(CMan* man);
	int Level;
	int Time;

	CSign(int x, int y, int level);
	int CollideJudge(CMan* man);
	
};

