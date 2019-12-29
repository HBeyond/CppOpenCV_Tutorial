#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {
    Mat img = imread(
        "/home/beyoung/Desktop/mac-ubuntu-share/work/0_Mine/15_openCV/OpenCV_Tutorial/test-images/reference.png");

    // 1. a poly
    //    Point pts[1][4];
    //    pts[0][0] = Point(215, 220);
    //    pts[0][1] = Point(460, 225);
    //    pts[0][2] = Point(466, 450);
    //    pts[0][3] = Point(235, 465);

    //    const Point* ppt[1] = {pts[0]};
    //    int npt[] = {4};
    //    polylines(img, ppt, npt, 1, 1, Scalar(255), 1, 8, 0);
    //    fillPoly(img, ppt, npt, 1, Scalar(255));

    // 2. a rectangle
    //    Point pts[1][4];  // must obey the link order of each points
    //    pts[0][0] = Point(200, 200);
    //    pts[0][1] = Point(250, 200);
    //    pts[0][2] = Point(250, 250);
    //    pts[0][3] = Point(200, 250);

    //    rectangle(img, pts[0][0], pts[0][2], Scalar(0, 255, 0), 3, 8, 0);  //用矩形画矩形窗
    //    const Point* ppt[1] = {pts[0]};
    //    int npt[] = {4};
    //    fillPoly(img, ppt, npt, 1, Scalar(0, 255, 0));

    // 3. transparently paint
    Mat new_img = img.clone();
    Point pts[1][4];  // must obey the link order of each points
    pts[0][0] = Point(200, 200);
    pts[0][1] = Point(250, 200);
    pts[0][2] = Point(250, 250);
    pts[0][3] = Point(200, 250);

    rectangle(img, pts[0][0], pts[0][2], Scalar(0, 255, 0), 3, 8, 0);  //用矩形画矩形窗
    const Point* ppt[1] = {pts[0]};
    int npt[] = {4};
    fillPoly(img, ppt, npt, 1, Scalar(0, 255, 0));
    addWeighted(new_img, 0.7, img, 0.3, 0, new_img);
    imshow("new_img", new_img);
    waitKey();

    // show
    imshow("img", img);
    waitKey();

    return 1;
}
