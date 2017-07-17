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
	m_pImg_right = cvLoadImage("图像资源/第四关/唐僧右.jpg", 1);
	m_pImg_left = cvLoadImage("图像资源/第四关/唐僧左.jpg", 1);
	m_pImg = m_pImg_right;
	m_size = cvGetSize(m_pImg);
	m_position.x = 50;
	m_position.y = 239;
	F_down = 1;
	F_up = 0;//无用
	F_up_time = 0;//无用
	F_other = 0;
	F = -1;
	life = 1;
	success = 0;
}

int CMan4::Jumpcontual()
{
	m_position.y -= SumFtoV();//人物的垂直坐标移动此函数的返回值
	if (m_position.y < 0)
	{
		m_position.y = 0;
	}
	return 0;
}
