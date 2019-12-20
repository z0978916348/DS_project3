# Chain Reaction Framework

Readme url: [Readme](https://gitlab.com/tzuyangw/chain-reaction-framework/blob/master/README.md)
The spec document: [Demand](https://gitlab.com/tzuyangw/chain-reaction-framework/blob/master/Demand.pdf)

# A very simple framework of chain reaction using C++ language. 

Apply the knowledge learned form the course of data structure and implement a competitive algorithm for the Critical Mass game.

## Compile Command:
* $g++ chain_reaction.cpp board.cpp rules.cpp player.cpp algorithm_A.cpp algorithm_TA.cpp

## Execution: 
* Execute the output file(Mac: a.out, Windows: a.exe)

## Some simple actions that can make your development easier 

### Main program

*  The main data flow is in the chain_reaction.cpp. 
*  The following three lines of code are used to declare the variable board, red player and blue player.<br></br>

![Variable Declaration](/images/002.png)

*  Firstly, the program will call your function which "should" return a board index (i, j).
*  Then the program will call place_orb function to put your orb on the index that obtained from your algorithm.
*  If a players' placement is illegal, the program will terminate immediately and annouce the winner.
*  If a players' last placement dominate the hole board, the program will terminate immediately and annouce the winner.

![Player action](/images/001.png)

### Algorithm_A

*  The algorithm_A.cpp file is where you need to impliment your algorithm.
*  All the constrains and support funcitons is commented in the file, please check the [algorithm_A.cpp](/source/algorithm_A.cpp) for more information.

### Submit

*  All you need to do is complete the algorithm_A.cpp with correct return format.
*  Any other modifies "will not" be compiled in TA's computer.(except algorithm_A.cpp)
*  But we do not restrict you from modifying any part of the framwork. You can do whatever you want to speed up your developement.

### Something you might want to know

*  system("pause")