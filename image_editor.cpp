//#include<stdafx.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;
Mat image;
//
//int main()
//{
//	/*Mat image = Mat::zeros(300, 600, CV_8UC3);
//	circle(image, Point(250, 150), 100, Scalar(0, 255, 128), -100);
//	circle(image, Point(350, 150), 100, Scalar(255, 255, 255), -100);
//	imshow("Display Window", image);
//	waitKey(0);
//	return 0;*/
//	
//	/* open an image 
//	Mat image = imread("C:/Users/hp/Pictures/Camera Roll/bg 1.jpg");
//	if (image.empty())
//	{
//		cout << "could not find the image or problem occured while opening it\n";
//		cin.get();// press any key
//		return(-1);
//	}
//	Mat imagebrightup50;
//	image.convertto(imagebrightup50, -1, 1, 50);
//	// Formula for brightness -> p.a+b ----> p is pixel , a=1 in above function , b=50 in above equation .
//	// for contrast same formula just 'b' will be zero and 'a' is expected multiplier.
//	// contrast can be done using histogram equalization.
//	//for applying contrast on BGR color space image one need to convert it into YcrCb color space as in that only 'Cr' and 'Cb'
//	// channel have color information ,'Y' is for 'luma' or brightness.
//	// use blur function to blur the image.
//	// for gaussian blur use GaussainBlur function.
//	// cvNot for inverting the image.
//	// To erode an image : erode(image, image_eroded_with_3x3_kernel, getStructuringElement(MORPH_RECT, Size(3, 3)));
//	/* dilation of an image :  cvDilate(img, img, 0, 2)
//    The 1st parameter is the source image.
//    The 2nd parameter is the destination image which is to be the dilated image.
//    Here the 3rd parameter is the structuring element used for dilation. If it is 0, a 3×3 rectangular structuring element is used. 
//    The 4th parameter is the number of times, dilation is applied.
//    This function can process images in place. That means same variable can be used for the 1st and 2nd parameter
//    */
//	string Window = "background";
//	string wind2 = "brightup50";
//	namedWindow(Window);
//	namedWindow(wind2);
//	imshow(Window, image);
//	imshow(wind2,imagebrightup50);
//	bool savesuccess=imwrite("image.jpg",frame);
//	if(savesuccess==false)
//	{
//	 cout<<"failed to save the image" <<"\n";
//     return(-1);
//    }
//
//	waitKey(0);
//	destroyWindow(Window);// after changing brightness u gonna have 2 windows so instead of writing this u gonna write-->
//	destroyAllWindows();9
//	return(0);*/
//
//	/*   display a blank screen
//	Mat image(600, 800, CV_8UC3, Scalar(200, 150, 30));
//	string Window = "A blank image";
//	namedWindow(Window);
//	imshow(Window, image);
//	waitKey(0);
//	destroyWindow(Window);
//	return(0);*/
//
//
//	/*  play a video
//	    from within your laptop
//		VideoCapture cap("D:/My OpenCV Website/A Herd of Deer Running.mp4"); 
//
//	 // if not success, exit program
//	 if (cap.isOpened() == false)  
//	 {
//	  cout << "Cannot open the video file" << endl;
//	  cin.get(); //wait for any key press
//	  return -1;
//	 }
//
//	 //Uncomment the following line if you want to start the video in the middle
//	 //cap.set(CAP_PROP_POS_MSEC, 300); 
//
//	 //get the frames rate of the video
//	 double fps = cap.get(CAP_PROP_FPS); 
//	 cout << "Frames per seconds : " << fps << endl;
//
//	 String window_name = "My First Video";
//
//	 namedWindow(window_name, WINDOW_NORMAL); //create a window
//
//	 while (true)
//	{
//	  Mat frame;
//	  bool bSuccess = cap.read(frame); // read a new frame from video 
//
//	  //Breaking the while loop at the end of the video
//	  if (bSuccess == false) 
//	  {
//	   cout << "Found the end of the video" << endl;
//	   break;
//	  }
//
//	  //show the frame in the created window
//	  imshow(window_name, frame);
//	 
//	  
//	  //wait for for 10 ms until any key is pressed.  
//	  //If the 'Esc' key is pressed, break the while loop.
//	  //If the any other key is pressed, continue the loop 
//	  //If any key is not pressed withing 10 ms, continue the loop
//	  if (waitKey(10) == 27)
//	  {
//	   cout << "Esc key is pressed by user. Stoppig the video" << endl;
//	   break;
//	  }
//	}
//
//	 return 0;
// */
//	VideoCapture cap(0);
//	if (cap.isOpened() == false)
//	{
//		cout << "some problem occured in your webcam";
//		cin.get();
//		return(-1);
//	}
//	double w = cap.get(CAP_PROP_FRAME_WIDTH);
//	double h = cap.get(CAP_PROP_FRAME_HEIGHT);
//	cout << "Desired Resolution is " << h << "x" << w << "\n";
//	Size framesize(h, w);
//	double frames_per_second = 10;
//	string Window = "Lazy Me";
//	namedWindow(Window);
//	VideoWriter videosave("lazy.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), frames_per_second, framesize, true);
//	if (videosave.isOpened() == false)
//	{
//		cout << "Failed to save video\n";
//		return(-1);
//	}
//	while (true)
//	{
//		Mat frame;
//		bool success = cap.read(frame);
//		if (success == false)
//		{
//			cout << "Something went wrong. Camera got disconnected\n";
//			cin.get();
//			return(-1);
//		}
//		videosave.write(frame);
//		imshow(Window, frame);
//		
//		if (waitKey(10) == 27)
//		{
//			cout << "Camera switched off by user\n";
//			return(0);
//		}
//	}
//	videosave.release();
//}
//// remember u need to do setups
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
//void callbackbutton(int, void*)
//{
//	printf("hola\n\n\n\n");
//}
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
	/*createButton("button5", callbackbutton, NULL, CV_PUSH_BUTTON);file C:\build\master_winpack-build-win64-vc15\opencv\modules\highgui\src\window.cpp*/

	imshow(wind1, image);
	waitKey(0);
	return(0);
}
