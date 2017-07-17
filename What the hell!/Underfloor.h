#pragma once
#include "Element.h"
class CUnderfloor :
	public CElement
{
public:
	CUnderfloor();
	CUnderfloor(int level, IplImage *Img);
	virtual ~CUnderfloor();
	
	int m_pitfall[2][2];
	void Init(int Level);
	void Init();
	int F;//反作用力
//	string function();
	int CollideJudge(CMan *man,int Level);
	int CollideJudge(CMan *man);
	void Function_death(CMan* man);
	///
	void Function_stopjump(CMan* man);
	int Level;
	IplImage *m_fallpImg;
	void DrawFall();
	IplImage *pBack;
	CvPoint m_fallstart;
	CvSize m_fallsize;
	void Fall();
};

