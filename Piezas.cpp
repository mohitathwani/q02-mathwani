#include "Piezas.h"
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas() {
	reset();
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset() {
	turn = X;

	if(board.size() == 3) {
		board.erase(board.begin(), board.end());
	}

	for(int i = 0; i < BOARD_ROWS; i++) {
		std::vector<Piece> x;
		for(int j = 0; j < BOARD_COLS; j++) {
			x.push_back(Blank);
		}

		board.push_back(x);

	}
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column) {

	Piece pieceToReturn = Invalid;
	if(column < 0 || column >= BOARD_COLS) {
		turn = (turn == X) ? O : X;
		return pieceToReturn;
	}

	if(board[2][column] != Blank) {
		pieceToReturn = Blank;
	}

	else if(board[0][column] == Blank)
		board[0][column] = turn;

	else if(board[1][column] == Blank)
		board[1][column] = turn;

	else if(board[2][column] == Blank)
		board[2][column] = turn;

	pieceToReturn = (pieceToReturn == Invalid) ? turn : Invalid;
	turn = (turn == X) ? O : X;

	return pieceToReturn;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column) {
	if(row < 0 || row >= BOARD_ROWS)
		return Invalid;

	if(column < 0 || column >= BOARD_COLS)
		return Invalid;

	if(board[row][column] == Blank)
		return Blank;

	return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState() {
	int xScore = 0, oScore = 0;
	if(allLocationsFilled()) {
		for(int i = 0; i < BOARD_ROWS; i++) {
			Piece p = board[i][0];
			if(p == board[i][1] && p == board[i][2]) {
				if(p == X) xScore++;
				else if(p == O) oScore++;
			}
			p = board[i][1];
			if(p == board[i][2] && p == board[i][3]) {
				if(p == X) xScore++;
				else if(p == O) oScore++;
			}
		}

		for(int j = 0; j < BOARD_COLS; j++) {
			Piece p = board[0][j];
			if(p == board[1][j]) {
				if(p == X) xScore++;
				else if(p == O) oScore++;
			}
			p = board[1][j];
			if(p == board[2][j]) {
				if(p == X) xScore++;
				else if(p == O) oScore++;
			}
		}
		if(xScore == oScore) return Blank;

		return (xScore > oScore) ? X : O;
	}
	else
	return Invalid;
}

bool Piezas::allLocationsFilled() {
	for(int i = 0; i < BOARD_ROWS; i++) {
		for(int j = 0; j < BOARD_COLS; j++) {
			Piece piece = pieceAt(i,j);
			if (piece == Blank) {
				return false;
			}
		}
	}

	return true;
}
