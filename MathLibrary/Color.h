#pragma once

namespace MathLibrary
{

	struct Color {

		unsigned int rgba;			// Need to figure out how to pack information into this. I understand the concept of
									// cramming 4 0-255 ints into this one variable, but not the actual code for it.
		Color() {
		
			rgba = 0;
		
		}
		
		Color(unsigned char RR, unsigned char GG, unsigned char BB, unsigned char AA) {
		
			rgba = RR << 24 | GG << 16 | BB << 8 | AA;
		
		}
		
		Color(const Color& Copy) {
		
		rgba = Copy.rgba;

		}
		
		
		unsigned char getRed() {

			return (unsigned char)rgba >> 24;

		}

		void SetRed(unsigned char red) {

			rgba &= 0x00FFFFFF;
			rgba |= red << 24;

		}   

		unsigned char getGreen() {

			return (unsigned char)rgba >> 16;

		}

		void setGreen (unsigned char green) {

			rgba &= 0xFF00FFFF;
			rgba |= green << 16;

		}

		unsigned char getBlue() {

			return (unsigned char)rgba >> 8;

		}

		void setBlue(unsigned char blue) {

			rgba &= 0xFFFF00FF;
			rgba |= blue << 8;

		}

		unsigned char getAlpha() {
		
			return (unsigned char)rgba;
		
		}
		
		void setAlpha(unsigned char alpha) {

			rgba &= 0xFFFFFF00;
			rgba |= alpha;

		}

	};

}