#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <string>
#include <vector>
#include <dlib/image_processing.h>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>

std::vector<float> GetFaceLandmarks(const cv::Mat& image) {
    // TODO
}

int main(void) {
    const std::string& filename = "ddemo.jpg";
    cv::Mat input_img = cv::imread(filename);
    if(input_img.empty()) {
        std::cerr << "can\'t read input image -> " << filename << std::endl;
        return 0;
    }

    cv::imshow("img", input_img);
    cv::waitKey(0);
    return 0;
}
