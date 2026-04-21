#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int boardSize = 4;

struct Game
{
    int board[boardSize][boardSize];
};

void displayboard(const Game &grid);
bool isGameWon(int *ptr);
bool isGameOver(int board[4][4]);
void newTile(int board[4][4]);
void shiftUp(int board[4][4]);
void shiftDown(int board[4][4]);
void shiftLeft(int board[4][4]);
void shiftRight(int board[4][4]);
void upmove(int board[4][4]);
void leftmove(int board[4][4]);
void rightmove(int board[4][4]);
void downmove(int board[4][4]);

int main()
{
    // Initialize structure (0 for all indexes)
    Game grid;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            grid.board[i][j] = 0;
        }
    }

    int *ptr = &grid.board[0][0];

    int menu;
    do
    {
        cout << endl;
        cout << "-----------------2048 GAME-----------------" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "1. Resume Last Game" << endl;
        cout << "2. Start New Game" << endl;
        cout << "3. Show Instructions" << endl;
        cout << "4. Exit" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Enter your choice : ";
        cin >> menu;

        if (menu == 1 || menu == 2)
        {
            if (menu == 1)
            {
                ifstream infile("2048.txt");
                if (!infile)
                {
                    cout << endl;
                    cout << "Error loading game..." << endl;
                    continue;;
                }
                else
                {
                    for (int row = 0; row < boardSize; row++)
                    {
                        for (int col = 0; col < boardSize; col++)
                        {
                            infile >> grid.board[row][col];
                        }
                    }
                    infile.close();
                }
            }

            if (menu == 2)
            {
                newTile(grid.board);
            }

            cout << endl;
            cout << "Controls :" << endl;
            cout << "Use keys (A, W, S, D) to move tiles in desired location." << endl;
            cout << "Enter 0 to save current game and back to Main Menu." << endl;

            bool gameplay = true;

            while (gameplay)
            {
                system("cls");
                // Display board
                displayboard(grid);

                // Input for move
                char move;
                cout << endl;
                cout << "Enter your move direction : ";
                cin >> move;

                // Perform move
                if (move == 'a' || move == 'A')
                {
                    leftmove(grid.board);
                }
                else if (move == 'w' || move == 'W')
                {
                    upmove(grid.board);
                }
                else if (move == 's' || move == 'S')
                {
                    downmove(grid.board);
                }
                else if (move == 'd' || move == 'D')
                {
                    rightmove(grid.board);
                }
                else if (move == '0')
                {
                    ofstream outfile("2048.txt");
                    for (int row = 0; row < boardSize; row++)
                    {
                        for (int col = 0; col < boardSize; col++)
                        {
                            outfile << grid.board[row][col] << "\t";
                        }
                        outfile << endl;
                    }
                    outfile.close();

                    cout << "Game saved successfully." << endl;
                    break;
                }

                if (move == 'a' || move == 'A' || move == 'w' || move == 'W' || move == 's' || move == 'S' || move == 'd' || move == 'D')
                {
                    newTile(grid.board);
                }
                else
                {
                    cout << "Invalid Move!" << endl;
                }

                system("cls");
                // Display board
                displayboard(grid);

                // Check for Win or GameOver
                if (isGameWon(ptr))
                {
                    cout << "YOU WON!" << endl;
                    gameplay = false;
                }

                if (isGameOver(grid.board))
                {
                    cout << "Game Over!" << endl;
                    gameplay = false;
                }
            }
        }

        if (menu == 3)
        {
            // Display Instructions
            cout << endl;
            cout << "How to Play :" << endl;
            cout << "1. Controls : Use keys (A, W, S, D) to move tiles in desired location." << endl;
            cout << "2. Tiles : Each tile is a power of 2 (2, 4, 8, 16, 32...)." << endl;
            cout << "3. New Tile : On each move a random (0) tile will be changed to 2." << endl;
            cout << "4. Combine Tiles : Tiles with the same number combine into one tile with double the value." << endl;
            cout << "5. Game Over : The game ends when no moves are left." << endl;
            cout << "6. Winning : You win by creating the 2048 tile." << endl;
        }
    } while (menu < 4);
}

void displayboard(const Game &grid)
{
    cout << endl;
    for (int row = 0; row < boardSize; row++)
    {
        cout << "+-------+-------+-------+-------+" << endl;
        for (int col = 0; col < boardSize; col++)
        {
            if (grid.board[row][col] == 0)
            {
                cout << "|  " << setw(5) << " ";
            }
            else
            {
                cout << "|  " << setw(5) << grid.board[row][col];
            }
        }
        cout << "|" << endl;
    }
    cout << "+-------+-------+-------+-------+" << endl;
    cout << endl;
}

bool isGameWon(int *ptr)
{
    for (int i = 0; i < 16; i++)
    {
        if (*(ptr + i) == 2048)
        {
            return true;
        }
    }
    return false;
}

bool isGameOver(int board[4][4])
{
    for (int row = 0; row < boardSize; row++)
    {
        for (int col = 0; col < boardSize; col++)
        {
            if (board[row][col] == 0)
            {
                return false;
            }
        }
    }

    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (col + 1 < boardSize && board[row][col] == board[row][col + 1])
            {
                return false;
            }

            if (row + 1 < boardSize && board[row][col] == board[row + 1][col])
            {
                return false;
            }
        }
    }

    return true;
}

void newTile(int board[4][4])
{
    int emptyCount = 0;
    int *empty = new int[16 * 2];

    for (int row = 0; row < boardSize; row++)
    {
        for (int col = 0; col < boardSize; col++)
        {
            if (board[row][col] == 0)
            {
                empty[emptyCount * 2] = row;
                empty[emptyCount * 2 + 1] = col;
                emptyCount++;
            }
        }
    }

    if (emptyCount > 0)
    {
        int randomIndex = rand() % emptyCount;
        int newRow = empty[randomIndex * 2];
        int newCol = empty[randomIndex * 2 + 1];
        board[newRow][newCol] = 2;
    }

    delete[] empty;
}

void shiftUp(int board[4][4])
{
    for (int col = 0; col < boardSize; col++)
    {
        for (int row = 0; row < 3; row++)
        {
            if (board[row][col] == 0)
            {
                for (int i = row; i < 3; i++)
                {
                    board[i][col] = board[i + 1][col];
                    board[i + 1][col] = 0;
                }
            }
        }
    }
}

void shiftDown(int board[4][4])
{
    for (int col = 0; col < boardSize; col++)
    {
        for (int row = boardSize - 1; row > 0; row--)
        {
            if (board[row][col] == 0)
            {
                for (int i = row; i > 0; i--)
                {
                    board[i][col] = board[i - 1][col];
                    board[i - 1][col] = 0;
                }
            }
        }
    }
}

void shiftLeft(int board[4][4])
{
    for (int row = 0; row < boardSize; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (board[row][col] == 0)
            {
                for (int i = col; i < 3; i++)
                {
                    board[row][i] = board[row][i + 1];
                    board[row][i + 1] = 0;
                }
            }
        }
    }
}

void shiftRight(int board[4][4])
{
    for (int row = 0; row < boardSize; row++)
    {
        for (int col = boardSize - 1; col > 0; col--)
        {
            if (board[row][col] == 0)
            {
                for (int i = col; i > 0; i--)
                {
                    board[row][i] = board[row][i - 1];
                    board[row][i - 1] = 0;
                }
            }
        }
    }
}

void upmove(int board[4][4])
{
    shiftUp(board);

    for (int col = 0; col < boardSize; col++)
    {
        for (int row = 0; row < 3; row++)
        {
            if (board[row][col] == board[row + 1][col] && board[row][col] != 0)
            {
                board[row][col] = board[row][col] * 2;
                board[row + 1][col] = 0;
            }
        }
    }

    shiftUp(board);
}

void leftmove(int board[4][4])
{
    shiftLeft(board);

    for (int row = 0; row < boardSize; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (board[row][col] == board[row][col + 1] && board[row][col] != 0)
            {
                board[row][col] = board[row][col] * 2;
                board[row][col + 1] = 0;
            }
        }
    }

    shiftLeft(board);
}

void rightmove(int board[4][4])
{
    shiftRight(board);

    for (int row = 0; row < boardSize; row++)
    {
        for (int col = boardSize - 1; col > 0; col--)
        {
            if (board[row][col] == board[row][col - 1] && board[row][col] != 0)
            {
                board[row][col] = board[row][col] * 2;
                board[row][col - 1] = 0;
            }
        }
    }

    shiftRight(board);
}

void downmove(int board[4][4])
{
    shiftDown(board);

    for (int col = 0; col < boardSize; col++)
    {
        for (int row = boardSize - 1; row > 0; row--)
        {
            if (board[row][col] == board[row - 1][col] && board[row][col] != 0)
            {
                board[row][col] = board[row][col] * 2;
                board[row - 1][col] = 0;
            }
        }
    }

    shiftDown(board);
}