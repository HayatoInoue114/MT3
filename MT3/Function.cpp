#include"Function.h"
#include<Novice.h>
#include<math.h>
#include<assert.h>


void MatrixScreenPrintf(int x, int y, Matrix2x2 matrix) {
	for (int row = 0; row < 2; ++row) {
		for (int column = 0; column < 2; ++column) {
			Novice::ScreenPrintf(x + column * kColumnWidth, y + row * kRowHeight, "%.02f", matrix.m[row][column]);
		}
	}
}

void VectorScreenprintf(int x, int y, Vector2 vector) {
	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", vector.y);
}

void MatrixScreenPrintf3x3(int x, int y, Matrix3x3 matrix) {
	for (int row = 0; row < 3; ++row) {
		for (int column = 0; column < 3; ++column) {
			Novice::ScreenPrintf(x + column * kColumnWidth, y + row * kRowHeight, "%.02f", matrix.m[row][column]);
		}
	}
}

Matrix2x2 Add(Matrix2x2 matrix1, Matrix2x2 matrix2) {
	return Matrix2x2{
		matrix1.m[0][0] + matrix2.m[0][0],matrix1.m[0][1] + matrix2.m[0][1],
		matrix1.m[1][0] + matrix2.m[1][0],matrix1.m[1][1] + matrix2.m[1][1]
	};
}

Matrix2x2 Subtract(Matrix2x2 matrix1, Matrix2x2 matrix2) {
	return Matrix2x2{
		matrix1.m[0][0] - matrix2.m[0][0],matrix1.m[0][1] - matrix2.m[0][1],
		matrix1.m[1][0] - matrix2.m[1][0],matrix1.m[1][1] - matrix2.m[1][1]
	};
}

Matrix2x2 Multiply(Matrix2x2 matrix1, Matrix2x2 matrix2) {
	return Matrix2x2{
		matrix1.m[0][0] * matrix2.m[0][0] + matrix1.m[0][1] * matrix2.m[1][0],matrix1.m[0][0] * matrix2.m[0][1] + matrix1.m[0][1] * matrix2.m[1][1],
		matrix1.m[1][0] * matrix2.m[0][0] + matrix1.m[1][1] * matrix2.m[1][0],matrix1.m[1][0] * matrix2.m[0][1] + matrix1.m[1][1] * matrix2.m[1][1]
	};
}

Vector2 Multiply(Vector2 vector, Matrix2x2 matrix) {
	return Vector2{
		vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0],vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1]
	};
}

Matrix2x2 MakeRotateMatrix(float theta) {
	return Matrix2x2{
		cosf(theta),sinf(theta),-sinf(theta),cosf(theta)
	};
}

float ToWorld(float y) {
	return -y + 500;
}

Matrix3x3 MaketranslateMatrix(Vector2 translate) {
	Matrix3x3 result =
	{
		1,0,0,
		0,1,0,
		translate.x,translate.y,1
	};
	return result;
}




Matrix3x3 MakeRotateMatrix3x3(float theta) {
	return Matrix3x3{
		cosf(theta),sinf(theta),0,
		 -sinf(theta),cosf(theta),0,
		 0,0,1
	};
}


Matrix3x3 Multiply(Matrix3x3 matrix1, Matrix3x3 matrix2) {
	return Matrix3x3{
		matrix1.m[0][0] * matrix2.m[0][0] + matrix1.m[0][1] * matrix2.m[1][0] + matrix1.m[0][2] * matrix2.m[2][0],
		matrix1.m[0][0] * matrix2.m[0][1] + matrix1.m[0][1] * matrix2.m[1][1] + matrix1.m[0][2] * matrix2.m[2][1],
		matrix1.m[0][0] * matrix2.m[0][2] + matrix1.m[0][1] * matrix2.m[1][2] + matrix1.m[0][2] * matrix2.m[2][2],

		matrix1.m[1][0] * matrix2.m[0][0] + matrix1.m[1][1] * matrix2.m[1][0] + matrix1.m[1][2] * matrix2.m[2][0],
		matrix1.m[1][0] * matrix2.m[0][1] + matrix1.m[1][1] * matrix2.m[1][1] + matrix1.m[1][2] * matrix2.m[2][1],
		matrix1.m[1][0] * matrix2.m[0][2] + matrix1.m[1][1] * matrix2.m[1][2] + matrix1.m[1][2] * matrix2.m[2][2],

		matrix1.m[2][0] * matrix2.m[0][0] + matrix1.m[2][1] * matrix2.m[1][0] + matrix1.m[2][2] * matrix2.m[2][0],
		matrix1.m[2][0] * matrix2.m[0][1] + matrix1.m[2][1] * matrix2.m[1][1] + matrix1.m[2][2] * matrix2.m[2][1],
		matrix1.m[2][0] * matrix2.m[0][2] + matrix1.m[2][1] * matrix2.m[1][2] + matrix1.m[2][2] * matrix2.m[2][2],
	};
}

Matrix3x3 MakeScaleMatrix(Vector2 scale) {
	return Matrix3x3{
		scale.x,0,0,
		0,scale.y,0,
		0,0,1
	};
}

Matrix3x3 MakeAffineMatrix(Vector2 scale, float theta, Vector2 translate) {
	return Matrix3x3{
		scale.x * cosf(theta),scale.x * sinf(theta),0,
		scale.y * -sinf(theta),scale.y * cosf(theta),0,
		translate.x,translate.y,1
	};
}


Matrix2x2 MatrixMultiply(float num, Matrix2x2 matrix) {
	Matrix2x2 mat;
	mat.m[0][0] = matrix.m[0][0] * num;
	mat.m[0][1] = matrix.m[0][1] * num;
	mat.m[1][0] = matrix.m[1][0] * num;
	mat.m[1][1] = matrix.m[1][1] * num;

	return mat;
}

Matrix3x3 MatrixMultiply(float num, Matrix3x3 matrix) {
	Matrix3x3 mat;
	mat.m[0][0] = matrix.m[0][0] * num;
	mat.m[0][1] = matrix.m[0][1] * num;
	mat.m[0][2] = matrix.m[0][2] * num;
	mat.m[1][0] = matrix.m[1][0] * num;
	mat.m[1][1] = matrix.m[1][1] * num;
	mat.m[1][2] = matrix.m[1][2] * num;
	mat.m[2][0] = matrix.m[2][0] * num;
	mat.m[2][1] = matrix.m[2][1] * num;
	mat.m[2][2] = matrix.m[2][2] * num;

	return mat;
}







Matrix2x2 Inverse(Matrix2x2 matrix) {
	Matrix2x2 mat{
		matrix.m[1][1], -matrix.m[0][1],
		-matrix.m[1][0], matrix.m[0][0]
	};

	float det = matrix.m[0][0] * matrix.m[1][1] - matrix.m[0][1] * matrix.m[1][0];

	mat = MatrixMultiply((1.0f / det), mat);

	return mat;

}

//Matrix3x3 Inverse3x3(Matrix3x3 matrix) {
//	Matrix3x3 mat{
//		matrix.m[1][1] * matrix.m[2][2] - matrix.m[1][2] * matrix.m[2][1],-(matrix.m[0][1] * matrix.m[2][2] - matrix.m[0][2] * matrix.m[2][1]),matrix.m[0][1] * matrix.m[1][2] - matrix.m[0][2] * matrix.m[1][1],
//		-(matrix.m[1][0] * matrix.m[2][2] - matrix.m[1][2] * matrix.m[2][0]), matrix.m[0][0] * matrix.m[2][2] - matrix.m[0][2] * matrix.m[2][0],-(matrix.m[0][0] * matrix.m[1][2] - matrix.m[0][2] * matrix.m[1][0]),
//		matrix.m[1][0] * matrix.m[2][1] - matrix.m[1][1] * matrix.m[2][0],-(matrix.m[0][0] * matrix.m[2][1] - matrix.m[0][1] * matrix.m[2][0]),matrix.m[0][0] * matrix.m[1][1] - matrix.m[0][1] * matrix.m[1][0]
//	};
//
//	float det =
//		matrix.m[0][0] * matrix.m[1][1] * matrix.m[2][2] + matrix.m[0][1] * matrix.m[1][2] * matrix.m[2][0] + matrix.m[0][2] * matrix.m[1][0] * matrix.m[2][1]
//		- matrix.m[0][2] * matrix.m[1][1] * matrix.m[2][0] - matrix.m[0][1] * matrix.m[1][0] * matrix.m[2][2] - matrix.m[0][0] * matrix.m[1][2] * matrix.m[2][1];
//
//	return mat = MatrixMultiply3x3((1.0f / det), mat);
//}



Matrix2x2 Transpose(Matrix2x2 matrix) {
	Matrix2x2 mat{
		matrix.m[0][0], matrix.m[1][0],
		matrix.m[0][1], matrix.m[1][1]
	};

	return mat;
}



Matrix3x3 Transpose(Matrix3x3 matrix) {
	Matrix3x3 mat{
		matrix.m[0][0], matrix.m[1][0],matrix.m[2][0],
		matrix.m[0][1], matrix.m[1][1],matrix.m[2][1],
		matrix.m[0][2], matrix.m[1][2],matrix.m[2][2]
	};
	return mat;
}

Matrix3x3 MakeOrthographicMatrix(float left, float top, float right, float bottom) {
	Matrix3x3 mat{
		2 / (right - left),0,0,
		0,2 / (top - bottom),0,
		(left + right) / (left - right),(top + bottom) / (bottom - top),1
	};
	return mat;
}

Matrix3x3 MakeViewposrtMatrix(float left, float top, float width, float height) {
	Matrix3x3 mat{
		width / 2,0,0,
		0,-(height / 2),0,
		left + (width / 2),top + (height / 2),1
	};
	return mat;
}

void DrawQuad(Vector2 leftTop, Vector2 rightTop, Vector2 LeftBottom, Vector2 rightBottom, Vector2 scale, int texturHundle) {
	Novice::DrawQuad((int)leftTop.x, (int)leftTop.y, (int)rightTop.x, (int)rightTop.y, (int)LeftBottom.x, (int)LeftBottom.y, (int)rightBottom.x, (int)rightBottom.y, 0, 0, (int)scale.x, (int)scale.y, texturHundle, WHITE);
}

Vector3 Add(const Vector3& v1, const Vector3& v2) {
	Vector3 num = {
		v1.x + v2.x,
		v1.y + v2.y,
		v1.z + v2.z
	};
	return num;
}

Vector3 Subtract(const Vector3& v1, const Vector3& v2) {
	Vector3 num = {
		v1.x - v2.x,
		v1.y - v2.y,
		v1.z - v2.z
	};
	return num;
}

Vector3 Multiply(float scalar, const Vector3& v) {
	Vector3 num = {
		scalar * v.x,scalar * v.y,scalar * v.z
	};
	return num;
}

float Dot(const Vector3& v1, const Vector3& v2) {
	float num = {
		v1.x * v2.x + v1.y * v2.y + v1.z * v2.z
	};
	return num;
}

float Length(const Vector3& v) {
	float num = {
		sqrtf(v.x * v.x + v.y * v.y + v.z * v.z)
	};
	return num;
}

Vector3 Normalize(const Vector3& v) {
	Vector3 num = {
		v.x / Length(v),
		v.y / Length(v),
		v.z / Length(v)
	};
	return num;
}

void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label) {
	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%.02f", vector.z);
	Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%s", label);
}

Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 mat = {
		m1.m[0][0] + m2.m[0][0],m1.m[0][1] + m2.m[0][1],m1.m[0][2] + m2.m[0][2],m1.m[0][3] + m2.m[0][3],
		m1.m[1][0] + m2.m[1][0],m1.m[1][1] + m2.m[1][1],m1.m[1][2] + m2.m[1][2],m1.m[1][3] + m2.m[1][3],
		m1.m[2][0] + m2.m[2][0],m1.m[2][1] + m2.m[2][1],m1.m[2][2] + m2.m[2][2],m1.m[2][3] + m2.m[2][3],
		m1.m[3][0] + m2.m[3][0],m1.m[3][1] + m2.m[3][1],m1.m[3][2] + m2.m[3][2],m1.m[3][3] + m2.m[3][3]
	};
	return mat;
}

Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 mat = {
		m1.m[0][0] - m2.m[0][0],m1.m[0][1] - m2.m[0][1],m1.m[0][2] - m2.m[0][2],m1.m[0][3] - m2.m[0][3],
		m1.m[1][0] - m2.m[1][0],m1.m[1][1] - m2.m[1][1],m1.m[1][2] - m2.m[1][2],m1.m[1][3] - m2.m[1][3],
		m1.m[2][0] - m2.m[2][0],m1.m[2][1] - m2.m[2][1],m1.m[2][2] - m2.m[2][2],m1.m[2][3] - m2.m[2][3],
		m1.m[3][0] - m2.m[3][0],m1.m[3][1] - m2.m[3][1],m1.m[3][2] - m2.m[3][2],m1.m[3][3] - m2.m[3][3]
	};
	return mat;
}

Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 mat = {
		m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0] + m1.m[0][2] * m2.m[2][0] + m1.m[0][3] * m2.m[3][0],  m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1] + m1.m[0][2] * m2.m[2][1] + m1.m[0][3] * m2.m[3][1],  m1.m[0][0] * m2.m[0][2] + m1.m[0][1] * m2.m[1][2] + m1.m[0][2] * m2.m[2][2] + m1.m[0][3] * m2.m[3][2],  m1.m[0][0] * m2.m[0][3] + m1.m[0][1] * m2.m[1][3] + m1.m[0][2] * m2.m[2][3] + m1.m[0][3] * m2.m[3][3],
		m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0] + m1.m[1][2] * m2.m[2][0] + m1.m[1][3] * m2.m[3][0],  m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1] + m1.m[1][2] * m2.m[2][1] + m1.m[1][3] * m2.m[3][1],  m1.m[1][0] * m2.m[0][2] + m1.m[1][1] * m2.m[1][2] + m1.m[1][2] * m2.m[2][2] + m1.m[1][3] * m2.m[3][2],  m1.m[1][0] * m2.m[0][3] + m1.m[1][1] * m2.m[1][3] + m1.m[1][2] * m2.m[2][3] + m1.m[1][3] * m2.m[3][3],
		m1.m[2][0] * m2.m[0][0] + m1.m[2][1] * m2.m[1][0] + m1.m[2][2] * m2.m[2][0] + m1.m[2][3] * m2.m[3][0],  m1.m[2][0] * m2.m[0][1] + m1.m[2][1] * m2.m[1][1] + m1.m[2][2] * m2.m[2][1] + m1.m[2][3] * m2.m[3][1],  m1.m[2][0] * m2.m[0][2] + m1.m[2][1] * m2.m[1][2] + m1.m[2][2] * m2.m[2][2] + m1.m[2][3] * m2.m[3][2],  m1.m[2][0] * m2.m[0][3] + m1.m[2][1] * m2.m[1][3] + m1.m[2][2] * m2.m[2][3] + m1.m[2][3] * m2.m[3][3],
		m1.m[3][0] * m2.m[0][0] + m1.m[3][1] * m2.m[1][0] + m1.m[3][2] * m2.m[2][0] + m1.m[3][3] * m2.m[3][0],  m1.m[3][0] * m2.m[0][1] + m1.m[3][1] * m2.m[1][1] + m1.m[3][2] * m2.m[2][1] + m1.m[3][3] * m2.m[3][1],  m1.m[3][0] * m2.m[0][2] + m1.m[3][1] * m2.m[1][2] + m1.m[3][2] * m2.m[2][2] + m1.m[3][3] * m2.m[3][2],  m1.m[3][0] * m2.m[0][3] + m1.m[3][1] * m2.m[1][3] + m1.m[3][2] * m2.m[2][3] + m1.m[3][3] * m2.m[3][3]
	};
	return mat;
}

Matrix4x4 Inverse(const Matrix4x4& m) {
	float num = { m.m[0][0] * m.m[1][1] * m.m[2][2] * m.m[3][3] + m.m[0][0] * m.m[1][2] * m.m[2][3] * m.m[3][1] + m.m[0][0] * m.m[1][3] * m.m[2][1] * m.m[3][2]
				+ m.m[0][1] * m.m[1][0] * m.m[2][3] * m.m[3][2] + m.m[0][1] * m.m[1][2] * m.m[2][0] * m.m[3][3] + m.m[0][1] * m.m[1][3] * m.m[2][2] * m.m[3][0]
				+ m.m[0][2] * m.m[1][0] * m.m[2][1] * m.m[3][3] + m.m[0][2] * m.m[1][1] * m.m[2][3] * m.m[3][0] + m.m[0][2] * m.m[1][3] * m.m[2][0] * m.m[3][1]
				+ m.m[0][3] * m.m[1][0] * m.m[2][2] * m.m[3][1] + m.m[0][3] * m.m[1][1] * m.m[2][0] * m.m[3][2] + m.m[0][3] * m.m[1][2] * m.m[2][1] * m.m[3][0]
				- m.m[0][0] * m.m[1][1] * m.m[2][3] * m.m[3][2] - m.m[0][0] * m.m[1][2] * m.m[2][1] * m.m[3][3] - m.m[0][0] * m.m[1][3] * m.m[2][2] * m.m[3][1]
				- m.m[0][1] * m.m[1][0] * m.m[2][2] * m.m[3][3] - m.m[0][1] * m.m[1][2] * m.m[2][3] * m.m[3][0] - m.m[0][1] * m.m[1][3] * m.m[2][0] * m.m[3][2]
				- m.m[0][2] * m.m[1][0] * m.m[2][3] * m.m[3][1] - m.m[0][2] * m.m[1][1] * m.m[2][0] * m.m[3][3] - m.m[0][2] * m.m[1][3] * m.m[2][1] * m.m[3][0]
				- m.m[0][3] * m.m[1][0] * m.m[2][1] * m.m[3][2] - m.m[0][3] * m.m[1][1] * m.m[2][2] * m.m[3][0] - m.m[0][3] * m.m[1][2] * m.m[2][0] * m.m[3][1]
	};

	Matrix4x4 mat = {
		mat.m[0][0] = 1.0f / num * (m.m[1][1] * m.m[2][2] * m.m[3][3] + m.m[1][2] * m.m[2][3] * m.m[3][1] + m.m[1][3] * m.m[2][1] * m.m[3][2] - m.m[1][1] * m.m[2][3] * m.m[3][2] - m.m[1][2] * m.m[2][1] * m.m[3][3] - m.m[1][3] * m.m[2][2] * m.m[3][1]),
		mat.m[0][1] = 1.0f / num * (m.m[0][1] * m.m[2][3] * m.m[3][2] + m.m[0][2] * m.m[2][1] * m.m[3][3] + m.m[0][3] * m.m[2][2] * m.m[3][1] - m.m[0][1] * m.m[2][2] * m.m[3][3] - m.m[0][2] * m.m[2][3] * m.m[3][1] - m.m[0][3] * m.m[2][1] * m.m[3][2]),
		mat.m[0][2] = 1.0f / num * (m.m[0][1] * m.m[1][2] * m.m[3][3] + m.m[0][2] * m.m[1][3] * m.m[3][1] + m.m[0][3] * m.m[1][1] * m.m[3][2] - m.m[0][1] * m.m[1][3] * m.m[3][2] - m.m[0][2] * m.m[1][1] * m.m[3][3] - m.m[0][3] * m.m[1][2] * m.m[3][1]),
		mat.m[0][3] = 1.0f / num * (m.m[0][1] * m.m[1][3] * m.m[2][2] + m.m[0][2] * m.m[1][1] * m.m[2][3] + m.m[0][3] * m.m[1][2] * m.m[2][1] - m.m[0][1] * m.m[1][2] * m.m[2][3] - m.m[0][2] * m.m[1][3] * m.m[2][1] - m.m[0][3] * m.m[1][1] * m.m[2][2]),

		mat.m[1][0] = 1.0f / num * (m.m[1][0] * m.m[2][3] * m.m[3][2] + m.m[1][2] * m.m[2][0] * m.m[3][3] + m.m[1][3] * m.m[2][2] * m.m[3][0] - m.m[1][0] * m.m[2][2] * m.m[3][3] - m.m[1][2] * m.m[2][3] * m.m[3][0] - m.m[1][3] * m.m[2][0] * m.m[3][2]),
		mat.m[1][1] = 1.0f / num * (m.m[0][0] * m.m[2][2] * m.m[3][3] + m.m[0][2] * m.m[2][3] * m.m[3][0] + m.m[0][3] * m.m[2][0] * m.m[3][2] - m.m[0][0] * m.m[2][3] * m.m[3][2] - m.m[0][2] * m.m[2][0] * m.m[3][3] - m.m[0][3] * m.m[2][2] * m.m[3][0]),
		mat.m[1][2] = 1.0f / num * (m.m[0][0] * m.m[1][3] * m.m[3][2] + m.m[0][2] * m.m[1][0] * m.m[3][3] + m.m[0][3] * m.m[1][2] * m.m[3][0] - m.m[0][0] * m.m[1][2] * m.m[3][3] - m.m[0][2] * m.m[1][3] * m.m[3][0] - m.m[0][3] * m.m[1][0] * m.m[3][2]),
		mat.m[1][3] = 1.0f / num * (m.m[0][0] * m.m[1][2] * m.m[2][3] + m.m[0][2] * m.m[1][3] * m.m[2][0] + m.m[0][3] * m.m[1][0] * m.m[2][2] - m.m[0][0] * m.m[1][3] * m.m[2][2] - m.m[0][2] * m.m[1][0] * m.m[2][3] - m.m[0][3] * m.m[1][2] * m.m[2][0]),

		mat.m[2][0] = 1.0f / num * (m.m[1][0] * m.m[2][1] * m.m[3][3] + m.m[1][1] * m.m[2][3] * m.m[3][0] + m.m[1][3] * m.m[2][0] * m.m[3][1] - m.m[1][0] * m.m[2][3] * m.m[3][1] - m.m[1][1] * m.m[2][0] * m.m[3][3] - m.m[1][3] * m.m[2][1] * m.m[3][0]),
		mat.m[2][1] = 1.0f / num * (m.m[0][0] * m.m[2][3] * m.m[3][1] + m.m[0][1] * m.m[2][0] * m.m[3][3] + m.m[0][3] * m.m[2][1] * m.m[3][0] - m.m[0][0] * m.m[2][1] * m.m[3][3] - m.m[0][1] * m.m[2][3] * m.m[3][0] - m.m[0][3] * m.m[2][0] * m.m[3][1]),
		mat.m[2][2] = 1.0f / num * (m.m[0][0] * m.m[1][1] * m.m[3][3] + m.m[0][1] * m.m[1][3] * m.m[3][0] + m.m[0][3] * m.m[1][0] * m.m[3][1] - m.m[0][0] * m.m[1][3] * m.m[3][1] - m.m[0][1] * m.m[1][0] * m.m[3][3] - m.m[0][3] * m.m[1][1] * m.m[3][0]),
		mat.m[2][3] = 1.0f / num * (m.m[0][0] * m.m[1][3] * m.m[2][1] + m.m[0][1] * m.m[1][0] * m.m[2][3] + m.m[0][3] * m.m[1][1] * m.m[2][0] - m.m[0][0] * m.m[1][1] * m.m[2][3] - m.m[0][1] * m.m[1][3] * m.m[2][0] - m.m[0][3] * m.m[1][0] * m.m[2][1]),

		mat.m[3][0] = 1.0f / num * (m.m[1][0] * m.m[2][2] * m.m[3][1] + m.m[1][1] * m.m[2][0] * m.m[3][2] + m.m[1][2] * m.m[2][1] * m.m[3][0] - m.m[1][0] * m.m[2][1] * m.m[3][2] - m.m[1][1] * m.m[2][2] * m.m[3][0] - m.m[1][2] * m.m[2][0] * m.m[3][1]),
		mat.m[3][1] = 1.0f / num * (m.m[0][0] * m.m[2][1] * m.m[3][2] + m.m[0][1] * m.m[2][2] * m.m[3][0] + m.m[0][2] * m.m[2][0] * m.m[3][1] - m.m[0][0] * m.m[2][2] * m.m[3][1] - m.m[0][1] * m.m[2][0] * m.m[3][2] - m.m[0][2] * m.m[2][1] * m.m[3][0]),
		mat.m[3][2] = 1.0f / num * (m.m[0][0] * m.m[1][2] * m.m[3][1] + m.m[0][1] * m.m[1][0] * m.m[3][2] + m.m[0][2] * m.m[1][1] * m.m[3][0] - m.m[0][0] * m.m[1][1] * m.m[3][2] - m.m[0][1] * m.m[1][2] * m.m[3][0] - m.m[0][2] * m.m[1][0] * m.m[3][1]),
		mat.m[3][3] = 1.0f / num * (m.m[0][0] * m.m[1][1] * m.m[2][2] + m.m[0][1] * m.m[1][2] * m.m[2][1] + m.m[0][2] * m.m[1][0] * m.m[2][1] - m.m[0][0] * m.m[1][2] * m.m[2][1] - m.m[0][1] * m.m[1][0] * m.m[2][2] - m.m[0][2] * m.m[1][1] * m.m[2][0])
	};
	return mat;
}

Matrix4x4 Transpose(const Matrix4x4& m) {
	Matrix4x4 mat = {
		m.m[0][0],m.m[1][0],m.m[2][0],m.m[3][0],
		m.m[0][1],m.m[1][1],m.m[2][1],m.m[3][1],
		m.m[0][2],m.m[1][2],m.m[2][2],m.m[3][2],
		m.m[0][3],m.m[1][3],m.m[2][3],m.m[3][3]
	};
	return mat;
}

Matrix4x4 MakeIdentity4x4() {
	Matrix4x4 mat = {
		1.0f,0.0f,0.0f,0.0f,
		0.0f,1.0f,0.0f,0.0f,
		0.0f,0.0f,1.0f,0.0f,
		0.0f,0.0f,0.0f,1.0f
	};
	return mat;
}

void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix) {
	for (int row = 0; row < 4; ++row) {
		for (int column = 0; column < 4; ++column) {
			Novice::ScreenPrintf(x + column * kColumnWidth, y + row * kRowHeight, "%6.02f", matrix.m[row][column]);
		}
	}
}

Matrix4x4 MakeTranslateMatrix(const Vector3& translate) {
	Matrix4x4 mat = {
		1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		translate.x,translate.y,translate.z,1
	};
	return mat;
}

Matrix4x4 MakeScaleMatrix(const Vector3& scale) {
	Matrix4x4 mat = {
		scale.x,0,0,0,
		0,scale.y,0,0,
		0,0,scale.z,0,
		0,0,0,1
	};
	return mat;
}

Vector2 Transform(Vector2 vector, Matrix3x3 matrix) {
	Vector2 result;
	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + 1.0f * matrix.m[2][0];
	result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + 1.0f * matrix.m[2][1];
	float w = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + 1.0f * matrix.m[2][2];
	assert(w != 0.0f);
	result.x /= w;
	result.y /= w;
	return result;
}

Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix) {
	Vector3 result;
	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + vector.z * matrix.m[2][0] + 1.0f * matrix.m[3][0];
	result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + vector.z * matrix.m[2][1] + 1.0f * matrix.m[3][1];
	result.z = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + vector.z * matrix.m[2][2] + 1.0f * matrix.m[3][2];
	float w = vector.x * matrix.m[0][3] + vector.y * matrix.m[1][3] + vector.z * matrix.m[2][3] + 1.0f * matrix.m[3][3];
	assert(w != 0.0f);
	result.x /= w;
	result.y /= w;
	result.z /= w;
	return result;
}