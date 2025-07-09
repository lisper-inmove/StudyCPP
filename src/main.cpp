#include <opencv4/opencv2/core/mat.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <string>
#include <opencv2/opencv.hpp>

/**
   OpenCV 中的 膨胀（Dilation）操作
   是形态学处理的一种，通常用于放大图像中白色区域（前景），在噪声去除、边缘检测、形状增强中非常常见。
 */

void createLetterImage(std::string text) {
    // 创建黑色背景
    cv::Mat image = cv::Mat::zeros(200, 600, CV_8UC3);

    // 设置字体、大小、颜色
    int fontFace     = cv::FONT_HERSHEY_SIMPLEX;
    double fontScale = 2;
    int thickness    = 3;
    cv::Scalar color(255, 255, 255);  // 白色

    // 计算文本尺寸以居中显示
    int baseline      = 0;
    cv::Size textSize = cv::getTextSize(text, fontFace, fontScale, thickness, &baseline);
    cv::Point textOrg((image.cols - textSize.width) / 2, (image.rows + textSize.height) / 2);

    // 画字
    cv::putText(image, text, textOrg, fontFace, fontScale, color, thickness);

    // 保存 & 显示
    cv::imwrite("text_image.png", image);
}

void createTestImageForDilate() {
    // 创建黑色图像
    cv::Mat image = cv::Mat::zeros(200, 200, CV_8UC1);

    // 画一些白色的图形用于测试
    cv::rectangle(image, cv::Point(50, 50), cv::Point(100, 100), cv::Scalar(255),
                  -1);                                                             // 实心矩形
    cv::circle(image, cv::Point(150, 50), 20, cv::Scalar(255), -1);                // 实心圆
    cv::line(image, cv::Point(30, 150), cv::Point(170, 150), cv::Scalar(255), 2);  // 白色直线

    // 保存为PNG
    cv::imwrite("test.png", image);
}

int main() {
    createLetterImage("Hello");
    std::string filename = "text_image.png";
    cv::Mat src          = cv::imread(filename);

    cv::Mat gray;
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);

    cv::Mat binary;
    cv::threshold(gray, binary, 200, 255, cv::THRESH_BINARY);

    int kernelSize = 7;
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(kernelSize, kernelSize));

    cv::Mat dilated;
    cv::dilate(binary, dilated, kernel);

    cv::Size newSize(512, 512);
    cv::resize(src, src, newSize);
    cv::resize(binary, binary, newSize);
    cv::resize(dilated, dilated, newSize);

    cv::imshow("src", src);
    cv::imshow("binary", binary);
    cv::imshow("dilated", dilated);

    cv::waitKey(0);

    return 0;
}
