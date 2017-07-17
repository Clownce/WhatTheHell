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
		m_pImg = cvLoadImage("ͼ����Դ/�ڶ���/����.jpg", 1);
	}
	else if (level == 1)
	{
		m_pImg = cvLoadImage("ͼ����Դ/��һ��/����.jpg", 1);
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
		m_pImg = cvLoadImage("ͼ����Դ/��һ��/����.jpg", 1);
		m_size = cvGetSize(m_pImg);
		m_position.x = 85;
		m_position.y = 30;
	}
	else if (Level == 3)
	{
		m_pImg = cvLoadImage("ͼ����Դ/������/������1.jpg", 1);
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
				m_pImg = cvLoadImage("ͼ����Դ/��һ��/�������.jpg", 1);
				Function_death(man);
				Function_stopjump(man);
			}
		}
	}
	else if (Level == 3)
	{
		//������������ָʾ�ƶ�����
		if (m_position.y==55&&man->m_position.x > 140 && man->m_position.x < 470 && man->m_position.y < 140)
		{
			m_pImg = cvLoadImage("ͼ����Դ/������/������2.jpg", 1);
			Function_death(man);
			Function_stopjump(man);
		}
		//��������ѹ��
		else if (man->m_position.x > 140 && man->m_position.x < 470 && m_position.y>166 && m_position.y < 197)
		{
			m_position.y = 197;
			Function_death(man);
			Function_stopjump(man);
		}
		//���������£���Ӵ�
		else if (m_position.y == 200 && man->m_position.x > 140 && man->m_position.x < 155 && man->m_position.y + man->m_size.height > 200)
			man->m_position.x = 140;
		//�ҽӴ�
		else if (m_position.y == 200 && man->m_position.x < 470 && man->m_position.x > 455 && man->m_position.y + man->m_size.height>200)
			man->m_position.x = 470;
		//�ṩ֧����
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
				m_pImg = cvLoadImage("ͼ����Դ/��һ��/�������.jpg", 1);
			}
			else if (Level == 2)
			{
				m_pImg = cvLoadImage("ͼ����Դ/�ڶ���/�������.jpg", 1);
			}
			Function_death(man);
			Function_stopjump(man);
		}
		if (man->m_position.y + man->m_size.height + 10 > m_position.y
			&&man->m_position.y + man->m_size.height - 10 < m_position.y)//�����Ƿ�Ӵ����棬������֧������
		{
			if (Level == 2 && Time < 2)
			{
				m_position.x = m_position.x + 120;
				Time++;
			}
			//man->m_position.y = m_position.y - man->m_size.height;//���������˼�ǣ������ͷ��������Ʒ��ͷ����������ߵĸ߶�
			//������������֧�ţ����Ҳ�֪��ԭ�򰡣��벻ͨ��
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

