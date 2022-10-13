# connect4-cli
Play the popular Connect 4 game directly from your command line! 

Two people are required to play.

![Demo](https://github.com/shahank42/connect4-cli/blob/main/connect4-cli-demo.gif?raw=true)

## What is Connect 4?
According to Wikipedia, Connect Four is a two-player connection board game, in which the players choose a color and then take turns dropping colored tokens into a seven-column, six-row vertically suspended grid.

The objective of the game is to be the first to form a horizontal, vertical, or diagonal line of four of one's own tokens.

## Installation Instructions
Nothing. Just download the release and execute the binary to start playing!

## Compilation Instructions
Download the source code and go into the directory with the `main.cpp` file.
Execute the following command for Windows:
```
g++ -std=c++17 main.cpp include\Connect4Board.h src\connect4Board.cpp include\Player.h include\Player.cpp -o bin\Release\connect4-cli-v0.1.exe -O3 -NDEBUG -s
```
or for Linux:
```
g++ -std=c++17 main.cpp include/Connect4Board.h src/connect4Board.cpp include/Player.h include/Player.cpp -o bin/Release/connect4-cli-v0.1.exe -O3 -NDEBUG -s
```
to get compile the release binary.
Then simply execute it (located at `bin/Release`) to start playing.

For a debug build just remove the compilation flags at the end of the flag.

---

Another way to compile would be build using Code::Blocks.

Building with Visual Studio C++ is not recommended, because of a macro collision error.

## Gameplay Instructions
The prompt at the bottom left shows which players turn it is. The corresponding player can enter the column number (from 1 to 7) in which they desire to place their coin.

## Future Update Plans
This project, though completely playable, is still not over. I still have plans to:

* Implement player names
* Implement custom player symbol selection
* Implement a separate function to handle the entire game loop
* Fix certain stray implicit type conversions
* Tidy up the code
* Add more accurate and meaningful comments

Stay tuned!
