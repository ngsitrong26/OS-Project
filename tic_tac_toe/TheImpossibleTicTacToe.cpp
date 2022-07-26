#include <iostream>
#include <string>
#include <conio.h>
#include <algorithm>
#include "../src/color/color.h"
#include "../src/commands/help/help.h"
using std::cin;
using std::max;
using std::min;
using std::to_string;

int playerWin = 0;
int AIWin = 0;
const string player = "x", ai = "o";

// Unbeatable AI

void resetBoard(string board[3][3])
{
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      board[i][j] = " ";
}

bool isMoveLeft(string board[3][3])
{
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (!board[i][j].compare(" "))
        return true;
  return false;
}

int eval(string board[3][3])
{
  // check row win
  for (int i = 0; i < 3; i++)
  {
    if ((board[i][0].compare(board[i][1]) == 0) && (board[i][2].compare(board[i][1]) == 0))
    {
      if (!board[i][0].compare(ai))
      {
        return 10;
      }
      else if (!board[i][0].compare(player))
      {
        return -10;
      }
    }
  }
  for (int i = 0; i < 3; i++)
  {
    if ((board[0][i].compare(board[1][i]) == 0) && (board[2][i].compare(board[1][i]) == 0))
    {
      if (!board[0][i].compare(ai))
      {
        return 10;
      }
      else if (!board[0][i].compare(player))
      {
        return -10;
      }
    }
  }
  if ((board[0][0].compare(board[1][1]) == 0) && (board[2][2].compare(board[1][1]) == 0))
  {
    if (!board[0][0].compare(ai))
    {
      return 10;
    }
    else if (!board[0][0].compare(player))
    {
      return -10;
    }
  }
  if ((board[0][2].compare(board[1][1]) == 0) && (board[2][0].compare(board[1][1]) == 0))
  {
    if (!board[0][2].compare(ai))
    {
      return 10;
    }
    else if (!board[0][2].compare(player))
    {
      return -10;
    }
  }
  return 0;
}

int minimax(string board[3][3], int depth, bool isMax)
{
  int score = eval(board);
  if (score == 10 || score == -10)
    return score;
  if (!isMoveLeft(board))
    return 0;
  if (isMax)
  {
    int best = -1000;
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        if (!board[i][j].compare(" "))
        {
          board[i][j] = ai;
          best = max(best, minimax(board, depth + 1, !isMax));
          board[i][j] = " ";
        }
      }
    }
    return best;
  }
  else
  {
    int best = 1000;
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        if (!board[i][j].compare(" "))
        {
          board[i][j] = player;
          best = min(best, minimax(board, depth + 1, !isMax));
          board[i][j] = " ";
        }
      }
    }
    return best;
  }
}

int findBestMove(string board[3][3])
{
  int best = -1000;
  int bestMove = -1;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (!board[i][j].compare(" "))
      {
        board[i][j] = ai;
        int moveVal = minimax(board, 0, false);
        board[i][j] = " ";
        if (moveVal > best)
        {
          best = moveVal;
          bestMove = i * 3 + j + 1;
        }
      }
    }
  }
  return bestMove;
}

void updateBoard(string board[3][3], int number, string player)
{
  int row = (number - 1) / 3;
  int col = (number - 1) % 3;
  board[row][col] = player;
}

void drawBoard(string board[3][3])
{
  system("cls");
  setConsoleColor(FOREGROUND_GREEN);
  cout << "    THE IMPOSSIBLE TIC TAC TOE" << endl;
  setConsoleColor(FOREGROUND_WHITE);
  cout << "---------------------------------------------------------------------------------------\n";
  cout << "Make your move by pressing numbers shown in the left Board. You go first and will be \"x\".\n";
  cout << "Please stay calm, this AI is unbeatable, even I couldn't do that.\n";
  cout << "      _____ _____ _____          |         _____ _____ _____" << endl;
  cout << "     |     |     |     |         |        |     |     |     |" << endl;
  cout << "     |  1  |  2  |  3  |         |        |  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  |" << endl;
  cout << "     |_____|_____|_____|         |        |_____|_____|_____|" << endl;
  cout << "     |     |     |     |         |        |     |     |     |" << endl;
  cout << "     |  4  |  5  |  6  |         |        |  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  |" << endl;
  cout << "     |_____|_____|_____|         |        |_____|_____|_____|" << endl;
  cout << "     |     |     |     |         |        |     |     |     |" << endl;
  cout << "     |  7  |  8  |  9  |         |        |  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  |" << endl;
  cout << "     |_____|_____|_____|         |        |_____|_____|_____|" << endl
       << "                                 |" << endl;
  setConsoleColor(BRIGHT_YELLOW);
  cout << "             Player Win = " << format(to_string(playerWin), 2) << "     ";
  setConsoleColor(FOREGROUND_WHITE);
  cout << "|      ";
  setConsoleColor(BRIGHT_RED);
  cout << "AI Win = " << format(to_string(AIWin), 2) << endl
       << endl;
  setConsoleColor(FOREGROUND_WHITE);
  cout << "Press \"e\" to exit game.\n";
}

int main()
{
  string board[3][3] = {
      {" ", " ", " "},
      {" ", " ", " "},
      {" ", " ", " "}};
  char input;
  cout << "\n";
  setConsoleColor(FOREGROUND_GREEN);
  cout << "    THE IMPOSSIBLE TIC TAC TOE" << endl;
  setConsoleColor(FOREGROUND_WHITE);
  cout << "    Press \"s\" to start, press \"e\" to exit\n\n";
  cout << "---------------------------------------------------------------------------------------\n";
  while (1)
  {
    input = _getch();
    if (input == 's')
    {
      break;
    }
    else if (input == 'e')
      return 0;
  }
  cout << "Game starting... please wait..." << endl;
  Sleep(1000);
  drawBoard(board);
  while (true)
  {
    input = _getch();
    if (input >= '0' && input <= '9')
    {
      int number = input - '0';
      if (board[(number - 1) / 3][(number - 1) % 3].compare(" "))
        continue;
      updateBoard(board, number, player);
      drawBoard(board);
      int score = eval(board);
      if (!isMoveLeft(board))
      {
        resetBoard(board);
        Sleep(1000);
        drawBoard(board);
        continue;
      }
      if (score == 10)
      {
        resetBoard(board);
        AIWin++;
        Sleep(1000);
        drawBoard(board);
        continue;
      }
      if (score == -10)
      {
        resetBoard(board);
        playerWin++;
        Sleep(1000);
        drawBoard(board);
        continue;
      }
      Sleep(1000);
      int move = findBestMove(board);
      updateBoard(board, move, ai);
      drawBoard(board);
      score = eval(board);
      if (!isMoveLeft(board))
      {
        resetBoard(board);
        Sleep(1000);
        drawBoard(board);
        continue;
      }
      if (score == 10)
      {
        resetBoard(board);
        AIWin++;
        Sleep(1000);
        drawBoard(board);
        continue;
      }
      if (score == -10)
      {
        resetBoard(board);
        playerWin++;
        Sleep(1000);
        drawBoard(board);
        continue;
      }
    }
    else if (input == 'e')
    {
      cout << "Thanks for playing The Impossible Tic Tac Toe!" << endl;
      Sleep(1000);
      return 0;
    }
  }
  return 0;
}