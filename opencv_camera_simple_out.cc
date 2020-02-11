// By Art Gavrysh: ghavart@gmail.com (2020)
// https://devtalk.nvidia.com/default/topic/1049463/jetson-nano/i-ve-plugged-in-the-mipi-csi-camera-but-nothing-comes-up-when-i-open-the-cam-/

#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char *argv[]) {
    Mat frame;
    VideoCapture cap;
    cap.open("nvarguscamerasrc ! video/x-raw(memory:NVMM), width=(int)1920, height=(int)1980,format=(string)NV12, framerate=(fraction)15/1 ! nvvidconv ! video/x-raw, format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! appsink");
    if (!cap.isOpened()) {
        std::cerr << "Cannot open thye video0 resource. Exiting" << std::endl;
        return 0;
    }
    while (1) {
        cap >> frame;
        if (frame.empty()) {
            break;
        }
        imshow("cam", frame);
        waitKey(20);
    }
    cap.release();
    return 0;
}
