#include "stdafx.h"
#include "Manage.h"


CManage::CManage()
{
}


CManage::~CManage()
{
}


void CManage::Draw2Back(int Level)
{
	if (Level == 1)
	{
		man.Draw2Back(back.m_pImg_show, man.m_position);
		for (int i = 0; i < 12; i++)
		{
			elements[i]->Draw2Back(back.m_pImg_show, elements[i]->m_position);
		}
		Death_Judge();
	}
	else if (Level == 3)
	{
		man.Draw2Back(back.m_pImg_show, man.m_position);
		if (elements[4]->TRIGGER_SIGNAL == true)//����������
		{
			if (elements[3]->m_position.y < 196)
			{
				elements[3]->m_position.y += 5;
			}
		}
		for (int i = 0; i < 16; i++)
		{
			elements[i]->Draw2Back(back.m_pImg_show, elements[i]->m_position);
		}
		Death_Judge();
	}
	
}

void CManage::Draw2Back()
{
	man.Draw2Back(back.m_pImg_show, man.m_position);
	if (Level == 1)
	{
		for (int i = 0; i < 12; i++)
		{
			elements[i]->Draw2Back(back.m_pImg_show, elements[i]->m_position);
		}
	}
	else if (Level == 2)
	{
		for (int i = 0; i < 14; i++)
		{
			if (i == 0 || i == 12 || i == 2 || i == 3 || i == 7 || i == 13 || i == 6)
			{
				elements[i]->Draw2Back(back.m_pImg_show, elements[i]->m_position);
			}
		}
	}
	Death_Judge();
}

void CManage::Init(int Level)
{
	ElementSum(Level);
	back.Init(Level);
	man.Init(Level);
	if (Level == 1)
	{
		for (int i = 0; i < 12; i++)
		{
			elements[i]->Init(Level);
		}
	}
	else if (Level == 3)
	{
		for (int i = 0; i < 16; i++)
		{
			elements[i]->Init(Level);
		}
	}
	
	
}

void CManage::Init()
{

	back.Init(Level);  /*��������������˳��*/
	ElementSum();

	man.Init();
	if (Level == 1)
	{
		for (int i = 0; i < 12; i++)
		{
			elements[i]->Init();
		}
	}
	else if (Level == 2)
	{
		for (int i = 0; i < 14; i++)
		{
			if (i == 0 || i == 12 || i == 2 || i == 3 || i == 7 || i == 13 || i == 6)
				elements[i]->Init();
		}
	}
}

void CManage::FPStime(int time)
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


int CManage::FunctionRun(int Level)
{
	bool sign=0;
	if (Level == 1)
	{
		for (int i = 0; i < 12; i++)
		{
			if (elements[i]->CollideJudge(&man,Level) == 1)
			{
				sign = 1;
			}
		}
	}
	else if (Level == 3)
	{
		for (int i = 0; i < 16; i++)
		{
			if (elements[i]->CollideJudge(&man,Level) == 1)
			{
				sign = 1;
			}
		}
	}
	
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

int CManage::FunctionRun()
{
	bool sign = 0;
	if (Level == 1)
	{
		for (int i = 0; i < 12; i++)
		{

			if (elements[i]->CollideJudge(&man) == 1)
			{
				sign = 1;
			}

		}
	}
	else if (Level == 2)
	{
		for (int i = 0; i < 14; i++)
		{
			if (i == 0 || i == 12 || i == 2 || i == 3 || i == 7 || i == 13 || i == 6)
			{
				if (elements[i]->CollideJudge(&man) == 1)
				{
					sign = 1;
				}
			}
			/*if (i==7)
			{
			if (elements[i]->CollideJudge(&man) == 1)
			{
			elements[]
			}
			}*/
		}
	}
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

void CManage::ElementSum(int Level)
{

	if (Level == 1)
	{
		elements[0] = new(CUnderfloor);
		elements[1] = new(CRoadsign);
		elements[2] = new(CBrick);
		elements[3] = new(CHidenBrick);
		elements[4] = new(CCloud);
		elements[5] = new(CHorse_f);
		elements[6] = new(CHorse_t);
		elements[7] = new(CSign);
		elements[8] = new CMonster(1760, 238, 1);
		elements[9] = new CMonster(1810, 238, 1);
		elements[10] = new CMonster(1860, 238, 1);
		elements[11] = new CMonster(1910, 238, -1);
	}
	else if (Level == 2)
	{
		elements[6] = new CHorse_t(2215, 2);
		elements[2] = new CBrick(877, 185);//����ʱ175�����������165
		elements[3] = new CHidenBrick(1356, 150);
		elements[7] = new CSign(1470, 50, 2);//���Ƶ�������ȥ
		elements[13] = new CGrass(1480, 245);
	}
	else if (Level == 3)
	{
		elements[0] = new(CUnderfloor);
		elements[1] = new(CHorse_f);
		elements[2] = new(CHorse_t);
		elements[3] = new(CSign);
		elements[4] = new CBrick(100, 241, 1);  //����
		elements[5] = new CBrick(470, 213, 2);  //����
		elements[6] = new CBrick(650, 165, 3);  //�ʺ�ש
		elements[7] = new CBrick(800, 120, 4);  //ǽ1
		elements[8] = new CBrick(770, 90, 5);  //ǽ2
		elements[9] = new CBrick(920, 60, 6);  //ǽ3
		elements[10] = new CBrick(980, 0, 7);  //ǽ4
		elements[11] = new CBrick(1150, 200, 5);  //����1
		elements[12] = new CBrick(1240, 150, 5);  //����2
		elements[13] = new CBrick(1330, 200, 5);  //����3
		elements[14] = new CBrick(1650, 165, 9);  //����ש
		elements[15] = new CBrick(1700, 60, 10);  //��
	}
}

void CManage::ElementSum()
{

	elements[0] = new CUnderfloor(Level, back.m_pImg_show);
	elements[1] = new(CRoadsign);
	elements[4] = new(CCloud);
	elements[5] = new(CHorse_f);

	elements[8] = new CMonster(1760, 238, 1);
	elements[9] = new CMonster(1810, 238, 1);
	elements[10] = new CMonster(1860, 238, 1);
	elements[11] = new CMonster(1910, 238, -1);
	elements[12] = new CGrass(775, 245);
	if (Level == 1)
	{
		elements[6] = new CHorse_t(23, 1);
		elements[2] = new CBrick(850, 165);
		elements[3] = new CHidenBrick(1030, 165);
		elements[7] = new CSign(85, 30, 1);
	}
	else if (Level == 2)
	{
		elements[6] = new CHorse_t(2215, 2);
		elements[2] = new CBrick(877, 185);//����ʱ175�����������165
		elements[3] = new CHidenBrick(1356, 150);
		elements[7] = new CSign(1470, 50, 2);//���Ƶ�������ȥ
		elements[13] = new CGrass(1480, 245);
	}

}


int CManage::CollideJudge()
{
	return 0;
}


int CManage::Death_Judge()
{
	if (man.life == 0)
	{
		back.Draw2Back(back.m_pImg_show, CvPoint(back.player_see.x + 150, 100));
		
		
	}
	return 0;
}
