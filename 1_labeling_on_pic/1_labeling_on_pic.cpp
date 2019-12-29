#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {
    vector<Point> k(2);
    vector<int> p = {1, 2, 3, 4, 5, 6};

    Mat img = imread(
        "/home/beyoung/Desktop/mac-ubuntu-share/work/0_Mine/1_C++/15_openCV/OpenCV_Tutorial/test-images/243.png");

    vector<Point2f> reference_image_corners;
    cv::Size board_size(5, 4);
    bool found = false;
    int flag = CALIB_CB_ADAPTIVE_THRESH | CALIB_CB_NORMALIZE_IMAGE;

    // 1. detect corners in reference image, and plot circle on the corner points
    found = findChessboardCorners(img, board_size, reference_image_corners, flag);
    for (auto& val : reference_image_corners) {
        circle(img, val, 2, Scalar(0, 0, 255), 5);
    }

    // 2. rectangel and number description and write a number one the left top of the rectangle
    //    Rect select;  //声明矩形
    //    Point pt1;    //点坐标1
    //    Point pt2;    //点坐标2

    //    select.x = 50;
    //    select.y = 50;
    //    select.width = 100;
    //    select.height = 100;

    //    pt1.x = 200;
    //    pt1.y = 200;
    //    pt2.x = 250;
    //    pt2.y = 250;

    //    rectangle(img, select, Scalar(0, 255, 0), 3, 8, 0);    //用矩形画矩形窗
    //    rectangle(img, pt1, pt2, Scalar(0, 0, 255), 3, 8, 0);  //用点画矩形窗

    //    // print the number
    //    string label = "999";
    //    putText(img, label.c_str(), Point(224, 225), CV_FONT_HERSHEY_COMPLEX, 0.5, Scalar(0, 255, 0));

    // show
    cv::imshow("show", img);
    waitKey(0);

    return 1;
}
