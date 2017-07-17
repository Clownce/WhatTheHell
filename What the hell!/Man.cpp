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
	m_pImg_right = cvLoadImage("ͼ����Դ/��һ��/��ɮ��.jpg", 1);
	m_pImg_left = cvLoadImage("ͼ����Դ/��һ��/��ɮ��.jpg", 1);
	m_pImg = m_pImg_right;
	m_size = cvGetSize(m_pImg);
	m_position.x = 580;
	m_position.y = 239;
	F_down = 1;
	F_up = 0;//����
	F_up_time = 0;//����
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
		m_pImg_right = cvLoadImage("ͼ����Դ/��һ��/��ɮ��.jpg", 1);
		m_pImg_left = cvLoadImage("ͼ����Դ/��һ��/��ɮ��.jpg", 1);
		m_pImg = m_pImg_right;
		m_size = cvGetSize(m_pImg);
		m_position.x = 580;
		m_position.y = 239;
		F_down = 1;
		F_up = 0;//����
		F_up_time = 0;//����
		F_other = 0;
		F = -1;
		life = 1;
		success = 0;
		l_speed = 4;
		r_speed = 4;
	}
	else if (Level == 3)
	{
		m_pImg_right = cvLoadImage("ͼ����Դ/������/��ɮ��.jpg", 1);
		m_pImg_left = cvLoadImage("ͼ����Դ/������/��ɮ��.jpg", 1);
		m_pImg = m_pImg_right;
		m_size = cvGetSize(m_pImg);
		m_position.x = 30;
		m_position.y = 241;
		F_down = 1;
		F_up = 0;//����
		F_up_time = 0;//����
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
				CV_IMAGE_ELEM(m_pImg, uchar, height, width * 3 + 1) > 250)//��������ص�Ϊ��ɫ����Чɫ��
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
	int size=0;//size�������ƶ��ľ��룬�����������ŷ�����Ϣ
	if (::GetAsyncKeyState(VK_RIGHT) && 0x8000 || ::GetAsyncKeyState('D') && 0x8000)//������յ���������
	{
		m_position.x += r_speed;//λ�������ƶ�
		size = 4;//size���ű䣬��ס������ƶ���Ϣ������return
		m_pImg = m_pImg_right;//��ʱ�������������ߵ�ͼƬ
	}
	if (::GetAsyncKeyState(VK_LEFT) && 0x8000 || ::GetAsyncKeyState('A') && 0x8000)//ͬ��
	{
		m_position.x -= l_speed;
		size = -4;
		m_pImg = m_pImg_left;
	}
	if (::GetAsyncKeyState(VK_SPACE) && 0x8000)//�����յ���Ծ��
	{
		if (F == 0)//���������Ϊ0������֧����ʱ�����ܼ�����Ծ�Ĺ���
		{
			V = 15;//������Ծ���ܣ���������һ�����ϵĳ��ٶ�15
		}
	}
	Jumpcontual();//������Ծ���ƺ���
	return size;//����size�����ڴ���CBack��playersee_remove�����Ĳ���
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
	m_position.y -= SumFtoV();//����Ĵ�ֱ�����ƶ��˺����ķ���ֵ
	return 0;
}
