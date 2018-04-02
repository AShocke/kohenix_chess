/* board.h
 * Aisosa Efemwonkieke
 * Using a 10x12 board alongside a piece list; a hybrid approach
 */

#ifndef BOARD
#define BOARD
/* The 10x12 board with out-of-bound indices. It considered to be
 * more efficient during move generation.
 * Little Endian Rank-File (LERF) System
 * 
 */

const int OUT_OF_BOUNDS = -1;
/*
 * Squares
 */
enum enumSquare {
  a1, b1, c1, d1, e1, f1, g1, h1,
  a2, b2, c2, d2, e2, f2, g2, h2,
  a3, b3, c3, d3, e3, f3, g3, h3,
  a4, b4, c4, d4, e4, f4, g4, h4,
  a5, b5, c5, d5, e5, f5, g5, h5,
  a6, b6, c6, d6, e6, f6, g6, h6,
  a7, b7, c7, d7, e7, f7, g7, h7,
  a8, b8, c8, d8, e8, f8, g8, h8
};
/*
 * Note that I am not using 2-dimensional arrays. This is simply because it is more efficient
 * to use a single dimensional array and there is actual a neat pattern for moving pieces around.
 * The board is 10x12 because it allows us to easily calculate out of bound moves especially for knights.
 */
const int BOARD_120[120] = {
	 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
     -1, a8, b8, c8, d8, e8, f8, g8, h8-1,
     -1, a7, b7, c7, d7, e7, f7, g7, h7, -1,
     -1, a6, b6, c6, d6, e6, f6, g6, h6, -1,
     -1, a5, b5, c5, d5, e5, f5, g5, h5, -1,
     -1, a4, b4, c4, d4, e4, f4, g4, h4, -1,
     -1, a3, b3, c3, d3, e3, f3, g3, h3, -1,
     -1, a2, b2, c2, d2, e2, f2, g2, h2, -1,
     -1, a1, b1, c1, d1, e1, f1, g1, h1, -1,
     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
};

/* converts a 64 bit square to one of the actual squares in the 10x12 board
 * for example.  if we a rook is on h6 (23) and we wan to see if we can legally
 * move it to the right 2 (a5). We would do a conditional check to see if
 * BOARD_120[BOARD_64[24]] equals -1 which it does
 */
const int BOARD_64[64] = {
	91, 92, 93, 94, 95, 96, 97, 98,
	81, 82, 83, 84, 85, 86, 87, 88,
	71, 72, 73, 74, 75, 76, 77, 78,
	61, 62, 63, 64, 65, 66, 67, 68,
	51, 52, 53, 54, 55, 56, 57, 58,
	41, 42, 43, 44, 45, 46, 47, 48,
	31, 32, 33, 34, 35, 36, 37, 38,
    21, 22, 23, 24, 25, 26, 27, 28,
};
/*
 * Pieces
 */
const int EMPTY = 0;
const int PAWN = 1;
const int KNIGHT = 2;
const int BISHOP = 3;
const int ROOK  = 4;
const int QUEEN = 5;
const int KING = 6;
const int BLACK = 1; // a black_piece = white_piece + BLACK

const int MAX_ROOKS = 10;
const int MAX_KNIGHTS = 10;
const int MAX_BISHOPS = 10;
const int MAX_PAWNS = 8;
const int MAX_QUEENS = 9;
const int MAX_KINGS = 1;
/*
 * Board class
 */

struct Board {
	// Piece  List
	//white
	int n_white_pawns_;
	int white_pawns_[MAX_PAWNS];
	int n_white_knights_;
	int white_knights_[MAX_KNIGHTS];
	int n_white_bishops_;
	int white_bishops_[MAX_BISHOPS];
	int n_white_rooks_;
	int white_rooks_[MAX_ROOKS];
	int n_white_queens_;
	int white_queens_[MAX_QUEENS];
	int white_king_[MAX_KINGS];
   	int white_board_[64] = {
		ROOK  , KNIGHT , BISHOP , KING   , QUEEN  , BISHOP , KNIGHT , ROOK  ,
		PAWN  , PAWN   ,  PAWN  , PAWN   , PAWN   ,  PAWN  , PAWN   , PAWN  ,
		EMPTY , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY ,
		EMPTY , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY ,
		EMPTY , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY ,
		EMPTY , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY ,
		EMPTY , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY ,
		EMPTY , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY
	};
	// black
	int n_black_pawns_;
	int black_pawns_[MAX_PAWNS];
	int n_black_knights_;
	int black_knights_[MAX_KNIGHTS];
	int n_black_bishops_;
	int black_bishops_[MAX_BISHOPS];
	int n_black_rooks_;
	int black_rooks_[MAX_ROOKS];
	int n_black_queens_;
	int black_queens_[MAX_QUEENS];
	int black_king_[MAX_KINGS];
	int black_board_[64] = {
		EMPTY , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY ,
		EMPTY , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY ,
		EMPTY , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY ,
		EMPTY , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY ,
		EMPTY , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY ,
		EMPTY , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY ,
		PAWN  , PAWN   ,  PAWN  , PAWN   , PAWN   ,  PAWN  , PAWN   , PAWN  ,
		ROOK  , KNIGHT , BISHOP , KING   , QUEEN  , BISHOP , KNIGHT , ROOK
	};
	//
	int board_[64] = {
		ROOK  , KNIGHT , BISHOP , KING   , QUEEN  , BISHOP , KNIGHT , ROOK  ,
		PAWN  , PAWN   ,  PAWN  , PAWN   , PAWN   ,  PAWN  , PAWN   , PAWN  ,
		EMPTY , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY ,
		EMPTY , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY ,
		EMPTY , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY ,
		EMPTY , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY  , EMPTY ,
		PAWN  , PAWN   ,  PAWN  , PAWN   , PAWN   ,  PAWN  , PAWN   , PAWN  ,
		ROOK  , KNIGHT , BISHOP , KING   , QUEEN  , BISHOP , KNIGHT , ROOK
	};
};

/*
 * Movements
 * 
 * North = +8
 * South = -8
 * East = +1
 * West = -1
 * North East = +9
 * North West = +7
 * South East = -7
 * South West = -9
 *
 * piece movements neatly correspond to the actual piece values
 */

int movements[7][8] = { //
	{0, 0, 0, 0, 0, 0, 0, 0}, // EMPTY could be arbitrary really
	{1, 2, 0, 0, 0, 0, 0, 0}, // PAWN; pawns are special cases when on their starting rank
							  // (when square % 8 = 1)
	{17, -17, 15, -15, 10, -10 , 6, -6}, //KNIGHT
	// Queens, Bishops and Rooks can move multiples of their ray directions, so this must be taken into account
	{9, -9, 7, -7, 0, 0, 0, 0}, // BISHOP
	{8, -8, 1, -1, 0, 0, 0, 0}, // ROOK
	{9, -9, 7, -7, 8, -8, 1, -1}, // QUEEN, BISHOP combined with ROOK
	{9, -9, 7, -7, 8, -8, 1, -1} // KING; same as queen	
};
#endif
