/**
 Blob Detection project
 *
 */

#include<opencv2/opencv.hpp>

using namespace cv;


int main(int argc, char** argv)
{
	Mat img = imread("blob.jpg", IMREAD_GRAYSCALE);
	imshow("anhgoc",img);
	// setup detector params
	SimpleBlobDetector::Params params;
	// Threshold
	params.minThreshold = 10;
	params.maxThreshold = 200;
	//FIlter by area
	params.filterByArea = true;
	params.minArea =1500 ;
	// Filter by circularity - do sat vong tron so vs blob
	params.filterByCircularity = true ;
	params.minCircularity=0.1;
	// Filter by  convexity - Do Lo'i
	params.filterByConvexity =true ;
	params.minConvexity = 0.87;
	// FIlter by Interia
	params.filterByInertia = true;
	params.minInertiaRatio = 0.01; // interia ratio ty le giua truc nho vs truc chinh: Imin/Imax

	// Setup Blobdetector with params
	Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create(params); 

	// Detect blob
	std::vector<KeyPoint> keypoints; // Key: keypoint
	// create smart pointer nen phai dung ->
	detector->detect(img, keypoints);
	//draw red circle
	Mat img_keypoint;
	drawKeypoints(img, keypoints, img_keypoint, Scalar(0, 0, 255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS); 
	// DRAW_RICH_KEYPOINTS dam bao vong tron o trong blob
	// Show blobs
	imshow("keypoints", img_keypoint);
	waitKey(0);

}