#include "BricksData.h"
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
// Initialize data structures to the initial position:
//  1  2  3  4
//  5  6  7  8
//  9 10 11 12
// 13 14 15
BricksData::BricksData(){
    // TO DO
    Shuffle();
}


// If 'toMove' is a legal brick to move then update the data
// structures, add the moved bricks to 'brickList, and return the
// direction of the move
// Otherwise return the move direction 'None'
BricksData::Movement BricksData::Move(int toMove, std::vector<int>& brickList){
    // TO DO
    int pos = 0;
    for(int i = 0;i<16;++i){
        if(brickList.at(i)==0)
            pos = i;
    }
    if((pos)>0&&brickList.at(pos-1)){
        return Left;
    }
    else if((pos)>3&&brickList.at(pos-4)){
        return Up;
    }
    else if((pos)<15&&brickList.at(pos+1)){
        return Right;
    }
    else if((pos)<12&&brickList.at(pos+4)){
        return Down;
    }
    return None;
}

// Add all brick numbers in according order to their current
// position (use '0' for the empty square)
// The order for the initial positions is:
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 0
void BricksData::Positions(std::vector<int>& brickList){
    // TO DO
    //brickList.insert(2);
    for(int* i:rad){
        brickList.push_back(*i);
    }
}

// Reset the data structures to the initial position
void BricksData::Reset(){
    // TO DO
    for(int i = 0; i<4;++i){
        for(int j = 0; j<4; ++j){
            if(i==3&&j==3)
                rad[3][3] = 0;
            else{
                rad[i][j] = (i*4+j+1);
            }
        }
    }

}

// Shuffle the bricks to random positions
void BricksData::Shuffle(){
    // TO DO
    srand(time(NULL)*time(NULL));
    int x=0,y=0;
    for(int i=0;i<16;++i){
        for(int j=0;rad[x][y]!=0;++j){
            x = rand()%4;
            y = rand()%4;
        }
        rad[x][y] = i;
    }

}

// Return 'true' if the puzzle is solved, i.e. all bricks are in
// their initial positions
bool BricksData::Check(){
    // TO DO
    bool correct = true;
     for(int i = 0; i<4;++i){
        for(int j = 0; j<4; ++j){
            if(i==3&&j==3)
                continue;
            else if(rad[i][j] != (i*4+j+1)){
                correct = false;
                break;
            }
        }
        if(!correct)
            break;
    }
    return correct;
}
