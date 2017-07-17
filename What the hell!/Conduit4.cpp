#include "stdafx.h"
#include "Conduit4.h"


CConduit4::CConduit4()
{
}

CConduit4::CConduit4(int x, int y)
{
	m_position.x = x;
	m_position.y = y;
}


CConduit4::~CConduit4()
{
}

void CConduit4::Init()
{
	m_pImg = cvLoadImage("图像资源/第四关/水管.jpg", 1);
	m_size = cvGetSize(m_pImg);
	m_suport[0][0] = m_position.x;
	m_suport[0][1] = m_position.x + m_size.width;
}

int CConduit4::CollideJudge(CMan *man)
{
	if (man->m_position.x + man->m_size.width -5 > m_suport[0][0]
		&& man->m_position.x+5 < m_suport[0][1])
	{
		if (man->m_position.x + man->m_size.width - 5 > m_suport[0][0]
			&& man->m_position.x + man->m_size.width - 5< m_suport[0][0]+5
			&& man->m_position.y + man->m_size.height > m_position.y-5)
			man->r_speed = 0;
		if (man->m_position.x +5 < m_suport[0][1]
			&& man->m_position.x + 5 > m_suport[0][1]-5
			&& man->m_position.y + man->m_size.height > m_position.y-5)
			man->l_speed = 0;
		if (man->m_position.y - 3 < m_position.y + 3
			&& man->m_position.y + 3 > m_position.y + 3)
		{
			//man->m_position.y = m_position.y + 40;
			Function_stopjump(man);
		}
		if (man->m_position.y + man->m_size.height + 5 > m_position.y
			&&man->m_position.y + man->m_size.height - 5 < m_position.y)//计算是否接触地面，才能有支撑力。
		{
			man->m_position.y = m_position.y - man->m_size.height;
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

void CConduit4::Function_stopjump(CMan* man)
{
		if (man->V > 0)
	{
		man->V = -man->V;
	}
}
