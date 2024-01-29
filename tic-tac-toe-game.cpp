#include <iostream>
using namespace std;
#include <cstdlib>

void initializeBoard(char board[3][3]);
void displayBoard(const char board[3][3]);
bool makeMove(char board[3][3], char player, int row, int col);
bool checkWin(const char board[3][3], char player);
bool checkDraw(const char board[3][3]);
bool isValidMove(const char board[3][3], int row, int col);

int main()
{
    char board[3][3];
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    initializeBoard(board);

    do
    {
        system("cls");
        displayBoard(board);

        int row, col;
        do
        {
            cout << "\nPlayer " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;
        } while (!isValidMove(board, row, col));

        makeMove(board, currentPlayer, row, col);

        gameWon = checkWin(board, currentPlayer);
        gameDraw = checkDraw(board);

        // Switch players only if the game is still ongoing
        if (!gameWon && !gameDraw)
        {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

    } while (!gameWon && !gameDraw);

    system("cls");
    displayBoard(board);

    if (gameWon)
    {
        cout << "\nPlayer " << currentPlayer << " wins!" << endl
             << endl;
    }
    else
    {
        cout << "\nIt's a draw!\n"
             << endl;
    }

    return 0;
}

void initializeBoard(char board[3][3])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(const char board[3][3])
{
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; ++i)
    {
        cout << i << " ";
        for (int j = 0; j < 3; ++j)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool makeMove(char board[3][3], char player, int row, int col)
{
    if (board[row][col] == ' ')
    {
        board[row][col] = player;
        return true;
    }
    else
    {
        cout << "\nInvalid move. Try again.\n"
             << endl;
        return false;
    }
}

bool checkWin(const char board[3][3], char player)
{
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true; // Row win
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return true; // Column win
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true; // Diagonal win (top-left to bottom-right)
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return true; // Diagonal win (top-right to bottom-left)
    }
    return false;
}

bool checkDraw(const char board[3][3])
{
    // Check if the board is full (no empty spaces left)
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == ' ')
            {
                return false; // There is an empty space, the game is not a draw
            }
        }
    }
    return true; // The board is full, it's a draw
}

bool isValidMove(const char board[3][3], int row, int col)
{
    // Check if the chosen position is within the board and is empty
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
}
