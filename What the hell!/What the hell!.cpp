// What the hell!.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void OnMouse(int event, int x, int y, int flags, void* param);
void OnMouse_Choose(int event, int x, int y, int flags, void* param);////关卡按钮响应
CManage manage;
bool Is_Ready;///////////////////////////////////////////////////////////开始游戏，进入关卡选择
int Level;///////////////////////////////////////////////////////////////选择关卡
CStartPage cs;
int _tmain(int argc, _TCHAR* argv[])
{
	
	Is_Ready = false;
	Level = 0;
	
	
	int movesize;
	int gameover=0;
	/////////////////////////开始界面//////////////////////////////////////
	cvNamedWindow("开始游戏", 1);
	cvMoveWindow("开始游戏",300, 100);
	cvSetMouseCallback("开始游戏", OnMouse, NULL);
	while (true)
	{
		cvShowImage("开始游戏", cs.start_back_img);
		cs.Draw_Button(cs.start_back_img, cs.start_bn_img1, cs.start_bn_pos);
		if (cvWaitKey(10)&&Is_Ready == true)
		{
			break;
		}
	}
	cvDestroyWindow("开始游戏");
	while (1){///////////////////////////////////////////死亡时可返回选择关卡
		//////////////////////////////////////////////////////
		/////////////////选择关卡/////////////////////////////
		///////////////////////////////////////////////////////
		cvNamedWindow("关卡选择", 1);
		cvMoveWindow("关卡选择", 300, 100);
		cvSetMouseCallback("关卡选择", OnMouse_Choose, NULL);
		while (true)//////////////////////////////////////等待关卡选择
		{
			cvShowImage("关卡选择", cs.start_choose_img);
			if (cvWaitKey(10) && Level >=1&&Level<=12)
			{
				break;
			}
		}
		cvDestroyWindow("关卡选择");
		/////////////////////////////////////////////////////////////
		//////////////////////游戏界面///////////////////////////////
		//////////////////////////////////////////////////////////////
		if (Level == 4)
		{
			CRun4* run4 = new CRun4;
			delete run4;
		}
		else
		{
			cvNamedWindow("万万没想到", 1);
			cvMoveWindow("万万没想到", 300, 100);
			for (;;)/////////////////////////////////////////////初始化某关卡   (int i=Level;i<=12;i++,Level++)
			{
				if (Level == 2)
				{
					manage.Init();
				}
				else
				{
                    manage.Init(Level);
				}
				

				gameover = 0;
				for (;;)////////////////////////////////////////当前关卡内部循环（人物移动）
				{
					if (gameover == -2)
					{
						for (;;)////////////////////////////////死亡时等待按键输入
						{
							if (::GetAsyncKeyState('R') && 0x8000)
							{
								break;
							}
							else if (::GetAsyncKeyState('Q') && 0x8000)
							{
								exit(0);
							}
							else if (::GetAsyncKeyState('T') && 0x8000)
							{
								Level = -1;
								break;
							}
						}
						break;
					}
					if (Level == -1) break;
					if (Level == 2)
					{
						gameover += manage.FunctionRun();
						manage.FPStime(30);/////////////////////////////刷新的等待时间
						movesize = manage.man.Move();///////////////////按键接收附带人物移动的计算    //数据变化的计算
						manage.back.player_seeRemove(&manage.man, movesize);////重新计算玩家可看见区域
						cvSetImageROI(manage.back.m_pImg_show, manage.back.player_see);////设置玩家可看见区域  


						manage.Draw2Back();//////////////////////////////把所有的元素绘制到背景     //绘制当前数据
						cvShowImage("万万没想到", manage.back.m_pImg_show);


						cvResetImageROI(manage.back.m_pImg_show);///////////释放玩家能看见区域 
						cvCopy(manage.back.m_pImg_all, manage.back.m_pImg_show);
					}
					else
					{
						gameover += manage.FunctionRun(Level);
						manage.FPStime(30);/////////////////////////////刷新的等待时间
						movesize = manage.man.Move();///////////////////按键接收附带人物移动的计算    //数据变化的计算
						manage.back.player_seeRemove(&manage.man, movesize, Level);////重新计算玩家可看见区域
						cvSetImageROI(manage.back.m_pImg_show, manage.back.player_see);////设置玩家可看见区域  


						manage.Draw2Back(Level);//////////////////////////////把所有的元素绘制到背景     //绘制当前数据
						cvShowImage("万万没想到", manage.back.m_pImg_show);


						cvResetImageROI(manage.back.m_pImg_show);///////////释放玩家能看见区域 
						cvCopy(manage.back.m_pImg_all, manage.back.m_pImg_show);//////清洗背景
					}
					


				}
				if (Level == -1) break;
			}
		}
		
		
	}
	return 0;
}

void OnMouse(int event, int x, int y, int flags, void* param)
{
	/*printf("( %d, %d) ", x, y);
	printf("The Event is : %d ", event);
	printf("The flags is : %d ", flags);
	printf("The param is : %d\n", param);*/
	if (x > 225 && x < 345 && y>200 && y < 250 && event == 1)
	{
		cs.Draw_Button(cs.start_back_img, cs.start_bn_img2, cs.start_bn_pos);
		if (x > 225 && x < 345 && y>200 && y < 250 && event == 4)
			cs.Draw_Button(cs.start_back_img, cs.start_bn_img1, cs.start_bn_pos);
	}
	else if (x > 225 && x < 345 && y>200 && y < 250 && event == 4)
	{
		cs.Draw_Button(cs.start_back_img, cs.start_bn_img1, cs.start_bn_pos);
		Is_Ready = TRUE;
	}
}

void OnMouse_Choose(int event, int x, int y, int flags, void* param)
{
	if (x > 89 && x < 146 && y>89 && y < 121 && event == 4)
	{
		Level = 1;
	}
	else if (x > 186 && x < 244 && y>89 && y < 121 && event == 4)
	{
		Level = 2;
	}
	else if (x > 301 && x < 360 && y>89 && y < 123 && event == 4)
	{
		Level = 3;
	}
	else if (x > 395 && x < 455 && y>89 && y < 124 && event == 4)
	{
		Level = 4;
	}
	else if (x > 89 && x < 146 && y>162 && y < 195 && event == 4)
	{
		Level = 5;
	}
	else if (x > 186 && x < 245 && y>161 && y < 195 && event == 4)
	{
		Level = 6;
	}
	else if (x > 302 && x < 361 && y>163 && y < 196 && event == 4)
	{
		Level = 7;
	}
	else if (x > 396 && x < 456 && y>162 && y < 196 && event == 4)
	{
		Level = 8;
	}
	else if (x > 87 && x < 145 && y>242 && y < 276 && event == 4)
	{
		Level = 9;
	}
	else if (x > 186 && x < 245 && y>242 && y < 277 && event == 4)
	{
		Level = 10;
	}
	else if (x > 304 && x < 363 && y>243 && y < 276 && event == 4)
	{
		Level = 11;
	}
	else if (x > 397 && x < 456 && y>242 && y < 276 && event == 4)
	{
		Level = 12;
	}
	manage.Level = Level;
}