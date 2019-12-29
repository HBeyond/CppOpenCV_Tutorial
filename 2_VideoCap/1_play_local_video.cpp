#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char *argv[]) {
    string local_video_path = "/home/beyoung/Desktop/outputVideo.avi";
    auto capture = VideoCapture(local_video_path);

    Mat frame;

    while (capture.isOpened()) {
        capture >> frame;
        if (!frame.empty()) {
            imshow("local_video", frame);
            if (waitKey(30) == 81) {
                break;
            }
        }
    }

    return 1;
}
