// AnnotatingImages.cpp : This file contains the 'main' function. Program execution begins and ends there.
// chu thich hinh anh
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("dog.jpg");
    imshow("anh goc", img);
    waitKey(0);
    if (img.empty()) {
        cout << " ko the mo anh" << endl;
    }
    ///////////// ke line
    Mat img_line = img.clone();
    Point pointA(200,80);
    Point pointB(450,80);
    line(img_line, pointA, pointB, Scalar(255, 255, 0), 3, 8, 0);
    imshow("ke line", img_line);
    waitKey();

    /////////////// ke circle
    Mat img_circle = img.clone();
    Point circle_center(415, 190);
    int radius(100);
    circle(img_circle, circle_center, radius, Scalar(0, 0, 255), 3, 8, 0); // red circle Scalar(B,G,R)
    imshow("Red circle", img_circle);
    waitKey();
   
    ////////////ke Filled Circle
    Mat img_filled_circle = img.clone();
   // Point circle_center(415, 190);
   // int radius2(100);
    circle(img_filled_circle, circle_center, radius, Scalar(255, 0, 0), -1, 8, 0); // filled blue circle 
    imshow("blue filled circle", img_filled_circle);
    waitKey(0);
    destroyAllWindows();

    ////////////ke Retangle
    Mat img_retangle = img.clone();
     pointA = Point(300, 115); 
     pointB = Point(475, 225);
    rectangle(img_retangle, pointA, pointB, Scalar(0, 0, 255), 3, 8, 0);
    imshow("red retangle", img_retangle);
    waitKey(0);
    
    //////////////ke ellipse
    Mat img_ellipse = img.clone();
    Point axis1(100, 50);
    Point axis2(125, 50);
    //elip ngang
    ellipse(img_ellipse, circle_center, axis1, 0, 0, 360, Scalar(255, 0, 0), 3, 8, 0);
    //elip doc
    ellipse(img_ellipse, circle_center,axis2, 90,0,360, Scalar(0, 0, 255), 3, 8, 0);
    imshow("ellipse", img_ellipse);
    waitKey(0);

    //////////ke 1 nua ellipse
    Mat Halfellipse = img.clone();
    //elip ngang
    ellipse(Halfellipse, circle_center, axis1, 0, 180, 360, Scalar(255, 0, 0), 3, 8, 0);
    //elip doc
    ellipse(Halfellipse, circle_center, axis1, 0, 0, 180, Scalar(0, 0, 255), -2, 8, 0);
    imshow("Halfellipse", Halfellipse);
    waitKey(0);
    destroyAllWindows();

    /////////////////adding text
    Mat img_adding_text= img.clone();
    putText(img_adding_text, "Con cho hanh phuc", Point(50, 350), FONT_HERSHEY_COMPLEX, 1.5, Scalar(255, 225, 100),3,8,0);
    imshow("img_adding_text", img_adding_text);
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
