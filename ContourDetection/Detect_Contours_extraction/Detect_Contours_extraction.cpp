// Detect_Contours_extraction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Different Contour Retrieval Techniques
#include<opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("simple.jpg");
	Mat img_gray;
	imshow("simple", img);
	cvtColor(img, img_gray, COLOR_BGR2GRAY);
	Mat img_thres;
	threshold(img_gray, img_thres, 150, 255, THRESH_BINARY);

	///RETR_LIST
	//The RETR_LIST contour retrieval method does not create any parent child relationship between the extracted contours
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(img_thres, contours, hierarchy, RETR_LIST,CHAIN_APPROX_NONE);
	Mat img_clone1 = img.clone();
	drawContours(img_clone1, contours, -1, Scalar(0, 255, 0), 2); // 2 - thickness
	imshow("LIST", img_clone1);
	imwrite("contours_retr_list.jpg",img_clone1);
	waitKey(0);

	//RETR_EXTERNAL
	//only detects the parent contours, and ignores any child contours
	vector<vector<Point>> contours2;
	vector<Vec4i> hierarchy2;
	findContours(img_thres, contours2, hierarchy2, RETR_EXTERNAL, CHAIN_APPROX_NONE);
	Mat img_clone2 = img.clone();
	drawContours(img_clone2, contours2, -1, Scalar(0, 255, 0), 2); // 2 - thickness
	imshow("external", img_clone2);
	imwrite("contours_retr_external.jpg", img_clone2);
	waitKey(0);
   
	//RETR_CCOMP
	//retrieves all the contours in an image
	vector<vector<Point>> contours3;
	vector<Vec4i> hierarchy3;
	findContours(img_thres, contours3, hierarchy3, RETR_CCOMP, CHAIN_APPROX_NONE);
	Mat img_clone3 = img.clone();
	drawContours(img_clone3, contours3, -1, Scalar(0, 255, 0), 2); // 2 - thickness
	imshow("CCOMP", img_clone3);
	imwrite("contours_retr_ccomp.jpg", img_clone3);
	waitKey(0);

	//RETR_TREE , just like ccomp ,also retrieves all the contours.

	/*  Contour Retrieval Method	Time Take(in seconds)
		RETR_LIST					0.000382
		RETR_EXTERNAL				0.000554
		RETR_CCOMP					0.001845
		RETR_TREE					0.005594 
		*/
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
