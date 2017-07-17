#pragma once
#include "Back.h"
class CBack4 :
	public CBack
{
public:
	CBack4();
	virtual ~CBack4();

	void Init();
	void player_seeRemove(CMan *man, int remove_x);
};

