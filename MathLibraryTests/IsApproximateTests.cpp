#include <cmath>

#include "CppUnitTest.h"
#include "TestToString.h"

//#include "Utils.h"
#include "Color.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix3.h"
#include "Matrix4.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ::MathLibrary;

namespace MathLibraryTests
{
    TEST_CLASS(IsApproximateMustPass)
    {
    public:
        TEST_METHOD(ExactMatch) {
            const Vector3 v3(1.f, 1.f, 1.f);
            const Vector4 v4(1.f, 1.f, 1.f, 1.f);
            const Matrix3 m3{
                1.f, 2.f, 3.f, 4.f,
                5.f, 6.f, 7.f, 8.f,
                9.f};
            const Matrix4 m4{
                1.f, 2.f, 3.f, 4.f,
                5.f, 6.f, 7.f, 8.f,
                9.f, 10.f, 11.f, 12.f,
                13.f, 14.f, 15.f, 16.f};

            Assert::IsTrue(v3.IsApproximatelyEqual(v3));
            Assert::IsTrue(v4.IsApproximatelyEqual(v4));
            Assert::IsTrue(m3.IsApproximatelyEqual(m3));
            Assert::IsTrue(m4.IsApproximatelyEqual(m4));
        }

        TEST_METHOD(WithinTolerance) {
            constexpr float s = 0.00001f;
            const Vector3 v3(1.f, 1.f, 1.f);
            const Vector4 v4(1.f, 1.f, 1.f, 1.f);
            const Matrix3 m3{
                1.f, 2.f, 3.f, 4.f,
                5.f, 6.f, 7.f, 8.f,
                9.f};
            const Matrix4 m4{
                1.f, 2.f, 3.f, 4.f,
                5.f, 6.f, 7.f, 8.f,
                9.f, 10.f, 11.f, 12.f,
                13.f, 14.f, 15.f, 16.f};

            Assert::IsTrue(v3.IsApproximatelyEqual(Vector3(1.f+s,1.f+s,1.f+s)));
            Assert::IsTrue(v4.IsApproximatelyEqual(Vector4(1.f+s,1.f+s,1.f+s,1.f+s)));
            Assert::IsTrue(m3.IsApproximatelyEqual(Matrix3{
                1.f + s, 2.f + s, 3.f + s, 
                4.f + s, 5.f + s, 6.f + s, 
                7.f + s, 8.f + s, 9.f + s}
            ));

            Assert::IsTrue(m4.IsApproximatelyEqual(Matrix4{
                1.f + s, 2.f + s, 3.f + s, 4.f + s, 
                5.f + s, 6.f + s, 7.f + s, 8.f + s, 
                9.f + s, 10.f+s,11.f+s,12.f+s,
                13.f+s,14.f+s,15.f+s,16.f+s}
            ));
        }

        TEST_METHOD(OutsideTolerance) {
            constexpr float s = 0.1f;
            const Vector3 v3(1.f, 1.f, 1.f);
            const Vector4 v4(1.f, 1.f, 1.f, 1.f);
            const Matrix3 m3{
                1.f, 2.f, 3.f, 4.f,
                5.f, 6.f, 7.f, 8.f,
                9.f};
            const Matrix4 m4{
                1.f, 2.f, 3.f, 4.f,
                5.f, 6.f, 7.f, 8.f,
                9.f, 10.f, 11.f, 12.f,
                13.f, 14.f, 15.f, 16.f};

            Assert::IsFalse(v3.IsApproximatelyEqual(Vector3(1.f + s, 1.f + s, 1.f + s)));
            Assert::IsFalse(v4.IsApproximatelyEqual(Vector4(1.f + s, 1.f + s, 1.f + s, 1.f + s)));
            Assert::IsFalse(m3.IsApproximatelyEqual(Matrix3{
                1.f + s, 2.f + s, 3.f + s,
                4.f + s, 5.f + s, 6.f + s,
                7.f + s, 8.f + s, 9.f + s}
            ));
            Assert::IsFalse(m4.IsApproximatelyEqual(Matrix4{
                1.f + s, 2.f + s, 3.f + s, 4.f + s,
                5.f + s, 6.f + s, 7.f + s, 8.f + s,
                9.f + s, 10.f + s, 11.f + s, 12.f + s,
                13.f + s, 14.f + s, 15.f + s, 16.f + s}
            ));
        }

        TEST_METHOD(Symmetric) {
            constexpr float s = 0.00001f;
            const Vector3 v3(1.f, 1.f, 1.f);
            const Vector4 v4(1.f, 1.f, 1.f, 1.f);
            const Matrix3 m3{
                1.f, 2.f, 3.f, 4.f,
                5.f, 6.f, 7.f, 8.f,
                9.f};
            const Matrix4 m4{
                1.f, 2.f, 3.f, 4.f,
                5.f, 6.f, 7.f, 8.f,
                9.f, 10.f, 11.f, 12.f,
                13.f, 14.f, 15.f, 16.f};

            Assert::IsTrue(Vector3(1.f + s, 1.f + s, 1.f + s).IsApproximatelyEqual(v3));
            Assert::IsTrue(Vector4(1.f + s, 1.f + s, 1.f + s, 1.f + s).IsApproximatelyEqual(v4));
            Assert::IsTrue(Matrix3{
                1.f + s, 2.f + s, 3.f + s,
                4.f + s, 5.f + s, 6.f + s,
                7.f + s, 8.f + s, 9.f + s}.IsApproximatelyEqual(m3)
            );

            Assert::IsTrue(Matrix4{
                1.f + s, 2.f + s, 3.f + s, 4.f + s,
                5.f + s, 6.f + s, 7.f + s, 8.f + s,
                9.f + s, 10.f + s, 11.f + s, 12.f + s,
                13.f + s, 14.f + s, 15.f + s, 16.f + s}.IsApproximatelyEqual(m4)
            );
        }

        TEST_METHOD(NaNHandling) {
            const Vector3 v3(1.f, 1.f, 1.f);
            const Vector4 v4(1.f, 1.f, 1.f, 1.f);
            const Matrix3 m3{
                1.f, 2.f, 3.f, 4.f,
                5.f, 6.f, 7.f, 8.f,
                9.f};
            const Matrix4 m4{
                1.f, 2.f, 3.f, 4.f,
                5.f, 6.f, 7.f, 8.f,
                9.f, 10.f, 11.f, 12.f,
                13.f, 14.f, 15.f, 16.f};

            Assert::IsFalse(v3.IsApproximatelyEqual(Vector3(NAN, NAN, NAN)));
            Assert::IsFalse(v4.IsApproximatelyEqual(Vector4(NAN, NAN, NAN, NAN)));
            Assert::IsFalse(m3.IsApproximatelyEqual(
                Matrix3{
                    NULL, NULL, NULL,
                    NULL, NULL, NULL,
                    NULL, NULL, NULL
                }
            ));
            Assert::IsFalse(m4.IsApproximatelyEqual(
                Matrix4{
                    NULL, NULL, NULL, NULL,
                    NULL, NULL, NULL, NULL,
                    NULL, NULL, NULL, NULL,
                    NULL, NULL, NULL, NULL
                })
            );
        }
    };
}