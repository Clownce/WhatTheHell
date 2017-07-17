#include "stdafx.h"
#include "Underfloor4.h"


CUnderfloor4::CUnderfloor4()
{
}


CUnderfloor4::~CUnderfloor4()
{
}

void CUnderfloor4::Init()
{
	m_pImg = cvLoadImage("图像资源/第四关/地面.jpg", 1);
	m_size = cvGetSize(m_pImg);
	m_position.x = 1;
	m_position.y = 270;
	m_pitfall[0][0] = 200;
	m_pitfall[0][1] = 290;
	m_pitfall[1][0] = 390;
	m_pitfall[1][1] = 445;
}

int CUnderfloor4::CollideJudge(CMan *man)
{
	if (man->m_position.x + man->m_size.width / 2 > m_pitfall[0][1]
		&& man->m_position.x + man->m_size.width / 2 < m_pitfall[1][1] +10)
	{
		man->l_speed = 2;
		man->r_speed = 2;
	}
	else
	{
		man->l_speed = 4;
		man->r_speed = 4;
	}
	if ((man->m_position.x + man->m_size.width / 2 > m_pitfall[0][0]
		&& man->m_position.x + man->m_size.width / 2 < m_pitfall[0][1])
		|| (man->m_position.x + man->m_size.width / 2 > m_pitfall[1][0]
		&& man->m_position.x + man->m_size.width / 2 < m_pitfall[1][1]))//人物的x坐标处于没有支撑力的两个范围
	{
		if (man->m_position.y > 330)//掉下悬崖
		{
			Function_death(man);//死亡
		}
		return 0;
	}
	else//人物的x坐标处于有支撑力的范围
	{
		if (man->m_position.y + man->m_size.height + 10 > m_position.y
			&&man->m_position.y + man->m_size.height - 10 < m_position.y)//人物的y坐标也处于有支撑力的范围
		{
			man->m_position.y = m_position.y - man->m_size.height;//精准对齐，使人物的脚踩到地上，而不是中间隔着空气
			return 1;//返回“人物收到支撑”的信息
		}
	}
	return 0;
}

void CUnderfloor4::Function_death(CMan* man)
{
	man->life = 0;
}
