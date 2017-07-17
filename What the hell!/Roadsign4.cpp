#include "stdafx.h"
#include "Roadsign4.h"


CRoadsign4::CRoadsign4()
{
}


CRoadsign4::~CRoadsign4()
{
}

void CRoadsign4::Init()
{
	m_pImg = cvLoadImage("图像资源/第四关/路标.jpg", 1);
	m_size = cvGetSize(m_pImg);
	m_position.x = 100;
	m_position.y = 185;
	m_suport[0][0] = m_position.x;
	m_suport[0][1] = m_position.x + m_size.width;
}

int CRoadsign4::CollideJudge(CMan *man)
{
	if (man->m_position.x + man->m_size.width / 2 > m_suport[0][0]
		&& man->m_position.x + man->m_size.width / 2 < m_suport[0][1])
	{
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

void CRoadsign4::Function_stopjump(CMan* man)
{
	if (man->V > 0)
	{
		man->V = -man->V;
	}
}
