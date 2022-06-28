#ifndef COLOR_H_
#define COLOR_H_

#include <iostream>
#include <windows.h>

const unsigned short FOREGROUND_BRIGHT_WHITE = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
const unsigned short FOREGROUND_WHITE = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
const unsigned short DARK_BLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
const unsigned short BRIGHT_GREEN = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
const unsigned short BRIGHT_YELLOW = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;

void setConsoleColor(unsigned short colour)
{
  static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  std::cout.flush();
  SetConsoleTextAttribute(hOut, colour);
}

#endif