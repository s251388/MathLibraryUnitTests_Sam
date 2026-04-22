#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

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


		static Matrix4 MakeRotateX(float op) {
			
			op *= 180/M_PI;

			return {1,0,0,0,cos(op),sin(op),0,-sin(op),cos(op)};

		}

		static Matrix4 MakeRotateY(float op) {

			op *= 180/M_PI;

			return {cos(op),0,sin(op),0,1,0,-sin(op),0,cos(op)};

		}

		static Matrix4 MakeRotateZ(float op) {

			op *= 180/M_PI;

			return {cos(op),-sin(op),0,sin(op),cos(op),0,0,0,1};
		
		}
		
		static Matrix4 MakeScale(float x, float y, float z) {
			
			return {x,0,0,0,0,y,0,0,0,0,z,0,0,0,0,1};
		
		}
		
		Vector4 GetRight() {
			
			Vector4 temp (grid[0][0],grid[1][0],grid[2][0],grid[3][0]);

			return temp;
		
		}
		
		Vector4 GetUp() {
			
			Vector4 temp (grid[0][1],grid[1][1],grid[2][1],grid[3][1]);

			return temp;
		
		}
		
		Vector4 GetForward() {
			
			Vector4 temp (grid[0][2],grid[1][2],grid[2][2],grid[3][2]);

			return temp;
		
		}
		
		Vector4 GetPosition() {
		
			Vector4 temp (grid[0][3],grid[1][3],grid[2][3],grid[3][3]);

			return temp;
		
		}
		
		bool IsApproximatelyEqual(const Matrix4& op, float E = 1e-4) const {

			for (int i = 0; i < 16; i++) {
				if (arr[i] - op.arr[i] > E) {
					return false;
				}
			}

			return true;

		}

		void SetTranslate(const Vector4& op) {
		
			for (int i = 0; i < 4; i++) {
				grid[i][3] = op[i];
			}
		
		}
		
		static Matrix4 MakeTranslation(float x, float y, float z) {

			return {1,0,0,x,0,1,0,y,0,0,1,z,0,0,0,1};
		
		}

	};

}