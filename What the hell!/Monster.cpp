#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster(int x,int y,int jump)
{
	jumptime = jump;
	m_position.x = x;
	m_position.y = y;
}


CMonster::CMonster()
{
}


CMonster::~CMonster()
{
}


void CMonster::Init(int Level)
{
	if (Level == 1)
	{
		m_pImg = cvLoadImage("图像资源/第一关/怪物.jpg", 1);
		m_size = cvGetSize(m_pImg);
		v = 0;
	}
	else if (Level == 3)
	{
		
	}
}


int CMonster::CollideJudge(CMan* man,int Level)
{
	if (Level == 1)
	{
		if (man->m_position.x + man->m_size.width / 2 > m_position.x
			&&man->m_position.x + man->m_size.width / 2 < m_position.x + m_size.width
			&&man->m_position.y + man->m_size.height / 2 < m_position.y + m_size.height
			&&man->m_position.y + man->m_size.height / 2 > m_position.y)//典型“人中物中”碰撞检测的if语句，含义是人物的中心，是否在小怪的矩形框内
		{
			Function_death(man);//满足if语句则碰撞成功，运行此碰撞成功的话所产生的后果，死亡（功能函数就插在这）
		}
		Move(man);//一开始4只小怪是呆在原地不动的，每一帧，小怪都会计算人物距离自己有多远，当距离达标了，小怪就开始向左移动。
	}
	return 0;//小怪不会对人物有支撑力，返回0，有支撑力详情请看CUnderfloor的CollideJudge
}


void CMonster::Function_death(CMan* man)
{
	man->life = 0;
}


void CMonster::Move(CMan* man)
{
	if (man->m_position.x + 640 > m_position.x)
	{
		m_position.x -= 5;
		if (man->m_position.x + 60 > m_position.x)
		{
			if (jumptime == 1)
			{
				jumptime = 0;
				v = 13;
			}
		}
	}
	if (jumptime== 0)
	{
		if (v >= -13)
		{
			m_position.y -= v;
			v--;
		}
	}
	
}
