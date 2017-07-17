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
	m_pImg = cvLoadImage("ͼ����Դ/���Ĺ�/����.jpg", 1);
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
		&& man->m_position.x + man->m_size.width / 2 < m_pitfall[1][1]))//�����x���괦��û��֧������������Χ
	{
		if (man->m_position.y > 330)//��������
		{
			Function_death(man);//����
		}
		return 0;
	}
	else//�����x���괦����֧�����ķ�Χ
	{
		if (man->m_position.y + man->m_size.height + 10 > m_position.y
			&&man->m_position.y + man->m_size.height - 10 < m_position.y)//�����y����Ҳ������֧�����ķ�Χ
		{
			man->m_position.y = m_position.y - man->m_size.height;//��׼���룬ʹ����ĽŲȵ����ϣ��������м���ſ���
			return 1;//���ء������յ�֧�š�����Ϣ
		}
	}
	return 0;
}

void CUnderfloor4::Function_death(CMan* man)
{
	man->life = 0;
}
