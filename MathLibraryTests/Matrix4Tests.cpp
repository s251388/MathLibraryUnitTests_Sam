
#define _USE_MATH_DEFINES
#include <math.h>

#include "CppUnitTest.h"
#include "TestToString.h"

//#include "Utils.h"
#include "Matrix4.h"

#include <array>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using ::MathLibrary::Matrix4;




using Matrix4x4 = std::array<float, 16>;  // Column-major
using Vector4x = std::array<float, 4>;     // Homogeneous vector

// Access element at (row, col)
constexpr float get(const Matrix4x4& m, int row, int col) {
	return m[col * 4 + row];  // Column-major indexing
}

// Set element at (row, col)
constexpr void set(Matrix4x4& m, int row, int col, float value) {
	m[col * 4 + row] = value;
}

// Multiply two column-major 4x4 matrices
constexpr Matrix4x4 multiply(const Matrix4x4& A, const Matrix4x4& B) {
	Matrix4x4 result{};

	for (int row = 0; row < 4; ++row) {
		for (int col = 0; col < 4; ++col) {
			float sum = 0.0f;
			for (int k = 0; k < 4; ++k) {
				sum += get(A, row, k) * get(B, k, col);
			}
			set(result, row, col, sum);
		}
	}

	return result;
}

constexpr Vector4x multiply(const Matrix4x4& m, const Vector4x& v) {
	Vector4x result{};
	for (int row = 0; row < 4; ++row) {
		float sum = 0.0f;
		for (int k = 0; k < 4; ++k) {
			sum += get(m, row, k) * v[k];  // Multiply row of matrix by column vector
		}
		result[row] = sum;
	}
	return result;
}


namespace MathLibraryTests
{
	TEST_CLASS(Matrix4Tests)
	{
	public:
		// default constructor
		TEST_METHOD(Constructor)
		{
			Matrix4 mat;

			Assert::AreEqual(1.f, mat.m1);
			Assert::AreEqual(0.f, mat.m2);
			Assert::AreEqual(0.f, mat.m3);
			Assert::AreEqual(0.f, mat.m4);

			Assert::AreEqual(0.f, mat.m5);
			Assert::AreEqual(1.f, mat.m6);
			Assert::AreEqual(0.f, mat.m7);
			Assert::AreEqual(0.f, mat.m8);

			Assert::AreEqual(0.f, mat.m9);
			Assert::AreEqual(0.f, mat.m10);
			Assert::AreEqual(1.f, mat.m11);
			Assert::AreEqual(0.f, mat.m12);

			Assert::AreEqual(0.f, mat.m13);
			Assert::AreEqual(0.f, mat.m14);
			Assert::AreEqual(0.f, mat.m15);
			Assert::AreEqual(1.f, mat.m16);
		}
		// parameterized constructor (individual)
		TEST_METHOD(ConstructorParamFloats)
		{
			Matrix4 mat{
				1.f, 2.f, 3.f,4.f, 
				5.f, 6.f,7.f, 8.f, 
				9.f,10.f,11.f,12.f,
				13.f,14.f,15.f,16.f
			};

			Assert::AreEqual(1.f, mat.m1);
			Assert::AreEqual(2.f, mat.m2);
			Assert::AreEqual(3.f, mat.m3);
			Assert::AreEqual(4.f, mat.m4);
			Assert::AreEqual(5.f, mat.m5);
			Assert::AreEqual(6.f, mat.m6);
			Assert::AreEqual(7.f, mat.m7);
			Assert::AreEqual(8.f, mat.m8);
			Assert::AreEqual(9.f, mat.m9);
			Assert::AreEqual(10.f, mat.m10);
			Assert::AreEqual(11.f, mat.m11);
			Assert::AreEqual(12.f, mat.m12);
			Assert::AreEqual(13.f, mat.m13);
			Assert::AreEqual(14.f, mat.m14);
			Assert::AreEqual(15.f, mat.m15);
			Assert::AreEqual(16.f, mat.m16);
		}
		TEST_METHOD(CopyConstructor)
		{
			Matrix4 mat{
				1.f, 2.f, 3.f, 4.f,
				5.f, 6.f, 7.f, 8.f,
				9.f, 10.f, 11.f, 12.f,
				13.f, 14.f, 15.f, 16.f
			};

			Matrix4 other = mat;

			Assert::AreEqual(1.f, mat.m1);
			Assert::AreEqual(2.f, mat.m2);
			Assert::AreEqual(3.f, mat.m3);
			Assert::AreEqual(4.f, mat.m4);
			Assert::AreEqual(5.f, mat.m5);
			Assert::AreEqual(6.f, mat.m6);
			Assert::AreEqual(7.f, mat.m7);
			Assert::AreEqual(8.f, mat.m8);
			Assert::AreEqual(9.f, mat.m9);
			Assert::AreEqual(10.f, mat.m10);
			Assert::AreEqual(11.f, mat.m11);
			Assert::AreEqual(12.f, mat.m12);
			Assert::AreEqual(13.f, mat.m13);
			Assert::AreEqual(14.f, mat.m14);
			Assert::AreEqual(15.f, mat.m15);
			Assert::AreEqual(16.f, mat.m16);
		}

		// mat3 * vec
		TEST_METHOD(TransformVec3)
		{
			Matrix4 m3b{
				-0.188076824f, 0.f, 0.982154310f,0.f,
				0.f, 1.f, 0.f,0.f,
				-0.982154310f, 0.f, -0.188076824f,0.f,
				3.f,0.f,0.f,1.f
			};

            Vector4 v3a(13.5f, -48.23f, 862.f,1.f);

			Assert::AreEqual( Approximate( Vector4(-846.15607f, -48.23f, -148.863144f,1.0f) ) , Approximate(m3b*v3a));
		}
		// mat3 * mat3
		TEST_METHOD(Multiply)
		{
			Matrix4 m3a{
				1, 3, 1, 2,
				2, 2, 3, 1,
				3, 5, 1, 4,
				2, 2, 5, 8};

			Matrix4 m3c{
				4, 6, 4, 5,
				5, 6, 6, 4,
				5, 10, -9, -3,
				2, -12, -7, 3
			};

			constexpr auto mv = multiply(Matrix4x4{
				1, 3, 1, 2,
				2, 2, 3, 1,
				3, 5, 1, 4,
				2, 2, 5, 8
				}, Matrix4x4{
							4, 6, 4, 5,
							5, 6, 6, 4,
							5, 10, -9, -3,
							2, -12, -7, 3
				});

			//Returned value is correct
			Assert::AreEqual(Approximate(Matrix4{ 38, 54,51,70,43,65,49,72,-8,-16,11,-40,-37,-47,-26,-12 }), Approximate(m3a * m3c));

			//Original is unchanged
			Assert::AreEqual(Matrix4{1, 3, 1, 2,
				2, 2, 3, 1,
				3, 5, 1, 4,
				2, 2, 5, 8}, m3a);
		}
		TEST_METHOD(MultiplyAssignment)
		{
			Matrix4 m3a{
				1, 3, 1, 2,
				2, 2, 3, 1,
				3, 5, 1, 4,
				2, 2, 5, 8};

			Matrix4 m3c{
				4, 6, 4, 5,
				5, 6, 6, 4,
				5, 10, -9, -3,
				2, -12, -7, 3
			};

			//*= returns new value
			Assert::AreEqual(Matrix4{ 38, 54,51,70,43,65,49,72,-8,-16,11,-40,-37,-47,-26,-12 } , m3a *= m3c);

			//original has changed
			Assert::AreNotEqual(Matrix4{
				1, 3, 1, 2,
				2, 2, 3, 1,
				3, 5, 1, 4,
				2, 2, 5, 8} , m3a);
		}

		TEST_METHOD(Equality)
		{
			Matrix4 m3a{38, 54, 51, 70, 43, 65, 49, 72, -8, -16, 11, -40, -37, -47, -26, -12};
			Matrix4 m3b{38, 54, 51, 70, 43, 65, 49, 72, -8, -16, 11, -40, -37, -47, -26, -12};


			//*= returns new value
			Assert::AreEqual(m3a,m3b);

			//original has changed
			Assert::AreNotEqual(Matrix4{1, 3, 1, 2,
				2, 2, 3, 1,
				3, 5, 1, 4,
				2, 2, 5, 8}, m3a);
		}


		TEST_METHOD(Subscript) {
			Matrix4 m3a{
				1, 3, 1, 2,
				2, 2, 3, 1,
				3, 5, 1, 4,
				2, 2, 5, 8
			};

			Assert::AreEqual(m3a[0], 1.f);
			Assert::AreEqual(m3a[1], 3.f);
			Assert::AreEqual(m3a[2], 1.f);
			Assert::AreEqual(m3a[3], 2.f);

			Assert::AreEqual(m3a[4], 2.f);
			Assert::AreEqual(m3a[5], 2.f);
			Assert::AreEqual(m3a[6], 3.f);
			Assert::AreEqual(m3a[7], 1.f);

			Assert::AreEqual(m3a[8], 3.f);
			Assert::AreEqual(m3a[9], 5.f);
			Assert::AreEqual(m3a[10], 1.f);
			Assert::AreEqual(m3a[11], 4.f);

			Assert::AreEqual(m3a[12], 2.f);
			Assert::AreEqual(m3a[13], 2.f);
			Assert::AreEqual(m3a[14], 5.f);
			Assert::AreEqual(m3a[15], 8.f);
		}

		TEST_METHOD(SubscriptReference) {
			Matrix4 m3a; //Identity

			m3a[0] = 1.f;
			m3a[1] = 4.f;
			m3a[2] = 1.f;
			m3a[3] = 2.f;
			m3a[4] = 3.f;
			m3a[5] = 2.f;
			m3a[6] = 3.f;
			m3a[7] = 2.f;
			m3a[8] = 0.f;
			m3a[9] = 3.f;
			m3a[10] = 2.f;
			m3a[11] = 0.f;
			m3a[12] = 1.f;
			m3a[13] = 3.f;
			m3a[14] = 2.f;
			m3a[15] = 3.f;

			Assert::AreEqual(
				Matrix4{
					1.f, 4.f, 1.f, 2.f,
					3.f, 2.f, 3.f, 2.f,
					0.f, 3.f, 2.f, 0.f,
					1.f, 3.f, 2.f, 3.f
				}
				, m3a);

			Assert::IsTrue(
				m3a.m1 == 1.f && m3a.m2 == 4.f && m3a.m3 == 1.f && m3a.m4 == 2.f &&
				m3a.m5 == 3.f && m3a.m6 == 2.f && m3a.m7 == 3.f && m3a.m8 == 2.f && 
				m3a.m9 == 0.f && m3a.m10 == 3.f && m3a.m11 == 2.f && m3a.m12 == 0.f &&
				m3a.m13 == 1.f && m3a.m14 == 3.f && m3a.m15 == 2.f && m3a.m16 == 3.f
			);
		}

		TEST_METHOD(MakeRotateX)
		{
			Matrix4 actual = Matrix4::MakeRotateX(3.98f);

			Assert::AreEqual(
				Approximate(
					Matrix4{
						1, 0, 0, 0,
						0, -0.668648f, 0.743579f, 0,
						0, -0.743579f, -0.668648f, 0,
						0, 0, 0, 1}
				), Approximate(actual) );
		}
		// make rotY from float
		TEST_METHOD(MakeRotateY)
		{
			Matrix4 actual = Matrix4::MakeRotateY(1.76f);

            Assert::AreEqual(
                Approximate(Matrix4{
                    -0.188077f, 0, 0.982154f, 0,
                    0, 1, 0, 0,
                    -0.982154f, 0, -0.188077f, 0,
                    0, 0, 0, 1}
                ),
                Approximate(actual));
		}
		// make rotZ from float
		TEST_METHOD(MakeRotateZ)
		{
			Matrix4 actual = Matrix4::MakeRotateZ(9.62f);

			Assert::AreEqual(
				Approximate(Matrix4{
					-0.981005f, -0.193984f, 0,0,
					0.193984f, -0.981005f, 0,0,
					0, 0, 1,0,
					0,0,0,1}),
				Approximate(actual));
		}
		// make scale from float
		TEST_METHOD(MakeScale)
		{
			Matrix4 actual = Matrix4::MakeScale(2.0f,2.0f,2.0f);

			Assert::AreEqual(
				Matrix4{
					2.f, 0, 0,0,
					0, 2.f, 0,0,
					0, 0, 2.f,0,
					0,0,0,1.f},
				actual);
		}

		TEST_METHOD(MakeTranslation)
		{
			Matrix4 actual = Matrix4::MakeTranslation(2.0f, 3.0f, 4.0f);

			Assert::AreEqual(
				Matrix4{1, 0, 0, 0,
					0, 1, 0, 0,
					0, 0, 1, 0,
					2.f, 3.f, 4.f, 1}, actual);
		}

		TEST_METHOD(GetForward)
		{
			Matrix4 actual = Matrix4::MakeRotateX(3.98f);
			Assert::AreEqual(Approximate(Vector4(0, -0.743579f, -0.668648f, 0)), Approximate(actual.GetForward()));
		}
		TEST_METHOD(GetRight)
		{
			Matrix4 actual = Matrix4::MakeRotateY(1.76f);
			Assert::AreEqual(Approximate(Vector4(-0.188077f, 0, 0.982154f, 0)), Approximate(actual.GetRight()));
		}
		TEST_METHOD(GetUp)
		{
			Matrix4 actual = Matrix4::MakeRotateZ(9.62f);
			Assert::AreEqual(Approximate(Vector4(0.193984f, -0.981005f, 0, 0)), Approximate(actual.GetUp()));
		}

		TEST_METHOD(IsApproximatelyEqual)
		{
			Matrix4 actual{1.00001f, 2.00001f, 3.00001f, 4.00001f, 5.00001f, 6.00001f, 7.00001f, 8.00001f, 9.00001f,10.00001f,11.000f,12.000f,13.000f,14.000f,15.000f,16.000f};
			Assert::IsTrue(actual.IsApproximatelyEqual(Matrix4{1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f,10.f,11.f,12.f,13.f,14.f,15.f,16.f}));
		}
	};
}