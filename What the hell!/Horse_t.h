#pragma once
#include "Element.h"
class CHorse_t :
	public CElement
{
public:
	CHorse_t();
	virtual ~CHorse_t();
	void Init(int Level);
	int CollideJudge(CMan* man,int Level);
	void Success(CMan* man);

	CHorse_t(int x, int level);
	void Init();
	int CollideJudge(CMan* man);
};

