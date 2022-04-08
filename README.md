# ICT1009-Part2

External libraries:

SQLite3

Installation guide: https://www.tutorialspoint.com/sqlite/sqlite_installation.htm

Download link to sqlite3: https://www.sqlite.org/download.html

CMake

Installation guide (Linux/WSL): https://vitux.com/how-to-install-cmake-on-ubuntu/

fmt

Official site: https://fmt.dev/
- Installation guide can be found in Usage


Bcrypt.cpp

Github repository: https://github.com/hilch/Bcrypt.cpp

Excluding SQLite3 and CMake, the dependencies fmt and Bcrypt.cpp has already been included in the project under the dependencies folder.

Progam is compiled in management directory using the following commands: g++ *.cpp ..\sql\sqlDb.cpp -l sqlite3 -o output

Alternatively if you have CMake installed, simply cd to the the folder where CMakeLists.txt is located and run:
```
cmake .
make
./ICT1009-Part2
```
* Note: Those 3 commands needs to be run the first time, after that you can simply run by entering the last command `./ICT1009-Part2`
