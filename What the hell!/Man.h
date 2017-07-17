#pragma once
class CMan
{
public:
	CMan();
	virtual ~CMan();
	IplImage *m_pImg;//人物指针，不装载图片，只被m_pImg_left或m_pImg_right赋值
	IplImage *m_pImg_left;//装载向左走的图片
	IplImage *m_pImg_right;//装载向右走的图片
	CvSize m_size;//人物指针的尺寸
	CvPoint m_position;//人物的位置，存放的是 图片左上角 在背景中的坐标

	int r_speed;
	int l_speed;

	int F;//物体受到的合力（正为上，负为下）
	int F_down;//可理解为重力，一直有，且固定
	int F_other;//其他力（比如支持力）
	int V;//每帧移动的距离

	int F_up_time;//这个力被我改写算法后，已经没用
	int F_up;//这个力被我改写算法后，已经没用

	int life;//生命值，起始为1
	int success;//成功值（过没过关），起始为0

	virtual void Init(int Level);
	void Draw2Back(IplImage* pBack,CvPoint start);//人物绘制到背景的函数，代入的是背景指针和开始绘制的坐标
	int Move();//详情请看函数内部
	int SumFtoV();//计算人物受到的合力F，根据合力F的方向，改变V的方向。特殊的，当F为0时，V为0
	virtual int Jumpcontual();//详情看函数内部

	virtual void Init();
};

