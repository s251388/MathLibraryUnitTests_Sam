#pragma once

namespace MathLibrary
{

	struct Color {

		unsigned int rgba;		// Need to figure out how to pack information into this. I understand the concept of cramming 4
								// 0-255 ints into this one variable, but not the actual code for it.
		Color() {
		
			rgba 0;
		
		}
		
		Color(float RR, float GG, float BB, float AA) {
		
			r = RR;
			g = GG;
			b = BB;
			a = AA;
		
		}
		
		Color(const Color& Copy) {
		
			r = Copy.r;
			g = Copy.g;
			b = Copy.b;
			a = Copy.a;
		
		}
		
		
		unsigned char getRed();
		void setRed(unsigned char redValue);
		unsigned char getGreen();
		void setGreen (unsigned char greenValue);
		unsigned char getBlue();
		void setBlue(unsigned char blueValue);
		unsigned char getAlpha();
		void setAlpha(unsigned char alphaValue);

	};

}