#include "stdafx.h"
#include "Run4.h"


CRun4::CRun4()
{
	CManage4 manage;
	int movesize;
	int gameover = 0;
	cvNamedWindow("test", 1);
	for (;;)
	{
		manage.ElementSum();
		manage.Init();
		gameover = 0;
		for (;;)
		{
			if (gameover == -2)
			{
				for (;;)
				{
					if (::GetAsyncKeyState('R') && 0x8000)
					{
						break;
					}
				}
				break;
			}
			gameover += manage.FunctionRun();                                                      /////////
			manage.FPStime(30);//刷新的等待时间                                                   //
			movesize = manage.man.Move();//按键接收附带人物移动的计算                             //数据变化的计算
			manage.back.player_seeRemove(&manage.man, movesize);//重新计算玩家可看见区域          //
			cvSetImageROI(manage.back.m_pImg_show, manage.back.player_see);//设置玩家可看见区域   /////////		

			/////////
			//
			manage.Drow2Back();//把所有的元素绘制到背景                                           //绘制当前数据
			cvShowImage("test", manage.back.m_pImg_show);                                         //
			/////////


			cvResetImageROI(manage.back.m_pImg_show);//释放玩家能看见区域 
			cvCopy(manage.back.m_pImg_all, manage.back.m_pImg_show);//清洗背景
		}
	}
}


CRun4::~CRun4()
{
}

