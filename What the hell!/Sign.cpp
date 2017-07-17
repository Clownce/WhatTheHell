#include "stdafx.h"
#include "Sign.h"


CSign::CSign()
{
}

CSign::CSign(int x, int y, int level)
{
	m_position.x = x;
	m_position.y = y;
	if (level == 2)
	{
		m_pImg = cvLoadImage("图像资源/第二关/标牌.jpg", 1);
	}
	else if (level == 1)
	{
		m_pImg = cvLoadImage("图像资源/第一关/标牌.jpg", 1);
	}
	Level = level;
	Time = 0;
}

CSign::~CSign()
{
}


void CSign::Init(int Level)
{
	if (Level == 1)
	{
		m_pImg = cvLoadImage("图像资源/第一关/标牌.jpg", 1);
		m_size = cvGetSize(m_pImg);
		m_position.x = 85;
		m_position.y = 30;
	}
	else if (Level == 3)
	{
		m_pImg = cvLoadImage("图像资源/第三关/陷阱牌1.jpg", 1);
		m_size = cvGetSize(m_pImg);
		m_position.x = 170;
		m_position.y = 55;
	}
}

void CSign::Init()
{

	m_size = cvGetSize(m_pImg);

}

int CSign::CollideJudge(CMan* man,int Level)
{

	if (Level == 1)
	{
		if (man->m_position.x + man->m_size.width / 2 > m_position.x
			&&man->m_position.x + man->m_size.width / 2 < m_position.x + m_size.width)
		{
			if (man->m_position.y - 7 < m_position.y + m_size.height
				&& man->m_position.y + 7 > m_position.y + m_size.height)
			{
				m_pImg = cvLoadImage("图像资源/第一关/陷阱标牌.jpg", 1);
				Function_death(man);
				Function_stopjump(man);
			}
		}
	}
	else if (Level == 3)
	{
		//上跳碰到陷阱指示牌而死亡
		if (m_position.y==55&&man->m_position.x > 140 && man->m_position.x < 470 && man->m_position.y < 140)
		{
			m_pImg = cvLoadImage("图像资源/第三关/陷阱牌2.jpg", 1);
			Function_death(man);
			Function_stopjump(man);
		}
		//被陷阱牌压死
		else if (man->m_position.x > 140 && man->m_position.x < 470 && m_position.y>166 && m_position.y < 197)
		{
			m_position.y = 197;
			Function_death(man);
			Function_stopjump(man);
		}
		//陷阱牌落下，左接触
		else if (m_position.y == 200 && man->m_position.x > 140 && man->m_position.x < 155 && man->m_position.y + man->m_size.height > 200)
			man->m_position.x = 140;
		//右接触
		else if (m_position.y == 200 && man->m_position.x < 470 && man->m_position.x > 455 && man->m_position.y + man->m_size.height>200)
			man->m_position.x = 470;
		//提供支持力
		if (m_position.y == 200 && man->m_position.y + man->m_size.height +10> 200 && man->m_position.y + man->m_size.height -10<200 && man->m_position.x + man->m_size.width / 2>= 170 && man->m_position.x + man->m_size.width / 2 <= 470)
		{
			man->m_position.y = 170;
			Function_stopjump(man);
			return 1;
		}
	}
	return 0;
}

int CSign::CollideJudge(CMan* man)
{

	if (man->m_position.x + man->m_size.width / 2 > m_position.x
		&&man->m_position.x + man->m_size.width / 2 < m_position.x + m_size.width)
	{
		if (man->m_position.y - 7 < m_position.y + m_size.height
			&& man->m_position.y + 7 > m_position.y + m_size.height)
		{
			if (Level == 1)
			{
				m_pImg = cvLoadImage("图像资源/第一关/陷阱标牌.jpg", 1);
			}
			else if (Level == 2)
			{
				m_pImg = cvLoadImage("图像资源/第二关/陷阱标牌.jpg", 1);
			}
			Function_death(man);
			Function_stopjump(man);
		}
		if (man->m_position.y + man->m_size.height + 10 > m_position.y
			&&man->m_position.y + man->m_size.height - 10 < m_position.y)//计算是否接触地面，才能有支撑力。
		{
			if (Level == 2 && Time < 2)
			{
				m_position.x = m_position.x + 120;
				Time++;
			}
			//man->m_position.y = m_position.y - man->m_size.height;//这句代码的意思是，人物的头，等于物品的头升高人物身高的高度
			//就是它干扰了支撑，但我不知道原因啊，想不通啊
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

void CSign::Function_death(CMan* man)
{
	man->life = 0;
}


void CSign::Function_stopjump(CMan* man)
{
	if (man->V > 0)
	{
		man->V = -man->V;
	}
}

