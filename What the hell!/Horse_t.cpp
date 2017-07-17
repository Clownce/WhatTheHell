#include "stdafx.h"
#include "Horse_t.h"


CHorse_t::CHorse_t()
{
}


CHorse_t::CHorse_t(int x, int level)
{
	m_position.x = x;
	if (level == 1)
	{
		m_pImg = cvLoadImage("图像资源/第一关/真马.jpg", 1);
	}
	else
	{
		m_pImg = cvLoadImage("图像资源/第二关/真马.jpg", 1);
	}
}

CHorse_t::~CHorse_t()
{
}


void CHorse_t::Init(int Level)
{
	if (Level == 1)
	{
		m_pImg = cvLoadImage("图像资源/第一关/真马.jpg", 1);
		m_size = cvGetSize(m_pImg);
		m_position.x = 23;
		m_position.y = 210;
	}
	else if (Level == 3)
	{
		m_pImg = cvLoadImage("图像资源/第三关/真马.jpg", 1);
		m_size = cvGetSize(m_pImg);
		m_position.x = 1720;
		m_position.y = 215;
	}
}


void CHorse_t::Init()
{

	m_size = cvGetSize(m_pImg);

	m_position.y = 210;
}

int CHorse_t::CollideJudge(CMan* man,int Level)
{
	if (Level == 1)
	{
		if (man->m_position.x + man->m_size.width / 2 > m_position.x
			&&man->m_position.x + man->m_size.width / 2 < m_position.x + m_size.width
			&&man->m_position.y + man->m_size.height / 2 < m_position.y + m_size.height
			&&man->m_position.y + man->m_size.height / 2 > m_position.y)
		{
			Success(man);
		}
	}
	else if (Level == 3)
	{
		if (m_position.x == 1720 && (man->m_position.x + man->m_size.width) > 1720 && (man->m_position.x + man->m_size.width) < 1730 && man->m_position.y > 200 && man->m_position.y < 245)
		{
			man->life = 0;
		}
		if (m_position.x == 1720 && man->m_position.x > 1750 && man->m_position.y > 230 && man->m_position.y < 245)
		{
			Success(man);
		}
	}
	return 0;
}

int CHorse_t::CollideJudge(CMan* man)
{
	if (man->m_position.x + man->m_size.width / 2 > m_position.x
		&&man->m_position.x + man->m_size.width / 2 < m_position.x + m_size.width
		&&man->m_position.y + man->m_size.height / 2 < m_position.y + m_size.height
		&&man->m_position.y + man->m_size.height / 2 > m_position.y)
	{
		Success(man);
	}
	return 0;
}


void CHorse_t::Success(CMan* man)
{
	man->success = 1;
}
