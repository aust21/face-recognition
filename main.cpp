#include <iostream>
#include <opencv4/opencv2/opencv.hpp>

int main()
{
    int cameraNumber{0};

    cv::VideoCapture cam;
    cam.open(cameraNumber, cv::CAP_V4L2);

    if (!cam.isOpened()) {
        std::cout << "Error opening camera" << std::endl;
        exit(1);
    }
}
