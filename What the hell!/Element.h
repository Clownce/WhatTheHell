#pragma once
class CElement
{
public:
	CElement();
	virtual ~CElement();
	bool TRIGGER_SIGNAL;
	IplImage *m_pImg;//��Ʒ��ͼƬ
	CvSize m_size;//��Ʒ�ĳߴ�
	CvPoint m_position;//��Ʒ�ڱ����е�����
	int jihuo;
	virtual void Init(int Level);
	virtual void Init();
//	virtual string function();
	void Draw2Back(IplImage* pBack, CvPoint start);
	virtual int CollideJudge(CMan *man,int Level);
	virtual int CollideJudge(CMan *man);
};

/*CElement��������Ʒ�Ļ��࣬������������ϸ���ͣ�
   
   һ�����к���Draw2Back
      ����������ʲô��Ʒ�����ƺ�����Ҫ�Ĳ��������䣬����ֱ����CManage��
	������ã������뿴CManage�����Draw2Back������
  
   �����麯��Init
      ��������Ʒ��Ϊ���ܵĲ�ͬ������Init�ĳ�Ա������ͬ���ٸ����ӣ�
	������������Underfloor�����棩���CCloud���ƣ��࣬������֧�ŵ�
	���ܣ����������ܣ�����ֻ���������ܣ����Ե�����ƶ��m_pitfall[2][2]��
	���ڴ���2��û��֧�����ķ�Χ�������ߵ���2����Χ������һ���ͻ᲻��֧������

   �����麯��CollideJudge   ����ײ�жϺ�����
      �˺����Ǵ���ĺ���˼·�����뿴����
	  1��ÿ����Ʒ���������ײ���״ﵽʲô�̶Ȳ����������أ�
	    ������Ʒ�и�����Ʒ�ı�׼�����硰ש�����ҿ��Դ����涥����
	Ҳ��������ȥ���������С��������¡�����ײ���������͡��������ϡ�
	����ײ���ȣ��������ơ����ǡ��������С�����ײ����������е㴦��
	���У���
	  2����ײ���ˣ���ô�������е���Ч�أ�
	    ����������ר��Ҫд���еĹ��ܺ�������CollideJudge���ӵ���ײ
	�ж����������ײ�ɹ���������if�������빦�ܺ������������ӣ�
	CMonster��CollideJudge����������ؿ�һ����


	��������뿴CManage�ࡣ*/
