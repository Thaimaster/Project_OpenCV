// Edge_Detection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//consist: Sobel edge detection & Canny edge detection

#include<opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{   // phat hien canh chi can anh gray
    Mat img = imread("tiger.jpg",IMREAD_GRAYSCALE);
    imshow("anhgoc", img);
    // blur cac diem gan edge de de dang detect hon
    Mat img_blur;
    GaussianBlur(img, img_blur, Size(3, 3), 0, 0);
    // Sobel dectection
    // phat hien bang cach su dung DAO HAM BAC NHAT
    Mat Sobelx, Sobely, Sobelxy;
    Sobel(img_blur, Sobelx, CV_64F, 1, 0, 5);
    Sobel(img_blur, Sobely, CV_64F, 0, 1, 5);
    Sobel(img_blur, Sobelxy, CV_64F, 1, 1, 5);
    
    imshow("sobel X", Sobelx);
    imshow("sobel Y", Sobely);
    imshow("sobel XY", Sobelxy);
    waitKey(0);
    // Canny edge detection
    Mat edge;
    Canny(img_blur, edge, 100, 200,3,false);
    imshow("canny edge", edge);
    waitKey(0);


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
