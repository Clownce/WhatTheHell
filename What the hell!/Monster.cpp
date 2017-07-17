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
		m_pImg = cvLoadImage("ͼ����Դ/��һ��/����.jpg", 1);
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
			&&man->m_position.y + man->m_size.height / 2 > m_position.y)//���͡��������С���ײ����if��䣬��������������ģ��Ƿ���С�ֵľ��ο���
		{
			Function_death(man);//����if�������ײ�ɹ������д���ײ�ɹ��Ļ��������ĺ�������������ܺ����Ͳ����⣩
		}
		Move(man);//һ��ʼ4ֻС���Ǵ���ԭ�ز����ģ�ÿһ֡��С�ֶ��������������Լ��ж�Զ�����������ˣ�С�־Ϳ�ʼ�����ƶ���
	}
	return 0;//С�ֲ����������֧����������0����֧���������뿴CUnderfloor��CollideJudge
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
