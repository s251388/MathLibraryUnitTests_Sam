#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

namespace MathLibrary {

	struct Matrix3 {

		union {
			struct {
				float m1, m2, m3, m4, m5, m6, m7, m8, m9;		// I'm using this union so i can read these 9 floats in any format i want while
			};													// still technically satisfying what the assessment wants from me, wholly separate
			float arr[9];										// variables are super tedious to write code for, often for loops make the code
			float grid[3][3];									// waayyy more compact and pleasant to read.
		};


		Matrix3() {

			for (int i = 0; i < 9; i++) {

				if (i % 4 == 0) {
					arr[i] = 1;
				}
				else {
					arr[i] = 0;
				}

			}

		}

		Matrix3(float ALL) {

			for (int i = 0; i < 9; i++) {		// This constructor takes a Matrix declaration with just 1 float
				// and assumes the user wants to build the Matrix3 with all stored
				arr[i] = ALL;					// floats being the same. Mostly just used for testing.

			}

		}

		Matrix3(std::initializer_list<float> m) {

			int i = 0;							// This constructor allows the user to specifically declare the value
			for (float m : m) {					// of each stored float on construction without having to be written as
				arr[i] = m;						// m1,m2,m3,m4,etc. Still learning how initializer_lists work,
				i++;
			}

		}

		Matrix3(const Matrix3& Copy) {

			for (int i = 0; i < 9; i++) {

				arr[i] = Copy.arr[i];

			}

		}


		Matrix3 operator=(const Matrix3& op) {

			for (int i = 0; i < 9; i++) {

				arr[i] = op.arr[i];

			}

			return *this;

		}

		Vector3 operator*(const Vector3& op) const {
			
			Vector3 temp;
			
			temp.x = grid[0][0] * op.x + grid[0][1] * op.y + grid[0][2] * op.z;		
			temp.y = grid[1][0] * op.x + grid[1][1] * op.y + grid[1][2] * op.z;		
			temp.z = grid[2][0] * op.x + grid[2][1] * op.y + grid[2][2] * op.z;		

			return temp;

		}

		Matrix3 operator*(const Matrix3& op) const {

			Matrix3 temp = 0;

			for (int A = 0; A < 3; A++) {				// A shmancy set of for loops i figured out after manually writing the order of
				for (int B = 0; B < 3; B++) {			// operations up on the whiteboard a bunch to see what changes with each process.
					for (int C = 0; C < 3; C++) {
						temp.grid[A][B] += grid[A][C] * op.grid[C][B];
					}
				}
			}

			return temp;

		}

		Matrix3 operator*=(const Matrix3& op) {

			*this = *this * op;

			return *this;

		}

		bool operator==(const Matrix3& op) const {

			for (int i = 0; i < 9; i++) {
				if (arr[i] != op.arr[i]) {
					return false;
				}
			}

			return true;

		}

		bool operator!=(const Matrix3& op) const {

			for (int i = 0; i < 9; i++) {
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

		static Matrix3 MakeRotate(float op) {

			op *= 180/M_PI;

			return {cos(op),-sin(op),0,sin(op),cos(op),0,0,0,1};
		
		}
		
		static Matrix3 MakeScale(float x, float y) {

			return {x,0,0,0,y,0,0,0,1};

		}
		
		static Matrix3 MakeTranslate(const Vector3& op) {

			return {op.x,0,0,0,op.y,0,0,0,1};

		}
		
		Vector3 GetRight() {
		
			Vector3 temp (grid[0][1],grid[1][1],grid[2][1]);

			return temp;
		
		}
		
		Vector3 GetForward() {
		
			Vector3 temp (grid[0][0],grid[1][0],grid[2][0]);

			return temp;
		
		}
		
		Vector3 GetTranslate() {
		
			Vector3 temp (grid[0][2],grid[1][2],grid[2][2]);

			return temp;
		
		}
		
		bool IsApproximatelyEqual(const Matrix3& op, float E = 1e-4) const {
			
			for (int i = 0; i < 9; i++) {
				if (arr[i] - op.arr[i] > E) {
					return false;
				}
			}

			return true;
		
		}

	};

}