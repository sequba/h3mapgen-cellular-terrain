// g++ -std=c++11 -W -Wall -Wextra -pedantic -o automata automata.cpp
#include<iostream>
#include<vector>
#include<string>
#include<cassert>
using namespace std;

const unsigned int neighbourhood_radius = 2;
const unsigned int neighbourhood_size = 2*neighbourhood_radius + 1;

enum SquareState {
        // swhite and sblack squares are not going to change their state
        white = ' ',
        black = '#',
        swhite = '.',
        sblack = '$'
};

typedef vector<vector<SquareState> > Array;

int state2int(SquareState s) {
        return (s == black || s == sblack);
}

char state2char(SquareState s) {
        return char(s);
}

SquareState char2state(char c) {
        SquareState values[4] { white, black, swhite, sblack };
        for(int i = 0 ; i < 4 ; i++)
                if(c == char(values[i]))
                        return values[i];
        assert(false);
        return white;
}

struct CAParams {
        // neighbourhood contains weights for squares' neighbourhood
        // treshold defines the minimum value for the weighted sum (over the nighbourhood)
        // for a square to survive or be born
        // hint: for distinct born/survive treshold, set weight for the middle square in neighbourhood accordingly
        int neighbourhood[neighbourhood_size][neighbourhood_size];
        int treshold;
};

void array_set_size(Array& board, int rows, int cols) {
        board.clear();
        board.resize(rows, vector<SquareState>(cols));
}

void print_array(const Array& board) {
        int rows = board.size();
        int cols = board[0].size();
        cout << rows << ' ' << cols << '\n';
        for(int i=0 ; i < rows ; i++) {
                for(int j=0 ; j < cols ; j++)
                        cout << state2char(board[i][j]);
                cout << '\n';
        }
}

void load_array(Array& board) {
        int rows, cols;
        string line;
        cin >> rows >> cols;
        getline(cin,line);
        array_set_size(board,rows,cols);
        for(int i=0 ; i < rows ; i++) {
                getline(cin, line);
                for(int j=0 ; j < cols ; j++)
                        board[i][j] = char2state(line[j]);
        }
}
