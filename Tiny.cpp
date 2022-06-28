#include <sstream>
#include <vector>
#include "src/color/color.h"
#include "src/commands/help/help.h"
#include "src/commands/process/process.h"
#include "src/commands/tiny/tiny.h"
#include "src/commands/cd/cd.h"
#include "src/commands/time/time.h"
#include "src/commands/env/env.h"
#include "src/commands/notepad/notepad.h"
using std::cin;
using std::stringstream;
using std::time_t;
using std::vector;

void printTime()
{
  time_t now;
  struct tm *localTime;
  time(&now);
  localTime = localtime(&now);
  int h = localTime->tm_hour;
  int m = localTime->tm_min;
  int s = localTime->tm_sec;
  setConsoleColor(BRIGHT_YELLOW);
  cout << "------------<(" << (h >= 10 ? to_string(h) : ("0" + to_string(h))) << ":" << (m >= 10 ? to_string(m) : ("0" + to_string(m))) << ":" << (s >= 10 ? to_string(s) : ("0" + to_string(s))) << ")>------------\n";
  setConsoleColor(FOREGROUND_WHITE);
}

void greed()
{
  setConsoleColor(BRIGHT_GREEN);
  cout << " ______                                    ____        __                   ___       ___" << endl;
  cout << "/\\__  _\\    __                            /\\  _`\\     /\\ \\                 /\\_ \\     /\\_ \\" << endl;
  cout << "\\/_/\\ \\/   /\\_\\      ___      __  __      \\ \\,\\L\\_\\   \\ \\ \\___        __   \\//\\ \\    \\//\\ \\" << endl;
  cout << "   \\ \\ \\   \\/\\ \\   /' _ `\\   /\\ \\/\\ \\      \\/_\\__ \\    \\ \\  _ `\\    /'__`\\   \\ \\ \\     \\ \\ \\" << endl;
  cout << "    \\ \\ \\   \\ \\ \\  /\\ \\/\\ \\  \\ \\ \\_\\ \\       /\\ \\L\\ \\   \\ \\ \\ \\ \\  /\\  __/    \\_\\ \\_    \\_\\ \\_" << endl;
  cout << "     \\ \\_\\   \\ \\_\\ \\ \\_\\ \\_\\  \\/`____ \\      \\ `\\____\\   \\ \\_\\ \\_\\ \\ \\____\\   /\\____\\   /\\____\\" << endl;
  cout << "      \\/_/    \\/_/  \\/_/\\/_/   `/___/> \\      \\/_____/    \\/_/\\/_/  \\/____/   \\/____/   \\/____/" << endl;
  cout << "                                  /\\___/" << endl;
  cout << "                                  \\/__/" << endl;
  cout << "\nTiny Shell";
  setConsoleColor(FOREGROUND_WHITE);
  cout << " by KLL Team\n";
  cout << "For more information, please visit https://github.com/Asphode1/TinyShell\n";
  cout << "Type \"help\" to show list of commands and their usage.\n";
  printTime();
}

string *getInput(string input, string *inputData)
{
  stringstream ss(input);
  string word;
  int i = 0;
  while (ss >> word)
  {
    inputData[i] = word;
    i++;
  }
  return inputData;
}

void start(string *input)
{
  string cmd = findCmd(input[0]);
  if (!cmd.compare("help"))
  {
    help(input);
  }
  else if (!cmd.compare("tiny"))
  {
    tiny(input);
  }
  else if (!cmd.compare("cd"))
  {
    cd(input);
  }
  else if (!cmd.compare("env"))
  {
    env(input);
  }
  else if (!cmd.compare("notepad"))
  {
    notepad(input);
  }
  else if (!cmd.compare("time"))
  {
    time(input);
  }
  else if (!cmd.compare("process"))
  {
    process(input);
  }
  else if (!cmd.compare("run"))
  {
    run(input);
  }
  else
  {
    cout << "Unknown command: \"" << *input << "\"\n\n";
    cout << "To see a list of supported commands, run:\n help\n\n";
  }
}

int main()
{
  string currentDir;
  vector<string> history;
  greed();
  setConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
  cout << ">";
  setConsoleColor(FOREGROUND_WHITE);
  string input;
  while (true)
  {
    getline(cin, input);
    if (!input.compare("exit") || !input.compare("e"))
    {
      cout << "Thanks for using our ";
      setConsoleColor(BRIGHT_GREEN);
      cout << "Tiny Shell";
      setConsoleColor(FOREGROUND_WHITE);
      cout << "!\n\n";
      sleep(2);
      break;
    }
    if (!input.compare("history"))
    {
      if (history.empty())
      {
        cout << "No command used.\n\n";
        printTime();
      }
      else
      {
        cout << "Commands used:\n\n";
        for (auto h : history)
        {
          cout << h << endl;
        }
        printTime();
      }
    }
    else if (!input.compare("clear") || !input.compare("c"))
    {
      history.clear();
      cout << "History cleared!\n\n";
      printTime();
    }
    else if (!input.compare("cls"))
    {
      system("cls");
      greed();
    }
    else
    {
      history.push_back(input);
      string inputData[10];
      auto inputDat = getInput(input, inputData);
      start(inputDat);
      cout << endl;
      printTime();
    }
    setConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << ">";
    setConsoleColor(FOREGROUND_WHITE);
  }
  return 0;
}