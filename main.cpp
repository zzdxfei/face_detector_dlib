#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "FaceDetector.h"

int main(void) {
    const std::string& filename = "1demo.jpg";
    clock_t time_begin = clock();
    for(int i = 0; i != 10; ++i) {
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

        // cv::imshow("img", input_img);
        // cv::waitKey(0);
    }
    clock_t time_end = clock();
    std::cout << "Per image -> "
        << 1000.0 * (time_end - time_begin) / CLOCKS_PER_SEC / 10.0 
        << " ms" << std::endl;
    return 0;
}
