#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../include/algorithm.h"

using namespace std;

/******************************************************
 * In your algorithm, you can just use the the funcitons
 * listed by TA to get the board information.(functions 
 * 1. ~ 4. are listed in next block)
 * 
 * The STL library functions is not allowed to use.
******************************************************/

/*************************************************************************
 * 1. int board.get_orbs_num(int row_index, int col_index)
 * 2. int board.get_capacity(int row_index, int col_index)
 * 3. char board.get_cell_color(int row_index, int col_index)
 * 4. void board.print_current_board(int row_index, int col_index, int round)
 * 
 * 1. The function that return the number of orbs in cell(row, col)
 * 2. The function that return the orb capacity of the cell(row, col)
 * 3. The function that return the color fo the cell(row, col)
 * 4. The function that print out the current board statement
*************************************************************************/

int territory_gap(Board board, Player player) {
    char player_color = player.get_color();
    char enemy_color = (player_color == 'r')? 'b' : 'r';
    int player_territory = 0;
    int enemy_territory = 0;
    for (int i=0; i<5; i++) {
        for (int j=0; j<6; j++) {
            if (player_color == board.get_cell_color(i, j)) 
                player_color++;
            if (enemy_color == board.get_cell_color(i, j)) 
                enemy_territory++;
        }
    }
    return (player_territory - enemy_territory);
}

int Counting_around(Board board, Player player, int i,  int j) {
    char player_color = player.get_color();
    int count = 0;
    if ( i == 0 && j == 0 ) {  // corner
        if ((board.get_cell_color(i+1, j) != player_color) && 
            (board.get_orbs_num(i+1, j) == board.get_capacity(i+1, j) - 1)) count++;   
        if ((board.get_cell_color(i, j+1) != player_color) && 
            (board.get_orbs_num(i, j+1) == board.get_capacity(i, j+1) - 1)) count++;  
        return count;
    } else if ( i == 0 && j == 5 ) {
        if ((board.get_cell_color(i, j-1) != player_color) && 
            (board.get_orbs_num(i, j-1) == board.get_capacity(i, j-1) - 1)) count++;  
        if ((board.get_cell_color(i+1, j) != player_color) && 
            (board.get_orbs_num(i+1, j) == board.get_capacity(i+1, j) - 1)) count++;
        return count;
    } else if ( i == 4 && j == 0 ) {
        if ((board.get_cell_color(i-1, j) != player_color) && 
            (board.get_orbs_num(i-1, j) == board.get_capacity(i-1, j) - 1)) count++;  
        if ((board.get_cell_color(i, j+1) != player_color) && 
            (board.get_orbs_num(i, j+1) == board.get_capacity(i, j+1) - 1)) count++;
        return count;
    } else if ( i == 4 && j == 5 ) {
        if ((board.get_cell_color(i, j-1) != player_color) && 
            (board.get_orbs_num(i, j-1) == board.get_capacity(i, j-1) - 1)) count++;  
        if ((board.get_cell_color(i-1, j) != player_color) && 
            (board.get_orbs_num(i-1, j) == board.get_capacity(i-1, j) - 1)) count++;
        return count;
    } else if ( (i == 0 && j != 0) && (i == 0 && j != 5) ) {  // edge 
        if ((board.get_cell_color(i, j-1) != player_color) && 
            (board.get_orbs_num(i, j-1) == board.get_capacity(i, j-1) - 1)) count++;  
        if ((board.get_cell_color(i, j+1) != player_color) && 
            (board.get_orbs_num(i, j+1) == board.get_capacity(i, j+1) - 1)) count++;
        if ((board.get_cell_color(i+1, j) != player_color) && 
            (board.get_orbs_num(i+1, j) == board.get_capacity(i+1, j) - 1)) count++;    
        return count;
    } else if ( (i != 0 && j == 0) && (i != 4 && j == 0) ) {
        if ((board.get_cell_color(i-1, j) != player_color) && 
            (board.get_orbs_num(i-1, j) == board.get_capacity(i-1, j) - 1)) count++;  
        if ((board.get_cell_color(i+1, j) != player_color) && 
            (board.get_orbs_num(i+1, j) == board.get_capacity(i+1, j) - 1)) count++;
        if ((board.get_cell_color(i, j+1) != player_color) && 
            (board.get_orbs_num(i, j+1) == board.get_capacity(i, j+1) - 1)) count++;    
        return count;
    } else if ( (i == 4 && j != 0) && (i == 4 && j != 5) ) {
        if ((board.get_cell_color(i, j-1) != player_color) && 
            (board.get_orbs_num(i, j-1) == board.get_capacity(i, j-1) - 1)) count++;  
        if ((board.get_cell_color(i, j+1) != player_color) && 
            (board.get_orbs_num(i, j+1) == board.get_capacity(i, j+1) - 1)) count++;
        if ((board.get_cell_color(i-1, j) != player_color) && 
            (board.get_orbs_num(i-1, j) == board.get_capacity(i-1, j) - 1)) count++;    
        return count;
    } else if ( (i != 0 && j == 5) && (i != 4 && j == 5) ) {
        if ((board.get_cell_color(i-1, j) != player_color) && 
            (board.get_orbs_num(i-1, j) == board.get_capacity(i-1, j) - 1)) count++;  
        if ((board.get_cell_color(i+1, j) != player_color) && 
            (board.get_orbs_num(i+1, j) == board.get_capacity(i+1, j) - 1)) count++;
        if ((board.get_cell_color(i, j-1) != player_color) && 
            (board.get_orbs_num(i, j-1) == board.get_capacity(i, j-1) - 1)) count++;    
        return count;
    } else {  // usual
        if ((board.get_cell_color(i-1, j) != player_color) && 
            (board.get_orbs_num(i-1, j) == board.get_capacity(i-1, j) - 1)) count++;
        if ((board.get_cell_color(i+1, j) != player_color) && 
            (board.get_orbs_num(i+1, j) == board.get_capacity(i+1, j) - 1)) count++;
        if ((board.get_cell_color(i, j-1) != player_color) && 
            (board.get_orbs_num(i, j-1) == board.get_capacity(i, j-1) - 1)) count++;
        if ((board.get_cell_color(i, j+1) != player_color) && 
            (board.get_orbs_num(i, j+1) == board.get_capacity(i, j+1) - 1)) count++;
        return count;
    }
    return count;
}

void algorithm_A(Board board, Player player, int index[]){

    // cout << board.get_capacity(0, 0) << endl;
    // cout << board.get_orbs_num(0, 0) << endl;
    // cout << board.get_cell_color(0, 0) << endl;
    // board.print_current_board(0, 0, 0);

    //////////// Random Algorithm ////////////
    // Here is the random algorithm for your reference, you can delete or comment it.
    
    
    Board Simulation_board = board;
    Player Simulation_player = player;
    char enemy_color = (player.get_color() == 'r')? 'b' : 'r';
    bool BestPoint = false;
    int Simulation_index[2] = {0};
    int Simulation_gap = 0;
    int Simulation_around_will_explode = 0;
    int Max_position_index[2] = {0};
    int Max_territory_gap = -777; 
    int Max_around_will_explode = 777;
    while ( true ) {
        for (int i=0; i<5; i++) {

            for (int j=0; j<6; j++) {

                Simulation_board = board;
                Simulation_player = player;
                Simulation_index[0] = i;
                Simulation_index[1] = j;

                if (Simulation_board.place_orb(Simulation_index[0], Simulation_index[1], &Simulation_player)) {  // if valid

                    Simulation_gap = territory_gap(Simulation_board, Simulation_player); // count gap
                    Simulation_around_will_explode = Counting_around(Simulation_board, Simulation_player, 
                                                                     Simulation_index[0], Simulation_index[1]); 

                    if ((Simulation_board.get_cell_color(0, 0) != enemy_color) && 
                            (Simulation_board.get_orbs_num(0, 0) == 1) && 
                            (i == 0 && j == 0) ) {
                            index[0] = i, index[1] = j;
                            return;
                        }

                    if ((Simulation_board.get_cell_color(0, 5) != enemy_color) && 
                            (Simulation_board.get_orbs_num(0, 5) == 1) && 
                            (i == 0 && j == 5) ) {
                            index[0] = i, index[1] = j;
                            return;
                        }

                    if ((Simulation_board.get_cell_color(4, 0) != enemy_color) && 
                            (Simulation_board.get_orbs_num(4, 0) == 1) && 
                            (i == 4 && j == 0) ) {
                            index[0] = i, index[1] = j;
                            return;
                        }

                    if ((Simulation_board.get_cell_color(4, 5) != enemy_color) && 
                            (Simulation_board.get_orbs_num(4, 5) == 1) && 
                            (i == 4 && j == 5) ) {
                            index[0] = i, index[1] = j;
                            return;
                        }

                    if (Simulation_gap > Max_territory_gap) {  // upadate max gap which represent the best point 

                        Max_territory_gap = Simulation_gap;
                        Max_position_index[0] = i;
                        Max_position_index[1] = j;
                        Max_around_will_explode = Simulation_around_will_explode;

                    } else if(Simulation_gap == Max_territory_gap) {

                        if ((Max_position_index[0] == 0 && Max_position_index[1] == 0) ||          // Max is corner
                            (Max_position_index[0] == 0 && Max_position_index[1] == 5) ||
                            (Max_position_index[0] == 4 && Max_position_index[1] == 0) ||
                            (Max_position_index[0] == 4 && Max_position_index[1] == 5)) {  
                            
                            if (Simulation_index[0] != 0 && Simulation_index[1] != 0 &&            // Simulation is usual
                                Simulation_index[0] != 4 && Simulation_index[1] != 5){
                                
                                Max_position_index[0] = i; Max_position_index[1] = j;
                                
                            } else if ((Simulation_index[0] == 0 && Simulation_index[1] != 0) ||   // Simulation is edge
                                       (Simulation_index[0] == 0 && Simulation_index[1] != 5) ||
                                       (Simulation_index[0] == 4 && Simulation_index[1] != 0) ||
                                       (Simulation_index[0] == 4 && Simulation_index[1] != 5)) {

                                Max_position_index[0] = i; Max_position_index[1] = j;
                                
                            } else {                                                               // Simulation is corner
                                
                                if (Simulation_around_will_explode < Max_around_will_explode)      // test around_will_explosion
                                    Max_position_index[0] = i,Max_position_index[1] = j;
                                else continue;
                            }
                                   
                        } else if (Max_position_index[1] == 0 || Max_position_index[5] == 5 ||     // Max is edge
                                   Max_position_index[0] == 0 || Max_position_index[0] == 4) {

                            if (Simulation_index[0] != 0 && Simulation_index[1] != 0 &&            // Simulation is usual
                                Simulation_index[0] != 4 && Simulation_index[1] != 5){
                                
                                Max_position_index[0] = i; Max_position_index[1] = j;
                                
                            } else if ((Simulation_index[0] == 0 && Simulation_index[1] != 0) ||   // Simulation is edge
                                       (Simulation_index[0] == 0 && Simulation_index[1] != 5) ||
                                       (Simulation_index[0] == 4 && Simulation_index[1] != 0) ||
                                       (Simulation_index[0] == 4 && Simulation_index[1] != 5)) {
                                if (Simulation_around_will_explode < Max_around_will_explode)      // test around_will_explosion
                                    Max_position_index[0] = i,Max_position_index[1] = j;
                                else continue;

                            } else {                                                               // Simulation is corner
                                continue;
                            }
                        } else {                                                                   // Max is usual

                            if (Simulation_index[0] != 0 && Simulation_index[1] != 0 &&            // Simulation is usual
                                Simulation_index[0] != 4 && Simulation_index[1] != 5){

                                if (Simulation_around_will_explode < Max_around_will_explode)      // test around_will_explosion
                                    Max_position_index[0] = i,Max_position_index[1] = j;
                                else continue;                                  
                                
                            } else if ((Simulation_index[0] == 0 && Simulation_index[1] != 0) ||   // Simulation is edge
                                       (Simulation_index[0] == 0 && Simulation_index[1] != 5) ||
                                       (Simulation_index[0] == 4 && Simulation_index[1] != 0) ||
                                       (Simulation_index[0] == 4 && Simulation_index[1] != 5)) {
                                continue;
                            } else {                                                               // Simulation is corner
                                continue;
                            }
                   
                        }
                    } else continue;                 
                }
                    
            }
        }
        break;
    } 
    index[0] = Max_position_index[0];
    index[1] = Max_position_index[1];
    return;

    
    
    
    /*srand(time(NULL));
    int row, col;
    int color = player.get_color();
    
    while(1){
        row = rand() % 5;
        col = rand() % 6;
        if(board.get_cell_color(row, col) == color || board.get_cell_color(row, col) == 'w') break;
    }
    

    index[0] = row;
    index[1] = col;*/
    
}