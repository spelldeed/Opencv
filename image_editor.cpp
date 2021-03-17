//#include<stdafx.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;
Mat image;
float centerx = 0, centery = 0;
int scale = 50;
void b_callback(int b_value, void* userData)
{
	Mat b_image;
	int c_value = *(static_cast<int*>(userData));
	int curr_b = b_value - 50;
	double curr_c = c_value / 50.0;
	cout << "Change in Brightness : Contrast=" << curr_c << ", Brightness=" << curr_b << endl;
	image.convertTo(b_image, -1, curr_c, curr_b);
	string wind2 = "changed_image";
	imshow(wind2, b_image);
}
void c_callback(int c_value, void* userData)
{
	Mat c_image;
	int b_value = *(static_cast<int*>(userData));
	int curr_b = b_value - 50;
	double curr_c = c_value / 50.0;
	cout << "Change in contrast : Contrast=" << curr_c << ", Brightness=" << curr_b << endl;
	image.convertTo(c_image, -1, curr_c, curr_b);
	string wind2 = "changed_image";
	imshow(wind2, c_image);
}
void blur_callback(int blur_value, void* userData)
{
	Mat blur_image;
	GaussianBlur(image, blur_image, Size(blur_value*2+1, blur_value*2+1), 0,0);
	cout << "Change in blur : " << blur_value * 2 + 1 << "\n";
	string wind2 = "changed_image";
	imshow(wind2, blur_image);
}
void e_callback(int e_value, void* userData) 
{
	Mat erode_image;
	erode(image, erode_image, getStructuringElement(MORPH_RECT, Size(e_value * 2 + 1, e_value * 2 + 1)));
	string wind2 = "changed_image";
	imshow(wind2, erode_image);
}
void d_callback(int d_value, void* userData)
{
	Mat dilation_image;
	dilate(image, dilation_image, getStructuringElement(MORPH_RECT, Size(d_value * 2 + 1, d_value * 2 + 1)));
	string wind2 = "changed_image";
	imshow(wind2, dilation_image);
}
void r_callback(int angle, void* userData)
{
	Mat rotated_image;
	Mat rotate = getRotationMatrix2D(Point(centerx, centery), (angle - 180), scale / 50.0);
	warpAffine(image, rotated_image, rotate, image.size(), INTER_LINEAR, BORDER_CONSTANT, Scalar(0,0,0));
	string wind2 = "changed_image";
	imshow(wind2, rotated_image);

}

int main()
{
	cout << "*******************************************NOTE*********************************************************\n";
	cout << "-> My program is using Gaussian Blur technique to blur the image\n-> Shape of kernel being used while ";
	cout << " erosion and dilation is rectangular\n";
	image = imread("NorthernLights.jpg");
	if (image.empty())
	{
		cout << "Could not open the image file\n";
		cin.get();
		return(1);
	}
	string wind1 = "Actual_Northern_Lights";
	namedWindow(wind1,0);
	int b_value = 50, c_value = 50,blur=1,erode=0,dilate=0,angle=180;
	blur_callback(0, 0);
	createTrackbar("Brightness", wind1, &b_value, 100, b_callback, &c_value);
	createTrackbar("Contrast", wind1, &c_value, 100, c_callback, &b_value);
	createTrackbar("Blur", wind1, &blur, 37, blur_callback);
	createTrackbar("Erode", wind1, &erode, 41, e_callback);
	createTrackbar("Dilate", wind1, &dilate, 41, d_callback);
	createTrackbar("Angle", wind1, &angle, 360, r_callback);
	

	imshow(wind1, image);
	waitKey(0);
	return(0);
}
