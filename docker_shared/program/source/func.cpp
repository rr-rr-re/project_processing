/*
#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

// This is sript for fauction



  cv::Mat input_image = cv::imread(pass_from_python, cv::IMREAD_UNCHANGED);

//画像データ
  static const int GRAY = 1;
cv::Mat create_image(int type, int rows, int cols, void* data){
    cv:: Mat img;
    if( type == GRAY){
        //グレイ画像
        img = cv::Mat(rows, cols, CV_8UC1 , data);   //CV_8UC1 はOpenCVの定数
    }else{
        //カラー画像
        img = cv::Mat(rows, cols, CV_8UC3 , data);   //CV_8UC3はOpenCVの定数
    }

    return img;
}






  // Haar 特徴ベースのカスケード分類器による物体検出の準備
  // 顔検出用のカスケード分類器を使用
  std::string face_cascade_name =
    "/root/tmp/opencv-3.4.4/data/haarcascades/haarcascade_frontalface_alt.xml";
  cv::CascadeClassifier face_cascade;
  if (!face_cascade.load(face_cascade_name)) {
    std::cerr << "分類器の読み込みに失敗しました。" << std::endl;
    return -1;
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
  cv::Mat pass_to_python_img << imwrite(output_image);

  return 0;

}

*/
