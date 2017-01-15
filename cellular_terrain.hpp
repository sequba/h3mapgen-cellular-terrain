#ifndef CELLULAR_TERRAIN_H
#define CELLULAR_TERRAIN_H

#include<vector>
#include<cassert>
using namespace std;

// Representation of sigle square's state
enum Square {
        // swhite and sblack squares are not going to change their square
        white = ' ',
        black = '#',
        swhite = '.',
        sblack = '$'
};

// Board is a 2-d array of squares
typedef vector<vector<Square> > Board;

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
void print_board(const Board& board);
void load_board(Board& board);

// Auxiliary conversions etc:
inline int square2int(Square s) {
        return (s == black || s == sblack);
}
inline char square2char(Square s) {
        return char(s);
}
inline Square char2square(char c) {
        Square values[4] { white, black, swhite, sblack };
        for(int i = 0 ; i < 4 ; i++)
                if(c == char(values[i]))
                        return values[i];
        assert(false);
        return white;
}

inline void board_set_size(Board& board, int rows, int cols) {
        board.clear();
        board.resize(rows, vector<Square>(cols));
}

#endif
