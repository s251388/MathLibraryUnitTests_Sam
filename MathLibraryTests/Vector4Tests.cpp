
#include "CppUnitTest.h"
#include "TestToString.h"
//#include "Utils.h"
#include "Vector4.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ::MathLibrary;

namespace MathLibraryTests
{
	TEST_CLASS(Vector4Tests)
	{
	public:
	// Constructors
	TEST_METHOD(DefaultConstructor)
	{
		Vector4 vec;
		Assert::AreEqual(0.f, vec.x);
		Assert::AreEqual(0.f, vec.y);
		Assert::AreEqual(0.f, vec.z);
		Assert::AreEqual(0.f, vec.w);
	}
	TEST_METHOD(CopyConstructor)
	{
		Vector4 vec(13.f, 0.1f, 8.f,1.f);
		Vector4 copy = vec;
		Assert::AreEqual(vec,copy);
	}
	TEST_METHOD(ParameterisedConstructor)
	{
		Vector4 vec(1.f, 2.f, 3.f,1.f);
		Assert::AreEqual(1.f, vec.x);
		Assert::AreEqual(2.f, vec.y);
		Assert::AreEqual(3.f, vec.z);
		Assert::AreEqual(1.f, vec.w);
	}

	// Operators
	TEST_METHOD(Add)
	{
		for (float w = 0; w < 2; ++w) {
			Vector4 v3a(13.5f, -48.23f, 862.f, w);
			Vector4 v3b(5.f, 4.00f, -12.f, w);

			Assert::AreEqual(Approximate(v3a + v3b), Approximate(Vector4(18.5f, -44.23f, 850.f, w)));

			// Make sure + is const
			Assert::AreEqual(Vector4(13.5f, -48.23f, 862.f, w), v3a);
		}
	}

	TEST_METHOD(Subtract)
	{
		for (float w = 0; w < 2; ++w) {
			Vector4 v3a(13.5f, -48.23f, 862.f, w);
			Vector4 v3b(5.f, 3.99f, -12.f, w);
			Assert::AreEqual(Approximate(v3a - v3b), Approximate(Vector4(8.5f, -52.22f, 874.f, w)));

			//Make sure - is const
			Assert::AreEqual(Vector4(13.5f, -48.23f, 862.f, w), v3a);
		}
	}

	// Hadamard product
	TEST_METHOD(Multiply)
	{
		for (float w = 0; w < 2; ++w) {
			Vector4 v3a(13.5f, -48.23f, 862.f, w);
			Vector4 v3b(5.f, 4.00f, -12.f, w);

			Assert::AreEqual(Approximate(v3a * v3b), Approximate(Vector4(67.5f, -192.92f, -10344, w)));

			// Make sure + is const
			Assert::AreEqual(Vector4(13.5f, -48.23f, 862, w), v3a);
		}
	}

	TEST_METHOD(ScalarMultiply)
	{
		for (float w = 0; w < 2; ++w) {
			Vector4 v3a(13.5f, -48.23f, 862.f,w);
			Vector4 v3c = v3a * 0.256f;

			Assert::AreEqual(Approximate(v3c), Approximate(Vector4(3.45600008965f, -12.3468809128f, 220.672012329f,w)));

			//Make sure * is const
			Assert::AreEqual(Vector4(13.5f, -48.23f, 862.f,w), v3a);
		}
	}
	TEST_METHOD(ScalarDivide)
	{
		for (float w = 0; w < 2; ++w) {
			Vector4 v3a(13.5f, -48.23f, 862.f, w);
			Vector4 v3c = v3a / 3.0f;

			Assert::AreEqual(Approximate(v3c), Approximate(Vector4(4.5f, -16.076666f, 287.33334f, w)));

			//Make sure * is const
			Assert::AreEqual(Vector4(13.5f, -48.23f, 862.f, w), v3a);
		}
	}

	TEST_METHOD(Assignment)
	{
		Vector4 v4a(13.5f, -48.23f, 862,1.f);
		Vector4 v4c(5.f, 4.00f, -12,0.f);

		v4a = v4c;
		Assert::AreEqual(v4a, v4c);
	}

	TEST_METHOD(AddAssign)
	{
		//Test with w as 0 and 1
		for (float w = 0; w < 2; ++w) {
			Vector4 v3a(13.5f, -48.23f, 862.f, w);
			Vector4 v3b(5.f, 3.99f, -12.f, w);

			Assert::AreEqual(Approximate(Vector4(18.5f, -44.239998f, 850.f, w)),Approximate(v3a += v3b));
			Assert::AreEqual(Approximate(Vector4(18.5f, -44.239998f, 850.f, w)),Approximate(v3a));

			//Make sure += mutates
			Assert::AreNotEqual(Vector4(13.5f, -48.23f, 862.f, w), v3a);
		}
	}

	TEST_METHOD(SubtractAssign)
	{
		//Test with w as 0 and 1
        for (float w = 0; w < 2; ++w) {
            Vector4 v3a(13.5f, -48.23f, 862.f, w);
            Vector4 v3b(5.f, 3.99f, -12.f, w);

            Assert::AreEqual(Approximate(Vector4(8.5f, -52.22f, 874.f, w)), Approximate(v3a -= v3b));
            Assert::AreEqual(Approximate(Vector4(8.5f, -52.22f, 874.f, w)), Approximate(v3a));

            //Make sure -= mutates
            Assert::AreNotEqual(Vector4(13.5f, -48.23f, 862.f, w), v3a);
        }
	}

	TEST_METHOD(MultiplyAssign)
	{
		Vector4 v3a(13.5f, -48.23f, 862,1.0f);
		Vector4 v3b(5.f, 3.99f, -12.f,1.0f);

		Assert::AreEqual(Approximate(v3a *= v3b), Approximate(Vector4(67.5f, -192.437698f, -10344.f,1.0f)));
		Assert::AreEqual(Approximate(v3a), Approximate(Vector4(67.5f, -192.437698f, -10344.f, 1.0f)));

		//Make sure *= mutates
		Assert::AreNotEqual(Vector4(13.5f, -48.23f, 862,3.4f), v3a);
	}

	// TODO: implement tests for compound operators

	TEST_METHOD(ScalarMultiplyAssign)
	{
		Vector4 v3a(13.5f, -48.23f, 862.f, 3.4f);

		Assert::AreEqual(Approximate(v3a *= 0.256f), Approximate(Vector4(3.45600008965f, -12.3468809128f, 220.672012329f,3.4f)));

		//Make sure *= is mutating
		Assert::AreEqual(Approximate(v3a), Approximate(Vector4(3.45600008965f, -12.3468809128f, 220.672012329f, 3.4f)));
	}
	TEST_METHOD(ScalarDivideAssign)
	{
		Vector4 v3a(13.5f, -48.23f, 862.f,1.0f);

		Assert::AreEqual(Approximate(v3a /= 3.f), Approximate(Vector4(4.5f, -16.076666f, 287.33334f,1.0f)));

		//Make sure * is mutating
		Assert::IsTrue(v3a.IsApproximatelyEqual(Vector4(4.5f, -16.076666f, 287.33334, 1.0f)));
	}

	TEST_METHOD(Negative)
	{
		Vector4 v3a(13.5f, -48.23f, 862.f, 1.0f);

		Assert::IsTrue(-v3a == Vector4(-13.5f, 48.23f, -862.f, 1.0f));
	}

	TEST_METHOD(Equality)
	{
		Vector4 v3a(13.5f, -48.23f, 862.f,1.0f);
		Vector4 v3b(13.5f, -48.23f, 862.f,1.0f);

		Assert::IsTrue(v3a == v3b);
	}

	TEST_METHOD(Inequality)
	{
		Vector4 v3a(13.5f, -48.23f, 862.f,0.f);
		Vector4 v3b(0.0f, 0.0f, 0.0f,0.0f);

		Assert::IsTrue(!(v3a == v3b));
	}

	TEST_METHOD(LessThan)
	{
		Vector4 v3a(13.5f, -48.23f, 862.f,1.0f);
		Vector4 v3b(1.5f, 1.f, 1.f,1.0f);

		Assert::IsTrue(v3b < v3a);
	}

	TEST_METHOD(SubscriptReference) {
		const Vector4 v3a(13.5f, -48.23f, 862.f, 1.0f);

		Assert::AreEqual(v3a[0], 13.5f);
		Assert::AreEqual(v3a[1], -48.23f);
		Assert::AreEqual(v3a[2], 862.f);
		Assert::AreEqual(v3a[3], 1.0f);
	}

	TEST_METHOD(Subscript) {
		Vector4 v3a(0, 0, 0,0);
		v3a[0] = 3;
		Assert::AreEqual(v3a[0], 3.f);
		v3a[1] = 4;
		Assert::AreEqual(v3a[1], 4.f);
		v3a[2] = 6;
		Assert::AreEqual(v3a[2], 6.f);
		v3a[3] = 1;
		Assert::AreEqual(v3a[3], 1.f);

		Assert::AreEqual(v3a.x, 3.f, L"X not set");
		Assert::AreEqual(v3a.y, 4.f, L"Y not set");
		Assert::AreEqual(v3a.z, 6.f, L"Z not set");
		Assert::AreEqual(v3a.w, 1.f, L"W not set");
	}

	// Methods
	TEST_METHOD(Dot)
	{
		Vector4 v3a(13.5f, -48.23f, 862.f,0.f);
		Vector4 v3b(5.f, 3.99f, -12.f, 0.f);
		float dot3 = v3a.Dot(v3b);

		Assert::AreEqual(Approximate(-10468.9375f), Approximate(dot3));

		Vector4 v3c(0.f, 0.f, 0.f,0.f);
		Vector4 v3d(5.f, 3.99f, -12.f,0.f);
		dot3 = v3c.Dot(v3d);

		Assert::AreEqual(0.0f, dot3);
	}

	TEST_METHOD(Cross)
	{
		Vector4 v3a(13.5f, -48.23f, 862,0.f);
		Vector4 v3b(5, 3.99f, -12, 0.f);
		Vector4 v3c = v3a.Cross(v3b);

		Assert::AreEqual(Approximate(v3c), Approximate(Vector4(-2860.62011719f, 4472.00000000f, 295.01498413f, 0.f)));
	}

	TEST_METHOD(Magnitude)
	{
		Vector4 v3a(13.5f, -48.23f, 862,1.f);
		float mag3 = v3a.Magnitude();
		Assert::AreEqual(Approximate(863.453735352f), Approximate(mag3));

		Vector4 v3b(0.f, 0.f, 0.f,1.f);
		mag3 = v3b.Magnitude();
		Assert::AreEqual(0.f, mag3);
	}
	TEST_METHOD(Normalise)
	{
		Vector4 v3a(13.5f, -48.23f, 862.f,1.0f);
		v3a.Normalise();
		Assert::AreEqual(Approximate(v3a), Approximate(Vector4(0.0156349f, -0.0558571f, 0.998316f,1.0f)));

		Vector4 v3b(0.f, 0.f, 0.f,0.f);
		v3b.Normalise();
		Assert::AreEqual(Vector4(0.f, 0.f, 0.f,0.f), v3b);
	}

	TEST_METHOD(Normalised)
	{
		Vector4 v3a(13.5f, -48.23f, 862,1.f);
		Assert::AreEqual(Approximate(v3a.Normalised()), Approximate(Vector4(0.0156349f, -0.0558571f, 0.998316f, 1.f)));

		Vector4 v3b(0.f, 0.f, 0.f, 0.f);
		Assert::AreEqual(Vector4(0.f, 0.f, 0.f,0.f), v3b.Normalised());

		Vector4 v3c(0.f, 1.f, 0.f,1.f);
		Assert::AreEqual(Vector4(0.f, 1.f, 0.f,1.f), v3c.Normalised());
	}

	TEST_METHOD(IsApproximatelyEqual)
	{
		Vector4 v3a(13.500001f, -48.230001f, 862.f,1.0f);
		Vector4 v3b(13.5f, -48.23000f, 862.00001f, 1.0f);

		Assert::IsTrue(v3a.IsApproximatelyEqual(v3b));
	}

	TEST_METHOD(AngleBetween)
	{
		Vector4 v3a(1.f, 0.f, 0.f,1.f);
		Vector4 v3b(0.f, 0.f, 1.f,1.f);

        constexpr float Deg2Rad = 3.14159f / 180.f;

		Assert::AreEqual(Approximate(Deg2Rad * 90.f), Approximate(v3a.AngleBetween(v3b)));
		Assert::AreEqual(Approximate(Deg2Rad * 90.f), Approximate(v3b.AngleBetween(v3a)));

		Vector4 v3c(82.f, -9.f, 140.f,0.f);
		Vector4 v3d(-20.f, 0.f, 0.f,0.f);

		Assert::AreEqual(Approximate(2.09974647f), Approximate(v3c.AngleBetween(v3d)));
		Assert::AreEqual(Approximate(2.09974647f), Approximate(v3d.AngleBetween(v3c)));
	}

	////////////////////////////

	};
}
