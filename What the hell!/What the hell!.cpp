// What the hell!.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

void OnMouse(int event, int x, int y, int flags, void* param);
void OnMouse_Choose(int event, int x, int y, int flags, void* param);////�ؿ���ť��Ӧ
CManage manage;
bool Is_Ready;///////////////////////////////////////////////////////////��ʼ��Ϸ������ؿ�ѡ��
int Level;///////////////////////////////////////////////////////////////ѡ��ؿ�
CStartPage cs;
int _tmain(int argc, _TCHAR* argv[])
{
	
	Is_Ready = false;
	Level = 0;
	
	
	int movesize;
	int gameover=0;
	/////////////////////////��ʼ����//////////////////////////////////////
	cvNamedWindow("��ʼ��Ϸ", 1);
	cvMoveWindow("��ʼ��Ϸ",300, 100);
	cvSetMouseCallback("��ʼ��Ϸ", OnMouse, NULL);
	while (true)
	{
		cvShowImage("��ʼ��Ϸ", cs.start_back_img);
		cs.Draw_Button(cs.start_back_img, cs.start_bn_img1, cs.start_bn_pos);
		if (cvWaitKey(10)&&Is_Ready == true)
		{
			break;
		}
	}
	cvDestroyWindow("��ʼ��Ϸ");
	while (1){///////////////////////////////////////////����ʱ�ɷ���ѡ��ؿ�
		//////////////////////////////////////////////////////
		/////////////////ѡ��ؿ�/////////////////////////////
		///////////////////////////////////////////////////////
		cvNamedWindow("�ؿ�ѡ��", 1);
		cvMoveWindow("�ؿ�ѡ��", 300, 100);
		cvSetMouseCallback("�ؿ�ѡ��", OnMouse_Choose, NULL);
		while (true)//////////////////////////////////////�ȴ��ؿ�ѡ��
		{
			cvShowImage("�ؿ�ѡ��", cs.start_choose_img);
			if (cvWaitKey(10) && Level >=1&&Level<=12)
			{
				break;
			}
		}
		cvDestroyWindow("�ؿ�ѡ��");
		/////////////////////////////////////////////////////////////
		//////////////////////��Ϸ����///////////////////////////////
		//////////////////////////////////////////////////////////////
		if (Level == 4)
		{
			CRun4* run4 = new CRun4;
			delete run4;
		}
		else
		{
			cvNamedWindow("����û�뵽", 1);
			cvMoveWindow("����û�뵽", 300, 100);
			for (;;)/////////////////////////////////////////////��ʼ��ĳ�ؿ�   (int i=Level;i<=12;i++,Level++)
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
				for (;;)////////////////////////////////////////��ǰ�ؿ��ڲ�ѭ���������ƶ���
				{
					if (gameover == -2)
					{
						for (;;)////////////////////////////////����ʱ�ȴ���������
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
						manage.FPStime(30);/////////////////////////////ˢ�µĵȴ�ʱ��
						movesize = manage.man.Move();///////////////////�������ո��������ƶ��ļ���    //���ݱ仯�ļ���
						manage.back.player_seeRemove(&manage.man, movesize);////���¼�����ҿɿ�������
						cvSetImageROI(manage.back.m_pImg_show, manage.back.player_see);////������ҿɿ�������  


						manage.Draw2Back();//////////////////////////////�����е�Ԫ�ػ��Ƶ�����     //���Ƶ�ǰ����
						cvShowImage("����û�뵽", manage.back.m_pImg_show);


						cvResetImageROI(manage.back.m_pImg_show);///////////�ͷ�����ܿ������� 
						cvCopy(manage.back.m_pImg_all, manage.back.m_pImg_show);
					}
					else
					{
						gameover += manage.FunctionRun(Level);
						manage.FPStime(30);/////////////////////////////ˢ�µĵȴ�ʱ��
						movesize = manage.man.Move();///////////////////�������ո��������ƶ��ļ���    //���ݱ仯�ļ���
						manage.back.player_seeRemove(&manage.man, movesize, Level);////���¼�����ҿɿ�������
						cvSetImageROI(manage.back.m_pImg_show, manage.back.player_see);////������ҿɿ�������  


						manage.Draw2Back(Level);//////////////////////////////�����е�Ԫ�ػ��Ƶ�����     //���Ƶ�ǰ����
						cvShowImage("����û�뵽", manage.back.m_pImg_show);


						cvResetImageROI(manage.back.m_pImg_show);///////////�ͷ�����ܿ������� 
						cvCopy(manage.back.m_pImg_all, manage.back.m_pImg_show);//////��ϴ����
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