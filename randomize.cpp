#include <iostream>
#include "cellular_terrain.hpp"
using namespace std;

// Reads input and puts white/black squares randomly with respect to super* ones

int main(int argc, char** argv) {
	if(argc < 2) {
		cout << "Usage: " << argv[0] << "p - the probability of empty square"
		     << "\n";
		return 0;
	}

	float p = atof(argv[1]);
	
	TerrainParams parameters;
	parameters.probability = p;

	Board board, board2;
	load_board(board);
	random_fill(board, board2, parameters);
	print_board(board2);

	return 0;
}
