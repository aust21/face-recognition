#include <iostream>
#include <opencv4/opencv2/opencv.hpp>
#include <vector>

int main()
{
    int cameraNumber{0};
    cv::CascadeClassifier classifier;
    classifier.load("resources/face_data.xml");

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

        std::vector<cv::Rect> faces;
        cv::Mat greyFaces;
        cv::cvtColor(frame, greyFaces, cv::COLOR_BGR2GRAY);

        cv::imshow("Cam", greyFaces);

        char keypress = cv::waitKey(1);
        if (keypress == 27)
            break;
    }
}
