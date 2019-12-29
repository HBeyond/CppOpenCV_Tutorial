#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char *argv[]) {
    string img_path =
        "/home/beyoung/Desktop/mac-ubuntu-share/work/0_Mine/1_C++/15_openCV/OpenCV_Tutorial/test-images/243.png";

    Mat img = imread(img_path);
    int rows = img.rows;
    int cols = img.cols;

    int target_row = rows * 1 / 3;
    int target_col = cols * 1 / 3;
    cout << "row = " << target_row << endl;
    cout << "col = " << target_col << endl;

    // method 1
    uchar blue = img.at<Vec3b>(target_row, target_col)[0];
    uchar green = img.at<Vec3b>(target_row, target_col)[1];
    uchar red = img.at<Vec3b>(target_row, target_col)[2];
    cout << "blue = " << static_cast<unsigned int>(blue) << endl;
    cout << "green = " << static_cast<unsigned int>(green) << endl;
    cout << "red = " << static_cast<unsigned int>(red) << endl;

    // method 2
    cv::Vec3b intensity = img.at<cv::Vec3b>(target_row, target_col);
    cout << "blue2 = " << static_cast<unsigned int>(intensity[0]) << endl;
    cout << "green2 = " << static_cast<unsigned int>(intensity[1]) << endl;
    cout << "red2 = " << static_cast<unsigned int>(intensity[2]) << endl;

    // show
    //    circle(img, Point2i(target_row, target_col), 1, Scalar(0, 0, 255), 1);
    imshow("img", img);
    waitKey(0);

    return 1;
}
