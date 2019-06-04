/**
 * fifteen.c
 *
 * CS50 AP
 * Fifteen
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 *
 * Extra features including printing an actual grid to make it look more
 * tile-like, and using ANSI color sequences for some additional customizing
 */

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// ansi escape sequence to print grid color
// replace the number beteen [ and m with 31 for red, 32 for green, 33 for brown,
// 34 for blue, 35 for purple, 36 for cyan, 37 for gray
#define COLOR "\033[32m"

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// placeholder variable for swap
int placeHolder;

// placeholder for blank space
string null = "_";

// saved locations of the blank tile
int blank_row;
int blank_col;
int subConstant = 0;
bool winBool = false;

// saved locations of attempted move tile
int tile_row;
int tile_col;

// prototypes
void clear(void);

void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void swap(int a, int b);
void print_grid_row(int d);
void print_tile(int tile);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
               DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();

        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(50000);
    }

    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).
 */

int find(int tilE)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == tilE)
            {
                tile_row = i;
                tile_col = j;
            }
        }
    }
    return 0;
}

void swap(int a, int b)
{
    find(a);
    board[tile_row][tile_col] = b;
    find(b);
    board[blank_row][blank_col] = a;
}

void init(void)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            board[i][j] = ((pow(d, 2) - 1) - subConstant);
            subConstant++;
        }
    }
    if (d % 2 == 0)
    {
        board[d - 1][d - 3] = 1;
        board[d - 1][d - 2] = 2;
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == 0)
            {
                printf("%4s", null);
            }
            else
            {
                printf("%4i", board[i][j]);
            }
        }
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 */
bool move(int tile)
{
    find(0);
    blank_row = tile_row;
    blank_col = tile_col;
    find(tile);
    if (((abs(tile_row - blank_row) == 1) && (abs(tile_col - blank_col) == 0)) || ((abs(tile_row - blank_row) == 0)
            && (abs(tile_col - blank_col) == 1)))
    {
        swap(tile, 0);
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */
bool won(void)
{
    int winConstant = 1;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == winConstant)
            {
                winBool = true;
            }
            else if ((i == d - 1 && j == d - 1) && (board[i][j] == 0))
            {
                printf("");
            }
            else
            {
                winBool = false;
            }
            winConstant++;
        }
    }
    if (winBool == true && board[d - 1][d - 1] == 0)
    {
        return true;
    }
    return false;
}
