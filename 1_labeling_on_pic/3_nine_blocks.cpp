#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {
    Mat img = imread(
        "/home/beyoung/Desktop/mac-ubuntu-share/work/0_Mine/15_openCV/OpenCV_Tutorial/test-images/reference.png");
    Mat dst = img.clone();

    // create nine blocks
    uint32_t width = 1936;
    uint32_t height = 1216;

    int resolution_width_cut_ = 8;              // the pixel to be cut at width
    int resolution_height_cut_ = 8;             // the pixel to be cut at height
    int width_resolution_piece_length_;         // the width resolution piece length
    int height_resolution_piece_length_;        // the height resolution piece length
    std::vector<int> width_separation_points_;  // the width separation points
    std::vector<int> height_separation_points_;

    int x_shift = 50;
    int y_shift = 100;

    double font_scale = 2.0;
    int thickness = 2.0;

    width_resolution_piece_length_ = (width - resolution_width_cut_ * 2) / 3;
    height_resolution_piece_length_ = (height - resolution_height_cut_ * 2) / 3;
    for (size_t i = 0; i < 4; ++i) {
        int width_point = resolution_width_cut_ + width_resolution_piece_length_ * i;
        width_separation_points_.emplace_back(width_point);
    }
    for (size_t i = 0; i < 4; ++i) {
        int height_point = resolution_height_cut_ + height_resolution_piece_length_ * i;
        height_separation_points_.emplace_back(height_point);
    }

    int npt[] = {4};

    bool paint = true;
    if (paint) {  // painting mode
        // LU
        Point pts_LU[1][4];
        pts_LU[0][0] = Point(width_separation_points_[0], height_separation_points_[0]);
        pts_LU[0][1] = Point(width_separation_points_[1], height_separation_points_[0]);
        pts_LU[0][2] = Point(width_separation_points_[1], height_separation_points_[1]);
        pts_LU[0][3] = Point(width_separation_points_[0], height_separation_points_[1]);
        rectangle(img, pts_LU[0][0], pts_LU[0][2], Scalar(0, 0, 255), 3, 8, 0);  //用矩形画矩形窗
        const Point* ppt_LU[1] = {pts_LU[0]};
        fillPoly(img, ppt_LU, npt, 1, Scalar(0, 0, 255));
        // addWeighted(dst, 0.7, img, 0.3, 0, dst);
        // MU
        Point pts_MU[1][4];
        pts_MU[0][0] = Point(width_separation_points_[1], height_separation_points_[0]);
        pts_MU[0][1] = Point(width_separation_points_[2], height_separation_points_[0]);
        pts_MU[0][2] = Point(width_separation_points_[2], height_separation_points_[1]);
        pts_MU[0][3] = Point(width_separation_points_[1], height_separation_points_[1]);
        rectangle(img, pts_MU[0][0], pts_MU[0][2], Scalar(0, 165, 255), 3, 8, 0);  //用矩形画矩形窗
        const Point* ppt_MU[1] = {pts_MU[0]};
        fillPoly(img, ppt_MU, npt, 1, Scalar(0, 165, 255));
        // addWeighted(dst, 0.7, img, 0.3, 0, dst);
        // RU
        Point pts_RU[1][4];
        pts_RU[0][0] = Point(width_separation_points_[2], height_separation_points_[0]);
        pts_RU[0][1] = Point(width_separation_points_[3], height_separation_points_[0]);
        pts_RU[0][2] = Point(width_separation_points_[3], height_separation_points_[1]);
        pts_RU[0][3] = Point(width_separation_points_[2], height_separation_points_[1]);
        rectangle(img, pts_RU[0][0], pts_RU[0][2], Scalar(0, 255, 255), 3, 8, 0);  //用矩形画矩形窗
        const Point* ppt_RU[1] = {pts_RU[0]};
        fillPoly(img, ppt_RU, npt, 1, Scalar(0, 255, 255));
        // addWeighted(dst, 0.7, img, 0.3, 0, dst);
        // LM
        Point pts_LM[1][4];
        pts_LM[0][0] = Point(width_separation_points_[0], height_separation_points_[1]);
        pts_LM[0][1] = Point(width_separation_points_[1], height_separation_points_[1]);
        pts_LM[0][2] = Point(width_separation_points_[1], height_separation_points_[2]);
        pts_LM[0][3] = Point(width_separation_points_[0], height_separation_points_[2]);
        rectangle(img, pts_LM[0][0], pts_LM[0][2], Scalar(0, 255, 0), 3, 8, 0);  //用矩形画矩形窗
        const Point* ppt_LM[1] = {pts_LM[0]};
        fillPoly(img, ppt_LM, npt, 1, Scalar(0, 255, 0));
        addWeighted(dst, 0.7, img, 0.3, 0, dst);
        // MM
        Point pts_MM[1][4];
        pts_MM[0][0] = Point(width_separation_points_[1], height_separation_points_[1]);
        pts_MM[0][1] = Point(width_separation_points_[2], height_separation_points_[1]);
        pts_MM[0][2] = Point(width_separation_points_[2], height_separation_points_[2]);
        pts_MM[0][3] = Point(width_separation_points_[1], height_separation_points_[2]);
        rectangle(img, pts_MM[0][0], pts_MM[0][2], Scalar(0, 127, 255), 3, 8, 0);  //用矩形画矩形窗
        const Point* ppt_MM[1] = {pts_MM[0]};
        fillPoly(img, ppt_MM, npt, 1, Scalar(0, 127, 255));
        // addWeighted(dst, 0.7, img, 0.3, 0, dst);
        // RM
        Point pts_RM[1][4];
        pts_RM[0][0] = Point(width_separation_points_[2], height_separation_points_[1]);
        pts_RM[0][1] = Point(width_separation_points_[3], height_separation_points_[1]);
        pts_RM[0][2] = Point(width_separation_points_[3], height_separation_points_[2]);
        pts_RM[0][3] = Point(width_separation_points_[2], height_separation_points_[2]);
        rectangle(img, pts_RM[0][0], pts_RM[0][2], Scalar(255, 0, 0), 3, 8, 0);  //用矩形画矩形窗
        const Point* ppt_RM[1] = {pts_RM[0]};
        fillPoly(img, ppt_RM, npt, 1, Scalar(255, 0, 0));
        // addWeighted(dst, 0.7, img, 0.3, 0, dst);
        // LL
        Point pts_LL[1][4];
        pts_LL[0][0] = Point(width_separation_points_[0], height_separation_points_[2]);
        pts_LL[0][1] = Point(width_separation_points_[1], height_separation_points_[2]);
        pts_LL[0][2] = Point(width_separation_points_[1], height_separation_points_[3]);
        pts_LL[0][3] = Point(width_separation_points_[0], height_separation_points_[3]);
        rectangle(img, pts_LL[0][0], pts_LL[0][2], Scalar(255, 0, 139), 3, 8, 0);  //用矩形画矩形窗
        const Point* ppt_LL[1] = {pts_LL[0]};
        fillPoly(img, ppt_LL, npt, 1, Scalar(255, 0, 139));
        // ML
        Point pts_ML[1][4];
        pts_ML[0][0] = Point(width_separation_points_[1], height_separation_points_[2]);
        pts_ML[0][1] = Point(width_separation_points_[2], height_separation_points_[2]);
        pts_ML[0][2] = Point(width_separation_points_[2], height_separation_points_[3]);
        pts_ML[0][3] = Point(width_separation_points_[1], height_separation_points_[3]);
        rectangle(img, pts_ML[0][0], pts_ML[0][2], Scalar(0, 0, 255), 3, 8, 0);  //用矩形画矩形窗
        const Point* ppt_ML[1] = {pts_ML[0]};
        fillPoly(img, ppt_ML, npt, 1, Scalar(0, 0, 255));
        // RL
        Point pts_RL[1][4];
        pts_RL[0][0] = Point(width_separation_points_[2], height_separation_points_[2]);
        pts_RL[0][1] = Point(width_separation_points_[3], height_separation_points_[2]);
        pts_RL[0][2] = Point(width_separation_points_[3], height_separation_points_[3]);
        pts_RL[0][3] = Point(width_separation_points_[2], height_separation_points_[3]);
        rectangle(img, pts_RL[0][0], pts_RL[0][2], Scalar(0, 255, 0), 3, 8, 0);  //用矩形画矩形窗
        const Point* ppt_RL[1] = {pts_RL[0]};
        fillPoly(img, ppt_RL, npt, 1, Scalar(0, 255, 0));

        // show
        addWeighted(dst, 0.7, img, 0.3, 0, dst);
        namedWindow("show", 0);
        cvResizeWindow("show", 800, 400);
        imshow("show", dst);
        waitKey();

    } else {  // number mode
        vector<vector<Point>> rect_diag;
        vector<Point> LU_rect;
        LU_rect.emplace_back(Point(width_separation_points_[0], height_separation_points_[0]));
        LU_rect.emplace_back(Point(width_separation_points_[1], height_separation_points_[1]));
        rect_diag.emplace_back(LU_rect);

        // LU
        Point pt1_LU = Point(width_separation_points_[0], height_separation_points_[0]);  //点坐标1
        Point pt2_LU = Point(width_separation_points_[1], height_separation_points_[1]);  //点坐标2
        rectangle(img, pt1_LU, pt2_LU, Scalar(0, 0, 255), 3, 8, 0);  //用点画矩形窗// print the number
        string label = "0";
        putText(img, label.c_str(), Point(pt1_LU.x + x_shift, pt1_LU.y + y_shift), CV_FONT_HERSHEY_COMPLEX, font_scale,
                Scalar(0, 255, 0), thickness);

        // MU
        Point pt1_MU = Point(width_separation_points_[1], height_separation_points_[0]);  //点坐标1
        Point pt2_MU = Point(width_separation_points_[2], height_separation_points_[1]);  //点坐标2
        rectangle(img, pt1_MU, pt2_MU, Scalar(0, 0, 255), 3, 8, 0);                       //用点画矩形窗
        putText(img, label.c_str(), Point(pt1_MU.x + x_shift, pt1_MU.y + y_shift), CV_FONT_HERSHEY_COMPLEX, font_scale,
                Scalar(0, 255, 0), thickness);

        // RU
        Point pt1_RU = Point(width_separation_points_[2], height_separation_points_[0]);  //点坐标1
        Point pt2_RU = Point(width_separation_points_[3], height_separation_points_[1]);  //点坐标2
        rectangle(img, pt1_RU, pt2_RU, Scalar(0, 0, 255), 3, 8, 0);                       //用点画矩形窗
        putText(img, label.c_str(), Point(pt1_RU.x + x_shift, pt1_RU.y + y_shift), CV_FONT_HERSHEY_COMPLEX, font_scale,
                Scalar(0, 255, 0), thickness);

        // LM
        Point pt1_LM = Point(width_separation_points_[0], height_separation_points_[1]);  //点坐标1
        Point pt2_LM = Point(width_separation_points_[1], height_separation_points_[2]);  //点坐标2
        rectangle(img, pt1_LM, pt2_LM, Scalar(0, 0, 255), 3, 8, 0);                       //用点画矩形窗
        putText(img, label.c_str(), Point(pt1_LM.x + x_shift, pt1_LM.y + y_shift), CV_FONT_HERSHEY_COMPLEX, font_scale,
                Scalar(0, 255, 0), thickness);

        // MM
        Point pt1_MM = Point(width_separation_points_[1], height_separation_points_[1]);  //点坐标1
        Point pt2_MM = Point(width_separation_points_[2], height_separation_points_[2]);  //点坐标2
        rectangle(img, pt1_MM, pt2_MM, Scalar(0, 0, 255), 3, 8, 0);                       //用点画矩形窗
        putText(img, label.c_str(), Point(pt1_MM.x + x_shift, pt1_MM.y + y_shift), CV_FONT_HERSHEY_COMPLEX, font_scale,
                Scalar(0, 255, 0), thickness);

        // RM
        Point pt1_RM = Point(width_separation_points_[2], height_separation_points_[1]);  //点坐标1
        Point pt2_RM = Point(width_separation_points_[3], height_separation_points_[2]);  //点坐标2
        rectangle(img, pt1_RM, pt2_RM, Scalar(0, 0, 255), 3, 8, 0);                       //用点画矩形窗
        putText(img, label.c_str(), Point(pt1_RM.x + x_shift, pt1_RM.y + y_shift), CV_FONT_HERSHEY_COMPLEX, font_scale,
                Scalar(0, 255, 0), thickness);

        // LL
        Point pt1_LL = Point(width_separation_points_[0], height_separation_points_[2]);  //点坐标1
        Point pt2_LL = Point(width_separation_points_[1], height_separation_points_[3]);  //点坐标2
        rectangle(img, pt1_LL, pt2_LL, Scalar(0, 0, 255), 3, 8, 0);                       //用点画矩形窗
        putText(img, label.c_str(), Point(pt1_LL.x + x_shift, pt1_LL.y + y_shift), CV_FONT_HERSHEY_COMPLEX, font_scale,
                Scalar(0, 255, 0), thickness);

        // ML
        Point pt1_ML = Point(width_separation_points_[1], height_separation_points_[2]);  //点坐标1
        Point pt2_ML = Point(width_separation_points_[2], height_separation_points_[3]);  //点坐标2
        rectangle(img, pt1_ML, pt2_ML, Scalar(0, 0, 255), 3, 8, 0);                       //用点画矩形窗
        putText(img, label.c_str(), Point(pt1_ML.x + x_shift, pt1_ML.y + y_shift), CV_FONT_HERSHEY_COMPLEX, font_scale,
                Scalar(0, 255, 0), thickness);

        // RL
        Point pt1_RL = Point(width_separation_points_[2], height_separation_points_[2]);  //点坐标1
        Point pt2_RL = Point(width_separation_points_[3], height_separation_points_[3]);  //点坐标2
        rectangle(img, pt1_RL, pt2_RL, Scalar(0, 0, 255), 3, 8, 0);                       //用点画矩形窗
        putText(img, label.c_str(), Point(pt1_RL.x + x_shift, pt1_RL.y + y_shift), CV_FONT_HERSHEY_COMPLEX, font_scale,
                Scalar(0, 255, 0), thickness);

        // show
        namedWindow("show", 0);
        cvResizeWindow("show", 400, 200);
        imshow("show", img);
        waitKey();
    }

    return 1;
}
