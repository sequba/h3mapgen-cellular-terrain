// convinient executable for testing and prototyping puropses

#include <iostream>
#include "cellular_terrain.hpp"
using namespace std;

int main(int argc, char** argv) {
        if(argc < 2) {
                cerr << "Usage: " << argv[0] << " treshold\n";
		return 0;
	}
		
	int treshold = atoi(argv[1]);
        int neighbourhood[5][5] = {5, 0, 0, 0, 5,
                                   0, 0, 2, 0, 0,
                                   0, 2, 2, 2, 0,
                                   0, 0, 2, 0, 0,
                                   5, 0, 0, 0, 5
        };
        TerrainParams params;
        params.treshold = treshold;
        copy(&neighbourhood[0][0], &neighbourhood[0][0]+25, &(params.neighbourhood[0][0]));
        Board board1, board2;
        load_board(board1);
        generation(board1, board2, params);
        print_board(board2);
        return 0;
}

