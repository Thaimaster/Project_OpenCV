// Image Filtering_Convolution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;
int main()
{
    std::cout << "Hello World!\n";
    //identity filter using kernel
    Mat kernel1 = (Mat_<double>(3, 3) << 0, 0, 0,
                                         0, 1, 0,
                                         0, 0, 0);
    Mat identity,gaussianblur;
    Mat img = imread("wood.jpg");
    imshow("anh goc", img);
    filter2D(img, identity, -1, kernel1, Point(-1, -1), 0, 4);
    imshow("identity filter", identity);
    imwrite("identity.jpg", identity);
    // Gaussian Blur
    Mat kernel2 = Mat::ones(5, 5, CV_64F);
    // chuan hoa ma tran
    kernel2 = kernel2 / 25;
    filter2D(img, gaussianblur, -1, kernel2, Point(-1, -1), 0, 4);
    imshow("Gaussian blur filter", gaussianblur);
    imwrite("Gaussian_blur.jpg", gaussianblur);

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
