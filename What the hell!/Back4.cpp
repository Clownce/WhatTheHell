#include "stdafx.h"
#include "Back4.h"


CBack4::CBack4()
{
}

CBack4::~CBack4()
{
}

void CBack4::Init()
{
	player_see.x = 1;
	player_see.y = 1;
	player_see.width = 570;
	player_see.height = 330;//玩家可见部分

	m_pImg_all = cvLoadImage("图像资源/第四关/背景.jpg", 1);//装载整张背景
	m_size_all = cvGetSize(m_pImg_all);
	m_pImg_show = cvLoadImage("图像资源/第四关/背景.jpg", 1);
	m_pImg_death = cvLoadImage("图像资源/第四关/死亡.jpg", 1);
	m_size_death = cvGetSize(m_pImg_death);
}

void CBack4::player_seeRemove(CMan *man, int remove_x)
{
	int right_moveline = player_see.x + (player_see.width * 2 / 3);
	int left_moveline = player_see.x + (player_see.width * 1 / 3);
// 	if (remove_x > 0)
// 	{
		if (man->m_position.x + man->m_size.width / 2 + remove_x > right_moveline)
		{
			if (player_see.x + player_see.width + remove_x <= m_size_all.width)
			{
				player_see.x += remove_x;
			}
// 			else
// 			{
// 				player_see.x = m_size_all.width - player_see.width;
// 			}
		}
/*	}*/
// 	if (remove_x < 0)
// 	{
// 		if (man->m_position.x + man->m_size.width / 2 + remove_x < left_moveline)
// 		{
// 			if (player_see.x + remove_x >= player_see.width)
// 			{
// 				player_see.x += remove_x;
// 			}
// 			else
// 			{
// 				player_see.x = player_see.width;
// 			}
// 		}
// 	}
}
