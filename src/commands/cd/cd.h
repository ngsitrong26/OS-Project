#ifndef CD_H_
#define CD_H_

#include <errno.h>
#include <stdlib.h>

const string rootDir(_getcwd(NULL, 0));

void curDir()
{
  char *buffer;
  if ((buffer = _getcwd(NULL, 0)) == NULL)
    cout << "_getcwd error";
  system("dir");
  free(buffer);
}

void parentDir()
{
  char *buffer;
  if ((buffer = _getcwd(NULL, 0)) == NULL)
    cout << "_getcwd error";
  string dir(buffer);
  string parentDir = dir.substr(0, dir.find_last_of("\\"));
  /* if (_chdir(parentDir.c_str())) */
  if (chdir(parentDir.c_str()))
  {
    switch (errno)
    {
    case ENOENT:
      printf("No such file or directory.\n");
      break;
    case EINVAL:
      printf("Invalid buffer.\n");
      break;
    default:
      printf("Unknown error.\n");
      break;
    }
  }
  else
    system("dir");
  free(buffer);
}

void changeDir(string path)
{
  if (chdir(path.c_str()))
  {
    switch (errno)
    {
    case ENOENT:
      printf("No such file or directory.\n");
      break;
    case EINVAL:
      printf("Invalid buffer.\n");
      break;
    default:
      printf("Unknown error.\n");
      break;
    }
  }
  else
    system("dir");
}

void cd(string *cmd)
{
  if (cmd[1].empty())
  {
    curDir();
  }
  else if (!cmd[2].empty())
  {
    cout << "Unknown command: \"" << cmd[2] << "\"\n\n";
    cout << "To see a list of supported commands, run:\n  cd  -help\n\n";
  }
  else if (!cmd[1].compare(".."))
  {
    parentDir();
  }
  else if (!cmd[1].compare("reset") || !cmd[1].compare("r"))
  {
    changeDir(rootDir);
  }
  else if (!cmd[1].compare("-h") || !cmd[1].compare("-help"))
  {
    cout << "Usage:\n";
    cout << format("cd", 15) << "Show list contents of the current directory" << endl;
    cout << format("cd ..", 15) << "Change to the parrent directory of its parent directory" << endl;
    cout << format("cd <Path>", 15) << "Change current directory to <Path>" << endl;
    cout << format("cd [reset|r]", 15) << "Change current directory to the initial Path" << endl;
    cout << "Options:\n";
    cout << "[-fore|-f][-back|-b]\n[-h|-help]\n\n";
  }
  else
  {
    changeDir(cmd[1]);
  }
}

#endif