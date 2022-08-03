#ifndef ENV_H_
#define ENV_H_

#include <winnt.h>

#define MAX_NAME 16383
#define MAX_VAL 100000

void envList()
{
  HKEY hKey;
  BYTE value[MAX_VAL];
  RegOpenKeyEx(HKEY_CURRENT_USER, "Environment", 0, KEY_ALL_ACCESS, &hKey);
  for (int i = 0;; i++)
  {
    TCHAR name[MAX_NAME];
    DWORD namesz = MAX_NAME;
    value[0] = '\0';
    DWORD valSize = MAX_VAL;
    if (RegEnumValue(hKey, i, name, &namesz, NULL, NULL, value, &valSize) == 0)
    {
      cout << (i < 9 ? "0" : "") << i + 1 << ". " << name << " = " << value << endl;
    }
    else
      break;
  }
  RegCloseKey(hKey);
}

void envFind(string name)
{
  HKEY hKey;
  BYTE value[MAX_VAL];
  DWORD valSize = sizeof(value);
  RegOpenKeyEx(HKEY_CURRENT_USER, "Environment", 0, KEY_ALL_ACCESS, &hKey);
  if (RegQueryValueEx(hKey, name.c_str(), NULL, NULL, value, &valSize) == 0)
  {
    cout << "Value of  " << name << " : " << value << "\n";
  }
  else
    cout << "There no variables has the name " << name << "\n\n";
  RegCloseKey(hKey);
}

void envAdd(string name, string val)
{
  HKEY hKey;
  static BYTE value[MAX_VAL];
  DWORD valSize = sizeof(value);
  RegOpenKeyEx(HKEY_CURRENT_USER, "Environment", 0, KEY_ALL_ACCESS, &hKey);
  if (RegQueryValueEx(hKey, name.c_str(), NULL, NULL, value, &valSize) == 0)
  {
    string envName(reinterpret_cast<char *>(value));
    envName = envName + " ; " + val;
    BYTE byteVal[MAX_NAME];
    std::copy(envName.begin(), envName.end(), byteVal);
    byteVal[envName.length()] = 0;
    RegSetValueEx(hKey, name.c_str(), 0, REG_SZ, byteVal, envName.length());
  }
  else
  {
    BYTE byteVal[MAX_NAME];
    std::copy(val.begin(), val.end(), byteVal);
    byteVal[val.length()] = 0;
    RegSetValueEx(hKey, name.c_str(), 0, REG_SZ, byteVal, val.length());
  }
  cout << "The environment variable " << name << " is added\n";
  RegCloseKey(hKey);
}

void envDel(string name)
{
  HKEY hKey;
  RegOpenKeyEx(HKEY_CURRENT_USER, "Environment", 0, KEY_ALL_ACCESS, &hKey);
  if (RegDeleteValue(hKey, name.c_str()) == ERROR_SUCCESS)
  {
    cout << "The environment variable " << name << " is deleted\n\n";
  }
  else
  {
    cout << "Variable \"" << name << "\" not found\n\n";
  }
  RegCloseKey(hKey);
}

void env(string *cmd)
{
  if (!cmd[1].compare("list"))
  {
    if (!cmd[2].empty())
    {
      cout << "Unknown command: \"" << cmd[2] << "\"\n\n";
      cout << "To see a list of supported commands, run:\n  env -help\n\n";
    }
    else
    {
      envList();
    }
  }
  else if (!cmd[1].compare("-h") || !cmd[1].compare("-help"))
  {
    cout << "\nUsage:\n";
    cout << format("env <Id>", 30) << "Display the value of the environment variable <Id>\n";
    cout << format("env [list|l]", 30) << "Display all environment variables\n";
    cout << format("env [add|a] <Id> <Value>", 30) << "Add the environment variable <Id> with its value <Value>,\n";
    cout << format("env [del|d|delete] <Id>", 30) << "Delete the environment variable <Id>\n\n";
    cout << "Options:\n";
    cout << "[-h|-help]\n\n";
    cout << "aliases: en, ev\n";
  }
  else if (!cmd[1].compare("add") || !cmd[1].compare("a"))
  {
    if (cmd[2].empty())
    {
      cout << "Wrong command: missing <Id> and <Value>\n\n";
    }
    else if (cmd[3].empty())
    {
      cout << "Wrong command: missing <Value>\n\n";
    }
    else if (!cmd[4].empty())
    {
      cout << "Unknown command: \"" << cmd[4] << "\"\n\n";
      cout << "To see a list of supported commands, run:\n  env -help\n\n";
    }
    else
    {
      envAdd(cmd[2], cmd[3]);
    }
  }
  else if (!cmd[1].compare("del") || !cmd[1].compare("d") || !cmd[1].compare("delete"))
  {
    if (cmd[2].empty())
    {
      cout << "Wrong command: missing <Path>\n\n";
    }
    else if (!cmd[3].empty())
    {
      cout << "Unknown command: \"" << cmd[3] << "\"\n\n";
      cout << "To see a list of supported commands, run:\n  env -help\n\n";
    }
    else
    {
      envDel(cmd[2]);
    }
  }
  else if (!cmd[1].empty())
  {
    if (!cmd[2].empty())
    {
      cout << "Invalid command\"\n\n";
      cout << "To see a list of supported commands, run:\n  env -help\n\n";
    }
    else
      envFind(cmd[1]);
  }
  else
  {
    cout << "Unknown command: \"" << cmd[1] << "\"\n\n";
    cout << "To see a list of supported commands, run:\n  env -help\n\n";
  }
}

#endif