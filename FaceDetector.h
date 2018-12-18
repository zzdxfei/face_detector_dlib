#ifndef face_detector_h_
#define  face_detector_h_

#include <vector>
#include <opencv2/opencv.hpp>

namespace FD {

struct Point {
    float x, y;  // w, h
};
struct Rect {
    Point p0, p1;  // 左上角, 右下角
};

struct FaceInfo {
    // 检测到的人脸
    std::vector<Rect> faces;
    // 人脸关键点
    std::vector<std::vector<Point> > landmarks;
};

FaceInfo FaceDetect()

}

#endif /* ifndef  */
