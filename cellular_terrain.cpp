#include <vector>
#include <random>
#include "cellular_terrain.hpp"
using namespace std;

// computes one generation of CA according to parameters given
void generation(const Board& board, Board& result, const TerrainParams& parameters) {
	// resulting board will be surrounded by 2-thick sblack boarders in order to get away with edge cases smoothly
	unsigned int rows = board.size();
	unsigned int cols = board[0].size();
	board_set_size(result, rows, cols);
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
						sum += parameters.neighbourhood[i][j] * square2int(board[ii+i][jj+j]);
				if(sum >= parameters.treshold)
					result[i][j] = black;
				else
					result[i][j] = white;
			}
		}
}


// fills the board randomly according to the probability (with respect to swhite and sblack squares)
void random_fill(const Board& board, Board& result, const TerrainParams& parameters) {
        unsigned int rows = board.size();
        unsigned int cols = board[0].size();
        board_set_size(result, rows, cols);
        
	default_random_engine gen;
        bernoulli_distribution dist(parameters.probability);

	for(unsigned int i=0 ; i < rows ; i++)
                for(unsigned int j=0 ; j < cols ; j++)
			if(board[i][j] == sblack || board[i][j] == swhite)
				result[i][j] = board[i][j];
			else if(dist(gen))
				result[i][j] = white;
			else
				result[i][j] = black;
}
