#include "stdafx.h"
#include "Horse_t4.h"


CHorse_t4::CHorse_t4()
{
}


CHorse_t4::~CHorse_t4()
{
}

void CHorse_t4::Init()
{
	m_pImg = cvLoadImage("ͼ����Դ/���Ĺ�/����.jpg", 1);
	m_size = cvGetSize(m_pImg);
	m_position.x = 1250;
	m_position.y = 210;
}
