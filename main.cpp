#define _USE_MATH_DEFINES
#include <Novice.h>
#include"Function.h"
#include<math.h>
#include<stdint.h>
#include<imgui.h>


const char kWindowTitle[] = "LE2B_03";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	//変数の定義


	Vector3 cameraTranslate{ 0.0f,1.9f,-6.49f };
	Vector3 cameraRotate{ 0.26f,0.0f,0.0f, };

	Sphere sphere1;
	sphere1.center = { 0.0f, 0.0f, 0.0f };
	sphere1.radius = 1.0f;

	Sphere sphere2;
	sphere2.center = { 0.5f, 0.5f, 0.0f };
	sphere2.radius = 1.0f;

	Plane plane = { {0,1,0},1 };

	Segment segment = { {0,0,0},{1,1,1} };

	Triangle triangle{};
	triangle.vertices[0] = { -1,0,0 };
	triangle.vertices[1] = { 0,1,0 };
	triangle.vertices[2] = { 1,0,0 };


	AABB aabb1{
		{-1.0f, -1.0f, -1.0f},
		{ 0.0f, 0.0f, 0.0f}
	};
	AABB aabb2{
		{0.5f, 0.5f, 0.5f},
		{ 1.0f, 1.0f, 1.0f}
	};

	unsigned int color = WHITE;
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
		Matrix4x4 cameraMatrix = MakeAffineMatrix({ 1.0f, 1.0f, 1.0f }, cameraRotate, cameraTranslate);
		Matrix4x4 viewMatrix = Inverse(cameraMatrix);
		Matrix4x4 projectionMatrix = MakePerspectiveFovMatrix(0.45f, float(kWindowWidth) / float(kWindowHeight), 0.1f, 100.0f);
		Matrix4x4 viewProjectionMatrix = Multiply(viewMatrix, projectionMatrix);
		Matrix4x4 viewportMatrix = MakeViewportMatrix(0, 0, float(kWindowWidth), float(kWindowHeight), 0.0f, 1.0f);

		if (IsCollision(aabb1, sphere2)) {
			color = RED;
		}
		else {
			color = WHITE;
		}

		ImGui::Begin("Window");
		ImGui::DragFloat3("CameraTranslate", &cameraTranslate.x, 0.01f);
		ImGui::DragFloat3("CameraRotate", &cameraRotate.x, 0.01f);
		ImGui::DragFloat3("AABB1min", &aabb1.min.x, 0.01f);
		ImGui::DragFloat3("AABB1max", &aabb1.max.x, 0.01f);
		/*ImGui::DragFloat3("AABB2min", &aabb2.min.x, 0.01f);
		ImGui::DragFloat3("AABB2max", &aabb2.max.x, 0.01f);*/
		/*ImGui::DragFloat3("SphereCenter1", &sphere1.center.x, 0.01f);
		ImGui::DragFloat("SphereRadius1", &sphere1.radius, 0.01f);*/
		ImGui::DragFloat3("SphereCenter2", &sphere2.center.x, 0.01f);
		ImGui::DragFloat("SphereRadius2", &sphere2.radius, 0.01f);
		/*ImGui::DragFloat3("Triangle.vertices0", &triangle.vertices[0].x, 0.01f);
		ImGui::DragFloat3("Triangle.vertices1", &triangle.vertices[1].x, 0.01f);
		ImGui::DragFloat3("Triangle.vertices2", &triangle.vertices[2].x, 0.01f);*/
		/*ImGui::DragFloat3("Segment.origin", &segment.origin.x, 0.01f);
		ImGui::DragFloat3("Segment.diff", &segment.diff.x, 0.01f);*/
		/*ImGui::DragFloat3("Plane.Normal", &plane.normal.x, 0.01f);
		plane.normal = Normalize(plane.normal);*/
		ImGui::End();

		
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
		DrawGrid(viewProjectionMatrix, viewportMatrix);
		DrawSphere(sphere2, Multiply(viewMatrix, projectionMatrix), viewportMatrix, color);
		//DrawSegment(segment, Multiply(viewMatrix, projectionMatrix), viewportMatrix, color);
		//DrawPlane(plane, Multiply(viewMatrix, projectionMatrix), viewportMatrix, WHITE);
		//DrawTriange(triangle, Multiply(viewMatrix, projectionMatrix), viewportMatrix, color);
		DrawAABB(aabb1, Multiply(viewMatrix, projectionMatrix), viewportMatrix, WHITE);
		//DrawAABB(aabb2, Multiply(viewMatrix, projectionMatrix), viewportMatrix, WHITE);

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
