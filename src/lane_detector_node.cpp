//
// Created by a on 24. 11. 5.
//
#include "lane_detector/lane_detector.h"

using namespace std;

int main(int argc, char **argv){
  ros::init(argc, argv, "lane_detector");
  LaneDetector lane_detector;
  ros::spin();
  }
