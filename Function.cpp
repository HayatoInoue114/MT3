#include"Function.h"


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

//void DrawQuad(Vector2 leftTop, Vector2 rightTop, Vector2 LeftBottom, Vector2 rightBottom, Vector2 scale,unsigned int color, int texturHundle) {
//	Novice::DrawQuad((int)leftTop.x, (int)leftTop.y, (int)rightTop.x, (int)rightTop.y, (int)LeftBottom.x, (int)LeftBottom.y, (int)rightBottom.x, (int)rightBottom.y, 0, 0, (int)scale.x, (int)scale.y,  WHITE, texturHundle);
//}

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

Vector3 Multiply(const Vector3& v1, const Vector3& v2) {
	Vector3 result = {
		v1.x * v2.x,v1.y * v2.y,v1.z * v2.z
	};

	return result;
}

Vector3 Clamp(const Vector3& v1, const Vector3& min, const Vector3& max) {
	Vector3 result = v1;
	if (result.x < min.x) {
		result.x = min.x;
	}
	if (result.x > max.x) {
		result.x = max.x;
	}

	if (result.y < min.y) {
		result.y = min.y;
	}
	if (result.y > max.y) {
		result.y = max.y;
	}

	if (result.z < min.z) {
		result.z = min.z;
	}
	if (result.z > max.z) {
		result.z = max.z;
	}
	return result;
}

void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label) {
	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%.02f", vector.z);
	Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%s", label);
}

Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 mat = {
		m1.m[0][0] + m2.m[0][0],m1.m[0][1] + m2.m[1][1],m1.m[0][2] + m2.m[0][2],m1.m[0][3] + m2.m[0][3],
		m1.m[1][0] + m2.m[1][0],m1.m[1][1] + m2.m[1][1],m1.m[1][2] + m2.m[1][2],m1.m[1][3] + m2.m[1][3],
		m1.m[2][0] + m2.m[2][0],m1.m[2][1] + m2.m[2][1],m1.m[2][2] + m2.m[2][2],m1.m[2][3] + m2.m[2][3],
		m1.m[3][0] + m2.m[3][0],m1.m[3][1] + m2.m[3][1],m1.m[3][2] + m2.m[3][2],m1.m[3][3] + m2.m[3][3]
	};
	return mat;
}

Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 mat = {
		m1.m[0][0] - m2.m[0][0],m1.m[0][1] - m2.m[1][1],m1.m[0][2] - m2.m[0][2],m1.m[0][3] - m2.m[0][3],
		m1.m[1][0] - m2.m[1][0],m1.m[1][1] - m2.m[1][1],m1.m[1][2] - m2.m[1][2],m1.m[1][3] - m2.m[1][3],
		m1.m[2][0] - m2.m[2][0],m1.m[2][1] - m2.m[2][1],m1.m[2][2] - m2.m[2][2],m1.m[2][3] - m2.m[2][3],
		m1.m[3][0] - m2.m[3][0],m1.m[3][1] - m2.m[3][1],m1.m[3][2] - m2.m[3][2],m1.m[3][3] - m2.m[3][3]
	};
	return mat;
}

//Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2) {
//	Matrix4x4 mat = {
//		m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0] + m1.m[0][2] * m2.m[2][0] + m1.m[0][3] * m2.m[3][0],   m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1] + m1.m[0][2] * m2.m[2][1] + m1.m[0][3] * m2.m[3][1],   m1.m[0][0] * m2.m[0][2] + m1.m[0][1] * m2.m[1][2] + m1.m[0][2] * m2.m[2][2] + m1.m[0][3] * m2.m[3][2],   m1.m[0][0] * m2.m[0][3] + m1.m[0][1] * m2.m[1][3] + m1.m[0][1] * m2.m[2][3] + m1.m[0][3] * m2.m[3][3],
//		m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0] + m1.m[1][2] * m2.m[2][0] + m1.m[1][3] * m2.m[3][0],   m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1] + m1.m[1][2] * m2.m[2][1] + m1.m[1][3] * m2.m[3][1],   m1.m[1][0] * m2.m[0][2] + m1.m[1][1] * m2.m[1][2] + m1.m[1][2] * m2.m[2][2] + m1.m[1][3] * m2.m[3][2],   m1.m[1][0] * m2.m[0][3] + m1.m[1][1] * m2.m[1][3] + m1.m[1][1] * m2.m[2][3] + m1.m[1][3] * m2.m[3][3],
//		m1.m[2][0] * m2.m[0][0] + m1.m[2][1] * m2.m[1][0] + m1.m[2][2] * m2.m[2][0] + m1.m[2][3] * m2.m[3][0],   m1.m[2][0] * m2.m[0][1] + m1.m[2][1] * m2.m[1][1] + m1.m[2][2] * m2.m[2][1] + m1.m[2][3] * m2.m[3][1],   m1.m[2][0] * m2.m[0][2] + m1.m[2][1] * m2.m[1][2] + m1.m[2][2] * m2.m[2][2] + m1.m[2][3] * m2.m[3][2],   m1.m[2][0] * m2.m[0][3] + m1.m[2][1] * m2.m[1][3] + m1.m[2][1] * m2.m[2][3] + m1.m[2][3] * m2.m[3][3],
//		m1.m[3][0] * m2.m[0][0] + m1.m[3][1] * m2.m[1][0] + m1.m[3][2] * m2.m[2][0] + m1.m[3][3] * m2.m[3][0],   m1.m[3][0] * m2.m[0][1] + m1.m[3][1] * m2.m[1][1] + m1.m[3][2] * m2.m[2][1] + m1.m[3][3] * m2.m[3][1],   m1.m[3][0] * m2.m[0][2] + m1.m[3][1] * m2.m[1][2] + m1.m[3][2] * m2.m[2][2] + m1.m[3][3] * m2.m[3][2],   m1.m[3][0] * m2.m[0][3] + m1.m[3][1] * m2.m[1][3] + m1.m[3][1] * m2.m[2][3] + m1.m[3][3] * m2.m[3][3]
//	};
//	return mat;
//}

//Matrix4x4 Inverse(const Matrix4x4& m) {
//	float num = { m.m[0][0] * m.m[1][1] * m.m[2][2] * m.m[3][3] + m.m[0][0] * m.m[1][2] * m.m[2][3] * m.m[3][1] + m.m[0][0] * m.m[1][3] * m.m[2][1] * m.m[3][2]
//				+ m.m[0][1] * m.m[1][0] * m.m[2][3] * m.m[3][2] + m.m[0][1] * m.m[1][2] * m.m[2][0] * m.m[3][3] + m.m[0][1] * m.m[1][3] * m.m[2][2] * m.m[3][0]
//				+ m.m[0][2] * m.m[1][0] * m.m[2][1] * m.m[3][3] + m.m[0][2] * m.m[1][1] * m.m[2][3] * m.m[3][0] + m.m[0][2] * m.m[1][3] * m.m[2][0] * m.m[3][1]
//				+ m.m[0][3] * m.m[1][0] * m.m[2][2] * m.m[3][1] + m.m[0][3] * m.m[1][1] * m.m[2][0] * m.m[3][2] + m.m[0][3] * m.m[1][1] * m.m[2][1] * m.m[3][0]
//				- m.m[0][0] * m.m[1][1] * m.m[2][2] * m.m[3][3] - m.m[0][0] * m.m[1][2] * m.m[2][3] * m.m[3][1] - m.m[0][0] * m.m[1][3] * m.m[2][1] * m.m[3][2]
//				- m.m[0][1] * m.m[1][0] * m.m[2][3] * m.m[3][2] - m.m[0][1] * m.m[1][2] * m.m[2][0] * m.m[3][3] - m.m[0][1] * m.m[1][3] * m.m[2][2] * m.m[3][0]
//				- m.m[0][2] * m.m[1][0] * m.m[2][1] * m.m[3][3] - m.m[0][2] * m.m[1][1] * m.m[2][3] * m.m[3][0] - m.m[0][2] * m.m[1][3] * m.m[2][0] * m.m[3][1]
//				- m.m[0][3] * m.m[1][0] * m.m[2][2] * m.m[3][1] - m.m[0][3] * m.m[1][1] * m.m[2][0] * m.m[3][2] - m.m[0][3] * m.m[1][1] * m.m[2][1] * m.m[3][0]
//	};
//
//	Matrix4x4 mat = {
//		1 / num * (m.m[1][1] * m.m[2][2] * m.m[3][3]  +  m.m[1][2] * m.m[2][3] * m.m[3][1]  +  m.m[1][3] * m.m[2][1] * m.m[3][2]  -  m.m[1][1] * m.m[2][3] * m.m[3][2]  -  m.m[1][2] * m.m[2][1] * m.m[3][3]  -  m.m[1][3] * m.m[2][2] * m.m[3][1]),
//		1 / num * (m.m[0][1] * m.m[2][3] * m.m[3][2]  +  m.m[0][2] * m.m[2][1] * m.m[3][3]  +  m.m[0][3] * m.m[2][2] * m.m[3][1]  -  m.m[0][1] * m.m[2][2] * m.m[3][3]  -  m.m[0][2] * m.m[2][3] * m.m[3][1]  -  m.m[0][3] * m.m[2][1] * m.m[3][2]),
//		1 / num * (m.m[0][1] * m.m[1][2] * m.m[3][3]  +  m.m[0][2] * m.m[1][3] * m.m[3][1]  +  m.m[0][3] * m.m[1][1] * m.m[3][2]  -  m.m[0][1] * m.m[1][3] * m.m[3][2]  -  m.m[0][2] * m.m[1][1] * m.m[3][3]  -  m.m[0][3] * m.m[1][2] * m.m[3][1]),
//		1 / num * (m.m[0][1] * m.m[1][3] * m.m[2][2]  +  m.m[0][2] * m.m[1][1] * m.m[2][3]  +  m.m[0][3] * m.m[1][2] * m.m[2][1]  -  m.m[0][1] * m.m[1][2] * m.m[2][3]  -  m.m[0][2] * m.m[1][3] * m.m[2][1]  -  m.m[0][3] * m.m[1][1] * m.m[2][2]),
//													     
//		1 / num * (m.m[1][0] * m.m[2][3] * m.m[3][2]  +  m.m[1][2] * m.m[2][0] * m.m[3][3]	+  m.m[1][3] * m.m[2][2] * m.m[3][0]  -  m.m[1][0] * m.m[2][2] * m.m[3][3]  -  m.m[1][2] * m.m[2][3] * m.m[3][0]  -  m.m[1][3] * m.m[2][0] * m.m[3][2]),
//		1 / num * (m.m[0][0] * m.m[2][2] * m.m[3][3]  +  m.m[0][2] * m.m[2][3] * m.m[3][0]	+  m.m[0][3] * m.m[2][0] * m.m[3][2]  -  m.m[0][0] * m.m[2][3] * m.m[3][2]  -  m.m[0][2] * m.m[2][0] * m.m[3][3]  -  m.m[0][3] * m.m[2][2] * m.m[3][0]),
//		1 / num * (m.m[0][0] * m.m[1][3] * m.m[3][2]  +  m.m[0][2] * m.m[1][0] * m.m[3][3]	+  m.m[0][3] * m.m[1][2] * m.m[3][0]  -  m.m[0][0] * m.m[1][2] * m.m[3][3]  -  m.m[0][2] * m.m[1][3] * m.m[3][0]  -  m.m[0][3] * m.m[1][0] * m.m[3][2]),
//		1 / num * (m.m[0][0] * m.m[1][2] * m.m[2][3]  +  m.m[0][2] * m.m[1][3] * m.m[2][0]	+  m.m[0][3] * m.m[1][0] * m.m[2][2]  -  m.m[0][0] * m.m[1][3] * m.m[2][2]  -  m.m[0][2] * m.m[1][0] * m.m[2][3]  -  m.m[0][3] * m.m[1][2] * m.m[2][0]),
//													     
//		1 / num * (m.m[1][0] * m.m[2][1] * m.m[3][3]  +  m.m[1][1] * m.m[2][3] * m.m[3][0]  +  m.m[1][3] * m.m[2][0] * m.m[3][1]  -  m.m[1][0] * m.m[2][3] * m.m[3][1]  -  m.m[1][1] * m.m[2][0] * m.m[3][3]  -  m.m[1][3] * m.m[2][1] * m.m[3][0]),
//		1 / num * (m.m[0][0] * m.m[2][3] * m.m[3][1]  +  m.m[0][1] * m.m[2][0] * m.m[3][3]  +  m.m[0][3] * m.m[2][1] * m.m[3][0]  -  m.m[0][0] * m.m[2][1] * m.m[3][3]  -  m.m[0][1] * m.m[2][3] * m.m[3][0]  -  m.m[0][3] * m.m[2][0] * m.m[3][1]),
//		1 / num * (m.m[0][0] * m.m[1][1] * m.m[3][3]  +  m.m[0][1] * m.m[1][3] * m.m[3][0]  +  m.m[0][3] * m.m[1][0] * m.m[3][1]  -  m.m[0][0] * m.m[1][3] * m.m[3][1]  -  m.m[0][1] * m.m[1][0] * m.m[3][3]  -  m.m[0][3] * m.m[1][1] * m.m[3][0]),
//		1 / num * (m.m[0][0] * m.m[1][3] * m.m[2][1]  +  m.m[0][1] * m.m[1][0] * m.m[2][3]  +  m.m[0][3] * m.m[1][1] * m.m[2][0]  -  m.m[0][0] * m.m[1][1] * m.m[2][3]  -  m.m[0][1] * m.m[1][3] * m.m[2][0]  -  m.m[0][3] * m.m[1][0] * m.m[2][1]),
//													     
//		1 / num * (m.m[1][0] * m.m[2][2] * m.m[3][1]  +  m.m[1][1] * m.m[2][0] * m.m[3][2]  +  m.m[1][2] * m.m[2][1] * m.m[3][0]  -  m.m[1][0] * m.m[2][1] * m.m[3][2]  -  m.m[1][1] * m.m[2][2] * m.m[3][0]  -  m.m[1][2] * m.m[2][0] * m.m[3][1]),
//		1 / num * (m.m[0][0] * m.m[2][1] * m.m[3][2]  +  m.m[0][1] * m.m[2][2] * m.m[3][0]  +  m.m[0][2] * m.m[2][0] * m.m[3][1]  -  m.m[0][0] * m.m[2][2] * m.m[3][1]  -  m.m[0][1] * m.m[2][0] * m.m[3][2]  -  m.m[0][2] * m.m[1][0] * m.m[3][0]),
//		1 / num * (m.m[0][0] * m.m[1][2] * m.m[3][1]  +  m.m[0][1] * m.m[1][0] * m.m[3][2]  +  m.m[0][2] * m.m[1][1] * m.m[3][0]  -  m.m[0][0] * m.m[1][1] * m.m[3][2]  -  m.m[0][1] * m.m[1][2] * m.m[3][0]  -  m.m[0][2] * m.m[1][0] * m.m[3][1]),
//		1 / num * (m.m[0][0] * m.m[1][1] * m.m[2][2]  +  m.m[0][1] * m.m[1][2] * m.m[2][0]  +  m.m[0][2] * m.m[1][0] * m.m[2][1]  -  m.m[0][0] * m.m[1][2] * m.m[2][1]  -  m.m[0][1] * m.m[1][0] * m.m[2][2]  -  m.m[0][2] * m.m[1][1] * m.m[2][0])
//	};
//	return mat;
//}

Matrix4x4 Transpose(const Matrix4x4& m) {
	Matrix4x4 mat = {
		m.m[0][0],m.m[1][0],m.m[2][0],m.m[3][0],
		m.m[0][1],m.m[1][1],m.m[2][1],m.m[3][1],
		m.m[0][2],m.m[1][2],m.m[2][2],m.m[3][2],
		m.m[0][3],m.m[0][3],m.m[2][3],m.m[3][3]
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

Matrix4x4 MakeRotateXMatrix(float radian) {
	Matrix4x4 mat = {
		1,0,0,0,
		0,std::cosf(radian),std::sinf(radian),0,
		0,-std::sinf(radian),std::cosf(radian),0,
		0,0,0,1
	};
	return mat;
}

Matrix4x4 MakeRotateYMatrix(float radian) {
	Matrix4x4 mat = {
		std::cosf(radian),0,-std::sinf(radian),0,
		0,1,0,0,
		std::sinf(radian),0,std::cosf(radian),0,
		0,0,0,1
	};
	return mat;
}

Matrix4x4 MakeRotateZMatrix(float radian) {
	Matrix4x4 mat = {
		std::cosf(radian),std::sinf(radian),0,0,
		-std::sinf(radian),std::cosf(radian),0,0,
		0,0,1,0,
		0,0,0,1
	};
	return mat;
}


Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate) {
	Matrix4x4 rotateXMatrix = MakeRotateXMatrix(rotate.x);
	Matrix4x4 rotateYMatrix = MakeRotateYMatrix(rotate.y);
	Matrix4x4 rotateZMatrix = MakeRotateZMatrix(rotate.z);
	Matrix4x4 rotateMatrix = Multiply(rotateXMatrix, Multiply(rotateYMatrix, rotateZMatrix));

	

	Matrix4x4 mat = {
		scale.x * rotateMatrix.m[0][0],   scale.x * rotateMatrix.m[0][1],   scale.x * rotateMatrix.m[0][2],   0,
		scale.y * rotateMatrix.m[1][0],   scale.y * rotateMatrix.m[1][1],   scale.y * rotateMatrix.m[1][2],   0,
		scale.z * rotateMatrix.m[2][0],   scale.z * rotateMatrix.m[2][1],   scale.z * rotateMatrix.m[2][2],   0,
		translate.x,translate.y,translate.z,1
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

Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip) {
	Matrix4x4 mat = {
		(1 / aspectRatio) * (1 / std::tanf(fovY / 2)),	0,	0,	0,
		0,	1 / std::tanf(fovY / 2),	0,	0,
		0,	0,	farClip / (farClip - nearClip),	1,
		0,	0,	(-nearClip * farClip) / (farClip - nearClip),	0
	};
	return mat;
}

Matrix4x4 MakeOrthographicMatrix(float left, float top, float right,float bottom, float nearClip, float farClip) {
	Matrix4x4 mat = {
		2 / (right - left),	0,0,0,
		0,2 / (top - bottom),0,0,
		0,0,1 / (farClip - nearClip),0,
		(left + right) / (left - right),(top + bottom) / (bottom - top),nearClip / (nearClip - farClip),1
	};
	return mat;
}

Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth) {
	Matrix4x4 mat = {
		width / 2,0,0,0,
		0,-height / 2,0,0,
		0,0,maxDepth - minDepth,0,
		left + width / 2,top + height / 2,minDepth,1
	};
	return mat;
}

Vector3 Cross(const Vector3& v1, const Vector3& v2) {
	Vector3 num = {};
	num.x = v1.y * v2.z - v1.z * v2.y;
	num.y = v1.z * v2.x - v1.x * v2.z;
	num.z = v1.x * v2.y - v1.y * v2.x;

	return num;
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

float InverseNum(const Matrix4x4& m, int a, int b, int c, int d, int e, int f, int g, int h) {
	float resultNum;
	resultNum = m.m[a - 1][b - 1] * m.m[c - 1][d - 1] * m.m[e - 1][f - 1] * m.m[g - 1][h - 1];
	return resultNum;
}
float InverseNum2(const Matrix4x4& m, int a, int b, int c, int d, int e, int f) {
	float resultNum;
	resultNum = m.m[a - 1][b - 1] * m.m[c - 1][d - 1] * m.m[e - 1][f - 1];
	return resultNum;
}

Matrix4x4 Inverse(const Matrix4x4& m) {
	Matrix4x4 resultInverse = {};
	float resultNum;
	resultNum =
		InverseNum(m, 1, 1, 2, 2, 3, 3, 4, 4) + InverseNum(m, 1, 1, 2, 3, 3, 4, 4, 2) + InverseNum(m, 1, 1, 2, 4, 3, 2, 4, 3) -
		InverseNum(m, 1, 1, 2, 4, 3, 3, 4, 2) - InverseNum(m, 1, 1, 2, 3, 3, 2, 4, 4) - InverseNum(m, 1, 1, 2, 2, 3, 4, 4, 3) -
		InverseNum(m, 1, 2, 2, 1, 3, 3, 4, 4) - InverseNum(m, 1, 3, 2, 1, 3, 4, 4, 2) - InverseNum(m, 1, 4, 2, 1, 3, 2, 4, 3) +
		InverseNum(m, 1, 4, 2, 1, 3, 3, 4, 2) + InverseNum(m, 1, 3, 2, 1, 3, 2, 4, 4) + InverseNum(m, 1, 2, 2, 1, 3, 4, 4, 3) +
		InverseNum(m, 1, 2, 2, 3, 3, 1, 4, 4) + InverseNum(m, 1, 3, 2, 4, 3, 1, 4, 2) + InverseNum(m, 1, 4, 2, 2, 3, 1, 4, 3) -
		InverseNum(m, 1, 4, 2, 3, 3, 1, 4, 2) - InverseNum(m, 1, 3, 2, 2, 3, 1, 4, 4) - InverseNum(m, 1, 2, 2, 4, 3, 1, 4, 3) -
		InverseNum(m, 1, 2, 2, 3, 3, 2, 4, 1) - InverseNum(m, 1, 3, 2, 4, 3, 2, 4, 1) - InverseNum(m, 1, 4, 2, 2, 3, 3, 4, 1) +
		InverseNum(m, 1, 4, 2, 3, 3, 2, 4, 1) + InverseNum(m, 1, 3, 2, 2, 3, 4, 4, 1) + InverseNum(m, 1, 2, 2, 4, 3, 3, 4, 1);

	resultInverse.m[0][0] = (InverseNum2(m, 2, 2, 3, 3, 4, 4) + InverseNum2(m, 2, 3, 3, 4, 4, 2) + InverseNum2(m, 2, 4, 3, 2, 4, 3) -
		InverseNum2(m, 2, 4, 3, 3, 4, 2) - InverseNum2(m, 2, 3, 3, 2, 4, 4) - InverseNum2(m, 2, 2, 3, 4, 4, 3)) * (1 / resultNum);
	resultInverse.m[0][1] = (InverseNum2(m, 1, 4, 3, 3, 4, 2) + InverseNum2(m, 1, 3, 3, 2, 4, 4) + InverseNum2(m, 1, 2, 3, 4, 4, 3) -
		InverseNum2(m, 1, 2, 3, 3, 4, 4) - InverseNum2(m, 1, 3, 3, 4, 4, 2) - InverseNum2(m, 1, 4, 3, 2, 4, 3)) * (1 / resultNum);
	resultInverse.m[0][2] = (InverseNum2(m, 1, 2, 2, 3, 4, 4) + InverseNum2(m, 1, 3, 2, 4, 4, 2) + InverseNum2(m, 1, 4, 2, 2, 4, 3) -
		InverseNum2(m, 1, 4, 2, 3, 4, 2) - InverseNum2(m, 1, 3, 2, 2, 4, 4) - InverseNum2(m, 1, 2, 2, 4, 4, 3)) * (1 / resultNum);
	resultInverse.m[0][3] = (InverseNum2(m, 1, 4, 2, 3, 3, 2) + InverseNum2(m, 1, 3, 2, 2, 3, 4) + InverseNum2(m, 1, 2, 2, 4, 3, 3) -
		InverseNum2(m, 1, 2, 2, 3, 3, 4) - InverseNum2(m, 1, 3, 2, 4, 3, 2) - InverseNum2(m, 1, 4, 2, 2, 3, 3)) * (1 / resultNum);

	resultInverse.m[1][0] = (InverseNum2(m, 2, 4, 3, 3, 4, 1) + InverseNum2(m, 2, 3, 3, 1, 4, 4) + InverseNum2(m, 2, 1, 3, 4, 4, 3) -
		InverseNum2(m, 2, 1, 3, 3, 4, 4) - InverseNum2(m, 2, 3, 3, 4, 4, 1) - InverseNum2(m, 2, 4, 3, 1, 4, 3)) * (1 / resultNum);
	resultInverse.m[1][1] = (InverseNum2(m, 1, 1, 3, 3, 4, 4) + InverseNum2(m, 1, 3, 3, 4, 4, 1) + InverseNum2(m, 1, 4, 3, 1, 4, 3) -
		InverseNum2(m, 1, 4, 3, 3, 4, 1) - InverseNum2(m, 1, 3, 3, 1, 4, 4) - InverseNum2(m, 1, 1, 3, 4, 4, 3)) * (1 / resultNum);
	resultInverse.m[1][2] = (InverseNum2(m, 1, 4, 2, 3, 4, 1) + InverseNum2(m, 1, 3, 2, 1, 4, 4) + InverseNum2(m, 1, 1, 2, 4, 4, 3) -
		InverseNum2(m, 1, 1, 2, 3, 4, 4) - InverseNum2(m, 1, 3, 2, 4, 4, 1) - InverseNum2(m, 1, 4, 2, 1, 4, 3)) * (1 / resultNum);
	resultInverse.m[1][3] = (InverseNum2(m, 1, 1, 2, 3, 3, 4) + InverseNum2(m, 1, 3, 2, 4, 3, 1) + InverseNum2(m, 1, 4, 2, 1, 3, 3) -
		InverseNum2(m, 1, 4, 2, 3, 3, 1) - InverseNum2(m, 1, 3, 2, 1, 3, 4) - InverseNum2(m, 1, 1, 2, 4, 3, 3)) * (1 / resultNum);

	resultInverse.m[2][0] = (InverseNum2(m, 2, 1, 3, 2, 4, 4) + InverseNum2(m, 2, 2, 3, 4, 4, 1) + InverseNum2(m, 2, 4, 3, 1, 4, 2) -
		InverseNum2(m, 2, 4, 3, 2, 4, 1) - InverseNum2(m, 2, 2, 3, 1, 4, 4) - InverseNum2(m, 2, 1, 3, 4, 4, 2)) * (1 / resultNum);
	resultInverse.m[2][1] = (InverseNum2(m, 1, 4, 3, 2, 4, 1) + InverseNum2(m, 1, 2, 3, 1, 4, 4) + InverseNum2(m, 1, 1, 3, 4, 4, 2) -
		InverseNum2(m, 1, 1, 3, 2, 4, 4) - InverseNum2(m, 1, 2, 3, 4, 4, 1) - InverseNum2(m, 1, 4, 3, 1, 4, 2)) * (1 / resultNum);
	resultInverse.m[2][2] = (InverseNum2(m, 1, 1, 2, 2, 4, 4) + InverseNum2(m, 1, 2, 2, 4, 4, 1) + InverseNum2(m, 1, 4, 2, 1, 4, 2) -
		InverseNum2(m, 1, 4, 2, 2, 4, 1) - InverseNum2(m, 1, 2, 2, 1, 4, 4) - InverseNum2(m, 1, 1, 2, 4, 4, 2)) * (1 / resultNum);
	resultInverse.m[2][3] = (InverseNum2(m, 1, 4, 2, 2, 3, 1) + InverseNum2(m, 1, 2, 2, 1, 3, 4) + InverseNum2(m, 1, 1, 2, 4, 3, 2) -
		InverseNum2(m, 1, 1, 2, 2, 3, 4) - InverseNum2(m, 1, 2, 2, 4, 3, 1) - InverseNum2(m, 1, 4, 2, 1, 3, 2)) * (1 / resultNum);

	resultInverse.m[3][0] = (InverseNum2(m, 2, 3, 3, 2, 4, 1) + InverseNum2(m, 2, 2, 3, 1, 4, 1) + InverseNum2(m, 2, 1, 3, 3, 4, 2) -
		InverseNum2(m, 2, 1, 3, 2, 4, 3) - InverseNum2(m, 2, 2, 3, 3, 4, 1) - InverseNum2(m, 2, 3, 3, 1, 4, 2)) * (1 / resultNum);
	resultInverse.m[3][1] = (InverseNum2(m, 1, 1, 3, 2, 4, 3) + InverseNum2(m, 1, 2, 3, 3, 4, 1) + InverseNum2(m, 1, 3, 3, 1, 4, 2) -
		InverseNum2(m, 1, 3, 3, 2, 4, 1) - InverseNum2(m, 1, 2, 3, 1, 4, 3) - InverseNum2(m, 1, 1, 3, 3, 4, 2)) * (1 / resultNum);
	resultInverse.m[3][2] = (InverseNum2(m, 1, 3, 2, 2, 4, 1) + InverseNum2(m, 1, 2, 2, 1, 4, 3) + InverseNum2(m, 1, 1, 2, 3, 4, 2) -
		InverseNum2(m, 1, 1, 2, 2, 4, 3) - InverseNum2(m, 1, 2, 2, 3, 4, 1) - InverseNum2(m, 1, 3, 2, 1, 4, 2)) * (1 / resultNum);
	resultInverse.m[3][3] = (InverseNum2(m, 1, 1, 2, 2, 3, 3) + InverseNum2(m, 1, 2, 2, 3, 3, 1) + InverseNum2(m, 1, 3, 2, 1, 3, 2) -
		InverseNum2(m, 1, 3, 2, 2, 3, 1) - InverseNum2(m, 1, 2, 2, 1, 3, 3) - InverseNum2(m, 1, 1, 2, 3, 3, 2)) * (1 / resultNum);

	return resultInverse;
}

Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 resultMatrix = {};

	resultMatrix.m[0][0] = m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0] +
		m1.m[0][2] * m2.m[2][0] + m1.m[0][3] * m2.m[3][0];
	resultMatrix.m[0][1] = m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1] +
		m1.m[0][2] * m2.m[2][1] + m1.m[0][3] * m2.m[3][1];
	resultMatrix.m[0][2] = m1.m[0][0] * m2.m[0][2] + m1.m[0][1] * m2.m[1][2] +
		m1.m[0][2] * m2.m[2][2] + m1.m[0][3] * m2.m[3][2];
	resultMatrix.m[0][3] = m1.m[0][0] * m2.m[0][3] + m1.m[0][1] * m2.m[1][3] +
		m1.m[0][2] * m2.m[2][3] + m1.m[0][3] * m2.m[3][3];

	resultMatrix.m[1][0] = m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0] +
		m1.m[1][2] * m2.m[2][0] + m1.m[1][3] * m2.m[3][0];
	resultMatrix.m[1][1] = m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1] +
		m1.m[1][2] * m2.m[2][1] + m1.m[1][3] * m2.m[3][1];
	resultMatrix.m[1][2] = m1.m[1][0] * m2.m[0][2] + m1.m[1][1] * m2.m[1][2] +
		m1.m[1][2] * m2.m[2][2] + m1.m[1][3] * m2.m[3][2];
	resultMatrix.m[1][3] = m1.m[1][0] * m2.m[0][3] + m1.m[1][1] * m2.m[1][3] +
		m1.m[1][2] * m2.m[2][3] + m1.m[1][3] * m2.m[3][3];

	resultMatrix.m[2][0] = m1.m[2][0] * m2.m[0][0] + m1.m[2][1] * m2.m[1][0] +
		m1.m[2][2] * m2.m[2][0] + m1.m[2][3] * m2.m[3][0];
	resultMatrix.m[2][1] = m1.m[2][0] * m2.m[0][1] + m1.m[2][1] * m2.m[1][1] +
		m1.m[2][2] * m2.m[2][1] + m1.m[2][3] * m2.m[3][1];
	resultMatrix.m[2][2] = m1.m[2][0] * m2.m[0][2] + m1.m[2][1] * m2.m[1][2] +
		m1.m[2][2] * m2.m[2][2] + m1.m[2][3] * m2.m[3][2];
	resultMatrix.m[2][3] = m1.m[2][0] * m2.m[0][3] + m1.m[2][1] * m2.m[1][3] +
		m1.m[2][2] * m2.m[2][3] + m1.m[2][3] * m2.m[3][3];

	resultMatrix.m[3][0] = m1.m[3][0] * m2.m[0][0] + m1.m[3][1] * m2.m[1][0] +
		m1.m[3][2] * m2.m[2][0] + m1.m[3][3] * m2.m[3][0];
	resultMatrix.m[3][1] = m1.m[3][0] * m2.m[0][1] + m1.m[3][1] * m2.m[1][1] +
		m1.m[3][2] * m2.m[2][1] + m1.m[3][3] * m2.m[3][1];
	resultMatrix.m[3][2] = m1.m[3][0] * m2.m[0][2] + m1.m[3][1] * m2.m[1][2] +
		m1.m[3][2] * m2.m[2][2] + m1.m[3][3] * m2.m[3][2];
	resultMatrix.m[3][3] = m1.m[3][0] * m2.m[0][3] + m1.m[3][1] * m2.m[1][3] +
		m1.m[3][2] * m2.m[2][3] + m1.m[3][3] * m2.m[3][3];

	return resultMatrix;
}
void DrawGrid(const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix) {
	const float kGridHalfWidth = 2.0f;											//Gridの半分の幅
	const uint32_t kSubdivision = 10;											//分割数
	const float kGridEvery = (kGridHalfWidth * 2.0f) / float(kSubdivision);	//1つ分の長さ

	//奥から手前への線を順に引いていく
	for (uint32_t xIndex = 0; xIndex <= kSubdivision; ++xIndex) {
		Matrix4x4 worldMatrix = MakeAffineMatrix({ 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, float(5 - int(xIndex)) * kGridEvery });

		Matrix4x4 worldViewProjectionMatrix = Multiply(worldMatrix, viewProjectionMatrix);

		Vector3 localVertices[2] = { {-2, 0, 0}, {2, 0, 0} };
		Vector3 screenVertices[2]{};
		for (uint32_t i = 0; i < 2; ++i) {
			//NDCまで変換。Transformを使うと同時座標系->デカルト座標系の処理が行われ、結果的にZDvivideが行われることになる
			Vector3 ndcVertex = Transform(localVertices[i], worldViewProjectionMatrix);
			//viewport変換を使ってScreen空間へ
			screenVertices[i] = Transform(ndcVertex, viewportMatrix);
		}
		if (xIndex != 5) {
			Novice::DrawLine((int)screenVertices[0].x, (int)screenVertices[0].y, (int)screenVertices[1].x, (int)screenVertices[1].y, 0xAAAAAAFF);
		}
		else {
			Novice::DrawLine((int)screenVertices[0].x, (int)screenVertices[0].y, (int)screenVertices[1].x, (int)screenVertices[1].y, 0x222222FF);
		}
	}
	//左からも線を引いていく
	for (uint32_t zIndex = 0; zIndex <= kSubdivision; ++zIndex) {
		Matrix4x4 worldMatrix = MakeAffineMatrix({ 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { float(5 - int(zIndex)) * kGridEvery, 0.0f, 0.0f });

		Matrix4x4 worldViewProjectionMatrix = Multiply(worldMatrix, viewProjectionMatrix);

		Vector3 localVertices[2] = { {0, 0, -2}, {0, 0, 2} };
		Vector3 screenVertices[2]{};
		for (uint32_t i = 0; i < 2; ++i) {
			//NDCまで変換。Transformを使うと同時座標系->デカルト座標系の処理が行われ、結果的にZDvivideが行われることになる
			Vector3 ndcVertex = Transform(localVertices[i], worldViewProjectionMatrix);
			//viewport変換を使ってScreen空間へ
			screenVertices[i] = Transform(ndcVertex, viewportMatrix);
		}
		if (zIndex != 5) {
			Novice::DrawLine((int)screenVertices[0].x, (int)screenVertices[0].y, (int)screenVertices[1].x, (int)screenVertices[1].y, 0xAAAAAAFF);
		}
		else {
			Novice::DrawLine((int)screenVertices[0].x, (int)screenVertices[0].y, (int)screenVertices[1].x, (int)screenVertices[1].y, 0x222222FF);
		}
	}
}

bool IsCollision(const Sphere& s1, const Sphere& s2) {
	float distance = Length(Subtract(s2.center, s1.center));

	if (distance <= s1.radius + s2.radius) {
		return true;
	}
	else {
		return false;
	}
}

void DrawSphere(const Sphere& sphere, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color) {
	const uint32_t kSubdivision = 16;
	const float kLonEvery = (2 * M_PI) / kSubdivision;
	const float kLatEvery = (M_PI) / kSubdivision;
	//緯度の方向に分割 -π/1 ～ π/2
	for (uint32_t latIndex = 0; latIndex < kSubdivision; ++latIndex) {
		float lat = -M_PI / 2.0f + kLatEvery * latIndex; //現在の緯度
		//経度の方向に分割 0～2π
		for (uint32_t lonIndex = 0; lonIndex < kSubdivision; ++lonIndex) {
			float lon = lonIndex * kLonEvery;
			//world座標系でのa, b, cを求める
			Vector3 a, b, c;
			a = { std::cos(lat) * std::cos(lon),
				std::sin(lat),
				std::cos(lat) * std::sin(lon) };

			b = { std::cos(lat + kLatEvery) * std::cos(lon),
				std::sin(lat + kLatEvery),
				std::cos(lat + kLatEvery) * std::sin(lon) };

			c = { std::cos(lat) * std::cos(lon + kLonEvery),
				std::sin(lat),
				std::cos(lat) * std::sin(lon + kLonEvery) };

			a.x *= sphere.radius;
			a.y *= sphere.radius;
			a.z *= sphere.radius;

			b.x *= sphere.radius;
			b.y *= sphere.radius;
			b.z *= sphere.radius;

			c.x *= sphere.radius;
			c.y *= sphere.radius;
			c.z *= sphere.radius;

			a.x += sphere.center.x;
			a.y += sphere.center.y;
			a.z += sphere.center.z;

			b.x += sphere.center.x;
			b.y += sphere.center.y;
			b.z += sphere.center.z;

			c.x += sphere.center.x;
			c.y += sphere.center.y;
			c.z += sphere.center.z;

			Matrix4x4 worldMatrixA = MakeAffineMatrix({ 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, a);

			Matrix4x4 worldViewProjectionMatrixA = Multiply(worldMatrixA, viewProjectionMatrix);

			Matrix4x4 worldMatrixB = MakeAffineMatrix({ 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, b);

			Matrix4x4 worldViewProjectionMatrixB = Multiply(worldMatrixB, viewProjectionMatrix);

			Matrix4x4 worldMatrixC = MakeAffineMatrix({ 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, c);

			Matrix4x4 worldViewProjectionMatrixC = Multiply(worldMatrixC, viewProjectionMatrix);

			Vector3 screenVertices[3]{};

			//NDCまで変換。Transformを使うと同時座標系->デカルト座標系の処理が行われ、結果的にZDvivideが行われることになる
			Vector3 ndcVertexA = Transform({ 0, 0, 0 }, worldViewProjectionMatrixA);
			//viewport変換を使ってScreen空間へ
			screenVertices[0] = Transform(ndcVertexA, viewportMatrix);

			//NDCまで変換。Transformを使うと同時座標系->デカルト座標系の処理が行われ、結果的にZDvivideが行われることになる
			Vector3 ndcVertexB = Transform({ 0, 0, 0 }, worldViewProjectionMatrixB);
			//viewport変換を使ってScreen空間へ
			screenVertices[1] = Transform(ndcVertexB, viewportMatrix);

			//NDCまで変換。Transformを使うと同時座標系->デカルト座標系の処理が行われ、結果的にZDvivideが行われることになる
			Vector3 ndcVertexC = Transform({ 0, 0, 0 }, worldViewProjectionMatrixC);
			//viewport変換を使ってScreen空間へ
			screenVertices[2] = Transform(ndcVertexC, viewportMatrix);

			Novice::DrawLine(
				(int)screenVertices[0].x, (int)screenVertices[0].y,
				(int)screenVertices[1].x, (int)screenVertices[1].y,
				color);

			Novice::DrawLine(
				(int)screenVertices[0].x, (int)screenVertices[0].y,
				(int)screenVertices[2].x, (int)screenVertices[2].y,
				color);
		}
	}
}

Vector3 Project(const Vector3& v1, const Vector3& v2) {
	Vector3 normalizeV2 = Normalize(v2);
	Vector3 result = Multiply(normalizeV2, Multiply(v1, normalizeV2));
	return result;
}

Vector3 ClosestPoint(const Vector3& point, const Segment& segment) {
	Vector3 result = Project(Subtract(point, segment.origin), segment.diff);
	Vector3 cp = Add(segment.origin, result);

	return cp;
}

bool IsCollision(const Sphere& sphere, const Plane& plane) {
	//絶対値で距離を求める
	float distance = fabs(Dot(plane.normal, sphere.center) - plane.distance);

	if (distance >= sphere.radius) {
		return false;//衝突していない
	}
	else if (distance <= sphere.radius) {
		return true;//衝突している
	}
}

Vector3 Perpendicular(const Vector3& vector) {
	if (vector.x != 0.0f || vector.y != 0.0f) {
		return { -vector.y,vector.x,0.0f };
	}
	return{ 0.0f,-vector.z,vector.y };
}

void DrawPlane(const Plane& plane, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color) {
	Vector3 center = Multiply(plane.distance, plane.normal); //1
	Vector3 perpendiculars[4];
	perpendiculars[0] = Normalize(Perpendicular(plane.normal)); //2
	perpendiculars[1] = { -perpendiculars[0].x - perpendiculars[0].y, -perpendiculars[0].z }; //3
	perpendiculars[2] = Cross(plane.normal, perpendiculars[0]); //4
	perpendiculars[3] = { -perpendiculars[2].x,-perpendiculars[2].y ,-perpendiculars[2].z }; //5
	//6
	Vector3 points[4];
	for (int32_t index = 0; index < 4; ++index) {
		Vector3 extend = Multiply(2.0f, perpendiculars[index]);
		Vector3 point = Add(center, extend);
		points[index] = Transform(Transform(point, viewProjectionMatrix), viewportMatrix);
	}
	Novice::DrawLine(points[0].x, points[0].y, points[2].x, points[2].y, color);
	Novice::DrawLine(points[1].x, points[1].y, points[3].x, points[3].y, color);
	Novice::DrawLine(points[2].x, points[2].y, points[1].x, points[1].y, color);
	Novice::DrawLine(points[3].x, points[3].y, points[0].x, points[0].y, color);
}

bool IsCollision(const Segment& segment, const Plane& plane) {
	//垂直判定を行うために、法線と線の内積を求める
	float dot = Dot(plane.normal, segment.diff);

	// 垂直=平行であるので、衝突しているはずがない
	if (dot == 0.0f) {
		return false;
	}

	// tを求める
	float t = (plane.distance - Dot(segment.origin, plane.normal)) / dot;
	// tの値と線の種類によって衝突しているかを判断する
	if (t < 0 || t > 1.0f) {
		return false;
	}
	return true;
}

void DrawSegment(const Segment& segment, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color) {
	Vector3 start = segment.origin;
	Vector3 end = { segment.origin.x + segment.diff.x, segment.origin.y + segment.diff.y, segment.origin.z + segment.diff.z };

	Vector3 points[2];
	points[0] = Transform(Transform(start, viewProjectionMatrix), viewportMatrix);
	points[1] = Transform(Transform(end, viewProjectionMatrix), viewportMatrix);

	Novice::DrawLine(points[0].x, points[0].y, points[1].x, points[1].y, color);
}


bool IsCollision(const Triangle& triangle, const Segment& segment) {
	Plane plane{};
	plane.normal = Normalize(
		Cross(
			Subtract(triangle.vertices[1], triangle.vertices[0]),
			Subtract(triangle.vertices[2], triangle.vertices[1])
		)
	);
	plane.distance = Dot(triangle.vertices[0], plane.normal);

	// 垂直な判定をとるために法線と線の内積をとる
	float dot = Dot(plane.normal, segment.diff);

	// 垂直な場合は平行であるため衝突はしていない
	if (dot == 0.0f) {
		return false;
	}

	// tを求める
	float t = (plane.distance - Dot(segment.origin, plane.normal)) / dot;

	if (0.0f < t && 1.0f > t) {
		// 衝突点pを求める
		Vector3 p = Add(segment.origin, Multiply(t,segment.diff));

		// 各辺を結んだベクトルと頂点と衝突点pを結んだベクトルのクロス積をとる
		Vector3 cross01 = Cross(
			Subtract(triangle.vertices[1], triangle.vertices[0]),
			Subtract(p, triangle.vertices[1])
		);

		Vector3 cross12 = Cross(
			Subtract(triangle.vertices[2], triangle.vertices[1]),
			Subtract(p, triangle.vertices[2])
		);

		Vector3 cross20 = Cross(
			Subtract(triangle.vertices[0], triangle.vertices[2]),
			Subtract(p, triangle.vertices[0])
		);

		// 全ての小三角形のクロス積と法線が同じ方向なら衝突している
		if (Dot(cross01, plane.normal) >= 0.0f &&
			Dot(cross12, plane.normal) >= 0.0f &&
			Dot(cross20, plane.normal) >= 0.0f) {

			return true;

		}

	}
	return false;
}

void DrawTriange(const Triangle& triangle, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color) {
	// 頂点座標
	Vector3 screenVertices[3];
	for (uint32_t i = 0; i < 3; ++i) {
		Vector3 ndcVertex = Transform(triangle.vertices[i], viewProjectionMatrix);
		screenVertices[i] = Transform(ndcVertex, viewportMatrix);
	}

	// 描画
	Novice::DrawTriangle(
		int(screenVertices[0].x), int(screenVertices[0].y),
		int(screenVertices[1].x), int(screenVertices[1].y),
		int(screenVertices[2].x), int(screenVertices[2].y),
		color, kFillModeWireFrame
	);
}

void DrawAABB(const AABB& aabb, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color) {
	Vector3 vers[8]{};
	vers[0] = { aabb.min.x, aabb.min.y, aabb.min.z };
	vers[1] = { aabb.min.x, aabb.min.y, aabb.max.z };
	vers[2] = { aabb.min.x, aabb.max.y, aabb.min.z };
	vers[3] = { aabb.max.x, aabb.min.y, aabb.min.z };
	vers[4] = { aabb.max.x, aabb.max.y, aabb.min.z };
	vers[5] = { aabb.min.x, aabb.max.y, aabb.max.z };
	vers[6] = { aabb.max.x, aabb.min.y, aabb.max.z };
	vers[7] = { aabb.max.x, aabb.max.y, aabb.max.z };

	Vector3 screenVers[8]{};
	for (int i = 0; i < 8; i++) {
		vers[i] = Transform(vers[i], viewProjectionMatrix);
		screenVers[i] = Transform(vers[i], viewportMatrix);
	}

	Novice::DrawLine(int(screenVers[0].x), int(screenVers[0].y), int(screenVers[1].x), int(screenVers[1].y), color);
	Novice::DrawLine(int(screenVers[0].x), int(screenVers[0].y), int(screenVers[2].x), int(screenVers[2].y), color);
	Novice::DrawLine(int(screenVers[0].x), int(screenVers[0].y), int(screenVers[3].x), int(screenVers[3].y), color);

	Novice::DrawLine(int(screenVers[1].x), int(screenVers[1].y), int(screenVers[5].x), int(screenVers[5].y), color);
	Novice::DrawLine(int(screenVers[1].x), int(screenVers[1].y), int(screenVers[6].x), int(screenVers[6].y), color);

	Novice::DrawLine(int(screenVers[2].x), int(screenVers[2].y), int(screenVers[4].x), int(screenVers[4].y), color);
	Novice::DrawLine(int(screenVers[2].x), int(screenVers[2].y), int(screenVers[5].x), int(screenVers[5].y), color);

	Novice::DrawLine(int(screenVers[3].x), int(screenVers[3].y), int(screenVers[4].x), int(screenVers[4].y), color);
	Novice::DrawLine(int(screenVers[3].x), int(screenVers[3].y), int(screenVers[6].x), int(screenVers[6].y), color);

	Novice::DrawLine(int(screenVers[4].x), int(screenVers[4].y), int(screenVers[7].x), int(screenVers[7].y), color);
	Novice::DrawLine(int(screenVers[5].x), int(screenVers[5].y), int(screenVers[7].x), int(screenVers[7].y), color);
	Novice::DrawLine(int(screenVers[6].x), int(screenVers[6].y), int(screenVers[7].x), int(screenVers[7].y), color);

}

bool IsCollision(const AABB& aabb1, const AABB& aabb2) {
	if ((aabb1.min.x <= aabb2.max.x && aabb1.max.x >= aabb2.min.x) &&
		(aabb1.min.y <= aabb2.max.y && aabb1.max.y >= aabb2.min.y) &&
		(aabb1.min.z <= aabb2.max.z && aabb1.max.z >= aabb2.min.z)
		) {
		return true;
	}
	return false;
}

bool IsCollision(const AABB& aabb, const Sphere& sphere) {
	Vector3 clossestPoint{
		std::clamp(sphere.center.x, aabb.min.x, aabb.max.x),
		std::clamp(sphere.center.y, aabb.min.y, aabb.max.y),
		std::clamp(sphere.center.z, aabb.min.z, aabb.max.z)
	};
	float distance = Length(Subtract(clossestPoint, sphere.center));
	if (distance <= sphere.radius) {
		return true;
	}
	return false;
}

Matrix4x4 MakeRotateAxisAngle(const Vector3& axis, float angle) {
	Matrix4x4 result = {
		std::pow(axis.x,2) * (1 - std::cos(angle)) + std::cos(angle),   axis.x * axis.y * (1 - std::cos(angle)) + axis.z * std::sin(angle),  axis.x * axis.z * (1 - std::cos(angle)) - axis.y * std::sin(angle),0,
		axis.x * axis.y * (1 - std::cos(angle)) - axis.z * std::sin(angle),   std::pow(axis.y,2) * (1 - std::cos(angle)) + std::cos(angle),  axis.y * axis.z * (1 - std::cos(angle)) + axis.x * std::sin(angle),0,
		axis.x * axis.z * (1 - std::cos(angle)) + axis.y * std::cos(angle),   axis.y * axis.z * (1 - std::cos(angle)) - axis.x * std::sin(angle),  std::pow(axis.z,2) * (1 - std::cos(angle)) + std::cos(angle),0,
		0,0,0,1
	};

	return result;
}