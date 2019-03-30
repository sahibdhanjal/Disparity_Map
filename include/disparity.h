#ifndef DISPARITY_H
#define DISPARITY_H

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv/cv.h>
#include <opencv2/core/core_c.h>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <vector>

// radius of the kernel for disparity
#define KERNEL_RADIUS 3

class Disparity {
private:
    /*
    allocate variables for storing the left and right frames,
    the frames in B&W and color after calculating disparity,
    and integer dimensions of each frame and the max disparity
    */
    cv::Mat fr_left, fr_right, disp_map;
    int fr_width, fr_height, max_disp;

    // preprocesses the frame before disparity calculation
    void preprocessFrame(cv::Mat& frame);
    // shifts frame by x,y
    cv::Mat shift(cv::Mat& frame, int x, int y);
    // function replicates the functionality of imfilter from MATLAB
    cv::Mat imfilter(cv::Mat& frame, cv::Mat& kernel);
    // calculates the disparity map
    void calcDisparityMap();

public:
    // constructor and destructor
    Disparity(cv::Mat left, cv::Mat right, int disp);
    ~Disparity();

    // sets left and right frames to new frames
    void setFrames(cv::Mat left, cv::Mat right);
    // outputs disparity map
    cv::Mat getDisparityMap();

};

#endif
