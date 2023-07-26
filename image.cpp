#include <iostream> // for standard I/O
#include <string>   // for strings
#include <iomanip>  // for controlling float print precision
#include <sstream>  // string to number conversion
#include <opencv2/core.hpp>     // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/core/bindings_utils.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <emscripten.h>
#include <emscripten/bind.h>

namespace ems = emscripten;


int lowThreshold = 50;
const int maxThreshold = 100;
const int ratio = 3;
const int kernel_size = 3;

template<typename T>
cv::Mat cannyImage(int width, int height, const ems::val& typedArray){
    std::vector<T> vec = ems::vecFromJSArray<T>(typedArray);
    cv::Mat mat(width,height, CV_8UC4, vec.data());
    cv::Mat bwmat, rmat, detected_edges;
    cv::cvtColor(mat, bwmat, cv::COLOR_BGRA2GRAY);

    cv::blur( bwmat, detected_edges, cv::Size(3,3) );
    cv::Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );

    
    cv::cvtColor(detected_edges, rmat, cv::COLOR_GRAY2BGRA);
    return rmat;
}

template<typename T>
ems::val matData(const cv::Mat& mat)
{
    return ems::val(ems::memory_view<T>((mat.total()*mat.elemSize())/sizeof(T),
                           (T*)mat.data));
}


EMSCRIPTEN_BINDINGS(my_module) {
    ems::register_vector<uchar>("vector_uchar");
    ems::class_<cv::Mat>("Mat")
        .property("rows", &cv::Mat::rows)
        .property("columns", &cv::Mat::cols)
        .property("data", &matData<unsigned char>);

    ems::function("cannyImage", &cannyImage<unsigned char>);
}

