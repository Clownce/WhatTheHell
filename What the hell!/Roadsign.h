#pragma once
#include "Element.h"
class CRoadsign :
	public CElement
{
public:
	CRoadsign();
	virtual ~CRoadsign();
	int m_suport[1][1];
	int F;//��������
	void Init(int Level);
//	string function();
	int CollideJudge(CMan *man,int Level);
	void Function_stopjump(CMan* man);
};

