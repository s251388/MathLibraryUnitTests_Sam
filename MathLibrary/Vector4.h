#pragma once

namespace MathLibrary {

	struct Vector4 {

		float x, y, z, w;


		Vector4() {

			x = 0;
			y = 0;
			z = 0;
			w = 0;

		}

		Vector4(float XX, float YY, float ZZ, float WW) {

			x = XX;
			y = YY;
			z = ZZ;
			w = WW;

		}

		Vector4(const Vector4& Copy) {

			x = Copy.x;
			y = Copy.y;
			z = Copy.z;
			w = Copy.w;

		}


		Vector4 operator+(const Vector4& op) {

			Vector4 temp;
			temp.x = x + op.x;
			temp.y = y + op.y;
			temp.z = z + op.z;
			temp.w = w + op.w;

			return temp;
		}

		Vector4 operator-(const Vector4& op) {

			Vector4 temp;
			temp.x = x - op.x;
			temp.y = y - op.y;
			temp.z = z - op.z;
			temp.w = w - op.w;

			return temp;
		}

		Vector4 operator*(const Vector4& op) {

			Vector4 temp;
			temp.x = x * op.x;
			temp.y = y * op.y;
			temp.z = z * op.z;
			temp.w = w * op.w;

			return temp;
		}

		Vector4 operator*(const float& op) {

			Vector4 temp;
			temp.x = x * op;
			temp.y = y * op;
			temp.z = z * op;
			temp.w = w * op;

			return temp;
		}

		Vector4 operator/(const float& op) {

			Vector4 temp;
			temp.x = x / op;
			temp.y = y / op;
			temp.z = z / op;
			temp.w = w / op;

			return temp;
		}

		Vector4 operator=(const Vector4& op) {

			x = op.x;
			y = op.y;
			z = op.z;
			w = op.w;

			return *this;
		}

		Vector4 operator+=(const Vector4& op) {

			x += op.x;
			y += op.y;
			z += op.z;
			w += op.w;

			return *this;
		}

		Vector4 operator-=(const Vector4& op) {

			x -= op.x;
			y -= op.y;
			z -= op.z;
			w -= op.w;

			return *this;
		}

		Vector4 operator*=(const Vector4& op) {

			x *= op.x;
			y *= op.y;
			z *= op.z;
			w *= op.w;

			return *this;
		}

		Vector4 operator*=(const float& op) {

			x *= op;
			y *= op;
			z *= op;
			w *= op;

			return *this;
		}

		Vector4 operator/=(const float& op) {

			x /= op;
			y /= op;
			z /= op;
			w /= op;

			return *this;
		}

		Vector4 operator-() {

			x *= -1;
			y *= -1;
			z *= -1;
			w *= -1;

			return *this;
		}

		bool operator==(const Vector4& op) {
			return (x == op.x && y == op.y && z == op.z && w == op.w);
		}

		bool operator!=(const Vector4& op) {
			return (x != op.x || y != op.y || z != op.z || w != op.w);
		}

		bool operator<(const Vector4& op) {

			Vector4 temp1 = *this;
			temp1 *= *this;
			float mag1 = (temp1.x + temp1.y + temp1.z + temp1.w);	// Gets the XYZW values squared and added. The two magnitudes don't need to be
			// square-rooted back down because they are BOTH squared, their relationship
			Vector4 temp2 = op;										// to eachother will be the same no matter what i multiply or divide them by.
			temp2 *= op;
			float mag2 = (temp2.x + temp2.y + temp2.z + temp2.w);

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
			case 3:
				return y;
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
			case 3:
				return y;
			}

		}


		float Dot(const Vector4& op) {

			return x*op.x + y*op.y + z*op.z;

		}

		Vector4 Cross(const Vector4& op) {

			return {y * op.z - z * op.y, z * op.x - x * op.z, x * op.y - y * op.x, w};

		}

		float Magnitude() {

			return sqrt(x * x + y * y + z * z);

		}

		void Normalise() {

			*this / Magnitude();

			return;

		}

		Vector4 Normalised() {				
			// These don't need an input because unlike regular functions, as members of structs they technically	
			Vector4 temp = *this;		// always have the object they are from fed into/accessible from within the function by default.

			return temp / Magnitude();

		}

		bool IsApproximatelyEqual(const Vector4& op, float E = 1e-4) {				
																	// By subtracting one from the other, if they are very similar the magnitude of
			return (*this - op).Magnitude() < E;					// the resulting vector3 should be close to 0. I worry about how this would work
																	// for vector4s as quaternions though, as any given rotation can be represented
		}															// by two different sets of values, like 1 0 0 0 and -1 0 0 0, for example.

		float AngleBetween(Vector4& op) {

			return acos(Normalised().Dot(op.Normalised()));

		}

		float Distance(const Vector4& op) {

			return (*this - op).Magnitude();

		}

	};

}