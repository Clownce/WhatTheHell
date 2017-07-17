#include "stdafx.h"
#include "Man.h"


CMan::CMan()
{
}


CMan::~CMan()
{
}

void CMan::Init()
{
	m_pImg_right = cvLoadImage("图像资源/第一关/唐僧右.jpg", 1);
	m_pImg_left = cvLoadImage("图像资源/第一关/唐僧左.jpg", 1);
	m_pImg = m_pImg_right;
	m_size = cvGetSize(m_pImg);
	m_position.x = 580;
	m_position.y = 239;
	F_down = 1;
	F_up = 0;//无用
	F_up_time = 0;//无用
	F_other = 0;
	F = -1;
	life = 1;
	success = 0;
	l_speed = 4;
	r_speed = 4;
}

void CMan::Init(int Level)
{
	if (Level == 1)
	{
		m_pImg_right = cvLoadImage("图像资源/第一关/唐僧右.jpg", 1);
		m_pImg_left = cvLoadImage("图像资源/第一关/唐僧左.jpg", 1);
		m_pImg = m_pImg_right;
		m_size = cvGetSize(m_pImg);
		m_position.x = 580;
		m_position.y = 239;
		F_down = 1;
		F_up = 0;//无用
		F_up_time = 0;//无用
		F_other = 0;
		F = -1;
		life = 1;
		success = 0;
		l_speed = 4;
		r_speed = 4;
	}
	else if (Level == 3)
	{
		m_pImg_right = cvLoadImage("图像资源/第三关/唐僧右.jpg", 1);
		m_pImg_left = cvLoadImage("图像资源/第三关/唐僧左.jpg", 1);
		m_pImg = m_pImg_right;
		m_size = cvGetSize(m_pImg);
		m_position.x = 30;
		m_position.y = 241;
		F_down = 1;
		F_up = 0;//无用
		F_up_time = 0;//无用
		F_other = 0;
		F = -1;
		life = 1;
		success = 0;
		l_speed = 4;
		r_speed = 4;
	}
}


void CMan::Draw2Back(IplImage* pBack, CvPoint start)
{
	for (int height = 1; height < m_size.height; height++)
	{
		for (int width = 1; width < m_size.width; width++)
		{
			if (height + start.y<1 || height + start.y>329 || width + start.x<1 || width + start.x>2274)
			{
				continue;
			}
			if (CV_IMAGE_ELEM(m_pImg, uchar, height, width * 3 + 1)>250 && CV_IMAGE_ELEM(m_pImg, uchar, height, width * 3 + 0)>250 &&
				CV_IMAGE_ELEM(m_pImg, uchar, height, width * 3 + 1) > 250)//如果此像素点为白色（无效色）
			 {
				continue;
		     }
 			CV_IMAGE_ELEM(pBack, uchar, height + start.y, (width + start.x) * 3 + 0) = CV_IMAGE_ELEM(m_pImg, uchar, height, width * 3 + 0);
			CV_IMAGE_ELEM(pBack, uchar, height + start.y, (width + start.x) * 3 + 1) = CV_IMAGE_ELEM(m_pImg, uchar, height, width * 3 + 1);
			CV_IMAGE_ELEM(pBack, uchar, height + start.y, (width + start.x) * 3 + 2) = CV_IMAGE_ELEM(m_pImg, uchar, height, width * 3 + 2);
			
		}
	}
}


int CMan::Move()
{
	int size=0;//size是人物移动的距离，正负还包含着方向信息
	if (::GetAsyncKeyState(VK_RIGHT) && 0x8000 || ::GetAsyncKeyState('D') && 0x8000)//如果接收到“→”键
	{
		m_position.x += r_speed;//位置向右移动
		size = 4;//size跟着变，存住人物的移动信息，用于return
		m_pImg = m_pImg_right;//这时候用人物像右走的图片
	}
	if (::GetAsyncKeyState(VK_LEFT) && 0x8000 || ::GetAsyncKeyState('A') && 0x8000)//同理
	{
		m_position.x -= l_speed;
		size = -4;
		m_pImg = m_pImg_left;
	}
	if (::GetAsyncKeyState(VK_SPACE) && 0x8000)//当接收到跳跃键
	{
		if (F == 0)//当人物合力为0，即被支撑着时，才能激活跳跃的功能
		{
			V = 15;//激活跳跃功能，让人物有一个向上的初速度15
		}
	}
	Jumpcontual();//这是跳跃控制函数
	return size;//返回size，用于代入CBack中playersee_remove函数的参数
}


int CMan::SumFtoV()
{
	F = F_up - F_down + F_other;
	if (F == 0)
	{
		if (V<1)
		V = 0;
	}
	if (F < 0)
	{
		V = V - 1;
	}
	return V;
}


int CMan::Jumpcontual()
{
	m_position.y -= SumFtoV();//人物的垂直坐标移动此函数的返回值
	return 0;
}
