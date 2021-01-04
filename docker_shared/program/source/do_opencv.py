import sys
sys.path.append('site-packagesのパス')
from skimage import data, io, filters, color, img_as_ubyte
from sklearn import preprocessing
import numpy as np
import matplotlib.pyplot as plt
import scipy
import Cython


# C++で作成した共有ファイルの.soをインポート
import face_detection

input_path = '/media/docker_shared/mono_develop/img/getImg.jpg'
output_path = '/media/docker_shared/mono_develop/img/kansei.jpg'
# /Users/ruimac/opt/anaconda3/bin/python

try :
    is_road_img = io.imread(input_path)

    # バイナリから読み込み(python3なのでbinaryモードで読み込み)??
    """
    with open(filename, 'rb') as f:
        binary = f.read()
        img = io.imread(BytesIO(data))
    """
    # c++の関数を呼び出し
    result_c_img = passing.processing(is_road_img)

    #ここになんかのscikit-imageの処理を入れて解析してそれもクライアントに送る

    io.imsave(output_path, result_c_img)

except:
    print('Error')

else:
    print("finish (no error)")
