#include "stdafx.h"
#include "StartPage.h"


CStartPage::CStartPage()
{
	start_bn_pos = CvPoint(225, 200);
	start_back_img = cvLoadImage("图像资源/界面/开始背景.png");
	start_bn_img1 = cvLoadImage("图像资源/界面/开始按钮1.png");
	start_bn_img2 = cvLoadImage("图像资源/界面/开始按钮2.png");
	start_choose_img = cvLoadImage("图像资源/界面/关卡选择.png");
}


CStartPage::~CStartPage()
{
}
void CStartPage::Draw_Button(IplImage *bkgd, IplImage *button, CvPoint pos)
{
	for (int height = 0; height < 50; height++)
	{
		for (int width = 0; width < 120; width++)
		{
			CV_IMAGE_ELEM(bkgd, uchar, height + pos.y, (width + pos.x) * 3 + 0) = CV_IMAGE_ELEM(button, uchar, height, width * 3 + 0);
			CV_IMAGE_ELEM(bkgd, uchar, height + pos.y, (width + pos.x) * 3 + 1) = CV_IMAGE_ELEM(button, uchar, height, width * 3 + 1);
			CV_IMAGE_ELEM(bkgd, uchar, height + pos.y, (width + pos.x) * 3 + 2) = CV_IMAGE_ELEM(button, uchar, height, width * 3 + 2);

		}
	}
}


