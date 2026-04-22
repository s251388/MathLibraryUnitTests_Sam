#pragma once

#include <cstdlib>
#include <string>

#include "CppUnitTestAssert.h"

#include "TestUtilities.h"

#include <Vector3.h>
#include <Vector4.h>
#include <Matrix3.h>
#include <Matrix4.h>
#include <Color.h>

namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework
		{
			using MathLibrary::Approximate;
			using MathLibrary::Vector3;
			using MathLibrary::Vector4;
			using MathLibrary::Matrix3;
			using MathLibrary::Matrix4;
			using MathLibrary::Color;

			template<typename T>
			std::wstring Stringify(const T& o, const int count) {
				std::wstring str = L"\n" + std::to_wstring(o[0])+L", ";
				for (int i = 1; i < count; ++i)
				{
					str += std::to_wstring(o[i]);
					if(i!=count-1) str+=L", ";
					if (count>4 && ((i+1) % (int)sqrt(count)) == 0) str += L"\n";
				}
				return str + L"\n";
			}

			template<> inline std::wstring ToString(const Approximate<typename Matrix3>& t)
			{
				return Stringify<Approximate<typename Matrix3>>(t, 9);
			}

			template<> inline std::wstring ToString(const Approximate<typename Matrix4>& t)
			{
				return Stringify<Approximate<typename Matrix4>>(t, 16);
			}

			template<> inline std::wstring ToString(const Approximate<typename Vector3>& t)
			{
				return Stringify<Approximate<typename Vector3>>(t, 3);
			}

			template<> inline std::wstring ToString(const Approximate<typename Vector4>& t)
			{
				return Stringify<Approximate<typename Vector4>>(t, 4);
			}

			template<> inline std::wstring ToString(const Approximate<typename float>& t)
			{
				return ToString(t.ref);
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
				return std::to_wstring(t.GetRed()) + L"," + std::to_wstring(t.GetGreen()) + L"," + std::to_wstring(t.GetBlue()) + L"," + std::to_wstring(t.GetAlpha());
			}
		}
	}
}