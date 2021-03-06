#include <iostream>
#include "cellular_terrain.hpp"
using namespace std;

// Program generates a sample input od superwhite and superblack with random filling

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

int main(int argc, char** argv) {
	if(argc < 4) {
		cout << "Usage: " << argv[0] << " map_height map_width p"
		     << "\n\n" << "p - the probability of a black cell"
		     << "\n";
		return 0;
	}

	int rows = atoi(argv[1]);
	int cols = atoi(argv[2]);
	float p = atof(argv[3]);
	
	TerrainParams parameters;
	parameters.probability = p;

	Board board, board2;
	generate_sample(board, rows, cols);
	random_fill(board, board2, parameters);
	print_board(board2);

	return 0;
}
