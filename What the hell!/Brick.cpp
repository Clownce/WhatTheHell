#include "stdafx.h"
#include "Brick.h"

CBrick::CBrick(int x, int y,int flag)
{
	TRIGGER_SIGNAL = false;
	m_position.x = x;
	m_position.y = y;
	if (flag == 1) m_pImg = cvLoadImage("图像资源/第三关/开关1.jpg", 1);
	else if (flag == 2) m_pImg = cvLoadImage("图像资源/第三关/西瓜1.jpg", 1);
	else if (flag == 3) m_pImg = cvLoadImage("图像资源/第三关/问号1.jpg", 1);
	else if (flag == 4) m_pImg = cvLoadImage("图像资源/第三关/墙1.jpg", 1);
	else if (flag == 5) m_pImg = cvLoadImage("图像资源/第三关/墙2.jpg", 1);
	else if (flag == 6) m_pImg = cvLoadImage("图像资源/第三关/墙3.jpg", 1);
	else if (flag == 7) m_pImg = cvLoadImage("图像资源/第三关/墙4.jpg", 1);
	else if (flag == 9) m_pImg = cvLoadImage("图像资源/第三关/隐身_砖.jpg", 1);
	else if (flag == 10) m_pImg = cvLoadImage("图像资源/第三关/云.jpg", 1);

	m_size = cvGetSize(m_pImg);
}
CBrick::CBrick()
{
	TRIGGER_SIGNAL = false;
}


CBrick::CBrick(int x, int y)
{
	m_position.x = x;
	m_position.y = y;
	m_suport[0][0] = x;
	m_suport[0][1] = x + 30;

}

CBrick::~CBrick()
{
}


void CBrick::Init(int Level)
{
	TRIGGER_SIGNAL = false;
	if (Level == 1)
	{
		m_pImg = cvLoadImage("图像资源/第一关/未撞_砖.jpg", 1);
		m_size = cvGetSize(m_pImg);
		m_position.x = 850;
		m_position.y = 165;
		m_suport[0][0] = 850;
		m_suport[0][1] = 880;
	}
	else if (Level == 3)
	{
		
	}
}

void CBrick::Init()
{
	m_pImg = cvLoadImage("图像资源/第一关/未撞_砖.jpg", 1);
	m_size = cvGetSize(m_pImg);


}

int CBrick::CollideJudge(CMan* man,int Level)
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
				man->F_up = -10;
			}
			if (man->m_position.y + man->m_size.height + 10 > m_position.y
				&&man->m_position.y + man->m_size.height - 10 < m_position.y)//计算是否接触地面，才能有支撑力。
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
		//碰到开关
		if (m_position.x==100&&m_pImg->height == 30 && man->m_position.x + man->m_size.width > 100 && man->m_position.x + man->m_size.width < 160 && man->m_position.y + man->m_size.height < 271 && man->m_position.y + man->m_size.height>241)
		{
			m_pImg = cvLoadImage("图像资源/第三关/开关2.jpg", 1);
			TRIGGER_SIGNAL = true;
		}
		//碰到西瓜
		if (m_position.x == 470&&man->m_position.x + man->m_size.width > 470 && man->m_position.x < 530 && man->m_position.y + man->m_size.height < 271 && man->m_position.y + man->m_size.height>221)
		{
			if (m_pImg->width == 60)
			{
				m_pImg = cvLoadImage("图像资源/第三关/西瓜2.jpg", 1);
				m_size = cvGetSize(m_pImg);
			}
			man->life = 0;
			Function_stopjump(man);
		}
		//碰到问号砖
		if (m_position.x == 650 && man->m_position.x + man->m_size.width>655 && man->m_position.x < 705 && man->m_position.y < 190 && man->m_position.y >180)
		{
			m_pImg = cvLoadImage("图像资源/第三关/问号2.jpg", 1);
			man->life = 0;
			Function_stopjump(man);
		}
		//问号砖提供支持力
		if (m_position.x == 650 && man->m_position.y + man->m_size.height + 10> 165 && man->m_position.y + man->m_size.height - 10<165 && man->m_position.x + man->m_size.width / 2 >= 650 && man->m_position.x + man->m_size.width / 2 <= 710)
		{
			man->m_position.y = 135;
			Function_stopjump(man);
			return 1;
		}
		//墙1左阻挡
		if (m_position.x == 800 &&man->m_position.x > 770 && man->m_position.x < 785 && man->m_position.y + man->m_size.height > 120)
			man->m_position.x = 770;
		//墙2左阻挡
		if (m_position.x == 770 && man->m_position.x > 740 && man->m_position.x < 755 && man->m_position.y + man->m_size.height > 90 && man->m_position.y <120)
			man->m_position.x = 740;
		//墙2提供支持力
		if (m_position.x == 770 && man->m_position.y + man->m_size.height + 10> 90 && man->m_position.y + man->m_size.height - 10<90 && man->m_position.x + man->m_size.width / 2 >= 770 && man->m_position.x + man->m_size.width / 2 <= 830)
		{
			man->m_position.y = 60;
			Function_stopjump(man);
			return 1;
		}
		//墙1、2右阻挡
		if (m_position.x == 800 && man->m_position.x < 830 && man->m_position.x > 815 && man->m_position.y + man->m_size.height > 90)
			man->m_position.x = 830;
		//墙3左阻挡
		if (m_position.x == 920 && man->m_position.x > 890 && man->m_position.x < 905 && man->m_position.y + man->m_size.height > 60 && man->m_position.y <270)
			man->m_position.x = 890;
		//第二场景
		//碰到上面的墙死亡
		if (m_position.x == 980 && man->m_position.x > 980 && man->m_position.x < 1390 && man->m_position.y < 50)
		{
			m_pImg = cvLoadImage("图像资源/第三关/墙4变形.jpg", 1);
			man->life = 0;
			Function_stopjump(man);
		}
		//跳板1提供支持力
		if (m_position.x == 1150 && (man->m_position.x + man->m_size.width / 2)>1150 && (man->m_position.x + man->m_size.width / 2)<1210
			&& (man->m_position.y + man->m_size.height + 10)>200 && (man->m_position.y + man->m_size.height - 10)<200)
		{
			man->m_position.y = 170;
			Function_stopjump(man);
			return 1;
		}
		//跳板2提供支持力
		if (m_position.x == 1240 && (man->m_position.x + man->m_size.width / 2)>1240 && (man->m_position.x + man->m_size.width / 2)<1300
			&& (man->m_position.y + man->m_size.height + 10)>150 && (man->m_position.y + man->m_size.height - 10)<150)
		{
			man->m_position.y = 120;
			Function_stopjump(man);
			return 1;
		}
		//跳板3提供支持力
		if (m_position.x == 1330 && (man->m_position.x + man->m_size.width / 2)>1330 && (man->m_position.x + man->m_size.width / 2)<1390
			&& (man->m_position.y + man->m_size.height + 10)>200 && (man->m_position.y + man->m_size.height - 10)<200)
		{
			man->m_position.y = 170;
			Function_stopjump(man);
			return 1;
		}
		//从下往上碰到隐身砖
		if (m_position.x == 1650 && man->m_position.x + man->m_size.width>1655 && man->m_position.x < 1675 && man->m_position.y < 199 && man->m_position.y >191)
		{
			if (TRIGGER_SIGNAL == false)
			{
				m_pImg = cvLoadImage("图像资源/第三关/已撞_砖.jpg", 1);
				TRIGGER_SIGNAL = true;
			}
			
			Function_stopjump(man);
		}
		//已撞砖提供支持力
		else if (m_position.x == 1650&&TRIGGER_SIGNAL==true && (man->m_position.x + man->m_size.width / 2)>1650 && (man->m_position.x + man->m_size.width / 2)<1680
			&& (man->m_position.y + man->m_size.height + 10)>165 && (man->m_position.y + man->m_size.height - 10)<165)
		{
			man->m_position.y = 135;
			Function_stopjump(man);
			return 1;
		}
		//陷阱地面
		if ((man->m_position.x + man->m_size.width) > 1150 && man->m_position.x < 1400 && man->m_position.y == 240)
		{
			man->life = 0;
		}
		return 0;
	}
	return 0;
}

int CBrick::CollideJudge(CMan* man)
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
			man->F_up = -10;
		}
		if (man->m_position.y + man->m_size.height + 10 > m_position.y
			&&man->m_position.y + man->m_size.height - 10 < m_position.y)//计算是否接触地面，才能有支撑力。
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


void CBrick::Function_stopjump(CMan* man)
{
	if (man->V > 0)
	{
		man->V = -man->V;
	}
}
