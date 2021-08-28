// SimpleBackgroundEstimate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<opencv2/opencv.hpp>
#include <iostream>
#include<random>

using namespace std;
using namespace cv;

int computeMedian(vector<int> elements) {
	// tim phan tu “nho” thu n theo thu tu < mac dinh
	nth_element(elements.begin(),
		elements.begin() + elements.size() / 2, // nth position - vi tri n, thuat toan sap xep sao cho ptu thu n sap khi sap xep van o tai vi tri n
												// cac vi tri con lai sap xep ngau nhien
		elements.end());

	return elements[elements.size() / 2];
}

Mat compute_median(vector<Mat> vec) {
	// yeu cau hinh dang dang CV_8UC3
	Mat medianImg(vec[0].rows, vec[0].cols, CV_8UC3, Scalar(0, 0, 0));

	for (int row = 0;row < vec[0].rows;row++) {
		for (int col = 0;col < vec[0].cols;col++) {
			vector<int> elements_B;
			vector<int> elements_G;
			vector<int> elements_R;

			for (int imgNumber = 0;imgNumber < vec.size();imgNumber++) {
				int B = vec[imgNumber].at<Vec3b>(row, col)[0];
				int G = vec[imgNumber].at<Vec3b>(row, col)[1];
				int R = vec[imgNumber].at<Vec3b>(row, col)[2];

				elements_B.push_back(B);
				elements_G.push_back(G);
				elements_R.push_back(R);



			}
			medianImg.at<cv::Vec3b>(row, col)[0] = computeMedian(elements_B);
			medianImg.at<cv::Vec3b>(row, col)[1] = computeMedian(elements_G);
			medianImg.at<cv::Vec3b>(row, col)[2] = computeMedian(elements_R);

		}
	}
	return medianImg;

}

int main(int argc, char const* argv[])
{
	
	//read
	VideoCapture cap("video.mp4");
	if (!cap.isOpened()) {
		cerr << "error  opening video" << endl; // bao loi ngay lap tuc ko can buffer
	}

	// random selected 25 frames
	default_random_engine generator;
	uniform_int_distribution<int>distribution(0, cap.get(CAP_PROP_FRAME_COUNT));

	vector<Mat> frames;
	Mat frame;


	for (int i = 0; i < 25; i++) {
		int fid = distribution(generator);
		cap.set(CAP_PROP_POS_FRAMES, fid);
		Mat frame;
		cap >> frame;
		if (frame.empty())
			continue;
		frames.push_back(frame);
	}

	Mat medianFrame = compute_median(frames);
	imshow("frame", medianFrame);
	imwrite("medianFrame.jpg", medianFrame);
	waitKey(0);
	
	//  Reset frame number to 0
	cap.set(CAP_PROP_POS_FRAMES, 0);
	// convert background to grayscale
	Mat graymedianFrame;
	cvtColor(medianFrame, graymedianFrame, COLOR_BGR2GRAY);
	// loop over all frames in video
	while (1) {
		cap >> frame; //read frame
		if (frame.empty()) break;

	// convert current frame to grayscale
	cvtColor(frame, frame, COLOR_BGR2GRAY);
	// Calculate absolute difference of current frame and the median frame
	Mat dframe;
	absdiff(frame, graymedianFrame, dframe);

	// threshold to binarize
	threshold(dframe, dframe, 30, 200, THRESH_BINARY);

	imshow("DFrame", dframe);
	waitKey(20);
	}



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
