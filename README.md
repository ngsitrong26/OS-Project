<div id=#top></div>
<div  id="TinyShell" align="center">
  <a href="https://github.com/Asphode1/TinyShell">
    <img src="src/img/TinyShell.png">
  </a>
  <h2 id="Welcome"> <em>Welcome to our TinyShell</em></h2>

  <p>TinyShell is an open-source, basic, simple, user-friendly terminal application like Command Prompt, PowerShell. Its main features include working with process, running executable/batch files, and more to discover.</p>
</div>

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
      <a href="#Start">Getting Started</a>
      <ul>
        <li><a href="#pre">Prerequisites</a></li>
        <li><a href="#ins">Installation</a></li>
      </ul>
    </li>
    <li>
      <a href="#Usage">Usage</a>
      <ol>
        <li><a href="#ProcessMode">Process Mode</a></li>
        <li><a href="#Process">Process Management</a></li>
        <li><a href="#Run">Run apps/files</a></li>
        <li><a href="#Environment">Environment Variables</a></li>
        <li><a href="#Dir">Dir</a></li>
        <li><a href="#Other">Other commands</a></li>
      </ol>
    <li><a href="#Issues">Issues</a></li>
    <li><a href="#Contact">Contact</a></li>
  </ol>
</details>

<h2 id="Aims">Aims</h2>

- Study about Windows process management APIs.
- Understand how to setup and work with Shell.

<h2 id="Features">Features</h2>

- Working with process: Create, Stop, Resume and Kill Processes with Foreground and Background Mode
- Working with Directory Path
- Working with environment variables
- Open Notepad, Calculator, executable/batch files, etc

<h2 id="Contributors">Contributors</h2>

This program is created by 3 Students of Talented in Computer Science - K65, HUST

- [Hồ Viết Đức Lương](mailto:luong.hvd200376@sis.hust.edu.vn)
- [Nguyễn Duy Long](mailto:long.nd204580@sis.hust.edu.vn)
- [Mai Trung Kiên](mailto:kien.mt200301@sis.hust.edu.vn)
<p align="right">(<a href="#top">back to top</a>)</p>

<h2 id="Start">Getting Started</h2>

<h3 id="pre">Prerequisites</h3>

The program works in Windows Machine with a C++ compiler installed ([MinGW](https://sourceforge.net/projects/mingw/), [VC++](https://visualstudio.microsoft.com/vs/features/cplusplus/) or [Clang](https://clang.llvm.org/)) with standard C++11 or higher.

<h3 id="ins">Instalation</h3>

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
If there are any errors while running the app, see <a href="#Issues">Issues</a>
<p align="right">(<a href="#top">back to top</a>)</p>
      
<h2 id="Usage">Usage</h2>

<h3 id="ProcessMode">1. Process Mode</h3>

#### 1. Foreground mode

Shell must wait for the process to finish

```sh
<Command> [-fore|-f]
```

_Example:_

```sh
run notepad -fore
```

#### 2. Background mode

Shell and process run in parallel

```sh
<Command> [-back|-b]
```

_Example:_

```sh
run notepad -back
```

<h3 id="Process">2. Process management (background mode)</h3>

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

<h3 id="Run">3. Run apps/files</h3>

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

<h3 id="Environment">4. Environment Variables</h3>

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

<h3 id="Dir">5. Dir</h3>

#### 1. cd

Show list contents of the current directory

```sh
cd
```

#### 2. Change current directory

Change current directory to \<Path\>

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

<h3 id="Other">6. Other commands</h3>

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

<p align="right">(<a href="#top">back to top</a>)</p>
<h2 id="Issues">Issues</h2>
<h3>a. Error on running the program</h3>

Recompile `Tiny.cpp` with flag `-std=c++11` and run again.</br>

_Example:_ using g++
 ```sh
 g++ -std=c++11 Tiny.cpp -o Tiny && ./Tiny
 ```
<h3>b. Error on running countdown clock</h3>

Recompile `src/commands/time/countDown.cpp` with flag `-std=c++11` and try again</br>

_Example:_ using g++
 ```sh
 g++ -std=c++11 src/commands/time/countDown.cpp -o src/commands/time/countDown
 ```

<h3>c. Error on running The Impossible Tic Tac Toe game</h3>

Recompile `tic_tac_toe/TheImpossibleTicTacToe.cpp` with flag `-std=c++11` and try again</br>

_Example:_ using g++
 ```sh
 g++ -std=c++11 tic_tac_toe/TheImpossibleTicTacToe.cpp -o tic_tac_toe/TheImpossibleTicTacToe
 ```

<p align="right">(<a href="#top">back to top</a>)</p>

<h2 id="Contact"> Contact</h2>

Mai Trung Kiên - [Outlook](mailto:kien.mt200301@sis.hust.edu.vn) - [Email](mailto:kien.mai191618@gmail.com)<br>
Project link: [https://github.com/Asphode1/TinyShell](https://github.com/Asphode1/TinyShell)
<p align="right">(<a href="#top">back to top</a>)</p>
