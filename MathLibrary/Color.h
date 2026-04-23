#pragma once

namespace MathLibrary
{

	struct Color {

		unsigned int rgba;
		

		Color() {
		
			rgba = 0;
		
		}
		
		Color(unsigned char RR, unsigned char GG, unsigned char BB, unsigned char AA) {
		
			rgba = RR << 24 | GG << 16 | BB << 8 | AA;
		
		}
		
		Color(const Color& Copy) {
		
		rgba = Copy.rgba;

		}
		

		bool operator==(const Color& op) const {

			return rgba == op.rgba;

		}

		
		unsigned char GetRed() const {

			return (unsigned char)rgba >> 24;

		}

		void SetRed(unsigned char red) {

			rgba &= 0x00FFFFFF;
			rgba |= red << 24;

		}   

		unsigned char GetGreen() const {

			return (unsigned char)rgba >> 16;

		}

		void SetGreen (unsigned char green) {

			rgba &= 0xFF00FFFF;
			rgba |= green << 16;

		}

		unsigned char GetBlue() const {

			return (unsigned char)rgba >> 8;

		}

		void SetBlue(unsigned char blue) {

			rgba &= 0xFFFF00FF;
			rgba |= blue << 8;

		}

		unsigned char GetAlpha() const {
		
			return (unsigned char)rgba;
		
		}
		
		void SetAlpha(unsigned char alpha) {
			
			rgba &= 0xFFFFFF00;
			rgba |= alpha;

		}

	};

}