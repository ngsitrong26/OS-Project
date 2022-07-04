#ifndef GAME_H_
#define GAME_H_

void game(string *input)
{
  if (input[2].empty())
  {
    if (!input[1].compare("-fore") || !input[1].compare("-f") || !input[1].compare("-back") || !input[1].compare("-b"))
      runExe(rootDir + "\\tic_tac_toe\\TheImpossibleTicTacToe.exe", input[1]);
    else if (!input[1].compare("-h") || !input[1].compare("-help"))
    {
      cout << "Usage:\n";
      cout << format("  game", 15) << "Play The Impossible Tic Tac Toe\n\n";
      cout << "Options:\n";
      cout << "[-fore|-f][-back|b]\n[-h|help]\n\n";
    }
    else
    {
      cout << "Unknown command: \"" << input[1] << "\"\n\n";
      cout << "To see a list of supported commands, run:\n  process -help\n\n";
    }
  }
  else
  {
    cout << "Unknown command: \"" << input[2] << "\"\n\n";
    cout << "To see a list of supported commands, run:\n  process -help\n\n";
  }
}

#endif
