#include "stdafx.h"
#include "Underfloor.h"


CUnderfloor::CUnderfloor()
{
}


CUnderfloor::CUnderfloor(int level, IplImage *Img)
{
	if (level == 1)
	{
		m_pImg = cvLoadImage("ͼ����Դ/��һ��/����.jpg", 1);
		m_pitfall[0][0] = 1027;
		m_pitfall[0][1] = 1117;
		m_pitfall[1][0] = 1942;
		m_pitfall[1][1] = 2032;
	}
	else if (level == 2)
	{
		m_pImg = cvLoadImage("ͼ����Դ/�ڶ���/����.jpg", 1);
		m_pitfall[1][0] = 2050;
		m_pitfall[1][1] = 2190;
	}
	Level = level;
	pBack = Img;
}

CUnderfloor::~CUnderfloor()
{
}


void CUnderfloor::Init(int Level)
{
	if (Level == 1)
	{
		m_pImg = cvLoadImage("ͼ����Դ/��һ��/����.jpg", 1);
		m_size = cvGetSize(m_pImg);
		m_position.x = 1;
		m_position.y = 270;
		m_pitfall[0][0] = 1027;
		m_pitfall[0][1] = 1117;
		m_pitfall[1][0] = 1942;
		m_pitfall[1][1] = 2032;
	}
	else if (Level == 3)
	{
		m_pImg = cvLoadImage("ͼ����Դ/������/����.jpg", 1);
		m_size = cvGetSize(m_pImg);
		m_position.x = 1;
		m_position.y = 270;
	}
}

void CUnderfloor::Init()
{

	m_size = cvGetSize(m_pImg);
	m_position.x = 1;
	m_position.y = 270;

}


int CUnderfloor::CollideJudge(CMan *man,int Level)
{

	if (Level == 1)
	{
		if ((man->m_position.x + man->m_size.width / 2 > m_pitfall[0][0]
			&& man->m_position.x + man->m_size.width / 2 < m_pitfall[0][1])
			|| (man->m_position.x + man->m_size.width / 2 > m_pitfall[1][0]
			&& man->m_position.x + man->m_size.width / 2 < m_pitfall[1][1]))//�����x���괦��û��֧������������Χ
		{
			if ((man->m_position.x + man->m_size.width / 2 > m_pitfall[1][0]
				&& man->m_position.x + man->m_size.width / 2 < m_pitfall[1][1]))//�����x���괦��û��֧�����ĵڶ�����Χ
			{
				m_pImg = cvLoadImage("ͼ����Դ/��һ��/�����Ұ���.jpg", 1);
			}
		}
		else//�����x���괦����֧�����ķ�Χ
		{
			if (man->m_position.y + man->m_size.height + 10> m_position.y
				&&man->m_position.y + man->m_size.height - 10 < m_position.y)//�����y����Ҳ������֧�����ķ�Χ
			{
				man->m_position.y = m_position.y - man->m_size.height;//��׼���룬ʹ����ĽŲȵ����ϣ��������м���ſ���
				return 1;//���ء������յ�֧�š�����Ϣ
			}
		}

		if (man->m_position.y > 330)//��������
		{
			Function_death(man);//����
		}
	}
	else if (Level == 2)
	{
		if (man->m_position.y + man->m_size.height + 10 > m_position.y
			&&man->m_position.y + man->m_size.height - 10 < m_position.y)//�����x���괦��û��֧�����ĵڶ�����Χ
		{
			if ((man->m_position.x + man->m_size.width / 2 > m_pitfall[1][0]))
				//&& man->m_position.x + man->m_size.width / 2 < m_pitfall[1][1]))
			{
				/*if (cvWaitKey(2000)==32)
				{*/
				man->Move();
				m_pImg = cvLoadImage("ͼ����Դ/�ڶ���/��������.jpg", 1);

				//}
				return 1;
			}
			else
			{
				man->m_position.y = m_position.y - man->m_size.height;//��׼���룬ʹ����ĽŲȵ����ϣ��������м���ſ���
				return 1;//���ء������յ�֧�š�����Ϣ
			}
		}
		if (man->m_position.y >= 280)//��������
		{
			Function_death(man);//����
		}
	}
	else if (Level == 3)
	{
		//�ڶ���������
		//if (man->m_position.x > 0 && man->m_position.x + man->m_size.width < 920)
			//return 0;
		//������֧����
		if (man->m_position.x > 830 && man->m_position.x + man->m_size.width < 920)
			return 0;
		else if (man->m_position.y + man->m_size.height + 10> m_position.y
			&&man->m_position.y + man->m_size.height - 10 < m_position.y)//�����y����Ҳ������֧�����ķ�Χ
		{
			man->m_position.y = m_position.y - man->m_size.height;//��׼���룬ʹ����ĽŲȵ����ϣ��������м���ſ���
			return 1;//���ء������յ�֧�š�����Ϣ
		}
		
	}
	return 0;
}


int CUnderfloor::CollideJudge(CMan *man)
{
	if (Level == 1)
	{
		if ((man->m_position.x + man->m_size.width / 2 > m_pitfall[0][0]
			&& man->m_position.x + man->m_size.width / 2 < m_pitfall[0][1])
			|| (man->m_position.x + man->m_size.width / 2 > m_pitfall[1][0]
			&& man->m_position.x + man->m_size.width / 2 < m_pitfall[1][1]))//�����x���괦��û��֧������������Χ
		{
			if ((man->m_position.x + man->m_size.width / 2 > m_pitfall[1][0]
				&& man->m_position.x + man->m_size.width / 2 < m_pitfall[1][1]))//�����x���괦��û��֧�����ĵڶ�����Χ
			{
				m_pImg = cvLoadImage("ͼ����Դ/��һ��/�����Ұ���.jpg", 1);
			}
		}
		else//�����x���괦����֧�����ķ�Χ
		{
			if (man->m_position.y + man->m_size.height + 10> m_position.y
				&&man->m_position.y + man->m_size.height - 10 < m_position.y)//�����y����Ҳ������֧�����ķ�Χ
			{
				man->m_position.y = m_position.y - man->m_size.height;//��׼���룬ʹ����ĽŲȵ����ϣ��������м���ſ���
				return 1;//���ء������յ�֧�š�����Ϣ
			}
		}
		if (man->m_position.y > 330)//��������
		{
			Function_death(man);//����
		}

	}
	else if (Level == 2)
	{
		if (man->m_position.y + man->m_size.height + 10 > m_position.y
			&&man->m_position.y + man->m_size.height - 10 < m_position.y)//�����x���괦��û��֧�����ĵڶ�����Χ
		{
			if ((man->m_position.x + man->m_size.width / 2 > m_pitfall[1][0]))
				//&& man->m_position.x + man->m_size.width / 2 < m_pitfall[1][1]))
			{
				/*if (cvWaitKey(2000)==32)
				{*/
				man->Move();
				m_pImg = cvLoadImage("ͼ����Դ/�ڶ���/��������.jpg", 1);

				//}
				return 1;
			}
			else
			{
				man->m_position.y = m_position.y - man->m_size.height;//��׼���룬ʹ����ĽŲȵ����ϣ��������м���ſ���
				return 1;//���ء������յ�֧�š�����Ϣ
			}
		}
		if (man->m_position.y >= 280)//��������
		{
			Function_death(man);//����
		}
	}
	return 0;
}


void CUnderfloor::Function_death(CMan* man)
{
	man->life = 0;
}


void CUnderfloor::Function_stopjump(CMan* man)
{
	if (man->V > 0)
	{
		man->V = -man->V;
	}
}