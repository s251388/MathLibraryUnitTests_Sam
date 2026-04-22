
#include "CppUnitTest.h"
#include "TestToString.h"

//#include "Utils.h"
#include "Vector3.h"

#include <type_traits>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ::MathLibrary;


namespace MathLibraryTests
{
	// A, B, C defines the points of a triangle in 3d space in counter-clockwise order
	// This function should calculate the normal vector of this triangle
	Vector3 CalculateTriangleNormal(const Vector3& A,const Vector3& B,const Vector3& C){
		return Vector3(0,0,0);
	}

	TEST_CLASS(Vector3Tests)
	{
	public:
		// Constructors
		TEST_METHOD(DefaultConstructor)
		{
			Vector3 vec;
			Assert::AreEqual(0.f, vec.x);
			Assert::AreEqual(0.f, vec.y);
			Assert::AreEqual(0.f, vec.z);
		}
		TEST_METHOD(CopyConstructor)
		{
			Vector3 vec(13.f,0.1f,8.f);
			Vector3 copy = vec;
			Assert::AreEqual(vec,copy);
		}
		TEST_METHOD(ParameterisedConstructor)
		{
			Vector3 vec(1.f,2.f,3.f);
			Assert::AreEqual(1.f, vec.x);
			Assert::AreEqual(2.f, vec.y);
			Assert::AreEqual(3.f, vec.z);
		}

		// Operators
		TEST_METHOD(Add)
		{
			Vector3 v3a(13.5f, -48.23f, 862);
			Vector3 v3b(5, 4.00f, -12);

			Assert::AreEqual(Approximate(Vector3(18.5f, -44.23f, 850)),  Approximate(v3a + v3b));

			// Make sure + is const
			Assert::AreEqual(Vector3(13.5f, -48.23f, 862), v3a);
		}

		TEST_METHOD(Subtract)
		{
			Vector3 v3a(13.5f, -48.23f, 862);
			Vector3 v3b(5, 3.99f, -12);
			Assert::AreEqual( Approximate(Vector3(8.5f, -52.22f, 874)) , Approximate(v3a - v3b));

			//Make sure - is const
			Assert::AreEqual( Vector3(13.5f, -48.23f, 862), v3a);
		}
		
		// Hadamard product
		TEST_METHOD(Multiply)
		{
			Vector3 v3a(13.5f, -48.23f, 862);
			Vector3 v3b(5, 4.00f, -12);

			Assert::AreEqual(Approximate(Vector3(67.5f, -192.92f, -10344)),Approximate(v3a * v3b));

			// Make sure + is const
			Assert::AreEqual(Vector3(13.5f, -48.23f, 862), v3a);
		}

		TEST_METHOD(ScalarMultiply)
		{
			Vector3 v3a(13.5f, -48.23f, 862);
			Vector3 v3c = v3a * 0.256f;

			Assert::AreEqual(Approximate(Vector3(3.45600008965f, -12.3468809128f, 220.672012329f)),Approximate(v3c));

			//Make sure * is const
			Assert::AreEqual(Vector3(13.5f, -48.23f, 862), v3a);
		}
		TEST_METHOD(ScalarDivide)
		{
			Vector3 v3a(13.5f, -48.23f, 862);
			Vector3 v3c = v3a / 3.0f;

			Assert::AreEqual(Approximate(Vector3(4.5f, -16.076666f, 287.33334f)), Approximate(v3c));

			//Make sure * is const
			Assert::AreEqual(Vector3(13.5f, -48.23f, 862), v3a);
		}

		TEST_METHOD(Assignment)
		{
			Vector3 v3a(13.5f, -48.23f, 862);
			Vector3 v3c(5, 4.00f, -12);
	
			v3a = v3c;
			Assert::AreEqual(v3a, v3c);
		}

		TEST_METHOD(AddAssign)
		{
			Vector3 v3a(13.5f, -48.23f, 862);
			Vector3 v3b(5, 3.99f, -12);

            Assert::AreEqual(Approximate(Vector3(18.5f, -44.239998f, 850)), Approximate(v3a += v3b));
            Assert::AreEqual(Approximate(Vector3(18.5f, -44.239998f, 850)), Approximate(v3a));
			
			//Make sure += mutates
			Assert::AreNotEqual(Vector3(13.5f, -48.23f, 862), v3a);
		}

		TEST_METHOD(SubtractAssign)
		{
			Vector3 v3a(13.5f, -48.23f, 862);
			Vector3 v3b(5, 3.99f, -12);
	
			Assert::AreEqual(Approximate(Vector3(8.5f, -52.22f, 874)) , Approximate(v3a-=v3b));

			//Make sure -= mutates
			Assert::AreEqual(Approximate(Vector3(8.5f, -52.22f, 874)), Approximate(v3a));
		}

		TEST_METHOD(MultiplyAssign)
		{
			Vector3 v3a(13.5f, -48.23f, 862);
			Vector3 v3b(5, 3.99f, -12);

			//Returns correct
			Assert::AreEqual(Approximate(Vector3(67.5f, -192.437698f, -10344)),Approximate(v3a *= v3b));

			//Mutates
			Assert::AreEqual(Approximate(Vector3(67.5f, -192.437698f, -10344)),Approximate(v3a));
		}

		// TODO: implement tests for compound operators

		TEST_METHOD(ScalarMultiplyAssign)
		{
			Vector3 v3a(13.5f, -48.23f, 862);
			Assert::AreEqual(Approximate(Vector3(3.45600008965f, -12.3468809128f, 220.672012329f)), Approximate(v3a *= 0.256f));

			//Make sure *= is mutating
			Assert::AreEqual(Approximate(Vector3(3.45600008965f, -12.3468809128f, 220.672012329f)), Approximate(v3a));
			Assert::AreNotEqual(Vector3(13.5f, -48.23f, 862), v3a);
		}
		TEST_METHOD(ScalarDivideAssign)
		{
			Vector3 v3a(13.5f, -48.23f, 862);
			Assert::AreEqual(Approximate(Vector3(4.5f, -16.076666f, 287.33334f)) ,Approximate(v3a /= 3.f));

			//Make sure * is mutating
			Assert::AreEqual(Approximate(Vector3(4.5f, -16.076666f, 287.33334f)) ,Approximate(v3a));
			Assert::AreNotEqual(Vector3(13.5f, -48.23f, 862), v3a);
		}

		TEST_METHOD(Negative)
		{
			Vector3 v3a(13.5f, -48.23f, 862);
			Assert::AreEqual(Approximate(Vector3(-13.5f, 48.23f, -862)),Approximate(-v3a));
			//Does not mutate
			Assert::AreEqual(Approximate(Vector3(13.5f, -48.23f, 862)), Approximate(v3a));
		}

		TEST_METHOD(Equality)
		{
			Vector3 v3a(13.5f, -48.23f, 862);
			Vector3 v3b(13.5f, -48.23f, 862);

			Assert::IsTrue(v3a == v3b);
			Assert::IsTrue(v3b == v3a);
		}

		TEST_METHOD(Inequality)
		{
			Vector3 v3a(13.5f, -48.23f, 862);
			Vector3 v3b(0.0f, 0.0f, 0.0f);

			Assert::IsTrue(!(v3a == v3b));
			Assert::IsTrue(!(v3b == v3a));
		}

		TEST_METHOD(LessThan)
		{
			Vector3 v3a(13.5f, -48.23f, 862);
			Vector3 v3b(1.5f,1.f, 1.f);

			Assert::IsTrue(v3b < v3a);
			Assert::IsFalse(v3a < v3b);

			Assert::IsFalse(Vector3(1, 1, 1) < Vector3(1, 1, 1));
		}

		TEST_METHOD(SubscriptReference) {
			const Vector3 v3a(13.5f, -48.23f, 862);

			Assert::AreEqual(v3a[0], 13.5f);
			Assert::AreEqual(v3a[1], -48.23f);
			Assert::AreEqual(v3a[2], 862.f);
		}
		TEST_METHOD(Subscript) {
			Vector3 v3a(0, 0, 0);
			v3a[0] = 3;
			Assert::AreEqual(v3a[0], 3.f);
			v3a[1] = 4;
			Assert::AreEqual(v3a[1], 4.f);
			v3a[2] = 6;
			Assert::AreEqual(v3a[2], 6.f);

			Assert::AreEqual(v3a.x, 3.f, L"X not set");
			Assert::AreEqual(v3a.y, 4.f, L"Y not set");
			Assert::AreEqual(v3a.z, 6.f, L"Z not set");
		}

		// Methods
		TEST_METHOD(Dot)
		{
			Vector3 v3a(13.5f, -48.23f, 862);
			Vector3 v3b(5, 3.99f, -12);
			float dot3 = v3a.Dot(v3b);

			Assert::AreEqual(Approximate(-10468.9375f), Approximate(dot3));

			Vector3 v3c(0, 0, 0);
			Vector3 v3d(5, 3.99f, -12);
			dot3 = v3c.Dot(v3d);

			Assert::AreEqual(0.0f, dot3);
		}

		TEST_METHOD(Cross)
		{
			Vector3 v3a(13.5f, -48.23f, 862);
			Vector3 v3b(5, 3.99f, -12);
			Vector3 v3c = v3a.Cross(v3b);

			Assert::AreEqual(Approximate(Vector3(-2860.62011719f, 4472.00000000f, 295.01498413f)),Approximate(v3c));
		}

		TEST_METHOD(Magnitude)
		{
			Vector3 v3a(13.5f, -48.23f, 862);
			float mag3 = v3a.Magnitude();
			Assert::AreEqual(Approximate(863.453735352f), Approximate(mag3));

			Vector3 v3b(0, 0, 0);
			mag3 = v3b.Magnitude();
			Assert::AreEqual(0.f, mag3);
		}
        TEST_METHOD(Normalise)
        {
            Vector3 v3a(13.5f, -48.23f, 862);
            v3a.Normalise();
            Assert::IsTrue(v3a.IsApproximatelyEqual(Vector3(0.0156349f, -0.0558571f, 0.998316f)));

            Vector3 v3b(0, 0, 0);
            v3b.Normalise();
            Assert::AreEqual(Vector3(0, 0, 0), v3b);
        }

        TEST_METHOD(Normalised)
        {
            Vector3 v3a(13.5f, -48.23f, 862);
			Assert::IsTrue(v3a.Normalised().IsApproximatelyEqual(Vector3(0.0156349f, -0.0558571f, 0.998316f)));

			Vector3 v3b(0, 0, 0);
			Assert::AreEqual(Vector3(0, 0, 0), v3b.Normalised());
		}
		
	/*	TEST_METHOD(IsApproximatelyEqual)
		{
			Vector3 v3a(13.500001f, -48.230001f, 862);
			Vector3 v3b(13.5f, -48.23000f, 862.00001);

			Assert::IsTrue(v3a.IsApproximatelyEqual(v3b));
		}*/

		TEST_METHOD(AngleBetween)
		{
			Vector3 v3a(1,0,0);
			Vector3 v3b(0, 0, 1);

            constexpr float Deg2Rad = 3.14159f / 180.f;

			Assert::AreEqual(Approximate(Deg2Rad * 90.f) , Approximate(v3a.AngleBetween(v3b)));
			Assert::AreEqual(Approximate(Deg2Rad * 90.f) , Approximate(v3b.AngleBetween(v3a)));
			
			Vector3 v3c(82,-9,140);
			Vector3 v3d(-20, 0, 0);

			Assert::AreEqual(Approximate(2.09974647f) , Approximate(v3c.AngleBetween(v3d)));
			Assert::AreEqual(Approximate(2.09974647f) , Approximate(v3d.AngleBetween(v3c)));
		}

		TEST_METHOD(Distance)
		{
			//6,13,18,23
			Vector3 v3a(-1.f, 10.f, 12.f);
			Vector3 v3b(5.f, -3.f, -6.f);

			Assert::AreEqual(Approximate(23.f), Approximate(v3a.Distance(v3b)));
		}

		TEST_METHOD(NormalofAPolygon){
			Vector3 A(0, 0, 1);
			Vector3 B(2, 1, 1);
			Vector3 C(1, 2, 2);
			Assert::AreEqual(Approximate(Vector3(0.26726124f, -0.53452248f, 0.80178373f)),Approximate(CalculateTriangleNormal(A, B, C)));
		}
		
	};
}
