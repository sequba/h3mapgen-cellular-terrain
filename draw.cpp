#include <iostream>
#include <string>
#include "board.hpp"
using namespace std;

// The program converts ascii map to bmp file
// Zoom factor could be specified below.

struct Color {
	Color(unsigned short int red, unsigned short int green, unsigned short int blue)
	: r(red), g(green), b(blue) {}
	unsigned short int r, g, b;
};

Color square2color(Square s) {
	if(s == white)
		return Color(255,255,255);
	else if(s == swhite)
		return Color(255,255,80);
	else if(s == black)
		return Color(0,0,0);
	else {
		assert(s == sblack);
		return Color(20,0,70);	
	}
}

const unsigned short int zoom = 4;

// function drawbmp based on:
// Nebulabrot / Buddhabrot generator.
// Brought to you by Wikipedia...
// Written by User:Evercat
// Released under the GNU Free Documentation License
// or the GNU Public License, whichever you prefer:
// November 23, 2004

void drawbmp (const Board& board, const string filename) {
	unsigned int headers[13];
	int extrabytes;
	int paddedsize;
	unsigned int height = board.size()* zoom;
	unsigned int width = board[0].size()* zoom;
	extrabytes = 4 - ((width * 3) % 4);                 // How many bytes of padding to add to each
       		                                            // horizontal line - the size of which must
                	                                    // be a multiple of 4 bytes.
	if (extrabytes == 4)
   		extrabytes = 0;
	paddedsize = ((width * 3) + extrabytes) * height;

	// Headers...
	// Note that the "BM" identifier in bytes 0 and 1 is NOT included in these "headers".
	headers[0]  = paddedsize + 54;      // bfSize (whole file size)
	headers[1]  = 0;                    // bfReserved (both)
	headers[2]  = 54;                   // bfOffbits
	headers[3]  = 40;                   // biSize
	headers[4]  = width;  // biWidth
	headers[5]  = height; // biHeight
	// Would have biPlanes and biBitCount in position 6, but they're shorts.
	// It's easier to write them out separately (see below) than pretend
	// they're a single int, especially with endian issues...
	headers[7]  = 0;                    // biCompression
	headers[8]  = paddedsize;           // biSizeImage
	headers[9]  = 0;                    // biXPelsPerMeter
	headers[10] = 0;                    // biYPelsPerMeter
	headers[11] = 0;                    // biClrUsed
	headers[12] = 0;                    // biClrImportant

	FILE* outfile = fopen(filename.data(), "wb");

	// Headers begin...
	// When printing ints and shorts, we write out 1 character at a time to avoid endian issues.
	fprintf(outfile, "BM");
	for(int n = 0; n <= 5; n++) {
   		fprintf(outfile, "%c", headers[n] & 0x000000FF);
   		fprintf(outfile, "%c", (headers[n] & 0x0000FF00) >> 8);
   		fprintf(outfile, "%c", (headers[n] & 0x00FF0000) >> 16);
   		fprintf(outfile, "%c", (headers[n] & (unsigned int) 0xFF000000) >> 24);
	}
	// These next 4 characters are for the biPlanes and biBitCount fields.
	fprintf(outfile, "%c", 1);
	fprintf(outfile, "%c", 0);
	fprintf(outfile, "%c", 24);
	fprintf(outfile, "%c", 0);
	for(int n = 7; n <= 12; n++) {
		fprintf(outfile, "%c", headers[n] & 0x000000FF);
   		fprintf(outfile, "%c", (headers[n] & 0x0000FF00) >> 8);
   		fprintf(outfile, "%c", (headers[n] & 0x00FF0000) >> 16);
   		fprintf(outfile, "%c", (headers[n] & (unsigned int) 0xFF000000) >> 24);
	}
	
	// Headers done, now write the data...

	for(int y = height - 1; y >= 0; y--) {     // BMP image format is written from bottom to top...
   		for(unsigned int x = 0; x <= width - 1; x++) {

			Color c = square2color(board[y/zoom][x/zoom]);

      			// Also, it's written in (b,g,r) format...
      			fprintf(outfile, "%c", c.b);
      			fprintf(outfile, "%c", c.g);
      			fprintf(outfile, "%c", c.r);	
   		}
		if (extrabytes)      // See above - BMP lines must be of lengths divisible by 4.
      			for(int n = 1; n <= extrabytes; n++)
         			fprintf(outfile, "%c", 0);
	}
	fclose(outfile);
}

int main(int argc, char** argv) {
	if(argc < 2) {
		cerr << "Usage: " << argv[0] << " output_filename.bmp\n";
		return 0;
	}

	string filename = argv[1];
	Board board;
	load_board(board);
	drawbmp(board, filename);
	return 0;
}
