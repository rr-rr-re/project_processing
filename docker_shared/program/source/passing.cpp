#include <pybind11/pybind11.h>

#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>


cv::Mat processing(img){
Cfunc::img;
//input_img
//  cv::Mat be_passed_image = img                 //cv::imread(img);
//Pythonからの画像はそのまま使える？

// Haar 特徴ベースのカスケード分類器による物体検出の準備
// 顔検出用のカスケード分類器を使用
  std::string face_cascade_name =
    "/root/tmp/opencv-3.4.4/data/haarcascades/haarcascade_frontalface_alt.xml";
  cv::CascadeClassifier face_cascade;
  if (!face_cascade.load(face_cascade_name)) {
    std::cerr << "分類器の読み込みに失敗しました。" << std::endl;
    return img;
  };

  //search_face
  std::vector<cv::Rect> faces;
  face_cascade.detectMultiScale(img, faces);

  cv::Mat output_image(img.size(), CV_8UC4);

  img.copyTo(output_image);

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

//  cv::Mat pass_img_to_python = cv::imwrite( output_image);

  return output_image;
  }
}


  BOOST_PYTHON_MODULE( passing ) {
    using namespace boost::python;
    def("processing", &processing);
  }
}
