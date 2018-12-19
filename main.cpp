#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>
#include "FaceDetector.h"

int main(void) {
    while(true) {
        const std::string& filename = "demo.png";
        cv::Mat input_img = cv::imread(filename);
        FD::FaceInfo face_info = FD::FaceDetect(input_img);
        std::cout << "faces : " << face_info.faces.size() << std::endl;
        std::cout << "landmarks : " << face_info.landmarks.size() << std::endl;

        if(!face_info.faces.empty()) {
            cv::rectangle(input_img, face_info.faces[0], cv::Scalar(255, 128, 255), 2);
            for(size_t i = 0; i != face_info.landmarks[0].size(); ++i) {
                cv::circle(input_img, face_info.landmarks[0][i], 2, cv::Scalar(0, 255, 0), 2);
            }
        }

        cv::imshow("img", input_img);
        cv::waitKey(0);
    }

    return 0;
}
