#pragma once
class CMan
{
public:
	CMan();
	virtual ~CMan();
	IplImage *m_pImg;//����ָ�룬��װ��ͼƬ��ֻ��m_pImg_left��m_pImg_right��ֵ
	IplImage *m_pImg_left;//װ�������ߵ�ͼƬ
	IplImage *m_pImg_right;//װ�������ߵ�ͼƬ
	CvSize m_size;//����ָ��ĳߴ�
	CvPoint m_position;//�����λ�ã���ŵ��� ͼƬ���Ͻ� �ڱ����е�����

	int r_speed;
	int l_speed;

	int F;//�����ܵ��ĺ�������Ϊ�ϣ���Ϊ�£�
	int F_down;//�����Ϊ������һֱ�У��ҹ̶�
	int F_other;//������������֧������
	int V;//ÿ֡�ƶ��ľ���

	int F_up_time;//��������Ҹ�д�㷨���Ѿ�û��
	int F_up;//��������Ҹ�д�㷨���Ѿ�û��

	int life;//����ֵ����ʼΪ1
	int success;//�ɹ�ֵ����û���أ�����ʼΪ0

	virtual void Init(int Level);
	void Draw2Back(IplImage* pBack,CvPoint start);//������Ƶ������ĺ�����������Ǳ���ָ��Ϳ�ʼ���Ƶ�����
	int Move();//�����뿴�����ڲ�
	int SumFtoV();//���������ܵ��ĺ���F�����ݺ���F�ķ��򣬸ı�V�ķ�������ģ���FΪ0ʱ��VΪ0
	virtual int Jumpcontual();//���鿴�����ڲ�

	virtual void Init();
};

