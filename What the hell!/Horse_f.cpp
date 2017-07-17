#include "stdafx.h"
#include "Horse_f.h"


CHorse_f::CHorse_f()
{
}


CHorse_f::~CHorse_f()
{
}


void CHorse_f::Init(int Level)
{
	if (Level == 1)
	{
		m_pImg = cvLoadImage("图像资源/第一关/假马.jpg", 1);
		m_size = cvGetSize(m_pImg);
		m_position.x = 2178;
		m_position.y = 210;
	}
	else if (Level == 3)
	{
		m_pImg = cvLoadImage("图像资源/第三关/假马.jpg", 1);
		m_size = cvGetSize(m_pImg);
		m_position.x = 920;
		m_position.y = 5;
	}
}


int CHorse_f::CollideJudge(CMan* man,int Level)
{
	if (Level == 1)
	{
		if (man->m_position.x + man->m_size.width / 2 > m_position.x
			&&man->m_position.x + man->m_size.width / 2 < m_position.x + m_size.width
			&&man->m_position.y + man->m_size.height / 2 < m_position.y + m_size.height
			&&man->m_position.y + man->m_size.height / 2 > m_position.y)
		{
			man->m_position.x = 1967;
			man->m_position.y -= 40;
		}
	}
	else if (Level == 3)
	{
		if (man->m_position.x + man->m_size.width > 920 && man->m_position.y + man->m_size.height > 0 && man->m_position.y + man->m_size.height < 60)
			Function_death(man);
	}
	return 0;
}


void CHorse_f :: Function_death(CMan* man)
{
	man->life = 0;
}
