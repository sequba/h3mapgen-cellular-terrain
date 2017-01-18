#include <iostream>
#include "cellular_terrain.hpp"
using namespace std;

// Simple demonstration how to use the main function.

const int zone_size = 16;
const int margin = zone_size/2;

void generate_sample(Board& result, unsigned int rows, unsigned int cols) {
	board_set_size(result, rows, cols);

	for(unsigned int i=0 ; i < rows ; i++)
                for(unsigned int j=0 ; j < cols ; j++)
                        // paths
                        if((i%zone_size == margin || j%zone_size == margin)
                            && i >= margin && i < rows-margin
                            && j >= margin && j < cols-margin)
                                result[i][j] = swhite;

                        // borders
                        else if(i%zone_size == 0 || j%zone_size == 0)
                                result[i][j] = sblack;
                
			// filling
                        else
				result[i][j] = white;
}

int main() {
	int rows = 33;
	int cols = 33;
	
	Board board, board2;
	generate_sample(board, rows, cols);
	//terrain(board, board2, neumann_neighbourhood(0.4, 4, 3), 4);
	terrain(board, board2, moore_neighbourhood(0.5, 3), 2);
	print_board(board2);

	return 0;
}
