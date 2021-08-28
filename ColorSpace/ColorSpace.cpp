// ColorSpace.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

Mat img, placeholder;

// Callback function for any event on he mouse
void onMouse(int event, int x, int y, int flag, void* userdata) {
    if (event == EVENT_MOUSEMOVE) {
        Vec3b bgrPixel(img.at<Vec3b>(y, x)); //y dimension 0, x dimension 1

        Mat3b  hsv;
        // create Mat ojb
        Mat3b bgr(bgrPixel);
        // convert to hsv
        cvtColor(bgr, hsv, COLOR_BGR2HSV);

        // get back the vector from Mat
        Vec3b hsvPixel(hsv.at<Vec3b>(0, 0));
        // Create an empty placeholder for displaying the values
        placeholder = Mat::zeros(img.rows, 400, CV_8UC3);

        // fill the placeholder with the values of color spaces hsv
        putText(placeholder, format("HSV[%d %d %d]", hsvPixel[0], hsvPixel[1], hsvPixel[2]), Point(20, 70), FONT_HERSHEY_COMPLEX, .9, Scalar(255, 255, 255), 1);
        putText(placeholder, format("HSV[%d %d %d]", bgrPixel[0], bgrPixel[1], bgrPixel[2]), Point(20, 140), FONT_HERSHEY_COMPLEX, .9, Scalar(255, 255, 255), 1);

        Size sz1 = img.size();
        Size sz2 = placeholder.size();

        // combine 2 anh
        Mat combinedResult(sz1.height, sz1.width + sz2.width, CV_8UC3);
        Mat left(combinedResult, Rect(0, 0, sz1.width, sz1.height));
        img.copyTo(left);
        Mat Right(combinedResult, Rect(sz1.width, 0, sz2.width, sz2.height));
        placeholder.copyTo(Right);
        imshow("Color Detection", combinedResult);
    }
}

int main(int argc, const char** argv) {
    //std::cout << "Hello World!\n";
    //Mat brightHSV, darkHSV, mask;
    //Mat 
    //Mat bright = cv::imread("img1.jpg");
    img = imread("img1.jpg");
    //Mat dark = cv::imread("img3.jpg");
   // int hmin = 10, smin = 110, vmin = 100;
   // int hmax = 255, smax = 255, vmax = 255;

    // imshow("bright", bright);


     // RGB to HSV
    //cvtColor(bright, brightHSV, COLOR_BGR2HSV);
    //cvtColor(dark, brightHSV, COLOR_BGR2HSV);
    //imshow("brightHSV", brightHSV);

    /*
    //create trackbar
    namedWindow("trackbar", (640,200));
    createTrackbar("HueMin", "trackbar", &hmin, 179);
    createTrackbar("HueMax", "trackbar", &hmax, 179);
    createTrackbar("SatMin", "trackbar", &smin, 255);
    createTrackbar("SatMax", "trackbar", &smax, 255);
    createTrackbar("ValMin", "trackbar", &vmin, 255);
    createTrackbar("ValMax", "trackbar", &vmax, 255);
    int k=0;
    while (k!=27) {
    Scalar lower(hmin, smin, vmin);
    Scalar upper(hmax, smax, vmax);
    inRange(brightHSV, lower, upper, mask);

    imshow("mask", mask);
    k=waitKey(1);
    }*/
    
    Size rsize(400, 400);
    resize(img, img, rsize);

    if (img.empty())
    {
        return -1;
    }

    cout << " next version color dectection with mouse event" << endl;
    namedWindow("1", WINDOW_AUTOSIZE);
    setMouseCallback("1", onMouse);
    imshow("1", img);
    waitKey(0);






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
