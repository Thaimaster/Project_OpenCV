// Mouse_and_Trackbar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include<string>


using namespace std;
using namespace cv;

/////////////////// trackbar/////////
int maxScaleup = 100;
int scaleFactor = 1;
string windownName = "Scale Image";
string trackbarValue = "Scale";

//function callback
void scaleImage( int, void*) {
    Mat image = imread("suabien.jpg");
    double scaleFactorDouble = 1 + scaleFactor / 100.0;
    Mat scaleImage;
    resize(image, scaleImage, Size(), scaleFactorDouble, scaleFactorDouble, INTER_LINEAR);
    imshow(windownName, scaleImage);
}


//////////////////Drawrectangle/////////
Point top_left_corner, bottom_right_corner;
Mat img;

void drawRectangle(int action, int x, int y, int flag,void *userdata) {
    if (action == EVENT_LBUTTONDOWN)
        top_left_corner = Point(x, y);
    else if (action == EVENT_LBUTTONUP)
    {
         bottom_right_corner = Point(x, y);
         rectangle(img, top_left_corner, bottom_right_corner, Scalar(0, 255, 0), 2, 8);
         imshow("image", img);
    }      
}

int main()
{
    ////////////////////// Draw Rectangle  
    img = imread("suabien.jpg");
    Mat img_clone = img.clone();
    namedWindow("image", WINDOW_AUTOSIZE);

    //callback
    setMouseCallback("image", drawRectangle);
    int k = 0;
    while (k != 27) {
        imshow("image", img);
        k = waitKey(0);
        if (k == 99) {
            img_clone.copyTo(img);
            // c de xoa
    }
    }
    destroyAllWindows;

    //////////////////////////Resize using Trackbar 
    img = imread("suabien.jpg");
    namedWindow(windownName, WINDOW_AUTOSIZE);
    //// create trackbar va lien ket voi callback function
    createTrackbar(trackbarValue, windownName, &scaleFactor, maxScaleup, scaleImage);
    scaleImage(25, 0);

    imshow(windownName, img);
    k=waitKey(0);
    while (k != 27);
    destroyWindow;




    return 0;
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
