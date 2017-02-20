#include <iostream>
#include "cellular_terrain.hpp"
using namespace std;

// Program reads map and runs one generation of CA

int main(int argc, char** argv) {
        if(argc < 3) {
                cerr << "Usage: " << argv[0] << " self_weight more_white\n";
		return 0;
	}
		
	int self_weight = atoi(argv[1]);
        int more_white = atoi(argv[2]);

        TerrainParams params = moore_neighbourhood(0.5, self_weight);

	Board board1;
        load_board(board1);
        autoset_threshold(params, board1, more_white);
	cout << params.threshold;
        return 0;
}

