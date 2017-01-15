# h3mapgen-cellular-terrain
Part of the Heroes 3 Map Generator. Module builds terrain shape using cellular automata.


Data representation description:

The game map (board) is represented as a 2-d vector of squares.
Namely: typedef vector<vector<Square> > Board;

A single square can be in one of 4 states: white, black, swhite or sblack:
enum Square {
        white,	black,
        swhite,	sblack
};




How to use the generator?

Take a look on facade function terrain(...) as well as specialized neighbourhood functions:
void terrain(const Board& board, Board& result, const TerrainParams& parameters, unsigned int iterations);
- board is an input; meant to contain some swhite and sblack squares
- result will hold the resulting terrain map
- parameters structure may be easly obtained from functions such as moore_neighbourhood etc.
- iterations just specifies the number of succesive CA generations

TerrainParams moore_neighbourhood(float probability, int treshold, int self_weight=1);
- probability is a probability of empty square on the initial board before running CA
- treshold defines the minimum value for the weighted sum (over the nighbourhood) for a square to survive or be born
- self_weight specifies the degree of contribution of the current square's state to the wighted sum

Example usage:
terrain(my_map, terrain_map, moore_neighbourhood(0.5, 3), 2);
terrain(my_map, terrain_map, neumann_neighbourhood(0.4, 4, 3), 4);






Note: Bash script produce.sh requires imagemagick.
