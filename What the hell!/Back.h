#pragma once
class CBack
{
public:
	CBack();
	virtual ~CBack();
	IplImage *m_pImg_all;//�������ű���
	IplImage *m_pImg_show;//�������ű����������ڻ��ƺ�չʾ
	IplImage *m_pImg_death;//����ʱ��ͼƬ

	CvSize m_size_death;//����ʱͼƬ�ĳߴ�

	CvSize m_size_all;//����ͼƬ�ĳߴ�
	CvRect player_see;//��ҿɼ�����cvrect��һ��cv�Դ�������
	virtual void Init(int Level);//��ʼ��������ͼƬ
	virtual void Init();
	virtual void player_seeRemove(CMan *man, int remove_x,int Level);//������ҿɼ�����ı仯
	virtual void player_seeRemove(CMan *man, int remove_x);
	void Draw2Back(IplImage* pBack, CvPoint start);//��������ʱͼƬ�Ļ���
};

