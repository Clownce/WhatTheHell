#pragma once
class CElement
{
public:
	CElement();
	virtual ~CElement();
	bool TRIGGER_SIGNAL;
	IplImage *m_pImg;//物品的图片
	CvSize m_size;//物品的尺寸
	CvPoint m_position;//物品在背景中的坐标
	int jihuo;
	virtual void Init(int Level);
	virtual void Init();
//	virtual string function();
	void Draw2Back(IplImage* pBack, CvPoint start);
	virtual int CollideJudge(CMan *man,int Level);
	virtual int CollideJudge(CMan *man);
};

/*CElement是所有物品的基类，在这里我做详细解释：
   
   一、公有函数Draw2Back
      不管派生的什么物品，绘制函数需要的参数都不变，所以直接在CManage里
	打包调用，详情请看CManage类里的Draw2Back函数。
  
   二、虚函数Init
      派生的物品因为功能的不同，所以Init的成员变量不同，举个例子，
	比如派生出的Underfloor（地面）类和CCloud（云）类，地面有支撑的
	功能，和致死功能，而云只有致死功能，所以地面比云多个m_pitfall[2][2]，
	用于储存2个没有支撑力的范围（人物走到这2个范围的其中一个就会不受支持力）

   三、虚函数CollideJudge   （碰撞判断函数）
      此函数是此类的核心思路，必须看懂。
	  1，每种物品与人物的碰撞到底达到什么程度才算碰到了呢？
	    各个物品有各个物品的标准。比如“砖”，我可以从下面顶它，
	也可以跳上去踩它，就有“人上物下”的碰撞（顶），和“人下物上”
	的碰撞（踩）。而“云”，是“人中物中”的碰撞（即人物的中点处于
	云中）。
	  2，碰撞到了，怎么触发该有的特效呢？
	    派生出的类专门要写特有的功能函数，在CollideJudge复杂的碰撞
	判定里，在满足碰撞成功的条件的if语句里插入功能函数。典型例子：
	CMonster的CollideJudge函数，请务必看一看。


	看完此类请看CManage类。*/
