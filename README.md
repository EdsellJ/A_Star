# A_Star
A_star algorithm designed to solve a python generated maze

## Where to begin
To begin, cd into src, this is the initial maze solving program. Run `sh solveMaze.sh`, this will compile the c++, build a new maze, then solve the maze.  
You can see how long it took to solve the maze and the path it took. You can run `./a_star.out` to see it solve the same maze again the time it takes to solve can vary.  

## Multiprocessing and Threading
Move back a directory and cd into Threaded. Here I have made a script that will simultaneously build 10 mazes at once (it will slam your CPU, check out top while running).  Running `sh multiMaze.sh` will build the c++ program, create ten mazes, solve all ten mazes one at a time and then threaded and compare the times.  
If you would simply like to test out creating the ten mazes with the python script run `sh multiprocess.sh pythonCommands.txt`. This is kind of fun to see all of my cores go to nearly 100% utilization.
