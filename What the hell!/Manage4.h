#pragma once
#include "Back4.h"
#include "Man4.h"
#include "HidenBrick4.h"
#include "Horse_t4.h"
#include "Roadsign4.h"
#include "Underfloor4.h"
#include "Bomb4.h"
#include "Conduit4.h"

class CManage4
{
public:
	CManage4();
	virtual ~CManage4();
	CBack4 back;
	CMan4 man;
	CElement* elements[12];//�뿴ElementSum������6��6��

	void Init();//��������forѭ��
	void Drow2Back();//ûɶ���͵ģ�����һ�������
	void FPStime(int time);//����ˢ�����ʣ�˳����˵����Ѱ���Ƶ�ʼӿ���������ӿ��������
	int FunctionRun();//��������CElement���CollideJudge
	void ElementSum();
	int CollideJudge();//����
	int Death_Judge();//����
};

