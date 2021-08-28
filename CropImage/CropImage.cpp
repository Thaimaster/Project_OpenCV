// Include Libraries
#include<opencv2/opencv.hpp>
#include<iostream>
#include<string>  

// Namespace nullifies the use of cv::function();
using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("hoa2.png");
    Mat image_copy = img.clone();
    cout << img.size << endl;
    
    int imgheight =     img.rows;
    int imgwidth =  img.cols;
    cout <<"height: "<< imgheight;
    cout << "   width: " << imgwidth << endl;;

    int M = imgheight/3;
    int N = imgwidth/3;

    int x1 = 0;
    int y1 = 0;

    for (int y = 0; y<imgheight; y=y+M)
    {
        for (int x = 0; x<imgwidth; x=x+N)
        {
            
            y1 = y + M;
            x1 = x + N;
            string a = to_string(x);
            string b = to_string(y);
            cout << " x:" << x << "   y:" << y << endl;

            if (x1 >= imgwidth && y1 >= imgheight)
            {
                x1 = imgwidth ;
                y1 = imgheight ;
                cout << " x:" << x << "   y:" << y << endl;
                cout << " x1:" << x1 << "   y1:" << y1 << endl;
                
                // crop the patches of size MxN
                Mat tiles = image_copy(Range(y, imgheight), Range(x, imgwidth));
                //save each patches into file directory
                imwrite("saved_patches/tile" + a + '_' + b + ".jpg", tiles);  
                rectangle(img, Point(x,y), Point(x1,y1), Scalar(0,255,0), 1);   
            }
            else if (y1 >= imgheight)
            {
               y1 = imgheight ;
                cout << " x:" << x << "   y:" << y << endl;
                cout << " x1:" << x1 << "   y1:" << y1 << endl;
                // crop the patches of size MxN
                Mat tiles = image_copy(Range(y, imgheight), Range(x, x+N));
                //save each patches into file directory
                imwrite("saved_patches/tile" + a + '_' + b + ".jpg", tiles);  
                rectangle(img, Point(x,y), Point(x1,y1), Scalar(0,255,0), 1);    
            }
            else if (x1 >= imgwidth)
            {  
                x1 = imgwidth ;
                cout << " x:" << x << "   y:" << y << endl;
                cout << " x1:" << x1 << "   y1:" << y1 << endl;
                
                // crop the patches of size MxN
                Mat tiles = image_copy(Range(y, y+M), Range(x, imgwidth));
                //save each patches into file directory
                imwrite("saved_patches/tile" + a + '_' + b + ".jpg", tiles);  
                rectangle(img, Point(x,y), Point(x1,y1), Scalar(0,255,0), 1);    
            }
            else
            {
                cout << " x:" << x << "   y:" << y << endl;
                cout << " x1:" << x1 << "   y1:" << y1 << endl;
                cout << endl;
                
                // crop the patches of size MxN
                Mat tiles = image_copy(Range(y, y+M), Range(x, x+N));
                //save each patches into file directory
                imwrite("saved_patches/tile" + a + '_' + b + ".jpg", tiles);  
                rectangle(img, Point(x,y), Point(x1,y1), Scalar(0,255,0), 1);  
            }
        }
    }
    imshow("Patched Image", img);
    imwrite("patched.jpg",img);
    waitKey();
    destroyAllWindows();

    return 0;
}