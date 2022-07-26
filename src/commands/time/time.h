#ifndef TIME_H_
#define TIME_H_

#include <thread>

void dateTime()
{
  int prev = 0;
  while (1)
  {
    int s, m, h;
    int dd, mm, yy;
    int weekdays;
    string wday[] = {
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"};
    string str;

    time_t total_seconds = time(0);
    struct tm *ct = localtime(&total_seconds);
    s = ct->tm_sec;
    m = ct->tm_min;
    h = ct->tm_hour;
    dd = ct->tm_mday;
    mm = ct->tm_mon + 1;
    yy = ct->tm_year + 1900;
    weekdays = ct->tm_wday;

    if (h >= 12)
      str = "PM";
    else
      str = "AM";
    h = h > 12 ? h - 12 : h;

    if (s == prev + 1 || (prev == 59 && s == 0))
    {
      cout << '\r';
      cout << wday[weekdays] << " ";
      cout << (h < 10 ? "0" : "") << h << ":" << (m < 10 ? "0" : "") << m << ":" << (s < 10 ? "0" : "") << s << " " << str;
      cout << '\t' << (dd < 10 ? "0" : "") << dd << "/" << (mm < 10 ? "0" : "") << mm << "/" << (yy < 10 ? "0" : "") << yy;
    }

    prev = s;
  }
}

void countDown(string mode)
{
  cout << "Countdown clock is running...\n";
  if (!mode.compare("-fore") || !mode.compare("-f"))
  {
    fore(rootDir + "\\src\\commands\\time\\countdown.exe");
  }
  else if (!mode.compare("-back") || !mode.compare("-b"))
  {
    back(rootDir + "\\src\\commands\\time\\countdown.exe");
  }
  else if (mode.empty())
  {
    cout << "Missing mode options.\n";
    cout << "To see a list of supported commands, run:\n  time -help\n\n";
  }
  else
  {
    cout << "Unknown command: \"" << mode << "\"\n\n";
    cout << "To see a list of supported commands, run:\n  time -help\n\n";
  }
}

void time(string *cmd)
{
  if (cmd[1].empty())
  {
    HANDLE h1;
    DWORD ThreadId;
    h1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)dateTime, NULL, 0, &ThreadId);
    std::cin.get();
    TerminateThread(h1, 0);
    CloseHandle(h1);
  }
  else if (!cmd[1].compare("countdown") || !cmd[1].compare("c"))
  {
    countDown(cmd[2]);
  }
  else if (!cmd[1].compare("-h"))
  {
    cout << "Usage:\n";
    cout << format("  time", 25) << "Display current date and time\n";
    cout << format("  time [countdown|c]", 25) << "Run countdown clock\n\n";
    cout << "Options:\n";
    cout << "[-fore|-f][-back|-b]\n[-h|-help]\n\n";
    cout << "aliases: t\n";
  }
  else
  {
    cout << "Unknown command: \"" << cmd[1] << "\"\n\n";
    cout << "To see a list of supported commands, run:\n  time -help\n\n";
  }
}

#endif