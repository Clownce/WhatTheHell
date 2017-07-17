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
	CElement* elements[12];//请看ElementSum函数，6不6！

	void Init();//理解里面的for循环
	void Drow2Back();//没啥解释的，就是一起调用了
	void FPStime(int time);//控制刷新速率，顺便加了点代码把按键频率加快整个画面加快的问题解决
	int FunctionRun();//调用所有CElement里的CollideJudge
	void ElementSum();
	int CollideJudge();//无视
	int Death_Judge();//无视
};

