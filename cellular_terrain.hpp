#ifndef CELLULAR_TERRAIN_H
#define CELLULAR_TERRAIN_H

#include "board.hpp"

// Some consts:
const unsigned int neighbourhood_radius = 2;
const unsigned int neighbourhood_size = 2*neighbourhood_radius + 1;

// Structure encapsulating all the parameters of terrain generation process
struct TerrainParams {
        // neighbourhood contains weights for squares' neighbourhood
        // treshold defines the minimum value for the weighted sum (over the nighbourhood)
        // for a square to survive or be born
        // hint: for distinct born/survive treshold, set weight for the middle square in neighbourhood accordingly
        int neighbourhood[neighbourhood_size][neighbourhood_size];
        int treshold;
};

// Real stuff:
void generation(const Board& board, Board& result, const TerrainParams& parameters);

#endif
