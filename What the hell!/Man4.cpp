#include "stdafx.h"
#include "Man4.h"


CMan4::CMan4()
{
}


CMan4::~CMan4()
{
}

void CMan4::Init()
{
	m_pImg_right = cvLoadImage("ͼ����Դ/���Ĺ�/��ɮ��.jpg", 1);
	m_pImg_left = cvLoadImage("ͼ����Դ/���Ĺ�/��ɮ��.jpg", 1);
	m_pImg = m_pImg_right;
	m_size = cvGetSize(m_pImg);
	m_position.x = 50;
	m_position.y = 239;
	F_down = 1;
	F_up = 0;//����
	F_up_time = 0;//����
	F_other = 0;
	F = -1;
	life = 1;
	success = 0;
}

int CMan4::Jumpcontual()
{
	m_position.y -= SumFtoV();//����Ĵ�ֱ�����ƶ��˺����ķ���ֵ
	if (m_position.y < 0)
	{
		m_position.y = 0;
	}
	return 0;
}
