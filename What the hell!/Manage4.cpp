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
	key = cvWaitKey(time);//�����key�������ж���70ms�ڣ������û�а�ʲô��
	if (key != -1)      //������-1�Ļ���ʾ��Ұ���ʲô��
	{
		cvWaitKey(1);
		//cvWaitKey(1);
		cvWaitKey(1);
		//cvWaitKey(1);
		cvWaitKey(1);
	}//�����ĳԵ���Ұ��ļ�λ�����廭��Ƶ�ʼӿ�����⡣��������5��1ms��cvwaitkey�պ��ֲ�Ӱ��������ֲ��ӿ컭��
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
	if (sign == 0)//û���κ�����֧������
	{
		man.F_other = 0;
	}
	else//������һ������֧��������
	{
		man.F_other = man.F_down;
	}
	if (man.life == 0)//����������
	{
		return -1;
	}
	if (man.success == 1)//��������
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
