#include "stdafx.h"
#include "HidenBrick4.h"


CHidenBrick4::CHidenBrick4()
{
}

CHidenBrick4::CHidenBrick4(int x, int y)
{
	m_position.x = x;
	m_position.y = y;
}


CHidenBrick4::~CHidenBrick4()
{
}

void CHidenBrick4::Init()
{
	m_pImg = cvLoadImage("图像资源/第四关/隐身_砖.jpg", 1);
	m_size = cvGetSize(m_pImg);
	m_suport[0][0] = m_position.x;
	m_suport[0][1] = m_position.x+m_size.width;
	jihuo = 0;
}

int CHidenBrick4::CollideJudge(CMan* man)
{
	if ((man->m_position.x + man->m_size.width >= m_suport[0][0]
		&& man->m_position.x + man->m_size.width <= m_suport[0][1])
		|| man->m_position.x >= m_suport[0][0]
		&& man->m_position.x <= m_suport[0][1])
	{
		if (man->m_position.y <=m_position.y + 30
			&& man->m_position.y >= m_position.y && man->V > 0)
		{
			//m_position.y + 40 = man->m_position.y;
			Function_stopjump(man);
			m_pImg = cvLoadImage("图像资源/第四关/已撞_砖.jpg", 1);
			jihuo = 1;
		}
		if (man->m_position.y + man->m_size.height + 10 > m_position.y
			&&man->m_position.y + man->m_size.height - 10 < m_position.y
			&&jihuo == 1)//计算是否接触地面，才能有支撑力。
		{
			man->m_position.y = m_position.y - man->m_size.height;
			Function_stopjump(man);
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

void CHidenBrick4::Function_stopjump(CMan* man)
{
	if (man->V > 0)
	{
		man->V = -man->V;
	}
}
