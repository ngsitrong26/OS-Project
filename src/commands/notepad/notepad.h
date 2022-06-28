#ifndef NOTEPAD_H_
#define NOTEPAD_H_

void notepad(string *cmd)
{
  if (cmd[1].empty())
  {
    cout << "Unknown command.\n";
    cout << "To see a list of supported commands, run:\n  help\n\n";
  }
  else if (!cmd[1].compare("-fore") || !cmd[1].compare("-f"))
  {
    fore("C:\\windows\\system32\\notepad.exe");
  }
  else if (!cmd[1].compare("-back") || !cmd[1].compare("-b"))
  {
    back("C:\\windows\\system32\\notepad.exe");
  }
  else if (!cmd[1].compare("-help") || !cmd[1].compare("-h"))
  {
    cout << "Usage:\n";
    cout << format("  notepad", 15) << "Open Notepad\n";
    cout << "Options:\n";
    cout << "[-fore|-f][-back|-b]\n[-h|-help]\n\n";
    cout << "aliases: n, np\n";
  }
  else
  {
    cout << "Unknown command: " << cmd[1] << endl;
    cout << "To see a list of supported commands, run:\n  help\n\n";
  }
}

#endif