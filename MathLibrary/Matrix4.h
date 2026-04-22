#pragma once

namespace MathLibrary {

	struct Matrix4 {

		union {
			struct {
				float m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16;
			};
			float arr[16];
			float grid[4][4];
		};


		Matrix4() {

			for (int i = 0; i < 16; i++) {

				if (i % 5 == 0) {
					arr[i] = 1;
				}
				else {
					arr[i] = 0;
				}

			}

		}

		Matrix4(float ALL) {

			for (int i = 0; i < 16; i++) {		// This constructor takes a Matrix declaration with just 1 float
				// and assumes the user wants to build the Matrix4 with all stored
				arr[i] = ALL;					// floats being the same. Mostly just useful for testing.

			}

		}

		Matrix4(std::initializer_list<float> m) {

			int i = 0;							// This constructor allows the user to specifically declare the value
			for (float m : m) {					// of each stored float on construction without having to be written as
				arr[i] = m;						// m1,m2,m3,m4,etc. Still learning how initializer_lists work,
				i++;
			}

		}

		Matrix4(const Matrix4& Copy) {

			for (int i = 0; i < 16; i++) {

				arr[i] = Copy.arr[i];

			}

		}


		Matrix4 operator=(const Matrix4& op) {

			for (int i = 0; i < 16; i++) {

				arr[i] = op.arr[i];

			}

			return *this;

		}

		Vector4 operator*(const Vector4& op) const {
			
			Vector4 temp;

			temp.x = grid[0][0] * op.x + grid[0][1] * op.y + grid[0][2] * op.z + grid[0][3] * op.w;			
			temp.y = grid[1][0] * op.x + grid[1][1] * op.y + grid[1][2] * op.z + grid[1][3] * op.w;			
			temp.z = grid[2][0] * op.x + grid[2][1] * op.y + grid[2][2] * op.z + grid[2][3] * op.w;			
			temp.w = grid[3][0] * op.x + grid[3][1] * op.y + grid[3][2] * op.z + grid[3][3] * op.w;

			return temp;

		}

		Matrix4 operator*(const Matrix4& op) const {

			Matrix4 temp = 0;

			for (int A = 0; A < 4; A++) {				// A shmancy set of for loops i figured out after writing
				for (int B = 0; B < 4; B++) {			// the order of operations up on the whiteboard a bunch.
					for (int C = 0; C < 4; C++) {
						temp.grid[A][B] += grid[A][C] * op.grid[C][B];
					}
				}
			}

			return temp;

		}

		Matrix4 operator*=(const Matrix4& op) {

			*this = *this * op;

			return *this;

		}

		bool operator==(const Matrix4& op) const {

			for (int i = 0; i < 16; i++) {
				if (arr[i] != op.arr[i]) {
					return false;
				}
			}

			return true;

		}

		bool operator!=(const Matrix4& op) const {

			for (int i = 0; i < 16; i++) {
				if (arr[i] != op.arr[i]) {
					return true;
				}
			}

			return false;

		}

		float operator[](int i) const {

			return arr[i];

		}

		float& operator[](int i) {

			return arr[i];

		}


		//Matrix4 MakeRotateX(float op) {
		//
		//	return;
		//
		//}
		//
		//Matrix4 MakeRotateY(float op) {
		//
		//	return;
		//
		//}
		//
		//Matrix4 MakeRotateZ(float op) {
		//
		//	return;
		//
		//}
		//
		//
		//Matrix4 MakeScale(const Vector4& op) {
		//
		//	return;
		//
		//}
		//
		//Vector4 GetRight() {
		//
		//	return;
		//
		//}
		//
		//Vector4 GetUp() {
		//
		//	return;
		//
		//}
		//
		//Vector4 GetForward() {
		//
		//	return;
		//
		//}
		//
		//Vector4 GetPosition() {
		//
		//	return;
		//
		//}
		//
		//
		//bool IsApproximatelyEqual(const Matrix4& op, float E) {
		//
		//	return;
		//
		//}
		//
		//void SetTranslate(const Vector4& op) {
		//
		//	return;
		//
		//}
		//
		//Matrix4 MakeTranslate(const Vector4& op) {
		//
		//	return;
		//
		//}

	};

}