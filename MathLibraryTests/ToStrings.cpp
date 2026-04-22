#include <cstdlib>
#include <string>

#include "CppUnitTestAssert.h"

#include "Vector3.h"
#include "Vector4.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include "Color.h"

namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework
		{
			using MathClasses::Vector3;
			using MathClasses::Vector4;
			using MathClasses::Matrix3;
			using MathClasses::Matrix4;
			using MathClasses::Color;

			template<typename T>
			std::wstring Stringify(const T& o, const int count) {
				std::wstring str = std::to_wstring(o[0]);
				for (size_t i = 1; i < count; ++i)
				{
					str += L", " + std::to_wstring(o[i]);
				}
				return str;
			}

			template<> inline std::wstring ToString<Vector3>(const Vector3& t)
			{
				return Stringify<Vector3>(t, 3);
			}

			template<> inline std::wstring ToString<Vector4>(const Vector4& t)
			{
				return Stringify<Vector4>(t, 4);
			}

			template<> inline std::wstring ToString<Matrix3>(const Matrix3& t)
			{
				return Stringify<Matrix3>(t, 9);
			}

			template<> inline std::wstring ToString<Matrix4>(const Matrix4& t)
			{
				return Stringify<Matrix4>(t, 16);
			}

			template<> inline std::wstring ToString<Color>(const Color& t)
			{
				return std::to_wstring(t.getRed()) + L"," + std::to_wstring(t.getGreen()) + L"," + std::to_wstring(t.getBlue()) + L"," + std::to_wstring(t.getAlpha());
			}
		}
	}
}