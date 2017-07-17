#include "stdafx.h"
#include "Grass.h"


CGrass::CGrass(int x,int y)
{
	m_position.x = x;
	m_position.y = y;
}


CGrass::~CGrass()
{
}

void CGrass::Init()
{
	m_pImg = cvLoadImage("图像资源/第二关/草.jpg", 1);
	m_size = cvGetSize(m_pImg);
}


int CGrass::CollideJudge(CMan* man)
{
	if (man->m_position.x + man->m_size.width / 2 > m_position.x
		&&man->m_position.x + man->m_size.width / 2 < m_position.x + m_size.width
		&&man->m_position.y + man->m_size.height / 2 < m_position.y + m_size.height
		&&man->m_position.y + man->m_size.height / 2 > m_position.y)
	{
		m_pImg = cvLoadImage("图像资源/第二关/陷阱草.jpg", 1);
		Function_death(man);
	}
	return 0;
}


void CGrass::Function_death(CMan* man)
{
	man->life = 0;
}

