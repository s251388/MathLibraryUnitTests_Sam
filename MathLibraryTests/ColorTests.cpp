#include "CppUnitTest.h"
#include "TestToString.h"

//#include "Utils.h"
#include "Color.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using ::MathLibrary::Color;

namespace MathLibraryTests
{
	TEST_CLASS(ColorTests)
	{
	public:
		// default constructor
		TEST_METHOD(ColorDefaultConstructor)
		{
			Color actual;
			Assert::AreEqual(255u,actual.rgba);
		}
		// copy constructor
		TEST_METHOD(ColorCopyConstructor)
		{
			Color actual(32,128,16,255);
			Color copy = actual;
			Assert::AreEqual(actual.rgba,copy.rgba);
		}

		// parameterized constructor
		TEST_METHOD(ColorParamConstructor)
		{
			{
				Color actual(32, 64, 0, 255);
				Assert::AreEqual(541065471u , actual.rgba, L"Constructor (32,64,0,255)");
			}
			{
				Color actual(0, 0, 0, 0);
				Assert::AreEqual(0u, actual.rgba, L"Constructor (0,0,0,0)");
			}
			{
				Color actual(255, 255, 255, 255);
				Assert::AreEqual(4294967295u, actual.rgba, L"Constructor (255,255,255,255) Failed");
			}
		}

		// equality
		TEST_METHOD(ColorEqualityOperator)
		{
			Color actual(32, 64, 0, 255);
			Color duplicate(32, 64, 0, 255);
			Assert::IsTrue(actual == duplicate);

			actual.SetBlue(192);
			duplicate.SetGreen(255);
			Assert::IsFalse(actual == duplicate);
		}

		// setting r
		TEST_METHOD(SetRed)
		{
			Color actual(32, 64, 0, 255);
			actual.SetRed(128);
			Assert::AreEqual(2151678207u, actual.rgba);
		}
		
		// setting g
		TEST_METHOD(SetGreen)
		{
			Color actual(32, 64, 0, 255);
			actual.SetGreen(128);
			Assert::AreEqual(545259775u, actual.rgba);
		}

		// setting b
		TEST_METHOD(SetBlue)
		{
			Color actual(32, 64, 0, 255);
			actual.SetBlue(128);
			Assert::AreEqual(541098239u, actual.rgba);
		}

		// setting a
		TEST_METHOD(SetAlpha)
		{
			Color actual(32, 64, 0, 255);
			actual.SetAlpha(128);
			Assert::AreEqual(541065344u, actual.rgba);
		}

		TEST_METHOD(GetRed)
		{
			Color actual(92, 164, 10, 25);
			const auto r = actual.GetRed();
			Assert::AreEqual((unsigned char)92, r);
		}

		// setting g
		TEST_METHOD(GetGreen)
		{
			Color actual(92, 164, 10, 25);
			const auto g = actual.GetGreen();
			Assert::AreEqual((unsigned char)164, g);
		}

		// setting b
		TEST_METHOD(GetBlue)
		{
			Color actual(92, 164, 10, 25);
			const auto b = actual.GetBlue();
			Assert::AreEqual((unsigned char)10, b);
		}

		// setting a
		TEST_METHOD(GetAlpha)
		{
			Color actual(92, 164, 10, 25);
			const auto a = actual.GetAlpha();
			Assert::AreEqual((unsigned char)25, a);
		}
	};
}
