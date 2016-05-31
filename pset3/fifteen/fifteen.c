/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
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
 * Functions init(), draw(), move(), and won() by Tim Hodge
 * 
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

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
    FILE* file = fopen("log.txt", "w");
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
        int tile = GetInt();
        
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
        usleep(500000);
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
    printf("\033[%d;%dH", 1, 1);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("Welcome to the game of Fifteen!\n");
    usleep(2000000);
}

/**
 * init()
 * 2016-05-30 Tim Hodge
 * 
 *  - Initializes the game's board with tiles numbered 1 through d*d - 1
 *  - Sets last tile to 0 (which we print as an underscore)
 *  - If there are an odd set of numbers on the board, switch numbers 1 and 2
 */
void init(void)
{
    // Fill in the board with all the numbers, descending from start to finish
    for ( int i=(d*d)-1, row = 0; row < d; row++ )
        for ( int column = 0; column < d; column++, i-- )
            board[row][column] = i;
    
    // swap positions of 1 and 2 if necessary
    if ( (d*d)%2 == 0 ) {
        int temp = board[d-1][d-3];
        board[d-1][d-3] = board[d-1][d-2];
        board[d-1][d-2] = temp;
    }
    
    // set the last tile to 0 (i.e. space or underscore)
    board[d-1][d-1] = 0;
}

/**
 * draw()
 * 2016-05-30 Tim Hodge
 * 
 * - Prints the board in its current state.
 * - Displays 0 as an underscore
 */
void draw(void)
{
    for ( int row = 0, underscore=95; row < d; row++ ) {
        for ( int column = 0; column < d; column++ )
            if ( board[row][column] == 0 )
                printf("%5c", underscore);
            else
                printf("%5i", board[row][column]);
        printf("\n");
    }

}

/**
 * move()
 * 2016-05-30 Tim Hodge
 * 
 * - If tile borders empty space, moves tile and returns true
 */
bool move(int tile)
{
    int spaceRow, spaceCol, tileRow, tileCol;
    
    // where is the space?
    for ( int row = 0; row < d; row++ )
        for ( int col = 0; col < d; col++ )
            if ( board[row][col] == 0 ) {
                spaceRow = row;
                spaceCol = col;
            }

    // where is the chosen tile?
    for ( int row = 0; row < d; row++ )
        for ( int col = 0; col < d; col++ )
            if ( board[row][col] == tile ) {
                tileRow = row;
                tileCol = col;
            }

    // is the tile adjacent to the space?
    if ( (( tileCol == spaceCol ) && ( ( tileRow == spaceRow - 1 ) || ( tileRow == spaceRow + 1 ) )) ||
        (( tileRow == spaceRow ) && ( ( tileCol ==  spaceCol - 1 ) || ( tileCol == spaceCol + 1 ) )) ) {
        
        // if so, swap positions
        board[spaceRow][spaceCol] = tile;
        board[tileRow][tileCol] = 0;

        return true;
    }

    return false;
}

/**
 * won()
 * 2015-05-31 Tim Hodge
 * 
 * - Returns true if game is won - i.e. numbers in order - else false
 */
bool won(void)
{
    
    // check first and last spaces, don't bother sorting if we're not ready
    if ( board[0][0] != 1 || board[d-1][d-1] != 0 )
        return false;
    
    // initiliaze a counter - for each tile that is in order we will increment
    // we assume if you passed the previous check, the first box is in order
    int inOrder = 1;
    
    // step through the matrix, compare each tile to the previous tile prevBox
    // each time a tile is in order, increment the counter inOrder
    for ( int row = 0, prevBox=0; row < d; row++ ) {
        for ( int col = 0; col < d; col++ ) {
            if ( board[row][col] == prevBox + 1 ) {
                inOrder = inOrder + 1;
                prevBox = board[row][col];
            }
        }
    }
    
    // if the last tile is the space then increase the counter
    if ( board[d-1][d-1] == 0 )
        inOrder = inOrder + 1;

    if ( inOrder == (d*d) + 1 )
        return true;
    else
        return false;
}