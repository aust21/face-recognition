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

    while (true) {
        cv::Mat frame;
        cam >> frame;
        if (frame.empty()) {
            std::cerr << "Error reading frame" << std::endl;
            exit(1);
        }
        cv::Mat flipped_output;
        cv::flip(frame, flipped_output, 1);
        cv::imshow("Cam", flipped_output);

        char keypress = cv::waitKey(1);
        if (keypress == 27)
            break;
    }
}
