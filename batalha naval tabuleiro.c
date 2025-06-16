#include <stdio.h>

#define BOARD_SIZE 
#define SHIP_SIZE 

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }

    int ship1_row = 1;
    int ship1_col = 2;

    int ship2_col = 6;

    int placement_successful = 1;

    if (ship1_row < 0 || ship1_row >= BOARD_SIZE ||
        ship1_col < 0 || (ship1_col + SHIP_SIZE) > BOARD_SIZE) {
        printf("Erro: Navio 1 (horizontal) fora dos limites do tabuleiro.\n");
        placement_successful = 0;
    } else {
    
        for (int j = 0; j < SHIP_SIZE; j++) {
            if (board[ship1_row][ship1_col + j] != 0) {
                printf("Erro: Navio 1 (horizontal) se sobrepõe a outro navio.\n");
                placement_successful = 0;
                break;
            }
        }
        
        if (placement_successful) {
            for (int j = 0; j < SHIP_SIZE; j++) {
                board[ship1_row][ship1_col + j] = 3;
            }
        }
    }

    if (placement_successful) {
    
        if (ship2_row < 0 || (ship2_row + SHIP_SIZE) > BOARD_SIZE ||
            ship2_col < 0 || ship2_col >= BOARD_SIZE) {
            printf("Erro: Navio 2 (vertical) fora dos limites do tabuleiro.\n");
            placement_successful = 0;
        } else {
        
            for (int i = 0; i < SHIP_SIZE; i++) {
                if (board[ship2_row + i][ship2_col] != 0) {
                    printf("Erro: Navio 2 (vertical) se sobrepõe a outro navio.\n");
                    placement_successful = 0;
                    break;
                }
            }
        
            if (placement_successful) {
                for (int i = 0; i < SHIP_SIZE; i++) {
                    board[ship2_row + i][ship2_col] = 3;
                }
            }
        }
    }

    printf("\n--- Tabuleiro do Batalha Naval ---\n");

    printf("   ");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("%2d ", col);
    }
    printf("\n");

    printf("   +");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("---");
    }
    printf("+\n");


    if (placement_successful) {
        for (int i = 0; i < BOARD_SIZE; i++) {
            printf("%2d |", i);
            for (int j = 0; j < BOARD_SIZE; j++) {
                printf("%2d ", board[i][j]);
            }
            printf("|\n");
        }
    } else {
        printf("\nNão foi possível posicionar todos os navios devido a erros.\n");
    }

    printf("   +");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("---");
    }
    printf("+\n");

    return 0;
}


#include <stdio.h> 

#define BOARD_SIZE 
#define SHIP_SIZE 
#define WATER
#define SHIP_PART

int placeHorizontalShip(int board[BOARD_SIZE][BOARD_SIZE], int start_row, int start_col) {

    if (start_row < 0 || start_row >= BOARD_SIZE ||
        start_col < 0 || (start_col + SHIP_SIZE) > BOARD_SIZE) {
        printf("Erro: Navio horizontal fora dos limites em (%d,%d).\n", start_row, start_col);
        return 0;
    }

    for (int j = 0; j < SHIP_SIZE; j++) {
        if (board[start_row][start_col + j] != WATER) {
            printf("Erro: Navio horizontal em (%d,%d) se sobrepõe a outro navio.\n", start_row, start_col);
            return 0;
        }
    }

    for (int j = 0; j < SHIP_SIZE; j++) {
        board[start_row][start_col + j] = SHIP_PART;
    }
    return 1;
}

int placeVerticalShip(int board[BOARD_SIZE][BOARD_SIZE], int start_row, int start_col) {

    if (start_row < 0 || (start_row + SHIP_SIZE) > BOARD_SIZE ||
        start_col < 0 || start_col >= BOARD_SIZE) {
        printf("Erro: Navio vertical fora dos limites em (%d,%d).\n", start_row, start_col);
        return 0;


    for (int i = 0; i < SHIP_SIZE; i++) {
        if (board[start_row + i][start_col] != WATER) {
            printf("Erro: Navio vertical em (%d,%d) se sobrepõe a outro navio.\n", start_row, start_col);
            return 0;
        }
    }

    for (int i = 0; i < SHIP_SIZE; i++) {
        board[start_row + i][start_col] = SHIP_PART;
    }
    return 1;
}

int placeDiagonalShip_IncInc(int board[BOARD_SIZE][BOARD_SIZE], int start_row, int start_col) {

    if (start_row < 0 || (start_row + SHIP_SIZE) > BOARD_SIZE ||
        start_col < 0 || (start_col + SHIP_SIZE) > BOARD_SIZE) {
        printf("Erro: Navio diagonal (inc/inc) fora dos limites em (%d,%d).\n", start_row, start_col);
        return 0;
    }

    for (int k = 0; k < SHIP_SIZE; k++) {
        if (board[start_row + k][start_col + k] != WATER) {
            printf("Erro: Navio diagonal (inc/inc) em (%d,%d) se sobrepõe a outro navio.\n", start_row, start_col);
            return 0;
        }
    }

    for (int k = 0; k < SHIP_SIZE; k++) {
        board[start_row + k][start_col + k] = SHIP_PART;
    }
    return 1;
}

int placeDiagonalShip_IncDec(int board[BOARD_SIZE][BOARD_SIZE], int start_row, int start_col) {

    if (start_row < 0 || (start_row + SHIP_SIZE) > BOARD_SIZE ||
        start_col < (SHIP_SIZE - 1) || start_col >= BOARD_SIZE) {
        printf("Erro: Navio diagonal (inc/dec) fora dos limites em (%d,%d).\n", start_row, start_col);
        return 0;
    }

    for (int k = 0; k < SHIP_SIZE; k++) {
        if (board[start_row + k][start_col - k] != WATER) {
            printf("Erro: Navio diagonal (inc/dec) em (%d,%d) se sobrepõe a outro navio.\n", start_row, start_col);
            return 0;
        }
    }

    for (int k = 0; k < SHIP_SIZE; k++) {
        board[start_row + k][start_col - k] = SHIP_PART;
    }
    return 1;
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = WATER;
        }
    }

    int all_ships_placed = 1;

    if (!placeHorizontalShip(board, 0, 0)) {
        all_ships_placed = 0;
    }

    if (all_ships_placed && !placeVerticalShip(board, 3, 9)) {
        all_ships_placed = 0;
    }

    if (all_ships_placed && !placeDiagonalShip_IncInc(board, 2, 2)) {
        all_ships_placed = 0;
    }

    if (all_ships_placed && !placeDiagonalShip_IncDec(board, 1, 8)) {
        all_ships_placed = 0;
    }


    printf("\n--- Tabuleiro do Batalha Naval ---\n");

    printf("   ");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("%2d ", col);
    }
    printf("\n");

    printf("   +");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("---");
    }
    printf("+\n");

    if (all_ships_placed) {
        for (int i = 0; i < BOARD_SIZE; i++) {
            printf("%2d |", i);
            for (int j = 0; j < BOARD_SIZE; j++) {
                printf("%2d ", board[i][j]);
            }
            printf("|\n");
        }
    } else {
        printf("\nNão foi possível posicionar todos os navios devido a erros de validação.\n");
    }

    printf("   +");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("---");
    }
    printf("+\n");

    return 0;
}





#include <stdio.h>
#include <math.h>

#define BOARD_SIZE
#define SHIP_SIZE
#define WATER
#define SHIP_PART
#define ABILITY_EFFECT
#define ABILITY_MATRIX_SIZE

int placeHorizontalShip(int board[BOARD_SIZE][BOARD_SIZE], int start_row, int start_col) {
    if (start_row < 0 || start_row >= BOARD_SIZE || start_col < 0 || (start_col + SHIP_SIZE) > BOARD_SIZE) {
        printf("Erro: Navio horizontal fora dos limites em (%d,%d).\n", start_row, start_col);
        return 0;
    }
    for (int j = 0; j < SHIP_SIZE; j++) {
        if (board[start_row][start_col + j] != WATER) {
            printf("Erro: Navio horizontal em (%d,%d) se sobrepõe a outro navio.\n", start_row, start_col);
            return 0;
        }
    }
    for (int j = 0; j < SHIP_SIZE; j++) {
        board[start_row][start_col + j] = SHIP_PART;
    }
    return 1;
}

int placeVerticalShip(int board[BOARD_SIZE][BOARD_SIZE], int start_row, int start_col) {
    if (start_row < 0 || (start_row + SHIP_SIZE) > BOARD_SIZE || start_col < 0 || start_col >= BOARD_SIZE) {
        printf("Erro: Navio vertical fora dos limites em (%d,%d).\n", start_row, start_col);
        return 0;
    }
    for (int i = 0; i < SHIP_SIZE; i++) {
        if (board[start_row + i][start_col] != WATER) {
            printf("Erro: Navio vertical em (%d,%d) se sobrepõe a outro navio.\n", start_row, start_col);
            return 0;
        }
    }
    for (int i = 0; i < SHIP_SIZE; i++) {
        board[start_row + i][start_col] = SHIP_PART;
    }
    return 1;
}

int placeDiagonalShip_IncInc(int board[BOARD_SIZE][BOARD_SIZE], int start_row, int start_col) {
    if (start_row < 0 || (start_row + SHIP_SIZE) > BOARD_SIZE || start_col < 0 || (start_col + SHIP_SIZE) > BOARD_SIZE) {
        printf("Erro: Navio diagonal (inc/inc) fora dos limites em (%d,%d).\n", start_row, start_col);
        return 0;
    }
    for (int k = 0; k < SHIP_SIZE; k++) {
        if (board[start_row + k][start_col + k] != WATER) {
            printf("Erro: Navio diagonal (inc/inc) em (%d,%d) se sobrepõe a outro navio.\n", start_row, start_col);
            return 0;
        }
    }
    for (int k = 0; k < SHIP_SIZE; k++) {
        board[start_row + k][start_col + k] = SHIP_PART;
    }
    return 1;
}

int placeDiagonalShip_IncDec(int board[BOARD_SIZE][BOARD_SIZE], int start_row, int start_col) {
    if (start_row < 0 || (start_row + SHIP_SIZE) > BOARD_SIZE || start_col < (SHIP_SIZE - 1) || start_col >= BOARD_SIZE) {
        printf("Erro: Navio diagonal (inc/dec) fora dos limites em (%d,%d).\n", start_row, start_col);
        return 0;
    }
    for (int k = 0; k < SHIP_SIZE; k++) {
        if (board[start_row + k][start_col - k] != WATER) {
            printf("Erro: Navio diagonal (inc/dec) em (%d,%d) se sobrepõe a outro navio.\n", start_row, start_col);
            return 0;
        }
    }
    for (int k = 0; k < SHIP_SIZE; k++) {
        board[start_row + k][start_col - k] = SHIP_PART;
    }
    return 1;
}

void createConeAbility(int cone_matrix[ABILITY_MATRIX_SIZE][ABILITY_MATRIX_SIZE]) {
    int center_col = ABILITY_MATRIX_SIZE / 2;

    for (int i = 0; i < ABILITY_MATRIX_SIZE; i++) {
        for (int j = 0; j < ABILITY_MATRIX_SIZE; j++) {
            int dist_from_center = abs(j - center_col);
            if (dist_from_center <= i) {
                cone_matrix[i][j] = 1;
            } else {
                cone_matrix[i][j] = 0;
            }
        }
    }
}

void createCrossAbility(int cross_matrix[ABILITY_MATRIX_SIZE][ABILITY_MATRIX_SIZE]) {
    int center = ABILITY_MATRIX_SIZE / 2;

    for (int i = 0; i < ABILITY_MATRIX_SIZE; i++) {
        for (int j = 0; j < ABILITY_MATRIX_SIZE; j++) {
            if (i == center || j == center) {
                cross_matrix[i][j] = 1;
            } else {
                cross_matrix[i][j] = 0;
            }
        }
    }
}

void createOctahedronAbility(int octahedron_matrix[ABILITY_MATRIX_SIZE][ABILITY_MATRIX_SIZE]) {
    int center = ABILITY_MATRIX_SIZE / 2;

    for (int i = 0; i < ABILITY_MATRIX_SIZE; i++) {
        for (int j = 0; j < ABILITY_MATRIX_SIZE; j++) {
            if (abs(i - center) + abs(j - center) <= center) {
                octahedron_matrix[i][j] = 1;
            } else {
                octahedron_matrix[i][j] = 0;
            }
        }
    }
}

void applyAbilityToBoard(int board[BOARD_SIZE][BOARD_SIZE],
                         int ability_matrix[ABILITY_MATRIX_SIZE][ABILITY_MATRIX_SIZE],
                         int origin_row, int origin_col) {

    int offset = ABILITY_MATRIX_SIZE / 2;

    for (int i = 0; i < ABILITY_MATRIX_SIZE; i++) {
        for (int j = 0; j < ABILITY_MATRIX_SIZE; j++) {
            int board_row = origin_row - offset + i;
            int board_col = origin_col - offset + j;

            if (board_row >= 0 && board_row < BOARD_SIZE &&
                board_col >= 0 && board_col < BOARD_SIZE) {
                if (ability_matrix[i][j] == 1) {
                    if (board[board_row][board_col] == WATER) {
                         board[board_row][board_col] = ABILITY_EFFECT;
                    }
                }
            }
        }
    }
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = WATER;
        }
    }

    int all_ships_placed = 1;

    if (!placeHorizontalShip(board, 0, 0)) {
        all_ships_placed = 0;
    }

    if (all_ships_placed && !placeVerticalShip(board, 3, 9)) {
        all_ships_placed = 0;
    }

    if (all_ships_placed && !placeDiagonalShip_IncInc(board, 2, 2)) {
        all_ships_placed = 0;
    }

    if (all_ships_placed && !placeDiagonalShip_IncDec(board, 1, 8)) {
        all_ships_placed = 0;
    }

    int cone_matrix[ABILITY_MATRIX_SIZE][ABILITY_MATRIX_SIZE];
    int cross_matrix[ABILITY_MATRIX_SIZE][ABILITY_MATRIX_SIZE];
    int octahedron_matrix[ABILITY_MATRIX_SIZE][ABILITY_MATRIX_SIZE];

    createConeAbility(cone_matrix);
    createCrossAbility(cross_matrix);
    createOctahedronAbility(octahedron_matrix);

    int cone_origin_row = 2;
    int cone_origin_col = 5;
    applyAbilityToBoard(board, cone_matrix, cone_origin_row, cone_origin_col);

    int cross_origin_row = 6;
    int cross_origin_col = 2;
    applyAbilityToBoard(board, cross_matrix, cross_origin_row, cross_origin_col);

    int octa_origin_row = 7;
    int octa_origin_col = 7;
    applyAbilityToBoard(board, octahedron_matrix, octa_origin_row, octa_origin_col);


    printf("\n--- Tabuleiro do Batalha Naval com Habilidades ---\n");

    printf("    ");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("%2d ", col);
    }
    printf("\n");

    printf("    +");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("---");
    }
    printf("+\n");

    if (all_ships_placed) {
        for (int i = 0; i < BOARD_SIZE; i++) {
            printf("%2d |", i);
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == WATER) {
                    printf(" ~ ");
                } else if (board[i][j] == SHIP_PART) {
                    printf(" S ");
                } else if (board[i][j] == ABILITY_EFFECT) {
                    printf(" X ");
                } else {
                    printf("%2d ", board[i][j]);
                }
            }
            printf("|\n");
        }
    } else {
        printf("\nNão foi possível posicionar todos os navios devido a erros de validação.\n");
    }

    printf("    +");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("---");
    }
    printf("+\n");

    return 0;
}