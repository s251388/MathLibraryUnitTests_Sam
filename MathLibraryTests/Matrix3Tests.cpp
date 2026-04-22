
#define _USE_MATH_DEFINES
#include <math.h>

#include "CppUnitTest.h"
#include "TestToString.h"

#include "Matrix3.h"
#include "Vector3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ::MathLibrary;

namespace MathLibraryTests
{
	TEST_CLASS(Matrix3Tests)
	{
	public:
		// default constructor
		TEST_METHOD(Constructor)
		{
			Matrix3 mat;

			Assert::AreEqual(1.f, mat.m1);
			Assert::AreEqual(0.f, mat.m2);
			Assert::AreEqual(0.f, mat.m3);

			Assert::AreEqual(0.f, mat.m4);
			Assert::AreEqual(1.f, mat.m5);
			Assert::AreEqual(0.f, mat.m6);

			Assert::AreEqual(0.f, mat.m7);
			Assert::AreEqual(0.f, mat.m8);
			Assert::AreEqual(1.f, mat.m9);
		}
		// parameterized constructor (individual)
		TEST_METHOD(ConstructorParamFloats)
		{
			Matrix3 mat {1.f,2.f,3.f,
				4.f,5.f,6.f,
				7.f,8.f,9.f};

			Assert::AreEqual(1.f, mat.m1);
			Assert::AreEqual(2.f, mat.m2);
			Assert::AreEqual(3.f, mat.m3);
			Assert::AreEqual(4.f, mat.m4);
			Assert::AreEqual(5.f, mat.m5);
			Assert::AreEqual(6.f, mat.m6);
			Assert::AreEqual(7.f, mat.m7);
			Assert::AreEqual(8.f, mat.m8);
			Assert::AreEqual(9.f, mat.m9);
		}
		TEST_METHOD(CopyConstructor)
		{
			Matrix3 mat {1.f, 2.f, 3.f,
				4.f, 5.f, 6.f,
				7.f, 8.f, 9.f};

			Matrix3 other = mat;

			Assert::AreEqual(1.f, other.m1);
			Assert::AreEqual(2.f, other.m2);
			Assert::AreEqual(3.f, other.m3);
			Assert::AreEqual(4.f, other.m4);
			Assert::AreEqual(5.f, other.m5);
			Assert::AreEqual(6.f, other.m6);
			Assert::AreEqual(7.f, other.m7);
			Assert::AreEqual(8.f, other.m8);
			Assert::AreEqual(9.f, other.m9);
		}

		// mat3 * vec
		TEST_METHOD(Assignment)
		{
			const Matrix3 m3a {-0.188076824f, 0.f, 0.982154310f,
				0.f, 1.f, 0.f,
				-0.982154310f, 0.f, -0.188076824f};

			Matrix3 m3b;

			m3b = m3a;

			Assert::AreEqual(m3a,m3b);

			//Ensure m3a isn't changed
			Assert::AreEqual(Matrix3{-0.188076824f, 0.f, 0.982154310f, 0.f, 1.f, 0.f, -0.982154310f, 0.f, -0.188076824f}, m3a);
		}
		
		// mat3 * vec
		TEST_METHOD(TransformVec3)
		{
			const Matrix3 m3b{-0.188076824f, 0.f, 0.982154310f,
				0.f, 1.f, 0.f,
				-0.982154310f, 0.f, -0.188076824f};

			const Vector3 v3a(13.5f, -48.23f, 862);
			const Vector3 v3b = m3b * v3a;

			Assert::AreEqual(Approximate(v3b),Approximate(Vector3(-849.156067f, -48.23f, -148.863144f)));
		}
		// mat3 * mat3
		TEST_METHOD(Multiply)
		{
			const Matrix3 m3a{1, 3, 1, 2, 2, 2, 3, 1, 3};
			const Matrix3 m3c{4, 6, 4, 5, 5, 6, 6, 4, 5};

			//Returned value is correct
			Assert::AreEqual(Approximate(Matrix3{28, 28, 28, 33, 31, 33, 29, 31, 29}), Approximate(m3a * m3c));
			
			//Original is unchanged
			Assert::AreEqual(Matrix3{1, 3, 1, 2, 2, 2, 3, 1, 3}, m3a);
		}
		TEST_METHOD(MultiplyAssignment)
		{
			Matrix3 m3a{1, 3, 1, 2, 2, 2, 3, 1, 3};
			const Matrix3 m3c{4, 6, 4, 5, 5, 6, 6, 4, 5};

			//*= returns new value
			Assert::AreEqual(Matrix3{28, 28, 28, 33, 31, 33, 29, 31, 29}, m3a *= m3c);

			//original has changed
			Assert::AreNotEqual(Matrix3{1, 3, 1, 2, 2, 2, 3, 1, 3}, m3a);
		}
		TEST_METHOD(Equality)
		{
			const Matrix3 m3a{1, 3, 1, 2, 2, 2, 3, 1, 3};
			const Matrix3 m3c{1, 3, 1, 2, 2, 2, 3, 1, 3};

			//*= returns new value
			Assert::IsTrue(m3a==m3c);
		}

		
		TEST_METHOD(Subscript) {
			Matrix3 m3a{1, 4, 1, 
						2, 3, 2, 
						3, 2, 3};

			Assert::AreEqual(m3a[0], 1.f);
			Assert::AreEqual(m3a[1], 4.f);
			Assert::AreEqual(m3a[2], 1.f);
				
			Assert::AreEqual(m3a[3], 2.f);
			Assert::AreEqual(m3a[4], 3.f);
			Assert::AreEqual(m3a[5], 2.f);
				
			Assert::AreEqual(m3a[6], 3.f);
			Assert::AreEqual(m3a[7], 2.f);
			Assert::AreEqual(m3a[8], 3.f);
		}
		
		TEST_METHOD(SubscriptReference) {
			Matrix3 m3a; //Identity

			m3a[0]= 1.f;
			m3a[1]= 4.f;
			m3a[2]= 1.f;

			m3a[3]= 2.f;
			m3a[4]= 3.f;
			m3a[5]= 2.f;

			m3a[6]= 3.f;
			m3a[7]= 2.f;
            m3a[8]= 3.f;

			Assert::AreEqual(Matrix3{1.f, 4.f, 1.f, 2.f, 3.f, 2.f, 3.f, 2.f, 3.f},m3a);

			Assert::IsTrue(
				m3a.m1 == 1.f && m3a.m2 == 4.f && m3a.m3 == 1.f &&
				m3a.m4 == 2.f && m3a.m5 == 3.f && m3a.m6 == 2.f &&
				m3a.m7 == 3.f && m3a.m8 == 2.f && m3a.m9 == 3.f
			);
        }

		TEST_METHOD(MakeRotate)
		{
			Matrix3 actual = Matrix3::MakeRotate(3.98f);
			constexpr auto s = 3.98f;
			auto x = cos(s) - sin(s);

			Assert::AreEqual(
				Approximate(Matrix3{
					-0.668648f, -0.743579f,0,
					 0.743579f, -0.668648f,0,
					0,0,1}),
				Approximate(actual));
		}
		
		// make scale from float
		TEST_METHOD(MakeScale)
		{
			Matrix3 actual = Matrix3::MakeScale(2.0f,2.0f);

			Assert::AreEqual(
				Matrix3{
					2.f, 0  , 0,
					0  , 2.f, 0,
					0  , 0  , 1.f},
				actual);
		}

        TEST_METHOD(GetForward)
        {
            Matrix3 actual = Matrix3::MakeRotate(9.62f);
            Assert::AreEqual(Approximate(Vector3(-0.981005f,-0.193984f, 0)), Approximate(actual.GetForward()));
        }
        TEST_METHOD(GetRight)
        {
            Matrix3 actual = Matrix3::MakeRotate(9.62f);
            Assert::AreEqual(Approximate(Vector3(0.193984f,-0.981005f, 0)), Approximate(actual.GetRight()));
        }

		/*TEST_METHOD(IsApproximatelyEqual)
		{
			Matrix3 actual {1.0001f, 2.0001f, 3.0001f, 4.0001f, 5.0001f, 6.0001f, 7.0001f, 8.0001f, 9.0001f};
			Assert::IsTrue(actual.IsApproximatelyEqual(Matrix3{1.0001f, 2.0001f, 3.0001f, 4.0001f, 5.0001f, 6.0001f, 7.0001f, 8.0001f, 9.0001f}));
		}*/
	};
}