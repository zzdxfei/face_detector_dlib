#ifndef face_detector_h_
#define  face_detector_h_

#include <vector>
#include <opencv2/opencv.hpp>

namespace FD {

struct FaceInfo {
    std::vector<std::vector<cv::Point2f> > landmarks;
    std::vector<cv::Rect> faces;
};

FaceInfo FaceDetect(const cv::Mat& image);

}

#endif
