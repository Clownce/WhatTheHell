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
			manage.FPStime(30);//ˢ�µĵȴ�ʱ��                                                   //
			movesize = manage.man.Move();//�������ո��������ƶ��ļ���                             //���ݱ仯�ļ���
			manage.back.player_seeRemove(&manage.man, movesize);//���¼�����ҿɿ�������          //
			cvSetImageROI(manage.back.m_pImg_show, manage.back.player_see);//������ҿɿ�������   /////////		

			/////////
			//
			manage.Drow2Back();//�����е�Ԫ�ػ��Ƶ�����                                           //���Ƶ�ǰ����
			cvShowImage("test", manage.back.m_pImg_show);                                         //
			/////////


			cvResetImageROI(manage.back.m_pImg_show);//�ͷ�����ܿ������� 
			cvCopy(manage.back.m_pImg_all, manage.back.m_pImg_show);//��ϴ����
		}
	}
}


CRun4::~CRun4()
{
}

