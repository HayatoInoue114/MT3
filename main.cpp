#define _USE_MATH_DEFINES
#include <Novice.h>
#include"Function.h"
#include<math.h>



const char kWindowTitle[] = "LC1A_04";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	//変数の定義
	Matrix4x4 m1 = { 3.2f,0.7f,9.6f,4.4f,
					5.5f,1.3f,7.8f,2.1f,
					6.9f,8.0f,2.6f,1.0f,
					0.5f,7.2f,5.1f,3.3f };

	Matrix4x4 m2 = { 4.1f,6.5f,3.3f,2.2f,
					8.8f,0.6f,9.9f,7.7f,
					1.1f,5.5f,6.6f,0.0f,
					3.3f,9.9f,8.8f,2.2f };

	/*const int WhiteTexture = Novice::LoadTexture("white1x1.png");*/

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		Vector3 scale{ 1.2f,0.79f,-2.1f };
		Vector3 rotate{ 0.4f,1.43f,-0.8f };
		Vector3 translate{ 2.7f,-4.15f,1.57f };
		Matrix4x4 worldMatrix = MakeAffineMatrix(scale, rotate, translate);
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		MatrixScreenPrintf(0, 0,worldMatrix);
		/*MatrixScreenPrintf(0, kRowHeight * 5, rotateYMatrix);
		MatrixScreenPrintf(0, kRowHeight * 5 * 2, rotateZMatrix);
		MatrixScreenPrintf(0, kRowHeight * 5 * 3, rotateXYZmatrix);*/
		
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
