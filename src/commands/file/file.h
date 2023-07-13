#ifndef FILE_H_
#define FILE_H_

#include <iostream> 
#include <fstream>
#include <windows.h>
using std::string;

void mkdir(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        std::cout << "File \"" << filename << "\" created successfully.\n";
        file.close();
    } else {
        std::cerr << "Error creating file \"" << filename << "\"\n";
    }
}

void rm(const std::string& filename) {
    if (DeleteFileA(filename.c_str())) {
        std::cout << "File \"" << filename << "\" deleted successfully.\n";
    } else {
        DWORD error = GetLastError();
        LPSTR errorMessage = nullptr;
        FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                       nullptr, error, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                       reinterpret_cast<LPSTR>(&errorMessage), 0, nullptr);

        std::cerr << "Error deleting file \"" << filename << "\". Error code: " << error << "\n";
        if (errorMessage != nullptr) {
            std::cerr << "Error message: " << errorMessage << "\n";
            LocalFree(errorMessage);
        }
    }
}

void cp(const std::string& sourceFile, const std::string& destFile) {
    if (CopyFileA(sourceFile.c_str(), destFile.c_str(), FALSE)) {
        std::cout << "File copied successfully.\n";
    } else {
        DWORD error = GetLastError();
        LPSTR errorMessage = nullptr;
        FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                       nullptr, error, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                       reinterpret_cast<LPSTR>(&errorMessage), 0, nullptr);

        std::cerr << "Error copying file. Error code: " << error << "\n";
        if (errorMessage != nullptr) {
            std::cerr << "Error message: " << errorMessage << "\n";
            LocalFree(errorMessage);
        }
    }
}

void file(string* cmd)
{
    if(!cmd[1].compare("mkdir")||!cmd[1].compare("mk"))
    {
        if(cmd[2].empty())
        {
            cout<<"Wrong command: mising file name \n\n";
        }
        else if(!cmd[3].empty()){
            cout<<"Unknown command: \""<< cmd[3] << "\"\n\n";
            cout<< "To see a list of supported commands, run:\n  file -help\n\n";
        }
        else
        {
            mkdir(cmd[2]);
        }
    }
    else if(!cmd[1].compare("-help")||!cmd[1].compare("-h"))
    {
        if(cmd[2].empty()){
            std::cout<< "Usage:\n";
            cout << format("  file [mkdir|mk] [name]", 25) << "Create new file\n";
            cout << format("  file [cp]", 25) << "Copy file to file\n";
            cout << format("  file [rm]", 25) << "Delete file\n";
            cout << "Options:\n";
            cout << "[-h|-help]\n\n";
        }
        else
        {
            cout<< "Unknown command: \""<<cmd[2]<< "\"\n\n";
            cout<< "To see a list of supported commands, run:\n  file -help\n\n";
        }
    }
    else if (!cmd[1].compare("rm"))
    {
        if(cmd[2].empty())
        {
            cout<<"Wrong command: missing file name \n\n";
        }
        else if(!cmd[3].empty())
        {
            cout<<"Unknown command: \""<< cmd[3] << "\"\n\n";
            cout<< "To see a list of supported commands, run:\n  file -help\n\n";
        }
        else
        {
            rm(cmd[2]);
        }
    }
    else if(!cmd[1].compare("cp"))
    {
        if(cmd[2].empty())
        {
            cout<<"Wrong command: missing source filename \n\n";
        }
        else if (cmd[3].empty())
        {
            cout<<"Wrong command: missing destination filename \n\n";
        }
        else if(!cmd[4].empty())
        {
            cout<<"Unknown command: \""<< cmd[4] << "\"\n\n";
            cout<< "To see a list of supported commands, run:\n  file -help\n\n";
        }
        else
        {
            cp(cmd[2],cmd[3]);
        }
        
    }
    else
    {
        cout<< "Unknown command: \"";
        cout<< "To see a list of supported commands, run:\n  file -help\n\n";
    }
    
}
#endif
