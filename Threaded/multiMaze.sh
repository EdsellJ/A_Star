#!/bin/sh
#will create 10 mazes simultaneousley and put them in the mazes folder
sh multiprocess.sh pythonCommands.txt

#compile c++ program
g++ mainThreaded.cpp -pthread -o threaded.out

#run
./threaded.out
