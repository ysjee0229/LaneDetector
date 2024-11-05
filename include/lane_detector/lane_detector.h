//
// Created by a on 24. 11. 5.
//

#ifndef LANE_DETECTOR_H
#define LANE_DETECTOR_H
#include <ros/ros.h>

#include <opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>

#include <sensor_msgs/Image.h>

class LaneDetector {
    private:
    //Variables
    ros::NodeHandle nh;
    ros::NodeHandle pnh;
    ros::Subscriber subCam;

    //Functions-ROS
    void Cam_CB(const sensor_msgs::Image::ConstPtr& msg);

    //Functions-Opencv
    void Blur(cv::Mat input_image, cv::Mat &output_image, cv::Size Kernel, cv::Size sigma);

    void show(std::string name, cv::Mat frame, int waitkey);



    public:
    LaneDetector();

};

#endif //LANE_DETECTOR_H
