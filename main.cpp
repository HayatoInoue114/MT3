#define _USE_MATH_DEFINES
#include <Novice.h>
#include"Function.h"
#include<math.h>
#include<stdint.h>

const int kWindowWidth = 1280;
const int kWindowHeight = 720;


const char kWindowTitle[] = "LC1A_04";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	//変数の定義
	Vector3 vector1 = { 1.2f,-3.9f,2.5f };
	Vector3 vector2 = { 2.8f,0.4f,-1.3f };
	Vector3 cross = Cross(vector1, vector2);

	Vector3 rotate{};
	Vector3 translate{};
	Vector3 cameraPosition = { 0.0f,0.0f,-5.0f };
	Vector3 kLocalVertices[3];
	kLocalVertices[0] = { 0, 0.5, 0 };
	kLocalVertices[1] = { -0.5, -0.5 ,0 };
	kLocalVertices[2] = { 0.5, -0.5, 0 };
	

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
		rotate.y += 0.01;
		if (keys[DIK_A]) {
			translate.x -= 0.01;
		}
		if (keys[DIK_D]) {
			translate.x += 0.01;
		}

		if (keys[DIK_W]) {
			translate.z += 0.03;
		}
		if (keys[DIK_S]) {
			translate.z -= 0.03;
		}
		Matrix4x4 worldMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, rotate, translate);
		Matrix4x4 cameraMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, { 0.0f,0.0f,0.0f }, cameraPosition);
		Matrix4x4 viewMatrix = Inverse(cameraMatrix);
		Matrix4x4 projectionMatrix = MakePerspectiveFovMatrix(0.45f, float(kWindowWidth) / float(kWindowHeight), 0.1f, 100.0f);
		Matrix4x4 worldViewProjectionMatrix = Multiply(worldMatrix, Multiply(viewMatrix, projectionMatrix));
		Matrix4x4 viewportMatrix = MakeViewportMatrix(0, 0, float(kWindowWidth), float(kWindowHeight), 0.0f, 1.0f);

		Vector3 screenVertices[3];
		for (uint32_t i = 0; i < 3; i++) {
			Vector3 ndcVertex = Transform(kLocalVertices[i], worldViewProjectionMatrix);
			screenVertices[i] = Transform(ndcVertex, viewportMatrix);
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
		Novice::DrawTriangle(
			int(screenVertices[0].x), int(screenVertices[0].y), int(screenVertices[1].x), int(screenVertices[1].y),
			int(screenVertices[2].x), int(screenVertices[2].y), RED, kFillModeSolid
				);

	/*	MatrixScreenPrintf(0, 0,orthographicmatrix);
		MatrixScreenPrintf(0, kRowHeight * 5, perspectiveFovMatrix);
		MatrixScreenPrintf(0, kRowHeight * 5 * 2, viewportMatrix);*/
		/*MatrixScreenPrintf(0, kRowHeight * 5 * 3, rotateXYZmatrix);*/
		
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
