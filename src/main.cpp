#include <chrono>
#include "a_star.cpp"

using namespace std::chrono;

void defineGrid(int grd[][COL]){
    //open file input stream
    ifstream fin ("maze", ios::in);

    string line;
    int charpos = 0;
    int row = 0, col = 0;

    //convert '#' and ' ' to 0's and 1's
    while(getline(fin, line)){
        cout << line << endl;
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
    //initialize and define grid
    int grid [ROW][COL] = {0};
    defineGrid(grid);
    
    AStar search;
    // Source is the left-most bottom-most corner
    AStar::Pair src = make_pair(1, 1);
 
    // Destination is the left-most top-most corner
    AStar::Pair dest = make_pair(ROW-2, COL-2);
    
    //start runtime timer
    auto start = high_resolution_clock::now();

    //call astar function
    search.aStarSearch(grid, src, dest);

    //stop runtime timer
    auto stop = high_resolution_clock::now();
    //calculate runtime
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nA* took " << duration.count() << " microseconds without threading." << endl;
    return (0);
}