#include "stdafx.h"
#include "Back.h"


CBack::CBack()
{
}


CBack::~CBack()
{
}


void CBack::Init(int Level)
{
	if (Level == 1)
	{
		player_see.x = 571;
		player_see.y = 1;
		player_see.width = 570;
		player_see.height = 330;//��ҿɼ�����

		m_pImg_all = cvLoadImage("ͼ����Դ/��һ��/����.jpg", 1);//װ�����ű���
		m_size_all = cvGetSize(m_pImg_all);
		m_pImg_show = cvLoadImage("ͼ����Դ/��һ��/����.jpg", 1);
		m_pImg_death = cvLoadImage("ͼ����Դ/��һ��/����.jpg", 1);
		m_size_death = cvGetSize(m_pImg_death);
	}
	else if (Level == 2)
	{
		player_see.x = 571;
		player_see.y = 1;
		player_see.width = 570;
		player_see.height = 330;//��ҿɼ�����
		m_pImg_all = cvLoadImage("ͼ����Դ/�ڶ���/����.jpg", 1);//װ�����ű���
		m_pImg_show = cvLoadImage("ͼ����Դ/�ڶ���/����.jpg", 1);
		m_size_all = cvGetSize(m_pImg_all);

		m_pImg_death = cvLoadImage("ͼ����Դ/��һ��/����.jpg", 1);
		m_size_death = cvGetSize(m_pImg_death);
	}
	else if (Level == 3)
	{
		player_see.x = 1;
		player_see.y = 1;
		player_see.width = 570;
		player_see.height = 330;//��ҿɼ�����

		m_pImg_all = cvLoadImage("ͼ����Դ/������/����.jpg", 1);//װ�����ű���
		m_size_all = cvGetSize(m_pImg_all);
		m_pImg_show = cvLoadImage("ͼ����Դ/������/����.jpg", 1);
		m_pImg_death = cvLoadImage("ͼ����Դ/��һ��/����.jpg", 1);
		m_size_death = cvGetSize(m_pImg_death);
	}
}


void CBack::Init()
{
	;
}


void CBack::player_seeRemove(CMan *man,int remove_x ,int Level)//����ʵ�ֹ��ܿ��Բ������о�������һ��Ҫ���������ƶ��ľ���remove_x
{
	int right_moveline = player_see.x + (player_see.width * 2 / 3);
	int left_moveline = player_see.x + (player_see.width * 1 / 3);
	if (Level == 1)
	{
		if (man->m_position.x + man->m_size.width / 2<player_see.width)
		{
			player_see.x = 1;
		}
		if (remove_x > 0)
		{
			if (man->m_position.x + man->m_size.width / 2 + remove_x > right_moveline)
			{
				if (player_see.x + player_see.width + remove_x <= m_size_all.width)
				{
					player_see.x += remove_x;
				}
				else
				{
					player_see.x = m_size_all.width - player_see.width;
				}
			}
		}
		if (remove_x < 0)
		{
			if (man->m_position.x + man->m_size.width / 2 + remove_x < left_moveline)
			{
				if (player_see.x + remove_x >= player_see.width)
				{
					player_see.x += remove_x;
				}
				else
				{
					player_see.x = player_see.width;
				}
			}
		}
	}
	else if (Level == 3)
	{
		if (remove_x > 0)
		{
			if (man->m_position.x + man->m_size.width / 2 + remove_x > right_moveline)
			{
				if (man->m_position.x < 980)//��һ����
				{
					if (player_see.x + player_see.width + remove_x <= 980)
					{
						player_see.x += remove_x;
					}
					else
					{
						player_see.x = 980 - player_see.width;
					}
				}
				else//�ڶ�����
				{
					if (player_see.x + player_see.width + remove_x <= m_size_all.width)
					{
						player_see.x += remove_x;
					}
					else
					{
						player_see.x = m_size_all.width - player_see.width;
					}
				}
				
			}
		}
		if (remove_x < 0)
		{
			if (man->m_position.x + man->m_size.width / 2 + remove_x < left_moveline)
			{
				if (man->m_position.x < 980)//��һ����
				{
					if (player_see.x + remove_x >= 0)
					{
						player_see.x += remove_x;
					}
					else
					{
						player_see.x = 0;
					}
					if (man->m_position.x < 0)
						man->m_position.x = 0;
				}
				else//�ڶ�����
				{
					if (player_see.x + remove_x >= 980)
					{
						player_see.x += remove_x;
					}
					else
					{
						player_see.x = 980;
					}
					if (man->m_position.x < 990)
						man->m_position.x = 990;
				}
				
			}
		}
		if (man->m_position.y > 330)//�������º������һ����
		{
			player_see.x = 980;
			man->m_position.x = 1010;
			man->m_position.y = 241;
		}
	}
}


void CBack::player_seeRemove(CMan *man, int remove_x)
{
	int right_moveline = player_see.x + (player_see.width * 2 / 3);
	int left_moveline = player_see.x + (player_see.width * 1 / 3);
	if (man->m_position.x + man->m_size.width / 2<player_see.width)
	{
		player_see.x = 1;
		return;
	}
	if (remove_x > 0)
	{
		if (man->m_position.x + man->m_size.width / 2 + remove_x > right_moveline)
		{
			if (player_see.x + player_see.width + remove_x <= m_size_all.width)
			{
				player_see.x += remove_x;
			}
			else
			{
				player_see.x = m_size_all.width - player_see.width;
			}
		}
	}
	if (remove_x < 0)
	{
		if (man->m_position.x + man->m_size.width / 2 + remove_x < left_moveline)
		{
			if (player_see.x + remove_x >= player_see.width)
			{
				player_see.x += remove_x;
			}
			else
			{
				player_see.x = player_see.width;
			}
		}
	}
}


void CBack::Draw2Back(IplImage* pBack, CvPoint start)//��������ʱ��Ҫ�ڻ����ϻ��Ƶ�ͼƬ
{
	for (int height = 1; height < m_size_death.height; height++)
	{
		for (int width = 1; width < m_size_death.width; width++)
		{
			if (height + start.y<1 || height + start.y>329 || width + start.x<1 || width + start.x>2274)
			{
				continue;
			}
			if (CV_IMAGE_ELEM(m_pImg_death, uchar, height, width * 3 + 1)>250 && CV_IMAGE_ELEM(m_pImg_death, uchar, height, width * 3 + 0)>250 &&
				CV_IMAGE_ELEM(m_pImg_death, uchar, height, width * 3 + 1) > 250)//��������ص�Ϊ��ɫ����Чɫ��
			{
				continue;
			}
			CV_IMAGE_ELEM(pBack, uchar, height + start.y, (width + start.x) * 3 + 0) = CV_IMAGE_ELEM(m_pImg_death, uchar, height, width * 3 + 0);
			CV_IMAGE_ELEM(pBack, uchar, height + start.y, (width + start.x) * 3 + 1) = CV_IMAGE_ELEM(m_pImg_death, uchar, height, width * 3 + 1);
			CV_IMAGE_ELEM(pBack, uchar, height + start.y, (width + start.x) * 3 + 2) = CV_IMAGE_ELEM(m_pImg_death, uchar, height, width * 3 + 2);

		}
	}
}



