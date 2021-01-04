#!/bin/bash
#################################################################
# 入力フォルダのパス
# std::string in_dir_str = argv[1];
# 
# 画像の構成によるモード切替
# (normal | other) normal: online版(一度offline版で処理した場合も)で取得した画像とテキストに対しての処理, other: 画像単体の場合
# std::string mode = argv[2];
# other 用画像の拡張子
# std::string ext_str = argv[3];
# 
# FW用claheのtilesize[int]
# fw_tilesize = atoi(argv[4]);
# 
# FW用claheのcliplimit[int]
# fw_cliplimit = atoi(argv[5]);
# 
# FW用直線フィルタの閾値[int]
# fw_thres = atoi(argv[6]);
# 
# FW用直線フィルタのカーネルサイズ[int]
# fw_kernel_size = atoi(argv[7]);
# 
# CB用claheのtilesize[int]
# cb_tilesize = atoi(argv[8]);
# 
# CB用claheのcliplimit[int]
# cb_cliplimit = atoi(argv[9]);
# 
# 出力フォルダのパス(in_dir_strと同じにするとエラー, save imageを押すたびに画像が上書きされる)
# std::string out_dir_str = argv[10]; 
# 
# CB用サークルボードの横方向のグリッドの数[int]
# int cx = atoi(argv[11]);
# 
# CB用サークルボードの縦方向のグリッドの数[int] 
# int cy = atoi(argv[12]);
# 
# 歪み取り用内部パラメータファイルのパス: noneで歪み取りをしない
##################################################################
./filter_test_3_offline.out \
./offline_img/ \
normal \
jpg \
16 \
26 \
18 \
21 \
16 \
26 \
./offline_img_r/ \
5 \
4 \
none
