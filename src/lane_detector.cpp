//
// Created by a on 24. 11. 5.
//
#include "lane_detector/lane_detector.h"

using namespace std;
using namespace cv;

LaneDetector::LaneDetector()
    : nh(""), pnh("~")
{
    pnh.getParam("demo_method", DEMOTYPE);
    if (DEMOTYPE=="video"){
        subCam = nh.subscribe("/usb_cam/image_raw", 1, &LaneDetector::Cam_CB, this);
    }
    else if (DEMOTYPE=="image") {
        ROS_WARN("Not implemnted yet");
    }
    else {
        ROS_ERROR("Wrong type : %s", DEMOTYPE);
    }
}
void LaneDetector::Cam_CB(const sensor_msgs::Image::ConstPtr &msg) {
    Mat frame = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8)->image;
    Mat grayFrame;
    cvtColor(frame, grayFrame, COLOR_BGR2GRAY);

    Mat blurredFrame;
    Blur(grayFrame, blurredFrame, Size(5,5), Size(1,0));

    Mat edgeFrame;
    Canny(blurredFrame, edgeFrame, 128, 255, 3);

    //show("frame", frame, 1);
    //show("grayFrame", grayFrame, 1);
    show("Blurred Gray Frame", blurredFrame, 1);
    show("Edge Frame", edgeFrame, 1);
}
void LaneDetector::Blur(cv::Mat input_image, cv::Mat &output_image, cv::Size Kernel, cv::Size sigma) {
    GaussianBlur(input_image, output_image, Kernel, sigma.width);

}

void LaneDetector::show(std::string name, cv::Mat frame, int waitkey){
    imshow(name, frame);
    if (waitKey(waitkey) =='c'){
        imwrite("/home/a/catkin_ws/src/lane_detector/frame.jpg", frame);
    }


}