# Description

Collection of simple games made in C++ (mostly with the help of SFML library)

#For Linux

## Pre-requisites:

Install SFML library in default location path (~).

For ubuntu you can use :
```sudo apt-get install libsfml-dev```

## Compiling and running the game
(Choice 1) Go to the folder of the game that you wanted to play, and run bash script by using

```
sudo bash play.sh
```

(Choice 2) Set permission for play.sh to run as an executable file (set play.sh properties)

```
./play.sh
```

(Choice 3) Alternatively, you can compile and then run it yourself
```
g++ -std=c++11 -c main.cpp
g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
./sfml-app
```

#For Windows

In windows, it is slightly more complicated.
Try to read the guide on how to install and configure the SFML project:

Codeblocks : http://www.sfml-dev.org/tutorials/2.4/start-cb.php
Visual Studio : http://www.sfml-dev.org/tutorials/2.4/start-vc.php

#For Mac OS X

Read the guide
http://www.sfml-dev.org/tutorials/2.4/start-osx.php

