#include <chrono>
#include<thread>
#include "a_star.cpp"

using namespace std::chrono;

#define THR 10

void defineGrid(int grd[][COL], string fileName){
    //open file input stream
    ifstream fin (fileName, ios::in);
    string line;
    int charpos = 0;
    int row = 0, col = 0;

    //convert '#' and ' ' to 0's and 1's
    while(getline(fin, line)){
        while (line[charpos] != '\0'){
            if (line[charpos] == '#'){
                grd[row][col] = 0;
            } 
            else {
                grd[row][col] = 1;
            }
            col++;
            charpos++;
        }
        row++;
        col = 0;
        charpos = 0;
    }
    fin.close();
}

// Driver program to test above function
int main()
{
    //list of filenames
    string fileNames[10] = {"mazes/maze0", "mazes/maze1", "mazes/maze2", "mazes/maze3","mazes/maze4", 
                            "mazes/maze5", "mazes/maze6", "mazes/maze7", "mazes/maze8", "mazes/maze9"};
    //initialize and define grids
    int grids [THR][ROW][COL] = {0};
    
    //spin up threads
    thread thr [10];

    //find all of the mazes and define them in the grid arrays
    for (int i = 0; i < THR; i++){
        thr[i] = thread(defineGrid, grids[i], fileNames[i]);
    }
    
    //join all of the threads back up
    for (int i = 0; i < THR; i++){
        thr[i].join();
    }
    

    
    AStar search;
    // Source is the left-most bottom-most corner
    AStar::Pair src = make_pair(1, 1);
 
    // Destination is the left-most top-most corner
    AStar::Pair dest = make_pair(ROW-2, COL-2);
    
    //find time it takes to run all 10 mazes without threads
    //start runtime timer
    auto start = high_resolution_clock::now();
    //call astar function
    for (int i = 0; i < THR; i++){
        search.aStarSearch(grids[i], src, dest);
    }
    //stop runtime timer
    auto stop = high_resolution_clock::now();
    //calculate runtime
    auto duration1 = duration_cast<microseconds>(stop - start);


    //find time it takes to run all 10 mazes WITH threads
    //start runtime timer
    start = high_resolution_clock::now();

     //find all of the mazes and define them in the grid arrays
    int grid [ROW][COL];
    for (int i = 0; i < THR; i++){
        thr[i] = thread([s = &search, grid = grids[i], src, dest](){
            s->aStarSearch(grid, src, dest);
        });
    }
    
    //join all of the threads back up
    for (int i = 0; i < THR; i++){
        thr[i].join();
    }
    //stop runtime timer
    stop = high_resolution_clock::now();
    //calculate runtime
    auto duration2 = duration_cast<microseconds>(stop - start);

    cout << "\n\nA* took " << duration1.count() << " microseconds to solve 10 mazes without threading." << endl;
    cout << "That is " << duration1.count()/10 << " microseconds per maze";
    cout << "\nA* took " << duration2.count() << " microseconds to solve 10 mazes with threading." << endl;
    cout << "That is " << duration2.count()/10 << " microseconds per maze";

    return (0);
}