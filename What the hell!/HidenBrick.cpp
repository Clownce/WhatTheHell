#include "stdafx.h"
#include "HidenBrick.h"


CHidenBrick::CHidenBrick()
{
}

CHidenBrick::CHidenBrick(int x, int y)
{
	m_position.x = x;
	m_position.y = y;
	m_suport[0][0] = x;
	m_suport[0][1] = x + 30;
}

CHidenBrick::~CHidenBrick()
{
}


void CHidenBrick::Init(int Level)
{
	if (Level == 1)
	{
		m_pImg = cvLoadImage("图像资源/第一关/隐身_砖.jpg", 1);
		m_size = cvGetSize(m_pImg);
		m_position.x = 1030;
		m_position.y = 165;
		m_suport[0][0] = 1030;
		m_suport[0][1] = 1060;
		jihuo = 0;
	}
	else if (Level == 3)
	{
	}
}

void CHidenBrick::Init()
{
	m_pImg = cvLoadImage("图像资源/第一关/隐身_砖.jpg", 1);
	m_size = cvGetSize(m_pImg);

	jihuo = 0;
}

int CHidenBrick::CollideJudge(CMan* man,int Level)
{
	if (Level == 1)
	{
		if ((man->m_position.x + man->m_size.width >= m_suport[0][0]
			&& man->m_position.x + man->m_size.width <= m_suport[0][1])
			|| man->m_position.x >= m_suport[0][0]
			&& man->m_position.x <= m_suport[0][1])
		{
			if (man->m_position.y - 10< m_position.y + 30
				&& man->m_position.y + 10>m_position.y + 30 && man->V>0)
			{
				//m_position.y + 40 = man->m_position.y;
				Function_stopjump(man);
					m_pImg = cvLoadImage("图像资源/第一关/已撞_砖.jpg", 1);
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
	else if (Level == 3)
	{
		//m_pImg = cvLoadImage("图像资源/第三关/已撞_砖.jpg", 1);
		return 0;
	}
	return 0;
}

int CHidenBrick::CollideJudge(CMan* man)
{
	if ((man->m_position.x + man->m_size.width >= m_suport[0][0]
		&& man->m_position.x + man->m_size.width <= m_suport[0][1])
		|| man->m_position.x >= m_suport[0][0]
		&& man->m_position.x <= m_suport[0][1])
	{
		if (man->m_position.y - 10 < m_position.y + 30
			&& man->m_position.y + 10 > m_position.y + 30 && man->V > 0)
		{
			//m_position.y + 40 = man->m_position.y;
			Function_stopjump(man);
			m_pImg = cvLoadImage("图像资源/第一关/已撞_砖.jpg", 1);
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



void CHidenBrick::Function_stopjump(CMan* man)
{
	if (man->V > 0)
	{
		man->V = -man->V;
	}
}
