/*
 *
 * STUDENT_ID: 2425693
 * m
 * COMMENTS (if any): I never thought I would say, "Hooray, recursion!"
 */

#include "my_pyramid_game.h"
#include "pyramid_helpers.h"

#define NUMBER_OF_POS_MOVES 36
#define SIZE_OF_BOARD 15

struct PossibleMove {
    int from;
    int over;
    int to;
};

int solve(int board[]);
int is_legal_move(struct PossibleMove move, int board[]);
int is_winning_board(int board[]);
int num_of_pegs(int board[]);
void make_move(int board[], struct PossibleMove move);
void undo_move(int board[], struct PossibleMove move);



const int all_possible_moves[NUMBER_OF_POS_MOVES][3] = {
    {0, 2, 5},
    {0, 1, 3},
    {1, 3, 6},
    {1, 4, 8},
    {2, 4, 7},
    {2, 5, 9},
    {3, 1, 0},
    {3, 4, 5},
    {3, 7, 12},
    {3, 6, 10},
    {4, 8, 13},
    {4, 7, 11},
    {5, 4, 3},
    {5, 8, 12},
    {5, 9, 14},
    {5, 2, 0},
    {6, 3, 1},
    {6, 7, 8},
    {7, 4, 2},
    {7, 8, 9},
    {8, 4, 1},
    {8, 7, 6},
    {9, 5, 2},
    {9, 8, 7},
    {10, 11, 12},
    {10, 6, 3},
    {11, 7, 4},
    {11, 12, 13},
    {12, 7, 3},
    {12, 8, 5},
    {12, 11, 10},
    {12, 13, 14},
    {13, 12, 11},
    {13, 8, 4},
    {14, 13, 12},
    {14, 9, 5}
};

/*
 * (Copied from 'my_pyramid_solver.h')
 *
 * THIS FUNCTION WILL BE CALLED DURING TEST ASSESSMENTS.
 *
 * solve: This is the game 'engine', in which the logic is based.
 *        It takes a board in any valid state, and determines
 *        if the game is solvable.
 *
 * Parameters:
 *        board - an integer array of size 15, with contents either 0 or 1.
 *
 * Returns:
 *        1  -  If the board is solvable;
 *        0  -  otherwise.
 */


int solve(int board[]) {
    int i;
    int no_of_pegs = num_of_pegs(board);
    int legal_move, solvable;

    /** declare and initialise struct variables **/
    struct PossibleMove move;
    move.from = 0;
    move.over = 0;
    move.to = 0;

    /** base case is when there is only one peg left on the board*/
    if (no_of_pegs == 1) {
        pyramid_print(board); // Print the winning board
        return 1;
    } else {

        for (i = 0; i < NUMBER_OF_POS_MOVES; i++) {

            /** assign value to relevant move variable**/
            move.from = *(all_possible_moves[i]);
            move.over = *(all_possible_moves[i]+1);
            move.to = *(all_possible_moves[i]+2);

            /** Check whether or not the move is legal **/
            if ((legal_move = is_legal_move(move, board))) {

                /** make the move*/
                make_move(board, move);

                /** Check if the board resulting from the move made
                 * is solvable and if so call the function solve again with the "new"
                 * board as a parameter
                 */
                if ((solvable = solve(board))) {

                    undo_move(board, move);
                    pyramid_print(board);
                    return 1;
                }
                undo_move(board, move);

            }
        }

        if (i == 36 && legal_move == 0) {
            printf("This board is unsolvable!");
        }

    }

    return 0;
}

int is_legal_move(struct PossibleMove move, int board[]) {
    int s, t, u;
    if (((s = board[move.from]) == 1) && ((t = board[move.over]) == 1) && ((u = board[move.to]) == 0))
        return 1;

    return 0;
}

int num_of_pegs(int board[]) {
    int temp, count = 0;

    for (int i = 0; i < 15; i++) {
        if ((temp = board[i]) == 1)
            count++;
    }
    return count;
}

void make_move(int board[], struct PossibleMove move) {
    board[move.from] = !board[move.from];
    board[move.over] = !board[move.over];
    board[move.to] = !board[move.to];
}

void undo_move(int board[], struct PossibleMove move) {
    board[move.from] = !board[move.from];
    board[move.over] = !board[move.over];
    board[move.to] = !board[move.to];
}

/*
 * main_pyramid:  This is the entry point to your pyramid game implementation.
 *
 * Pretend this is the main() function as you are use to writing,
 * i.e. the function where your program logic begins and terminates.
 */

int main_pyramid() {
    int board[15];

    pyramid_input(board);

    printf("Here is the board you entered:\n");
    pyramid_print(board);

    int result = solve(board);
    printf("\nResult:  %d", result);
    return 0;
}
