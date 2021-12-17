#!/bin/sh
#compile c++ program
g++ mainThreaded.cpp -pthread -o threaded.out

#will create 10 mazes simultaneousley and put them in the mazes folder
sh multiprocess.sh pythonCommands.txt

#run
./threaded.out
