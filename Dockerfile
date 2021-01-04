FROM ubuntu:18.04

WORKDIR /root

ENV DEBIAN_FRONTEND noninteractive
# sh->bash
RUN mv /bin/sh /bin/sh_tmp && ln -s /bin/bash /bin/sh

# apt-get更新 wget取得
RUN sed -i.bak -e "s%http://archive.ubuntu.com/ubuntu/%http://ftp.iij.ad.jp/pub/linux/ubuntu/archive/%g" /etc/apt/sources.list
RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y wget
RUN apt-get install -y apt-utils
RUN apt-get install -y nano
RUN apt-get install -y less

RUN apt-get install -y vim
RUN apt-get install -y git

# 日本語環境＆タイムゾーン
RUN apt-get install -y locales language-pack-ja-base language-pack-ja fonts-ipafont-gothic
RUN locale-gen ja_JP.UTF-8
RUN echo 'export LANG=ja_JP.UTF-8' >> /root/.bashrc
RUN source /root/.bashrc

ENV PYTHONIOENCODING "utf-8"
ENV LANG ja_JP.UTF-8
ENV LC_ALL ja_JP.UTF-8
ENV LC_CTYPE ja_JP.UTF-8

ENV TZ='Asia/Tokyo'
RUN apt-get install -y tzdata

#library install
WORKDIR /root/
RUN mkdir /root/tmp
COPY library /root/tmp

# opencv install
RUN apt-get install -y build-essential cmake unzip pkg-config libavcodec-dev libavformat-dev libswscale-dev libv4l-dev libxvidcore-dev libx264-dev libgtk-3-dev libatlas-base-dev gfortran python3-dev

WORKDIR /root/tmp/

RUN unzip opencv344.zip
RUN unzip opencv344cont.zip
WORKDIR /root/tmp/opencv-3.4.4
RUN mkdir build
WORKDIR /root/tmp/opencv-3.4.4/build
RUN cmake -D CMAKE_BUILD_TYPE=RELEASE -D PYTHON_EXECUTABLE=$(which python3) -D BUILD_opencv_python2=OFF -D BUILD_opencv_python3=ON -D INSTALL_PYTHON_EXAMPLES=ON -D OPENCV_EXTRA_MODULES_PATH=/root/tmp/opencv_contrib-3.4.4/modules ..
RUN make -j11
RUN make install
RUN /bin/bash -c 'echo "/usr/local/lib" > /etc/ld.so.conf.d/opencv.conf'
RUN ldconfig

# group設定
RUN groupadd -g 1001 docker
RUN usermod -aG docker root

# shared folder作成
RUN mkdir /media/docker_shared/
RUN mkdir /media/docker_shared/mono_develop
RUN chown root:docker -R /media/docker_shared/mono_develop
RUN chmod 2775 -R /media/docker_shared/mono_develop

#
RUN apt-get install -y python3
RUN apt-get install -y build-essential
RUN apt-get install -y python3-dev


# python3の設定$HOME/pythonを作りそこにシンボリックを貼って環境変数で読み込みさせる
RUN echo 'alias python=python3' >> ~/.bashrc
# RUN mkdir -p $HOME/python
# RUN ln -s /usr/bin/python3 $HOME/python/python
# ENV PATH=$HOME/python/python:$PATH


RUN echo $PATH

# pipのインストール
RUN apt-get install -y python-pip python3-pip


#必要なモジュールのインストール
RUN pip3 install numpy
RUN pip3 install scipy
RUN pip3 install Cython
RUN pip3 install matplotlib
RUN pip3 install scikit-learn
RUN pip3 install scikit-image

# Pybindのインストール ソースのクローンではなくPIPでインストール
RUN pip3 install pybind11


# sh->bashを元に戻す
RUN rm /bin/sh && mv /bin/sh_tmp /bin/sh
