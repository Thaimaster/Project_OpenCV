// ContourDetection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    //
   ////////////////////////// using gray_image///////////////////////////
    Mat img = imread("ip.jpg");
    Mat img_gray;

    cvtColor(img, img_gray, COLOR_BGR2GRAY);
    imshow("gray image", img_gray);

    Mat threshold_img, contour_img;
    threshold(img_gray, threshold_img, 150, 255, THRESH_BINARY);
    imshow("threshold image", threshold_img);
    waitKey(0);
    destroyAllWindows();

    //////// phat hien dg bao su dung CHAIN_APPROX_NONE
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(threshold_img, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);
    // draw contours
    Mat img_clone = img.clone();
    drawContours(img_clone, contours, -1, Scalar(0, 255, 0), 2);
    imshow("None approximation", img_clone);
    imwrite("contours_none_image.jpg", img_clone);
    waitKey(0);
    destroyAllWindows();

    ///////// phat hien dg bao su dung CHAIN_APPROX_SIMPLE
    ///this method is faster than the CHAIN_APPROX_NONE because 
    // the algorithm does not store all the points, uses less memory, and therefore, takes less time to execute.
    vector<vector<Point>> contours1;
    vector<Vec4i> hierarchy1;
    findContours(threshold_img, contours1,
                                                hierarchy1, // danh sach cac vector chua moi qhe giua cac contour
                                                RETR_TREE // kieu cua contours
                                            , CHAIN_APPROX_SIMPLE // phuong thuc contours
                                                                    );
    // draw contours
    Mat img_clone1 = img.clone();
    drawContours(img_clone1, contours1, -1 // -1 ve tat ca contours
                      , Scalar(0, 255, 0), 2);
    imshow("Simple approximation", img_clone1);
    imwrite("contours_simple_image.jpg", img_clone1);
    waitKey(0);
    destroyAllWindows();

    /*
    /////////////noi cac contour = circle
    Mat img2 = imread("book.jpg");
    Mat img2_gray,thres2;
    cvtColor(img2, img2_gray, COLOR_BGR2GRAY);

    threshold(img2_gray, thres2, 150, 255,THRESH_BINARY);
    vector<vector<Point>> contour3;
    vector<Vec4i> hierarchy3;
    findContours(thres2, contour3, hierarchy3, RETR_TREE, CHAIN_APPROX_NONE);

    Mat img_clone2 = img2.clone();
    drawContours(img_clone2,contour3,-1,Scalar(0, 255, 0), 2);
    imshow("ve theo drawcontour", img_clone2);
    waitKey(0);
    
    Mat img_clone3 = img2.clone();
  
    imshow("CHAIN_APPROX_SIMPLE : chi gom cac diem", img_clone3);
    waitKey(0);
    destroyAllWindows();
        */

    /////////////////////////////////////////////////////////////////////////
    /////////////////using single channel: R, G, B
    //tach 3 kenh b g r
    Mat channels[3];
    split(img, channels);
    // detect using blue channel without threshold
    vector<vector<Point>> contour2;
    vector<Vec4i> hierarchy2;
    findContours(channels[0], contour2, hierarchy2, RETR_TREE, CHAIN_APPROX_NONE);

    Mat img_cloneb= img.clone();
    drawContours(img_cloneb, contour2, -1, Scalar(0, 255, 0), 2);
    imshow("draw contour using blue channel", img_cloneb);
    imwrite("contour_bluechannel.jpg", img_cloneb);
    waitKey(0);
    destroyAllWindows();


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
