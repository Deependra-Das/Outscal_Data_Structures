#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void printBoxedSentence(const string& sentence)
{
    int length = sentence.length();
    cout << "+" << string(length + 2, '-') << "+" << endl;
    cout << "| " << sentence << " |" << endl;
    cout << "+" << string(length + 2, '-') << "+" << endl;
}

class Cell
{
public:
    bool isMine, isRevealed;
    char value;
    int adjacentMines;

    Cell() : isMine(false), isRevealed(false), value('-'), adjacentMines(0) {}
};

class MineSweeper
{
private:
	Cell** arrBoard;
	int rows, cols, minesCount;
    bool isInitialized;

    void countAdjacentCells()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (arrBoard[i][j].isMine)
                {
                    continue;
                }
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        int ni = i + x;
                        int nj = j + y;
                        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && arrBoard[ni][nj].isMine)
                        {
                            arrBoard[i][j].adjacentMines++;
                        }
                    }
                }

                if (arrBoard[i][j].adjacentMines > 0)
                {
                    arrBoard[i][j].value = '0' + arrBoard[i][j].adjacentMines;
                }
            }
        }
        isInitialized = true;
    }

public:

    MineSweeper(int r, int c, int m) : rows(r), cols(c), minesCount(m), arrBoard(nullptr), isInitialized(false)
    {
        srand(time(0));
        arrBoard = new Cell * [rows];
        for (int i = 0; i < rows; i++)
        {
            arrBoard[i] = new Cell[cols];
        }
    }

    ~MineSweeper() 
    {
        if (arrBoard != nullptr)
        {
            for (int i = 0; i < rows; i++)
            {
                delete[] arrBoard[i];
            }
            delete[] arrBoard;
            arrBoard = nullptr;
        }
    }

    void initializeBoard(int firstRow, int firstCol)
    {
        int count = 0;
        while (count < minesCount)
        {
            int r = rand() % rows;
            int c = rand() % cols;

            if (!arrBoard[r][c].isMine && !(r == firstRow && c == firstCol) && (r<firstRow - 1 || r> firstRow + 1 || c< firstCol - 1 || c> firstCol + 1))
            {
                arrBoard[r][c].isMine = true;
                count++;
            }
        }

        countAdjacentCells();
    }

    void printBoard(bool revealMines = false)
    {
        cout << endl;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (arrBoard[i][j].isRevealed)
                {
                    cout << arrBoard[i][j].value << " ";
                }
                else
                {
                    if (revealMines && arrBoard[i][j].isMine)
                    {
                        cout << "* ";
                    }
                    else
                    {
                        cout << "- ";
                    }
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    bool revealCell(int r, int c)
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols || arrBoard[r][c].isRevealed)
        {
            return true;
        }

        arrBoard[r][c].isRevealed = true;
        
        if (arrBoard[r][c].isMine)
        {
            arrBoard[r][c].value = '*';
            return false;
        }

        if (arrBoard[r][c].adjacentMines == 0)
        {
            arrBoard[r][c].value = '0';

            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    revealCell(r + x, c + y);
                }
            }
        }
        return true;
    }

    bool checkWin()
    {
        int revealedCells = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (arrBoard[i][j].isRevealed)
                {
                    revealedCells++;
                }
            }
        }
        return revealedCells == (rows * cols - minesCount);
    }

    void play()
    {
        int moves = 0;
        bool isGameOver = false, isInitialized= false;
        int firstRow, firstCol;

        while (!isInitialized)
        {
            cout << "\n\nTo start playing, enter your first move: " << endl;
            cout << "Row (0-" << rows - 1 << ") : ";
            cin >> firstRow;
            cout << "Column (0-" << cols - 1 << ") : ";
            cin >> firstCol;

            if (firstRow < 0 || firstRow >= rows || firstCol < 0 || firstCol >= cols)
            {
                cout << "Invalid Input. Try Again." << endl;
                isInitialized = false;
            }
            else
            {
                isInitialized = true;
                initializeBoard(firstRow, firstCol);
                isGameOver = !revealCell(firstRow, firstCol);
                moves++;
                if (checkWin())
                {
                    printBoxedSentence("Congratulations! You won the game!");
                    isGameOver = true;
                }
                //printBoard(true); // to check the mine positions
                printBoard();
            }
        }

        int totalMoves = rows * cols - minesCount;
      
        while (!isGameOver && moves < totalMoves)
        {
            int rValue, cValue;

            cout << "Moves Left : " << totalMoves - moves<<endl;
            cout << "Enter your next move:" << endl;
            cout << "Row (0-" << rows - 1 << ") : ";
            cin >> rValue;
            cout << "Column (0-" << cols - 1 << ") : ";
            cin >> cValue;

            if (rValue < 0 || rValue >= rows || cValue < 0 || cValue >= cols)
            {
                cout << "Invalid Input. Try Again." << endl;
                continue;
            }

            isGameOver = !revealCell(rValue, cValue);
            moves++;
            printBoard();

            if (isGameOver)
            {
                printBoxedSentence("Game Over! You hit a mine!");
                printBoard(true);
            }
            else if (checkWin())
            {
                printBoxedSentence("Congratulations! You won the game!");
                printBoard();
                break;
            }
        }

        if (moves >= totalMoves)
        {
            printBoxedSentence("You are out of Moves!");
        }

        printBoxedSentence("Game has Ended | Thank you for Playing");

    }
};

int main()
{
    int rows, cols, minesCount, minValue=9;

    printBoxedSentence("Welcome to Minesweeper");

    cout << "\n\nRULES: "<<endl;
    cout << "1. The board is divided into cells, with mines randomly distributed." << endl;
    cout << "2. To win, you need to open all the cells in limited number of moves." << endl;
    cout << "3. The number on a cell reveals the number of mines adjacent to it." << endl;
    cout << "4. Use the revealed cells to determine whether the next cell is safe or contains mine." << endl;

    cout << "\n\nHow to Play: "<<endl;
    cout << "1. Player will input x & y cooardinates where they want to click to open cell." << endl;
    cout << "2. On every step, win & lose conditions will be checked then board will be printed." << endl<<endl<<endl;

    do {
        cout << "Enter number of rows (>="<< minValue<<"):";
        cin >> rows;
        if (rows < minValue) {
            cout << "Error: Number of rows must be at least " << minValue << "!"<< endl;
        }
    } while (rows < minValue);

    do {
        cout << "Enter number of columns (>=" << minValue << "):";
        cin >> cols;
        if (cols < minValue) {
            cout << "Error: Number of columns must be at least " << minValue << "!" << endl;
        }
    } while (cols < minValue);

    do {
        cout << "Enter number of mines (<= " << (rows * cols) / 2 << " and >= 1): ";
        cin >> minesCount;
        if (minesCount < 1 || minesCount >(rows * cols) / 2) {
            cout << "Error: Mines count must be between 1 and " << (rows * cols)/2 << "!" << endl;
        }
    } while (minesCount < 1 || minesCount > (rows * cols) / 2);

    MineSweeper newGame(rows, cols, minesCount);

    newGame.play();
	return 0;
} 