#ifndef __MAZE_H__
#define __MAZE_H__

#include "Coordinates.h"
#include "Pixel.h"
#include <list>
#include <iostream>
#include <cassert>

using namespace std;

enum class ErrorNum { NoError=0, MazeGrid, NoStartCell, NumOfRowsIsZero, NumOfColsIsZero, NoLeftwall, NoTargetCell, PathNotFound };

// Class representing the Maze
// The Maze will be responsible for solving the puzzle, by moving
// the pixel object from the startcell to the targetcell.
class Maze
{
private:
	Pixel _pixel;
	int* _grid;
	int _numOfRows;
	int _numOfCols;
	int _size;
	list<Coordinates> _path;
	int _startID;
	int _targetID;
	Coordinates _startCell;
	ErrorNum _error;

	static const Coordinates Edelta;
	static const Coordinates Wdelta;
	static const Coordinates Ndelta;
	static const Coordinates Sdelta;

	// Find the startcell in the grid
	// Assuming that the start cell will always be in the first row
	Coordinates findstartcellinmaze(void);

	void handleerror(ErrorNum error);

	bool iswallcell(Coordinates coord);

	bool isycoordoutofbounds(Coordinates coord);

	bool istargetcell(Coordinates coord);

	bool iscellinboundary(Coordinates coord);

	bool iscellempty(Coordinates coord);
	
	Coordinates getleftcell(void);
	
	Coordinates getfrontcell(void);

	void rotateccw(void);

	void rotatecw(void);

	void moveforward(void);

	bool testcellvalue(Coordinates coord, int testval);
	
public:

	Maze(int startID) :_pixel(Direction::S, Coordinates()), _grid(NULL), _numOfRows(0), _numOfCols(0), _size(0), _path({}), _startID(startID), _targetID(3) {}

	// Loads the maze with the gridArray to be solved and the num of rows and cols.
	// Find the start cell and set up the pixel to the start cell.
	bool LoadMaze(int* gridArray, int numOfRows, int numOfCols);

	Coordinates GetStartCell(void) const;

	list<Coordinates> GetPath();

	ErrorNum GetErrorCode(void);
	list<Coordinates> Solve(void);
};

#endif