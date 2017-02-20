#include <iostream>
#include "cellular_terrain.hpp"
using namespace std;

// Program reads map and runs one generation of CA

int main(int argc, char** argv) {
        if(argc < 3) {
                cerr << "Usage: " << argv[0] << " threshold self_weight\n";
		return 0;
	}
		
	int threshold = atoi(argv[1]);
	int self_weight = atoi(argv[2]);
        
        TerrainParams params = moore_neighbourhood(0.5, self_weight, threshold);
        /*
	for(int i=0 ; i < neighbourhood_size ; i++) {
		for(int j=0 ; j < neighbourhood_size ; j++) {
			cerr << params.neighbourhood[i][j] << ' ';
		}
		cerr << '\n';
	}
	*/
	Board board1, board2;
        load_board(board1);
        generation(board1, board2, params);
        print_board(board2);
        return 0;
}

