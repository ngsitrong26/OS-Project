#ifndef HELP_H_
#define HELP_H_

#include <string>
#include <algorithm>
#include <map>
using std::endl;
using std::string;

string format(string s, unsigned long long len)
{
  string a = s;
  while (a.length() < len)
    a += ' ';
  return a;
}

void getHelpCmd(string s)
{
  if (!s.compare("cd"))
  {
    cout << "Usage:\n";
    cout << format("  cd", 15) << "Show list contents of the current directory" << endl;
    cout << format("  cd ..", 15) << "Change current directory to its parent directory" << endl;
    cout << format("  cd <Path>", 15) << "Change current directory to <Path>" << endl;
    cout << format("  cd [reset|r]", 15) << "Change current directory to the initial Path" << endl;
    cout << "Options:\n";
    cout << "[-fore|-f][-back|-b]\n[-h|-help]\n\n";
  }
  else if (!s.compare("time"))
  {
    cout << "Usage:\n";
    cout << format("  time", 20) << "Display current date and time\n\n";
    cout << format("  time [countdown|c]", 20) << "Run countdown clock\n\n";
    cout << "Options:\n";
    cout << "[-fore|-f][-back|-b]\n[-h|-help]\n\n";
    cout << "aliases: t\n";
  }
  else if (!s.compare("process"))
  {
    cout << "Usage:\n";
    cout << format("  process [list|l]", 30) << "Display list of processes\n";
    cout << format("  process [stop|s] <Id>", 30) << "Stop running process with id <Id>\n";
    cout << format("  process [resume|r] <Id>", 30) << "Resume process with id <Id>\n";
    cout << format("  process [kill|k] <Id>", 30) << "Kill process with id <Id>\n";
    cout << format("  process [kill|k] [-a|-all]", 30) << "Kill all process\n\n";
    cout << "Options:\n";
    cout << "[-fore|-f][-back|-b]\n[-h|-help]\n\n";
    cout << "aliases: p\n";
  }
  else if (!s.compare("env"))
  {
    cout << "Usage:\n";
    cout << format("  env <Id>", 30) << "Display the value of the environment variable <Id>\n";
    cout << format("  env [list|l]", 30) << "Display all environment variables\n";
    cout << format("  env [add|a] <Id> <Value>", 30) << "Add the environment variable <Id> with its value <Value>,\n";
    cout << format("  env [del|d|delete] <Id>", 30) << "Delete the environment variable <Id>\n\n";
    cout << "Options:\n";
    cout << "[-fore|-f][-back|-b]\n[-h|-help]\n\n";
    cout << "aliases: en, ev\n";
  }
  else if (!s.compare("history"))
  {
    cout << "Usage:\n";
    cout << format("  history", 30) << "Print all used commands\n";
  }
  else if (!s.compare("clear"))
  {
    cout << "Usage:\n";
    cout << format("  clear", 15) << "Clear command history\n\n";
    cout << "aliases: c";
  }
  else if (!s.compare("exit"))
  {
    cout << "Usage:\n";
    cout << format("  exit", 15) << "Exit TinyShell\n\n";
    cout << "aliases: e";
  }
  else if (!s.compare("tiny"))
  {
    cout << "Usage:\n";
    cout << format("  tiny", 15) << "More information about Tiny Shell\n\n";
    cout << "Options:\n";
    cout << "[-h|-help]\n\n";
  }
  else if (!s.compare("cls"))
  {
    cout << "Usage:\n";
    cout << format("  cls", 15) << "Clear screen\n\n";
  }
  else if (!s.compare("run"))
  {
    cout << "Usage:\n";
    cout << format("  run <Path/to/exe>", 25) << "Run executable file\n";
    cout << format("  run <Path/to/bat>", 25) << "Run batch file\n";
    cout << format("  run [notepad|n]", 25) << "Run notepad\n";
    cout << format("  run [calc|c]", 25) << "Run calculator\n\n";
    cout << "Options:\n";
    cout << "[-fore|-f][-back|-b]\n[-h|-help]\n\n";
    cout << "aliases: r\n\n";
  }
  else
  {
    cout << "Unknown command: \"" << s << "\"\n\n";
    cout << "To see a list of supported commands, run:\n  help\n\n";
  }
}

string findCmd(string s)
{
  string ss[12][3] = {
      {"help", "h"},
      {"cd"},
      {"cls"},
      {"time", "t"},
      {"process", "p"},
      {"env", "en", "ev"},
      {"history"},
      {"clear", "c"},
      {"exit", "e"},
      {"tiny"},
      {"run", "r"}};
  for (int i = 0; i < 11; i++)
  {
    int j = 0;
    while (!ss[i][j].empty() && j < 3)
    {
      string a = ss[i][j];
      if (!s.compare(a))
        return ss[i][0];
      j++;
    }
  }
  return "0";
}

void help(string *inputString)
{
  std::map<string, string> cmds;
  cmds.insert(std::pair<string, string>("help", "Show list of commands and their usage"));
  cmds.insert(std::pair<string, string>("cd", "Get current directory path"));
  cmds.insert(std::pair<string, string>("cls", "Clear screen"));
  cmds.insert(std::pair<string, string>("time", "Display current time"));
  cmds.insert(std::pair<string, string>("process", "Working with processes"));
  cmds.insert(std::pair<string, string>("env", "Working with environment variables"));
  cmds.insert(std::pair<string, string>("history", "Print all used commands"));
  cmds.insert(std::pair<string, string>("clear", "Clear command history"));
  cmds.insert(std::pair<string, string>("exit", "Exit TinyShell"));
  cmds.insert(std::pair<string, string>("tiny", "More information about Tiny Shell on GitHub"));
  cmds.insert(std::pair<string, string>("run", "Run executable/batch file"));
  if (inputString[1].empty())
  {
    for (auto const &x : cmds)
    {
      cout << format(x.first, 15) << x.second << endl;
    }
    cout << "For more information on each command, type \"help <Command>\"" << endl;
  }
  else
  {
    string in = findCmd(inputString[1]);
    auto f = cmds.find(in);
    if (f != cmds.end())
    {
      cout << f->first << "\n\n"
           << f->second << "\n\n";
      getHelpCmd(in);
    }
    else
    {
      cout << "Unknown command: \"" << inputString[1] << "\"\n\n";
      cout << "To see a list of supported commands, run:\n  help\n\n";
    }
  }
}

#endif