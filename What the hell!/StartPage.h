#pragma once

class CStartPage
{
public:
	CStartPage();
	~CStartPage();
	IplImage *start_back_img, *start_bn_img1, *start_bn_img2;
	IplImage *start_choose_img;
	CvPoint start_bn_pos;
	void Draw_Button(IplImage *bkgd, IplImage *button, CvPoint pos);
};