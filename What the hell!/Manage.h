#pragma once
class CManage
{
public:
	CManage();
	virtual ~CManage();
	CBack back;
	CMan man;
	CElement* elements[18];//�뿴ElementSum������6��6��
	int Level;

	void Init(int Level);//��������forѭ��
	void Draw2Back(int Level);//ûɶ���͵ģ�����һ�������
	void FPStime(int time);//����ˢ�����ʣ�˳����˵����Ѱ���Ƶ�ʼӿ���������ӿ��������
	int FunctionRun(int Level);//��������CElement���CollideJudge
	void ElementSum(int Level);
	int CollideJudge();//����
	int Death_Judge();//����

	void Init();//��������forѭ��
	void Draw2Back();//ûɶ���͵ģ�����һ�������
	int FunctionRun();//��������CElement���CollideJudge
	void ElementSum();
};

