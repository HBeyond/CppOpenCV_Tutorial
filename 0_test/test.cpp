#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {
    // 1. imshow
    //    Mat img = imread("/home/beyoung/Desktop/mac-ubuntu-share/30_RGB.bmp");
    //    //    Mat img(600, 600, 3);
    //    imshow("img", img);
    //    waitKey();

    // 2. point2f dot
    Point2f a(1.0, 2.0);
    Point2f b(3.0, 4.0);
    cout << a.dot(b) << endl;

    return 1;
}
