#include "FaceDetector.h"
#include <dlib/opencv.h>
#include <dlib/image_processing.h>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <algorithm>

namespace FD {

// 获得面积最大的人脸的索引
int GetMaxAreaFaceIndex(const std::vector<dlib::rectangle>& faces) {
    std::vector<float> areas(faces.size());
    for(size_t i = 0; i != faces.size(); ++i) {
        float current = (faces[i].right() - faces[i].left());
        current *= (faces[i].bottom() - faces[i].top());
        areas[i] = current;
    }
    auto max_pos = std::max_element(areas.begin(), areas.end());
    return max_pos - areas.begin();
}

// 将dlib获得的特征点转化为opencv格式
std::vector<cv::Point2f> LandmarksDlib2Opencv(const dlib::full_object_detection& shape) {
    std::vector<cv::Point2f> result(shape.num_parts());
    for(size_t i = 0; i != shape.num_parts(); ++i) {
        result[i] = cv::Point2f(shape.part(i).x(), shape.part(i).y());
    }
    return result;
}

// 将dlib::rectangle转化为opencv::Rect
cv::Rect RectDlib2Opencv(const dlib::rectangle& rect) {
    return cv::Rect(rect.left(), rect.top(),
            (rect.right() - rect.left()), (rect.bottom() - rect.top()));
}

// 获得最大的人脸区域和对应的人脸特征点
FaceInfo FaceDetect(const cv::Mat& image) {
    FaceInfo result;
    if(image.empty()) { return result; }

    dlib::frontal_face_detector face_detector = dlib::get_frontal_face_detector();
    dlib::shape_predictor pose_model;
    dlib::deserialize("shape_predictor_68_face_landmarks.dat") >> pose_model;
    dlib::cv_image<dlib::bgr_pixel> d_image(image);
    std::vector<dlib::rectangle> faces = face_detector(d_image);
    if(faces.empty()) { return result; }
    dlib::rectangle max_area_face = faces[GetMaxAreaFaceIndex(faces)];
    dlib::full_object_detection face_shape = pose_model(d_image, max_area_face);
    result.faces.push_back(RectDlib2Opencv(max_area_face));
    result.landmarks.push_back(LandmarksDlib2Opencv(face_shape));

    return result;
}

}
