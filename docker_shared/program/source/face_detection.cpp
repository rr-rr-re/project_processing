#include <pybind11/pybind11.h>

#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

void face_detect() {

  std::string input_image_path  = "/media/docker_shared/mono_develop/img/lena.jpeg";
  std::string output_image_path = "/media/docker_shared/mono_develop/img/kansei.jpg";

  // 画像を読み込む
  // アルファチャンネル付きに対応するため IMREAD_UNCHANGED を使う
  cv::Mat input_image = cv::imread(input_image_path, cv::IMREAD_UNCHANGED);

  // Haar 特徴ベースのカスケード分類器による物体検出の準備
  // 顔検出用のカスケード分類器を使用
  std::string face_cascade_name =
    "/root/tmp/opencv-3.4.4/data/haarcascades/haarcascade_frontalface_alt.xml";
  cv::CascadeClassifier face_cascade;
  if (!face_cascade.load(face_cascade_name)) {
    std::cerr << "分類器の読み込みに失敗しました。" << std::endl;
  //  return -1;
  };

  // 顔を検出
  std::vector<cv::Rect> faces;
  face_cascade.detectMultiScale(input_image, faces);

  // 出力画像データを入れるオブジェクト
  // アルファチャンネル付きに対応するため CV_8UC4 を使う
  // CV_<bit-depth>{U|S|F}C(<number_of_channels>)
  // CV_8U: ビット深度=符号なし8ビット整数(0〜255)
  // C4: チャンネル数=4
  cv::Mat output_image(input_image.size(), CV_8UC4);

  // 入力画像データを出力画像データにコピー
  input_image.copyTo(output_image);

  for (size_t i=0; i<faces.size(); i++) {
    // 検出した顔の座標を出力
    std::cout << "Face: " << faces[i] << std::endl;
    // 顔の位置に楕円を描画
    cv::Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
    cv::Size size(faces[i].width / 2, faces[i].height / 2);
    cv::Scalar color(255, 0, 255, 255); // Blue, Green, Red, Alpha
    double angle = 0;
    double startAngle = 0;
    double endAngle = 360;
    int thickness = 4;
    cv::ellipse(output_image, center, size, angle, startAngle, endAngle, color, thickness);
  }

  // 画像を出力
  cv::imwrite(output_image_path, output_image);

  //return 0;
}

PYBIND11_MODULE(face_detection, m) {
    m.doc() = "pybind11 example plugin";
    m.def("face_detect", &face_detect, "A function which detect face");
}
