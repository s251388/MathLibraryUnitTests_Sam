#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

namespace MathLibrary {

	struct Vector3 {

		float x, y, z;


		Vector3() {

			x = 0;
			y = 0;
			z = 0;

		}

		Vector3(float XX, float YY, float ZZ) {

			x = XX;
			y = YY;
			z = ZZ;

		}

		Vector3(const Vector3& Copy) {

			x = Copy.x;
			y = Copy.y;
			z = Copy.z;

		}


		Vector3 operator+(const Vector3& op) {

			Vector3 temp;
			temp.x = x + op.x;
			temp.y = y + op.y;
			temp.z = z + op.z;

			return temp;
		}

		Vector3 operator-(const Vector3& op) {

			Vector3 temp;
			temp.x = x - op.x;
			temp.y = y - op.y;
			temp.z = z - op.z;

			return temp;
		}

		Vector3 operator*(const Vector3& op) {

			Vector3 temp;
			temp.x = x * op.x;
			temp.y = y * op.y;
			temp.z = z * op.z;

			return temp;
		}

		Vector3 operator*(const float& op) {

			Vector3 temp;
			temp.x = x * op;
			temp.y = y * op;
			temp.z = z * op;

			return temp;
		}

		Vector3 operator/(const float& op) {

			Vector3 temp;
			temp.x = x / op;
			temp.y = y / op;
			temp.z = z / op;

			return temp;
		}

		Vector3 operator=(const Vector3& op) {

			x = op.x;
			y = op.y;
			z = op.z;

			return *this;
		}

		Vector3 operator+=(const Vector3& op) {

			x += op.x;
			y += op.y;
			z += op.z;

			return *this;
		}

		Vector3 operator-=(const Vector3& op) {

			x -= op.x;
			y -= op.y;
			z -= op.z;

			return *this;
		}

		Vector3 operator*=(const Vector3& op) {

			x *= op.x;
			y *= op.y;
			z *= op.z;

			return *this;
		}

		Vector3 operator*=(const float& op) {

			x *= op;
			y *= op;
			z *= op;

			return *this;
		}

		Vector3 operator/=(const float& op) {

			x /= op;
			y /= op;
			z /= op;

			return *this;
		}

		Vector3 operator-() {

			x *= -1;
			y *= -1;
			z *= -1;

			return *this;
		}

		bool operator==(const Vector3& op) {
			return (x == op.x && y == op.y && z == op.z);
		}

		bool operator!=(const Vector3& op) {
			return (x != op.x || y != op.y || z != op.z);
		}

		bool operator<(const Vector3& op) {

			Vector3 temp1 = *this;
			temp1 *= temp1;
			float mag1 = (temp1.x + temp1.y + temp1.z);			// Gets the XYZ values squared and added. The two magnitudes don't need to be
																// square-rooted back down because they are BOTH squared, their relationship
			Vector3 temp2 = op;									// to eachother will be the same no matter what i multiply or divide them by.
			temp2 *= temp2;
			float mag2 = (temp2.x + temp2.y + temp2.z);

			return (mag1 < mag2);
		}

		float operator[](int i) const {

			switch (i) {
				case 0:
					return x;
				case 1:
					return y;
				case 2:
					return z;
			}

		}

		float& operator[](int i) {

			switch (i) {
				case 0:
					return x;
				case 1:
					return y;
				case 2:
					return z;
			}

		}


		float Dot(const Vector3& op) {

			return x*op.x + y*op.y + z*op.z;

		}

		Vector3 Cross(const Vector3& op) {

			return {y * op.z - z * op.y, z * op.x - x * op.z, x * op.y - y * op.x};

		}

		float Magnitude() {

			return sqrt(x * x + y * y + z * z);

		}

		void Normalise() {

			*this / Magnitude();

		}

		Vector3 Normalised() {				 
											// These don't need an input because unlike regular functions, as members of structs they technically 
			Vector3 temp = *this;			// always have the object they are from fed into/accessible from within the function by default.

			return temp / Magnitude();

		}

		bool IsApproximatelyEqual(const Vector3& op, float E = 1e-4) const {				
			
			Vector3 temp = *this;

			return (temp - op).Magnitude() < E;

		}															

		float AngleBetween(Vector3& op) {

			return acos(Normalised().Dot(op.Normalised()));

		}

		float Distance(const Vector3& op) {

			return (*this - op).Magnitude();

		}

		float Angle2D() {									
																	// Assessment had confusing wording for this part, said it wants the angle around
			float XYroot = sqrt(x * x + y * y);						// XY from 1,0 but early on it mentions that for 2D stuff x=forward and y=right.
																	// Also i had to include <math.h> to get proper PI here, hopefully that's allowed.
			return atan2(y / XYroot, x / XYroot) * (180 / M_PI);

		}

	};

}