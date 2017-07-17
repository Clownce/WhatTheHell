#pragma once
class CIOcontrol
{
public:
	CIOcontrol();
	virtual ~CIOcontrol();//这个类我忽略了，按键接收在CMan里，因为不这样做的话不能实现多键位感应

	//string Getkey();
};

