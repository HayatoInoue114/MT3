#pragma once
#include<Novice.h>
#include<math.h>
#include<assert.h>
#include<cmath>
#include <algorithm>

#define M_PI 3.14f

const int kWindowWidth = 1280;
const int kWindowHeight = 720;


struct Matrix2x2
{
	float m[2][2];
};

struct Vector2
{
	float x;
	float y;
};

struct Box {
	Vector2 pos;
	int W;
	int H;
};


static Matrix2x2 B;

static Matrix2x2 A;

//float mat;

//1.行列の加法
Matrix2x2 Add(Matrix2x2 matrix1, Matrix2x2 matrix2);

//2.行列の減法
Matrix2x2 Subtract(Matrix2x2 matrix1, Matrix2x2 matrix2);

//3.行列の積
Matrix2x2 Multiply(Matrix2x2 matrix1, Matrix2x2 matrix2);

//4.ベクトルと行列の積
Vector2 Multiply(Vector2 vecter, Matrix2x2 matrix);



//表示の関数化
static const int kRowHeight = 20;
//static const int kColumnWidth = 44;

void MatrixScreenPrintf(int x, int y, Matrix2x2 matrix);
void VectorScreenprintf(int x, int y, Vector2 vector);


Matrix2x2 MakeRotateMatrix(float theta);

float ToWorld(float y);


struct Matrix3x3 {
	float m[3][3];
};


Matrix3x3 MaketranslateMatrix(Vector2 translate);

Vector2 Transform(Vector2 vector, Matrix3x3 matrix);

Matrix3x3 MakeRotateMatrix3x3(float theta);

Matrix3x3 Multiply(Matrix3x3 matrix1, Matrix3x3 matrix2);

Matrix3x3 MakeScaleMatrix(Vector2 scale);

Matrix3x3 MakeAffineMatrix(Vector2 scale, float theta, Vector2 translate);

//2x2逆行列を求める
Matrix2x2 Inverse(Matrix2x2 matrix);
//3x3逆行列を求める
//Matrix3x3 Inverse3x3(Matrix3x3 matrix);

//void MatrixScreenPrintf(int x, int y, Matrix3x3 matrix);


Matrix2x2 MatrixMultiply(float num, Matrix2x2 matrix);
//Matrix3x3 MatrixMultiply3x3(float num, Matrix3x3 matrix);

Matrix2x2 Transpose(Matrix2x2 matrix);
Matrix3x3 Transpose(Matrix3x3 matrix);

Matrix3x3 MakeOrthographicMatrix(float left, float top, float right, float bottom);
Matrix3x3 MakeViewposrtMatrix(float left, float top, float width, float height);

//void DrawQuad(Vector2 leftTop, Vector2 rightTop, Vector2 LeftBottom, Vector2 rightBottom, Vector2 scale,unsigned int color, int texturHundle);

struct Vector3
{
	float x, y, z;
};

//加算
Vector3 Add(const Vector3& v1, const Vector3& v2);
//減算
Vector3 Subtract(const Vector3& v1, const Vector3& v2);
//スカラー倍
Vector3 Multiply(float scalar, const Vector3& v);
//内積
float Dot(const Vector3& v1, const Vector3& v2);
//長さ(ノルム)
float Length(const Vector3& v);
//正規化
Vector3 Normalize(const Vector3& v);

//Vector3同士の掛け算
Vector3 Multiply(const Vector3& v1, const Vector3& v2);

//Clamp
Vector3 Clamp(const Vector3& v1,const Vector3& min, const Vector3& max);

static const int kColumnWidth = 60;
void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label);

struct Matrix4x4 {
	float m[4][4];
};
//行列の加法
Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2);
//行列の減法
Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2);
//行列の積
Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);
//逆行列
Matrix4x4 Inverse(const Matrix4x4& m);
//転置行列
Matrix4x4 Transpose(const Matrix4x4& m);
//単位行列の作成
Matrix4x4 MakeIdentity4x4();

//X軸回転行列
Matrix4x4 MakeRotateXMatrix(float radian);
//Y軸回転行列
Matrix4x4 MakeRotateYMatrix(float radian);
//Z軸回転行列
Matrix4x4 MakeRotateZMatrix(float radian);

//3次元アフィン変換行列
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);


void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix);

//1.透視投影行列
Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip);
//2.正射影行列
Matrix4x4 MakeOrthographicMatrix(float left, float right, float top, float bottom, float nearClip, float farClip);
//3.ビューポート変換行列
Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth);


//クロス積
Vector3 Cross(const Vector3& v1, const Vector3& v2);

Vector3 Transform(const Vector3& num, const Matrix4x4& m);

float InverseNum(const Matrix4x4& m, int a, int b, int c, int d, int e, int f, int g, int h);
float InverseNum2(const Matrix4x4& m, int a, int b, int c, int d, int e, int f);

void DrawGrid(const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix);

struct Sphere
{
	Vector3 center;
	float radius;
};

bool IsCollision(const Sphere& s1, const Sphere& s2);

void DrawSphere(const Sphere& sphere, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);

struct Line
{
	Vector3 origin; //!< 始点
	Vector3 diff; //!< 終点への差分ベクトル
};

struct Ray
{
	Vector3 origin; //!< 始点
	Vector3 diff; //!< 終点への差分ベクトル
};

struct Segment
{
	Vector3 origin; //!< 始点
	Vector3 diff; //!< 終点への差分ベクトル
};

Vector3 Project(const Vector3& v1, const Vector3& v2);
Vector3 ClosestPoint(const Vector3& point, const Segment& segment);

struct Plane 
{
	Vector3 normal; //!< 法線
	float distance; //!< 距離
};

bool IsCollision(const Sphere& sphere, const Plane& plane);

Vector3 Perpendicular(const Vector3& vector);

void DrawPlane(const Plane& plane, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);

bool IsCollision(const Segment& segment, const Plane& plane);

void DrawSegment(const Segment& segment, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);

struct Triangle
{
	Vector3 vertices[3]; //!<頂点
};

bool IsCollision(const Triangle& triange, const Segment& segment);

void DrawTriange(const Triangle& triangle, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);

struct AABB
{
	Vector3 min; //!< 最小点
	Vector3 max; //!< 最大点
};

bool IsCollision(const AABB& aabb1, const AABB& aabb2);

void DrawAABB(const AABB& aabb, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);

bool IsCollision(const AABB& aabb, const Sphere& sphere);

Matrix4x4 MakeRotateAxisAngle(const Vector3& axis, float angle);