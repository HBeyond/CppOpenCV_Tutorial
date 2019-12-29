#include <fstream>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {
    Mat img = imread(
        "/home/beyoung/Desktop/mac-ubuntu-share/work/0_Mine/1_C++/15_openCV/OpenCV_Tutorial/test-images/lena.jpg");
    //    imshow("img", img);
    //    waitKey(0);

    // 1. image memory from Mat to buffer
    vector<uchar> buffer;
    vector<int> params(2);
    params[0] = CV_IMWRITE_JPEG_QUALITY;
    params[1] = 95;

    imencode(".jpg", img, buffer, params);

    cout << "buffer.size: " << buffer.size() << endl;
    //    for (vector<uchar>::iterator iter = buffer.begin(); iter != buffer.end(); ++iter) {
    //        cout << to_string(*iter.base()) << endl;
    //    }

    // 2. convert from buffer back to Mat and show
    Mat dst;
    dst = imdecode(buffer, CV_LOAD_IMAGE_COLOR);
    imshow("imdecode", dst);
    waitKey(0);
    return 1;
}
