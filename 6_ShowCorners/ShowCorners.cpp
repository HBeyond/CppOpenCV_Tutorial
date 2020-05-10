#include <stdio.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
#include "boost/filesystem.hpp"

using namespace std;
using namespace cv;
using namespace boost::filesystem;

int main(int argc, char* argv[]) {
    string targetPath =
        "/home/beyoung/Desktop/mac-ubuntu-share/2_sensor_alignment/10_Corner3D_CameraPoseReconstructor/1_data/"
        "2_20200312_binyang/Position1/dataSet_5/camNormal1";
    // add all the images
    vector<string> image_paths;
    path file_path(targetPath);
    if (!exists(file_path)) {
        cout << "file path not exists" << endl;
    }
    directory_iterator end;
    for (directory_iterator pos(file_path); pos != end; ++pos) {
        //        cout << pos->path().extension().string() << endl;
        if (strcmp(pos->path().extension().string().c_str(), ".png") == 0) {
            image_paths.emplace_back(pos->path().string());
        }
    }

    // show(
    if (!image_paths.empty()) {
        for (size_t var = 0; var < image_paths.size(); ++var) {
            Mat img = imread(image_paths[var], IMREAD_UNCHANGED);
            int cols = 5;
            int rows = 4;
            Size board_size(cols, rows);
            vector<Point2f> corners;
            int flags = CALIB_CB_ADAPTIVE_THRESH + CALIB_CB_NORMALIZE_IMAGE + CALIB_CB_FAST_CHECK;
            bool find_corners = findChessboardCorners(img, board_size, corners, flags);
            //            imshow("img", img);
            //            waitKey(10);
            if (find_corners) {
                cout << "corners in image: " << image_paths[var] << endl;
                cout << corners << endl;
                drawChessboardCorners(img, board_size, corners, find_corners);
                namedWindow("found corners", WINDOW_NORMAL);
                imshow("found corners", img);
                waitKey(0);
                destroyWindow("found corners");
            } else {
                cout << "cannot find corners in image " << image_paths[var] << endl;
            }
        }
    }
    return 1;
}
