#pragma once
#include "Element.h"
class CUnderfloor4 :
	public CElement
{
public:
	CUnderfloor4();
	virtual ~CUnderfloor4();

	int m_pitfall[2][2];
	void Init();
	int F;//反作用力
	//	string function();
	int CollideJudge(CMan *man);
	void Function_death(CMan* man);
};

