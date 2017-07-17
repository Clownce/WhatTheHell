#include "stdafx.h"
#include "Underfloor.h"


CUnderfloor::CUnderfloor()
{
}


CUnderfloor::CUnderfloor(int level, IplImage *Img)
{
	if (level == 1)
	{
		m_pImg = cvLoadImage("图像资源/第一关/地面.jpg", 1);
		m_pitfall[0][0] = 1027;
		m_pitfall[0][1] = 1117;
		m_pitfall[1][0] = 1942;
		m_pitfall[1][1] = 2032;
	}
	else if (level == 2)
	{
		m_pImg = cvLoadImage("图像资源/第二关/地面.jpg", 1);
		m_pitfall[1][0] = 2050;
		m_pitfall[1][1] = 2190;
	}
	Level = level;
	pBack = Img;
}

CUnderfloor::~CUnderfloor()
{
}


void CUnderfloor::Init(int Level)
{
	if (Level == 1)
	{
		m_pImg = cvLoadImage("图像资源/第一关/地面.jpg", 1);
		m_size = cvGetSize(m_pImg);
		m_position.x = 1;
		m_position.y = 270;
		m_pitfall[0][0] = 1027;
		m_pitfall[0][1] = 1117;
		m_pitfall[1][0] = 1942;
		m_pitfall[1][1] = 2032;
	}
	else if (Level == 3)
	{
		m_pImg = cvLoadImage("图像资源/第三关/地面.jpg", 1);
		m_size = cvGetSize(m_pImg);
		m_position.x = 1;
		m_position.y = 270;
	}
}

void CUnderfloor::Init()
{

	m_size = cvGetSize(m_pImg);
	m_position.x = 1;
	m_position.y = 270;

}


int CUnderfloor::CollideJudge(CMan *man,int Level)
{

	if (Level == 1)
	{
		if ((man->m_position.x + man->m_size.width / 2 > m_pitfall[0][0]
			&& man->m_position.x + man->m_size.width / 2 < m_pitfall[0][1])
			|| (man->m_position.x + man->m_size.width / 2 > m_pitfall[1][0]
			&& man->m_position.x + man->m_size.width / 2 < m_pitfall[1][1]))//人物的x坐标处于没有支撑力的两个范围
		{
			if ((man->m_position.x + man->m_size.width / 2 > m_pitfall[1][0]
				&& man->m_position.x + man->m_size.width / 2 < m_pitfall[1][1]))//人物的x坐标处于没有支撑力的第二个范围
			{
				m_pImg = cvLoadImage("图像资源/第一关/地面右凹陷.jpg", 1);
			}
		}
		else//人物的x坐标处于有支撑力的范围
		{
			if (man->m_position.y + man->m_size.height + 10> m_position.y
				&&man->m_position.y + man->m_size.height - 10 < m_position.y)//人物的y坐标也处于有支撑力的范围
			{
				man->m_position.y = m_position.y - man->m_size.height;//精准对齐，使人物的脚踩到地上，而不是中间隔着空气
				return 1;//返回“人物收到支撑”的信息
			}
		}

		if (man->m_position.y > 330)//掉下悬崖
		{
			Function_death(man);//死亡
		}
	}
	else if (Level == 2)
	{
		if (man->m_position.y + man->m_size.height + 10 > m_position.y
			&&man->m_position.y + man->m_size.height - 10 < m_position.y)//人物的x坐标处于没有支撑力的第二个范围
		{
			if ((man->m_position.x + man->m_size.width / 2 > m_pitfall[1][0]))
				//&& man->m_position.x + man->m_size.width / 2 < m_pitfall[1][1]))
			{
				/*if (cvWaitKey(2000)==32)
				{*/
				man->Move();
				m_pImg = cvLoadImage("图像资源/第二关/地面下陷.jpg", 1);

				//}
				return 1;
			}
			else
			{
				man->m_position.y = m_position.y - man->m_size.height;//精准对齐，使人物的脚踩到地上，而不是中间隔着空气
				return 1;//返回“人物收到支撑”的信息
			}
		}
		if (man->m_position.y >= 280)//掉下悬崖
		{
			Function_death(man);//死亡
		}
	}
	else if (Level == 3)
	{
		//第二场景测试
		//if (man->m_position.x > 0 && man->m_position.x + man->m_size.width < 920)
			//return 0;
		//悬崖无支持力
		if (man->m_position.x > 830 && man->m_position.x + man->m_size.width < 920)
			return 0;
		else if (man->m_position.y + man->m_size.height + 10> m_position.y
			&&man->m_position.y + man->m_size.height - 10 < m_position.y)//人物的y坐标也处于有支撑力的范围
		{
			man->m_position.y = m_position.y - man->m_size.height;//精准对齐，使人物的脚踩到地上，而不是中间隔着空气
			return 1;//返回“人物收到支撑”的信息
		}
		
	}
	return 0;
}


int CUnderfloor::CollideJudge(CMan *man)
{
	if (Level == 1)
	{
		if ((man->m_position.x + man->m_size.width / 2 > m_pitfall[0][0]
			&& man->m_position.x + man->m_size.width / 2 < m_pitfall[0][1])
			|| (man->m_position.x + man->m_size.width / 2 > m_pitfall[1][0]
			&& man->m_position.x + man->m_size.width / 2 < m_pitfall[1][1]))//人物的x坐标处于没有支撑力的两个范围
		{
			if ((man->m_position.x + man->m_size.width / 2 > m_pitfall[1][0]
				&& man->m_position.x + man->m_size.width / 2 < m_pitfall[1][1]))//人物的x坐标处于没有支撑力的第二个范围
			{
				m_pImg = cvLoadImage("图像资源/第一关/地面右凹陷.jpg", 1);
			}
		}
		else//人物的x坐标处于有支撑力的范围
		{
			if (man->m_position.y + man->m_size.height + 10> m_position.y
				&&man->m_position.y + man->m_size.height - 10 < m_position.y)//人物的y坐标也处于有支撑力的范围
			{
				man->m_position.y = m_position.y - man->m_size.height;//精准对齐，使人物的脚踩到地上，而不是中间隔着空气
				return 1;//返回“人物收到支撑”的信息
			}
		}
		if (man->m_position.y > 330)//掉下悬崖
		{
			Function_death(man);//死亡
		}

	}
	else if (Level == 2)
	{
		if (man->m_position.y + man->m_size.height + 10 > m_position.y
			&&man->m_position.y + man->m_size.height - 10 < m_position.y)//人物的x坐标处于没有支撑力的第二个范围
		{
			if ((man->m_position.x + man->m_size.width / 2 > m_pitfall[1][0]))
				//&& man->m_position.x + man->m_size.width / 2 < m_pitfall[1][1]))
			{
				/*if (cvWaitKey(2000)==32)
				{*/
				man->Move();
				m_pImg = cvLoadImage("图像资源/第二关/地面下陷.jpg", 1);

				//}
				return 1;
			}
			else
			{
				man->m_position.y = m_position.y - man->m_size.height;//精准对齐，使人物的脚踩到地上，而不是中间隔着空气
				return 1;//返回“人物收到支撑”的信息
			}
		}
		if (man->m_position.y >= 280)//掉下悬崖
		{
			Function_death(man);//死亡
		}
	}
	return 0;
}


void CUnderfloor::Function_death(CMan* man)
{
	man->life = 0;
}


void CUnderfloor::Function_stopjump(CMan* man)
{
	if (man->V > 0)
	{
		man->V = -man->V;
	}
}