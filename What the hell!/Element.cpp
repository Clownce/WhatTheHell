#include "stdafx.h"
#include "Element.h"


CElement::CElement()
{
}


CElement::~CElement()
{
}


void CElement::Init(int Level)
{
	
}


void CElement::Init()
{

}


void CElement::Draw2Back(IplImage* pBack, CvPoint start) 
{
	for (int height = 0; height < m_size.height; height++)
	{
		for (int width = 0; width < m_size.width; width++)
		{
			if (height + start.y<1 || height + start.y>329 || width + start.x<1 || width + start.x>2274)
			{
				continue;
			}
			if (CV_IMAGE_ELEM(m_pImg, uchar, height, width * 3 + 1)>250 && CV_IMAGE_ELEM(m_pImg, uchar, height, width * 3 + 0)>250 &&
				CV_IMAGE_ELEM(m_pImg, uchar, height, width * 3 + 1) > 250)//如果此像素点为白色（无效色）
			{
				continue;
			}
			CV_IMAGE_ELEM(pBack, uchar, height + start.y, (width + start.x) * 3 + 0) = CV_IMAGE_ELEM(m_pImg, uchar, height, width * 3 + 0);
			CV_IMAGE_ELEM(pBack, uchar, height + start.y, (width + start.x) * 3 + 1) = CV_IMAGE_ELEM(m_pImg, uchar, height, width * 3 + 1);
			CV_IMAGE_ELEM(pBack, uchar, height + start.y, (width + start.x) * 3 + 2) = CV_IMAGE_ELEM(m_pImg, uchar, height, width * 3 + 2);

		}
	}
}

int CElement::CollideJudge(CMan *man,int Level)
{
	return 0;
}


int CElement::CollideJudge(CMan *man)
{
	return 0;
}
