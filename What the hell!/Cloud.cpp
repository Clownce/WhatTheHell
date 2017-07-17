#include "stdafx.h"
#include "Cloud.h"


CCloud::CCloud()
{
}


CCloud::~CCloud()
{
}


void CCloud::Init(int Level)
{
	if (Level == 1)
	{
		m_pImg = cvLoadImage("图像资源/第一关/云.jpg", 1);
		m_size = cvGetSize(m_pImg);
		m_position.x = 1082;
		m_position.y = 17;
	}
	else if (Level == 3)
	{
		m_pImg = cvLoadImage("图像资源/第三关/云.jpg", 1);
		m_size = cvGetSize(m_pImg);
		m_position.x = 1082;
		m_position.y = 17;
	}
}


int CCloud::CollideJudge(CMan* man,int Level)
{
	if (Level == 1)
	{
		if (man->m_position.x + man->m_size.width / 2 > m_position.x
			&&man->m_position.x + man->m_size.width / 2 < m_position.x + m_size.width
			&&man->m_position.y + man->m_size.height / 2 < m_position.y + m_size.height
			&&man->m_position.y + man->m_size.height / 2 > m_position.y)
		{
			m_pImg = cvLoadImage("图像资源/第一关/陷阱云.jpg", 1);
			Function_death(man);
		}
	}
	
	return 0;
}


void CCloud::Function_death(CMan* man)
{
	man->life = 0;
}

