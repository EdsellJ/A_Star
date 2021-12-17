#!/bin/sh
g++ main.cpp -o a_star.out
python rnd_maze.py 135 135 > maze
./a_star.out
