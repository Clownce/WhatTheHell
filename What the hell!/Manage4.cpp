#include "stdafx.h"
#include "Manage4.h"


CManage4::CManage4()
{
}


CManage4::~CManage4()
{
}

void CManage4::Init()
{
	back.Init();
	man.Init();
	for (int i = 0; i < 12; i++)
	{
		elements[i]->Init();
	}

}

void CManage4::Drow2Back()
{
	man.Draw2Back(back.m_pImg_show, man.m_position);
	for (int i = 0; i < 12; i++)
	{
		elements[i]->Draw2Back(back.m_pImg_show, elements[i]->m_position);
	}
	Death_Judge();
}

void CManage4::FPStime(int time)
{
	char key;
	key = cvWaitKey(time);//这里的key，用来判断在70ms内，玩家有没有按什么键
	if (key != -1)      //不等于-1的话表示玩家按了什么键
	{
		cvWaitKey(1);
		//cvWaitKey(1);
		cvWaitKey(1);
		//cvWaitKey(1);
		cvWaitKey(1);
	}//单纯的吃掉玩家按的键位，缓冲画面频率加快的问题。经测试用5个1ms的cvwaitkey刚好又不影响操作，又不加快画面
}

int CManage4::FunctionRun()
{
	bool sign = 0;
	for (int i = 0; i < 12; i++)
	{
		if (elements[i]->CollideJudge(&man) == 1)
		{
			sign = 1;
		}
	}
	if (elements[9]->jihuo == 1 && elements[10]->jihuo == 1 && elements[11]->jihuo == 1)
		man.life = 0;
	if (sign == 0)//没有任何物体支撑人物
	{
		man.F_other = 0;
	}
	else//有至少一个物体支撑着人物
	{
		man.F_other = man.F_down;
	}
	if (man.life == 0)//人物死了吗？
	{
		return -1;
	}
	if (man.success == 1)//过关了吗？
	{
		return 1;
	}
	return 0;
}

void CManage4::ElementSum()
{
	elements[0] = new CUnderfloor4;
	elements[1] = new CRoadsign4;
	elements[2] = new CHidenBrick4;
	elements[3] = new CHorse_t4;
	elements[4] = new CBomb4(470, -77, 1);
	elements[5] = new CBomb4(540, 407, 0);
	elements[6] = new CConduit4(850, 205);
	elements[7] = new CConduit4(1028, 205);
	elements[8] = new CHidenBrick4(915, 120);
	elements[9] = new CHidenBrick4(918, 205);
	elements[10] = new CHidenBrick4(951, 205);
	elements[11] = new CHidenBrick4(984, 205);
}

int CManage4::CollideJudge()
{
	return 0;
}

int CManage4::Death_Judge()
{
	if (man.life == 0)
	{
		back.Draw2Back(back.m_pImg_show, CvPoint(back.player_see.x + 150, 100));


	}
	return 0;
}
