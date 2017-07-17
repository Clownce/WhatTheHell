#include "stdafx.h"
#include "Brick.h"

CBrick::CBrick(int x, int y,int flag)
{
	TRIGGER_SIGNAL = false;
	m_position.x = x;
	m_position.y = y;
	if (flag == 1) m_pImg = cvLoadImage("ͼ����Դ/������/����1.jpg", 1);
	else if (flag == 2) m_pImg = cvLoadImage("ͼ����Դ/������/����1.jpg", 1);
	else if (flag == 3) m_pImg = cvLoadImage("ͼ����Դ/������/�ʺ�1.jpg", 1);
	else if (flag == 4) m_pImg = cvLoadImage("ͼ����Դ/������/ǽ1.jpg", 1);
	else if (flag == 5) m_pImg = cvLoadImage("ͼ����Դ/������/ǽ2.jpg", 1);
	else if (flag == 6) m_pImg = cvLoadImage("ͼ����Դ/������/ǽ3.jpg", 1);
	else if (flag == 7) m_pImg = cvLoadImage("ͼ����Դ/������/ǽ4.jpg", 1);
	else if (flag == 9) m_pImg = cvLoadImage("ͼ����Դ/������/����_ש.jpg", 1);
	else if (flag == 10) m_pImg = cvLoadImage("ͼ����Դ/������/��.jpg", 1);

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
		m_pImg = cvLoadImage("ͼ����Դ/��һ��/δײ_ש.jpg", 1);
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
	m_pImg = cvLoadImage("ͼ����Դ/��һ��/δײ_ש.jpg", 1);
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
					m_pImg = cvLoadImage("ͼ����Դ/��һ��/��ײ_ש.jpg", 1);
				man->F_up = -10;
			}
			if (man->m_position.y + man->m_size.height + 10 > m_position.y
				&&man->m_position.y + man->m_size.height - 10 < m_position.y)//�����Ƿ�Ӵ����棬������֧������
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
		//��������
		if (m_position.x==100&&m_pImg->height == 30 && man->m_position.x + man->m_size.width > 100 && man->m_position.x + man->m_size.width < 160 && man->m_position.y + man->m_size.height < 271 && man->m_position.y + man->m_size.height>241)
		{
			m_pImg = cvLoadImage("ͼ����Դ/������/����2.jpg", 1);
			TRIGGER_SIGNAL = true;
		}
		//��������
		if (m_position.x == 470&&man->m_position.x + man->m_size.width > 470 && man->m_position.x < 530 && man->m_position.y + man->m_size.height < 271 && man->m_position.y + man->m_size.height>221)
		{
			if (m_pImg->width == 60)
			{
				m_pImg = cvLoadImage("ͼ����Դ/������/����2.jpg", 1);
				m_size = cvGetSize(m_pImg);
			}
			man->life = 0;
			Function_stopjump(man);
		}
		//�����ʺ�ש
		if (m_position.x == 650 && man->m_position.x + man->m_size.width>655 && man->m_position.x < 705 && man->m_position.y < 190 && man->m_position.y >180)
		{
			m_pImg = cvLoadImage("ͼ����Դ/������/�ʺ�2.jpg", 1);
			man->life = 0;
			Function_stopjump(man);
		}
		//�ʺ�ש�ṩ֧����
		if (m_position.x == 650 && man->m_position.y + man->m_size.height + 10> 165 && man->m_position.y + man->m_size.height - 10<165 && man->m_position.x + man->m_size.width / 2 >= 650 && man->m_position.x + man->m_size.width / 2 <= 710)
		{
			man->m_position.y = 135;
			Function_stopjump(man);
			return 1;
		}
		//ǽ1���赲
		if (m_position.x == 800 &&man->m_position.x > 770 && man->m_position.x < 785 && man->m_position.y + man->m_size.height > 120)
			man->m_position.x = 770;
		//ǽ2���赲
		if (m_position.x == 770 && man->m_position.x > 740 && man->m_position.x < 755 && man->m_position.y + man->m_size.height > 90 && man->m_position.y <120)
			man->m_position.x = 740;
		//ǽ2�ṩ֧����
		if (m_position.x == 770 && man->m_position.y + man->m_size.height + 10> 90 && man->m_position.y + man->m_size.height - 10<90 && man->m_position.x + man->m_size.width / 2 >= 770 && man->m_position.x + man->m_size.width / 2 <= 830)
		{
			man->m_position.y = 60;
			Function_stopjump(man);
			return 1;
		}
		//ǽ1��2���赲
		if (m_position.x == 800 && man->m_position.x < 830 && man->m_position.x > 815 && man->m_position.y + man->m_size.height > 90)
			man->m_position.x = 830;
		//ǽ3���赲
		if (m_position.x == 920 && man->m_position.x > 890 && man->m_position.x < 905 && man->m_position.y + man->m_size.height > 60 && man->m_position.y <270)
			man->m_position.x = 890;
		//�ڶ�����
		//���������ǽ����
		if (m_position.x == 980 && man->m_position.x > 980 && man->m_position.x < 1390 && man->m_position.y < 50)
		{
			m_pImg = cvLoadImage("ͼ����Դ/������/ǽ4����.jpg", 1);
			man->life = 0;
			Function_stopjump(man);
		}
		//����1�ṩ֧����
		if (m_position.x == 1150 && (man->m_position.x + man->m_size.width / 2)>1150 && (man->m_position.x + man->m_size.width / 2)<1210
			&& (man->m_position.y + man->m_size.height + 10)>200 && (man->m_position.y + man->m_size.height - 10)<200)
		{
			man->m_position.y = 170;
			Function_stopjump(man);
			return 1;
		}
		//����2�ṩ֧����
		if (m_position.x == 1240 && (man->m_position.x + man->m_size.width / 2)>1240 && (man->m_position.x + man->m_size.width / 2)<1300
			&& (man->m_position.y + man->m_size.height + 10)>150 && (man->m_position.y + man->m_size.height - 10)<150)
		{
			man->m_position.y = 120;
			Function_stopjump(man);
			return 1;
		}
		//����3�ṩ֧����
		if (m_position.x == 1330 && (man->m_position.x + man->m_size.width / 2)>1330 && (man->m_position.x + man->m_size.width / 2)<1390
			&& (man->m_position.y + man->m_size.height + 10)>200 && (man->m_position.y + man->m_size.height - 10)<200)
		{
			man->m_position.y = 170;
			Function_stopjump(man);
			return 1;
		}
		//����������������ש
		if (m_position.x == 1650 && man->m_position.x + man->m_size.width>1655 && man->m_position.x < 1675 && man->m_position.y < 199 && man->m_position.y >191)
		{
			if (TRIGGER_SIGNAL == false)
			{
				m_pImg = cvLoadImage("ͼ����Դ/������/��ײ_ש.jpg", 1);
				TRIGGER_SIGNAL = true;
			}
			
			Function_stopjump(man);
		}
		//��ײש�ṩ֧����
		else if (m_position.x == 1650&&TRIGGER_SIGNAL==true && (man->m_position.x + man->m_size.width / 2)>1650 && (man->m_position.x + man->m_size.width / 2)<1680
			&& (man->m_position.y + man->m_size.height + 10)>165 && (man->m_position.y + man->m_size.height - 10)<165)
		{
			man->m_position.y = 135;
			Function_stopjump(man);
			return 1;
		}
		//�������
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
			m_pImg = cvLoadImage("ͼ����Դ/��һ��/��ײ_ש.jpg", 1);
			man->F_up = -10;
		}
		if (man->m_position.y + man->m_size.height + 10 > m_position.y
			&&man->m_position.y + man->m_size.height - 10 < m_position.y)//�����Ƿ�Ӵ����棬������֧������
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
