#ifndef BOARD_H
#define BOARD_H

#include<vector>
#include<cassert>
using namespace std;

// Representation of single square's state
enum Square {
        // swhite and sblack squares are not going to change their square
        white = ' ',
        black = '#',
        swhite = '.',
        sblack = '$'
};

// Board is a 2-d array of squares
typedef vector<vector<Square> > Board;

// Functions for I/O
void print_board(const Board& board);
void load_board(Board& board);

// Statistical measures
float black_rate(const Board& board);

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
