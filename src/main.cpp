#include <iostream>
#include <opencv4/opencv2/opencv.hpp>
#include <vector>

int main()
{
    int cameraNumber{0};
    cv::CascadeClassifier classifier;
    classifier.load("../../resources/face_data.xml");

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
        classifier.detectMultiScale(greyFaces, faces, 1.1, 3, 0, cv::Size(30, 30));

        for (const cv::Rect &face : faces) {
            cv::rectangle(frame, face, cv::Scalar(255, 0, 0), 1);
        }
        cv::imshow("Cam", frame);

        char keypress = cv::waitKey(1);
        if (keypress == 27)
            break;
    }
}
