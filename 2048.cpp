#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>
#include <windows.graphics.h>
#include <fstream>


using namespace std;
const int maxScore = 5;
const int TOP_SCORES = 5;
int score = 0;

void arrowkeys(int grid[][4]);
void saveScore(int newScore);
void displayScores();

void displayInstructions()
{
    cout << "***********************************************" << endl;
    cout << "*                                             *" << endl;
    cout << "*               HOW TO PLAY:                  *" << endl;
    cout << "*                                             *" << endl;
    cout << "***********************************************" << endl;
    cout << "*                                             *" << endl;
    cout << "*  Use your arrow keys to move the tiles      *" << endl;
    cout << "*  and they will merge into one!              *" << endl;
    cout << "*                                             *" << endl;
    cout << "*  W : up    S : down    A : left    D : right*" << endl;
    cout << "*                                             *" << endl;
    cout << "*  N : new game    X : exit                   *" << endl;
    cout << "*                                             *" << endl;
    cout << "*  Add them up to reach 2048!                 *" << endl;
    cout << "*                                             *" << endl;
    cout << "***********************************************" << endl;
    cout << "*                                             *" << endl;
    cout << "*          Press any key to play              *" << endl;
    cout << "*                                             *" << endl;
    cout << "***********************************************" << endl;
}

void start(int x)
{
    system("Color E5");
    system("cls");
    switch (x)
    {
    case 0:
        int ss;
        displayInstructions();
        _getch();
        system("cls");
        break;
    case 1:
        system("cls");
        break;
    }

}

void startingconsole()
{
    system("Color 64");     //E->background color     4->text color  2,3,6,7
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "                                          **********************************" << endl;
    cout << "                                          *                                *" << endl;
    cout << "                                          *      WELCOME TO 2048 GAME      *" << endl;
    cout << "                                          *                                *" << endl;
    cout << "                                          **********************************" << endl;
    cout << "                                          Press any key to continue" << endl;
    _getch();   //wait for key press
    system("cls");   //clear console
    int step1;
    system("Color 6C");        //5,C
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "                                          **********************************" << endl;
    cout << "                                          *                                *" << endl;
    cout << "                                          *        SELECT AN OPTION        *" << endl;
    cout << "                                          *                                *" << endl;
    cout << "                                          **********************************" << endl;
    cout << "                                          *                                *" << endl;
    cout << "                                          *  0: INSTRUCTIONS               *" << endl;
    cout << "                                          *                                *" << endl;
    cout << "                                          *  Others: START                 *" << endl;
    cout << "                                          *                                *" << endl;
    cout << "                                          **********************************" << endl;
    cin >> step1;
    start(step1);
}

void contgame(int gr[4][4])
{
    system("Color E3");
    int flag = 1;


    while (flag)
    {
        srand(time(0));
        int i = rand() % 4;
        int j = rand() % 4;
        int l = rand() % 3 + 1;


        if (gr[i][j] == 0)
        {
            if (l % 2 == 0)
            {
                gr[i][j] = l;
                flag = 0;
                break;
            }
            else {
                gr[i][j] = l + 1;
                flag = 0;
                break;
            }
        }
        else
        {
            continue;
        }
    }
    cout << "  ___________________________________" << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << " | ";
            if (gr[i][j] == 0)
            {
                cout << setw(4) << " " << "  ";
            }
            else
            {
                cout << setw(4) << gr[i][j] << "  ";
            }
        }
        cout << " |" << endl;
        cout << " |________|________|________|________|" << endl;
    }
    cout << " _________________________" << endl << endl;
}
// game beginning


void down(int gr[4][4])
{
    int i;
    for (int j = 0; j < 4; j++)
    {
        i = 2;
        while (true)
        {
            while (gr[i][j] == 0)
            {
                if (i == -1)
                    break;
                i--;
            }
            if (i == -1)
                break;
            while (i < 4 - 1 && (gr[i + 1][j] == 0 || gr[i][j] == gr[i +
                1][j]))
            {
                if (gr[i][j] == gr[i + 1][j])
                {
                    int scor = gr[i + 1][j] + gr[i][j];

                    score = score + scor;
                }
                gr[i + 1][j] += gr[i][j];
                gr[i][j] = 0;

                i++;

            }
            i--;
        }
    }
}

void up(int gr[4][4])
{
    int i;
    for (int j = 0; j < 4; j++)
    {
        i = 1;   //bcz row 0 is top most
        while (true)
        {
            while (gr[i][j] == 0)
            {
                if (i == 4)
                    break;
                i++;
            }
            if (i == 4)
                break;
            while (i > 0 && (gr[i - 1][j] == 0 || gr[i][j] == gr[i - 1][j]))
            {
                if (gr[i][j] == gr[i - 1][j])
                {
                    int scor = gr[i - 1][j] + gr[i][j];

                    score = score + scor;
                }
                gr[i - 1][j] += gr[i][j];
                gr[i][j] = 0;
                i--;
            }
            i++;
        }
    }
}

void right(int gr[4][4])
{
    int j;
    for (int i = 0; i < 4; i++)
    {
        j = 2;
        while (true)
        {
            while (gr[i][j] == 0)
            {
                if (j == -1)
                    break;
                j--;
            }
            if (j == -1)
                break;
            while (j < 4 - 1 && (gr[i][j + 1] == 0 || gr[i][j] == gr[i][j +
                1]))
            {
                if (gr[i][j] == gr[i][j + 1])
                {
                    int scor = gr[i][j + 1] + gr[i][j];

                    score = score + scor;
                }
                gr[i][j + 1] += gr[i][j];
                gr[i][j] = 0;
                j++;

            }
            j--;
        }
    }
}

void left(int gr[4][4])
{
    int j;
    for (int i = 0; i < 4; i++)
    {
        j = 1;
        while (true)
        {
            while (gr[i][j] == 0)
            {
                if (j == 4)
                    break;
                j++;
            }
            if (j == 4)
                break;
            while (j > 0 && (gr[i][j - 1] == 0 || gr[i][j] == gr[i][j - 1]))
            {
                if (gr[i][j] == gr[i][j - 1])
                {
                    int scor = gr[i][j - 1] + gr[i][j];

                    score = score + scor;
                }
                gr[i][j - 1] += gr[i][j];
                gr[i][j] = 0;
                j--;
            }
            j++;

        }
    }
}

void scorerec(int x)
{
    system("Color E3");
    cout << "          score: " << score << endl << endl;
    cout << " _________________________" << endl;

    displayScores();
}

void startnum(int grid[][4])
{

    for (int l = 0; l < 2; l++)    //placing 4 randomly in grid
    {
        int i = rand() % 4;
        int j = rand() % 4;

        grid[i][j] = 4;
    }


    for (int l = 0; l < 2; l++)     //placing 2 randomly in grid
    {
        int i = rand() % 4;
        int j = rand() % 4;

        grid[i][j] = 2;
    }
    system("Color E3");
    cout << "  ___________________________________" << endl;
    for (int i = 0; i < 4; i++)   //rows
    {
        for (int j = 0; j < 4; j++)   //coloumns
        {
            cout << " | ";
            if (grid[i][j] == 0)   //spaces
            {
                cout << setw(4) << " " << "  ";
            }
            else
            {
                cout << setw(4) << grid[i][j] << "  ";
            }
        }cout << " |" << endl;
        cout << " |________|________|________|________|" << endl;
    }
    system("Color E3");
    cout << " _________________________" << endl << endl;
    cout << "          score: " << score << endl << endl;
    cout << " _________________________" << endl << endl;

    displayScores();
}  // second apperance

void resetgame()
{
    int grid[4][4] = { {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} };
    startnum(grid);
    arrowkeys(grid);
}

void wincheck(int grid[4][4])
{
    system("Color E3");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (grid[i][j] == 16)
            {
                char x;
                system("cls");
                cout << "    YOU WON!  " << endl;
                cout << "  _____________________" << endl;
                cout << "  Total Score: " << score << endl;
                cout << "  _____________________" << endl << endl;
                cout << "  Do you want to play again? (y/n)" << endl;
                saveScore(score);
                cin >> x;
                system("cls");
                if (tolower(x) == 'y')
                {
                    score = 0;
                    resetgame();
                }
                else
                {
                    system("cls");
                    cout << endl << endl << endl;
                    cout << "-------------------Thanks for playing-----------------" << endl << endl;
                    exit(x);
                    break;
                }
                break;
            }
        }
    }
}

int gameover(int gr[4][4])
{
    system("Color E3");
    int movepossible = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (gr[i][j] == 0 || (gr[i][j] == gr[i][j - 1] || gr[i][j] ==
                gr[i][j + 1] || gr[i][j] == gr[i - 1][j] || gr[i][j] == gr[i + 1][j]))
            {
                movepossible++;
            }
        }
    }
    if (movepossible == 0)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}
void arrowkeys(int grid[4][4])
{

    for (int i = 0; i < 10000; i++)
    {
        char x;
        cin >> x;


        if (toupper(x) == 'W')
        {
            system("cls");
            up(grid);
        }
        else if (toupper(x) == 'A')
        {
            system("cls");
            left(grid);
        }
        else if (toupper(x) == 'S')
        {
            system("cls");
            down(grid);
        }
        else if (toupper(x) == 'D')
        {
            system("cls");
            right(grid);
        }
        else if (toupper(x) == 'N')
        {
            score = 0;
            system("cls");
            resetgame();
            arrowkeys(grid);
            continue;
        }
        else if (toupper(x) == 'X')
        {
            system("cls");
            cout << endl << endl;
            cout << "-------------------Thanks for playing-----------------" << endl << endl;
            exit(x);
        }
        else
        {
            continue;
        }
        contgame(grid);  //add random tile and upgrade the grid
        scorerec(score);
        wincheck(grid);
        if (gameover(grid))   //if any possible moves are available
        {
            system("Color E4");
            system("cls");
            cout << "---------------Gameover--------------" << endl << "Total score : " << score << endl;
            saveScore(score);
            break;
        }
    }
}


void saveScore(int newScore)
{
    int scores[maxScore] = { 0 };
    ifstream infile("file.txt");
    for (int i = 0; i < maxScore; i++)
    {
        infile >> scores[i];
    }
    infile.close();
    if (newScore <= scores[maxScore - 1])
    {
        return;
    }

    scores[maxScore - 1] = newScore;

    for (int i = 0; i < maxScore; i++)
    {
        for (int j = i + 1; j < maxScore; j++)
        {
            if (scores[j] > scores[i])
            {
                int temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
            }
        }
    }

    ofstream outfile("file.txt");
    for (int i = 0; i < maxScore; i++)
    {
        outfile << scores[i] << endl;
    }
    outfile.close();
}

void displayScores()
{
    ifstream infile("file.txt");
    if (!infile) 
    {
        cout << "Error opening file." << endl;
        return;
    }

    cout << "Top Scores:" << endl;
    int score;
    while (infile >> score)
    {
        cout << score << endl;
    }
    infile.close();
}


int main()
{
    int grid[4][4] = { {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} };

    startingconsole();
    startnum(grid);
    arrowkeys(grid);
}