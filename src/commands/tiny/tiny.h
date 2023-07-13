#ifndef TINY_H_
#define TINY_H_

#include <shellapi.h>

void tiny(string *input)
{
  if (!input[2].empty())
  {
    cout << "Unknown command: \"" << input[2] << "\"\n\n";
    cout << "To see a list of supported commands, run:\n  help\n\n";
  }
  else if (input[1].empty())
    ShellExecute(0, 0, "https://github.com/ngsitrong26/OS-Project", 0, 0, SW_SHOW);
  else if (!input[1].compare("-h") || !input[1].compare("-help"))
  {
    cout << "\nUsage:\n";
    cout << format("tiny", 15) << "More information about Tiny Shell\n\n";
    cout << "Options:\n";
    cout << "[-h|-help]\n\n";
  }
  else
  {
    cout << "Unknown command: \"" << input[1] << "\"\n\n";
    cout << "To see a list of supported commands, run:\n  help\n\n";
  }
}

#endif