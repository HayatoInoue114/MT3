//import numpy as np
//
//def create_affine_matrix(scale, rotation, translation) :
//    # 大きさ変更（拡大縮小）行列
//    scale_matrix = np.diag(scale)
//
//    # 回転行列
//    rotation_x = rotation[0]
//    rotation_y = rotation[1]
//    rotation_z = rotation[2]
//    rotation_matrix = np.array([
//        [np.cos(rotation_y) * np.cos(rotation_z), np.sin(rotation_x) * np.sin(rotation_y) * np.cos(rotation_z) - np.cos(rotation_x) * np.sin(rotation_z), np.cos(rotation_x) * np.sin(rotation_y) * np.cos(rotation_z) + np.sin(rotation_x) * np.sin(rotation_z)],
//            [np.cos(rotation_y) * np.sin(rotation_z), np.sin(rotation_x) * np.sin(rotation_y) * np.sin(rotation_z) + np.cos(rotation_x) * np.cos(rotation_z), np.cos(rotation_x) * np.sin(rotation_y) * np.sin(rotation_z) - np.sin(rotation_x) * np.cos(rotation_z)],
//            [-np.sin(rotation_y), np.sin(rotation_x) * np.cos(rotation_y), np.cos(rotation_x) * np.cos(rotation_y)]
//    ] )
//
//    # 平行移動行列
//        translation_matrix = np.array([
//            [1, 0, 0, translation[0]],
//                [0, 1, 0, translation[1]],
//                [0, 0, 1, translation[2]],
//                [0, 0, 0, 1]
//        ] )
//
//        # 大きさ変更行列、回転行列、平行移動行列を組み合わせたアフィン変換行列
//            affine_matrix = translation_matrix @ rotation_matrix @ scale_matrix
//
//            return affine_matrix
