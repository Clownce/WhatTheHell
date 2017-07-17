#include "stdafx.h"
#include "Bomb4.h"


CBomb4::CBomb4()
{
}

CBomb4::CBomb4(int x, int y, int num)
{
	nub = num;
	m_position.x = x;
	m_position.y = y;
}


CBomb4::~CBomb4()
{
}

void CBomb4::Init()
{
	if (nub == 0)
		m_pImg = cvLoadImage("ͼ����Դ/���Ĺ�/������.jpg", 1);
	if (nub == 1)
		m_pImg = cvLoadImage("ͼ����Դ/���Ĺ�/������.jpg", 1);
	m_size = cvGetSize(m_pImg);
	move = false;
}

int CBomb4::CollideJudge(CMan* man)
{
	if (man->m_position.x + man->m_size.width > m_position.x
		&&man->m_position.x + man->m_size.width / 2 < m_position.x + m_size.width
		&&man->m_position.y + man->m_size.width / 2 < m_position.y + m_size.height
		&&man->m_position.y + man->m_size.width > m_position.y)//���͡��������С���ײ����if��䣬��������������ģ��Ƿ���С�ֵľ��ο���
	{
		Function_death(man);//����if�������ײ�ɹ������д���ײ�ɹ��Ļ��������ĺ�������������ܺ����Ͳ����⣩
	}
	Move(man);//һ��ʼ4ֻС���Ǵ���ԭ�ز����ģ�ÿһ֡��С�ֶ��������������Լ��ж�Զ�����������ˣ�С�־Ϳ�ʼ�����ƶ���
	return 0;//С�ֲ����������֧����������0����֧���������뿴CUnderfloor��CollideJudge
}

void CBomb4::Function_death(CMan* man)
{
	man->life = 0;
}

void CBomb4::Move(CMan* man)
{
	if (man->m_position.x + 50 > m_position.x)
		move = true;
	if (move == true)
	{
		if (nub == 0)
			m_position.y -= 9;
		if (nub == 1)
			m_position.y += 9;
	}

}
