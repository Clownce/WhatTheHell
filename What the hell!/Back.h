#pragma once
class CBack
{
public:
	CBack();
	virtual ~CBack();
	IplImage *m_pImg_all;//加载整张背景
	IplImage *m_pImg_show;//加载整张背景，但用于绘制和展示
	IplImage *m_pImg_death;//死亡时的图片

	CvSize m_size_death;//死亡时图片的尺寸

	CvSize m_size_all;//背景图片的尺寸
	CvRect player_see;//玩家可见区域，cvrect是一个cv自带矩形类
	virtual void Init(int Level);//初始化，加载图片
	virtual void Init();
	virtual void player_seeRemove(CMan *man, int remove_x,int Level);//控制玩家可见区域的变化
	virtual void player_seeRemove(CMan *man, int remove_x);
	void Draw2Back(IplImage* pBack, CvPoint start);//用于死亡时图片的绘制
};

