#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {
    Mat img = imread("/home/beyoung/Desktop/mac-ubuntu-share/work/6_image_depth/image/243_d.png");
    imshow("img", img);
    waitKey(0);

    return 1;
}
