#include "cellular.hpp"

void CA_generation(const Array& board, Array& result, const CAParams& parameters) {
	// resulting board will be surrounded by 2-thick sblack boarders in order to get away with edge cases smoothly
	unsigned int rows = board.size();
	unsigned int cols = board[0].size();
	array_set_size(result, rows, cols);
	for(unsigned int i=0 ; i < rows ; i++)
		for(unsigned int j=0 ; j < cols ; j++) {
			// near edge -> sblack boarder
			if(i < neighbourhood_radius || i >= rows - neighbourhood_radius || j < neighbourhood_radius || j >= cols - neighbourhood_radius )
				result[i][j] = sblack;
			// swhite and sblack squares don't change
			else if(board[i][j] == swhite || board[i][j] == sblack) {
				result[i][j] = board[i][j];
			} else {
				int ii = i-neighbourhood_radius;
				int jj = j-neighbourhood_radius;
				int sum = 0;
				for (unsigned int i=0 ; i < neighbourhood_size ; i++)
					for(unsigned int j = 0 ; j < neighbourhood_size ; j++)
						sum += parameters.neighbourhood[i][j] * state2int(board[ii+i][jj+j]);
				if(sum >= parameters.treshold)
					result[i][j] = black;
				else
					result[i][j] = white;
			}
		}
}

int main(int argc, char** argv) {
	if(argc < 2)
		cerr << "Usage: " << argv[0] << " treshold\n";
	int treshold = atoi(argv[1]);
	int neighbourhood[5][5] = {0, 0, 0, 0, 0,
				   0, 0, 1, 0, 0,
				   0, 1, 2, 1, 0,
				   0, 0, 1, 0, 0,
				   0, 0, 0, 0, 0
	};
	CAParams params;
	params.treshold = treshold;
	copy(&neighbourhood[0][0], &neighbourhood[0][0]+25, &(params.neighbourhood[0][0]));
	Array board1, board2;
	load_array(board1);
	CA_generation(board1, board2, params);
	print_array(board2);
	return 0;
}
