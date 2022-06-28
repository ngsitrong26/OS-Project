<div id=#top></div>
## TinyShell
<br>
## _Welcome to our TinyShell_

TinyShell is an open-source, basic, simple, user-friendly terminal application like Command Prompt, PowerShell. Its main features include working with process, running executable/batch files, and more to discover.

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#TinyShell">About The Project</a>
    </li>
    <li><a href="#Aims">Aims</a></li>
    <li><a href="#Features">Features</a></li>
    <li><a href="#Contributors">Contributors</a></li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li>
      <a href="#Usage">Usage</a>
      <ol>
        <li><a href="#1.-Process-Mode">Process Mode</a></li>
        <li><a href="#2.-Process-management-(background-mode)">Process Management</a></li>
        <li><a href="#3.-Run-apps/files">Run apps/files</a></li>
        <li><a href="#4.-Environment-Variables">Environment Variables</a></li>
        <li><a href="#5.-Dir">Dir</a></li>
        <li><a href="#6.-Other-commands">Other commands</a></li>
      <ol>
  </ol>
</details>

## Aims

- Study about Windows process management APIs.
- Understand how to setup and work with Shell.

## Features

- Working with process: Create, Stop, Resume and Kill Processes with Foreground and Background Mode
- Working with Directory Path
- Working with environment variables
- Open Notepad, Calculator, executable/batch files, etc

## Contributors:

This program is created by 3 Students of Talented in Computer Science - K65, HUST

- [Hồ Viết Đức Lương](mailto:luong.hvd200376@sis.hust.edu.vn)
- [Nguyễn Duy Long](mailto:long.nd204580@sis.hust.edu.vn)
- [Mai Trung Kiên](mailto:kien.mt200301@sis.hust.edu.vn)

## Getting Started

### Prerequisites

The program works in Windows Machine with a C++ compiler installed ([MinGW](https://sourceforge.net/projects/mingw/), [VC++](https://visualstudio.microsoft.com/vs/features/cplusplus/) or [Clang](https://clang.llvm.org/)) with standard C++11 or higher.

### Instalation

To run this program, download this repository from Github.
If you have [Git](https://git-scm.com/) installed, you can clone this repository to your machine:

```sh
git clone https://github.com/Asphode1/TinyShell.git
cd TinyShell
```

Run `Tiny.exe` directly from Windows Explorer or using Command Prompt:

```cmd
./Tiny
```

## Usage

### 1. Process Mode

#### 1. Foreground mode

Shell must wait for the process to finish

```sh
<Command> [-fore|-f]
```

_Example:_

```sh
notepad -fore
```

#### 2. Background mode

Shell and process run in parallel

```sh
<Command> [-back|-b]
```

_Example:_

```sh
notepad -back
```

### 2. Process management (background mode)

#### 1. List

Print out list of the processes (process Id, Cmd name, status)

```sh
process [list|l]
```

#### 2. Stop

Stop a running process

```sh
process [stop|s] <Id>
```

#### 3. Resume

Resume a stopped process

```sh
process [resume|r] <Id>
```

#### 4. Kill

Kill a process:

```sh
process [kill|k] <Id>
```

To kill all processes:

```sh
process [kill|k] [-all|-a]
```

### 3. Run apps/files

Run Notepad with mode:

```sh
run notepad <Mode>
```

Run Calculator with mode:

```sh
run calc <Mode>
```

Run executable/batch file with mode:

```sh
run path/to/file <Mode>
```

### 4. Environment Variables

#### 1. Show environment variables

Display the value of an environment variable

```sh
env <Id>
```

To print list of environment variables:

```sh
env [list|l]
```

#### 2. Add

Add new environment variable

```sh
env [add|a] <Name> <Value>
```

#### 3.Delete

Delete existing environment variable

```sh
env [delete|del|d] <Name>
```

### 5. Dir

#### 1. cd

Show list contents of the current directory

```sh
cd
```

#### 2. Change current directory

Change current directory to <Path>

```sh
cd <Path>
```

Change current directory to its parent directory:

```sh
cd ..
```

#### 3. Reset

Reset current directory to the Initial Path

```sh
cd [reset|r]
```

### 6. Other commands

#### 1. Show command history

```sh
history
```

To clear command history:

```sh
clear
```

#### 2. Time

Display current date and time

```sh
time
```

Run countdown program (With mode):

```sh
time [countdown|c] <Mode>
```

#### 3. Exit TinyShell

```sh
exit
```

#### And more commands to discover!

## Contact

Mai Trung Kiên - [Outlook](mailto:kien.mt200301@sis.hust.edu.vn) - [Email](kien.mai191618@gmail.com)
Project link: [https://github.com/Asphode1/TinyShell](https://github.com/Asphode1/TinyShell)
