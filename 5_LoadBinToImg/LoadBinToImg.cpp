#include <stdio.h>
#include <fstream>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {
    string targetPath =
        "/home/beyoung/Desktop/mac-ubuntu-share/work/6_image_depth/depth_img_analysis_results_far1500/249.bin";
    string savePath = "/home/beyoung/Desktop/dst.jpg";
    ifstream rfs(targetPath, ios::in | ios::binary);
    // get the data lengh
    streampos pos = rfs.tellg();
    rfs.seekg(0, ios::end);
    int bufSize = rfs.tellg();
    rfs.seekg(pos);
    // create buffer
    char* rBuffer = (char*)malloc(bufSize);
    // read
    rfs.read(rBuffer, bufSize);
    // convert to Mat
    Mat img;
    img.create(800, 1280, CV_8UC4);
    memcpy(img.data, rBuffer, bufSize);
    // show
    Mat bgra, dst;
    cvtColor(img, bgra, CV_RGBA2BGR);
    flip(bgra, dst, 0);
    imshow("image", dst);
    if (waitKey(0) == 13) {
        imwrite(savePath, dst);
        cout << "save" << endl;
    } else {
        cout << "not save" << endl;
    }

    return 1;
}
