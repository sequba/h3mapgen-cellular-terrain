#ifndef CELLULAR_TERRAIN_H
#define CELLULAR_TERRAIN_H

#include "board.hpp"

// Some consts:
const unsigned int neighbourhood_radius = 2;
const unsigned int neighbourhood_size = 2*neighbourhood_radius + 1;

// Structure encapsulating all the parameters of terrain generation process
struct TerrainParams {
        // neighbourhood contains weights for squares' neighbourhood
        // initially board is filled randomly according to the probability of empty square
	// treshold defines the minimum value for the weighted sum (over the nighbourhood)
        // for a square to survive or be born
        int neighbourhood[neighbourhood_size][neighbourhood_size];
        float probability; //of empty square
	int treshold;
};

// Real stuff:
void generation(const Board& board, Board& result, const TerrainParams& parameters);
void random_fill(const Board& board, Board& result, const TerrainParams& parameters);

#endif
