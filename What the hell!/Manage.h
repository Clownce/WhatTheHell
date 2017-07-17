#pragma once
class CManage
{
public:
	CManage();
	virtual ~CManage();
	CBack back;
	CMan man;
	CElement* elements[18];//请看ElementSum函数，6不6！
	int Level;

	void Init(int Level);//理解里面的for循环
	void Draw2Back(int Level);//没啥解释的，就是一起调用了
	void FPStime(int time);//控制刷新速率，顺便加了点代码把按键频率加快整个画面加快的问题解决
	int FunctionRun(int Level);//调用所有CElement里的CollideJudge
	void ElementSum(int Level);
	int CollideJudge();//无视
	int Death_Judge();//无视

	void Init();//理解里面的for循环
	void Draw2Back();//没啥解释的，就是一起调用了
	int FunctionRun();//调用所有CElement里的CollideJudge
	void ElementSum();
};

