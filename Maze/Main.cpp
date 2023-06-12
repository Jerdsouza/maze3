// Maze.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <cassert>
#include "Coordinates.h"
#include "Pixel.h"
#include "Maze.h"
#include <cassert>

using namespace std;


int main()
{
	
	int grid[] =
	{
		1, 2, 1, 1, 1, 1,
		1, 0, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 1,
		1, 1, 1, 3, 1, 1,
	};

	// positive tests
	Maze myMaze(2);
	if (myMaze.LoadMaze(&grid[0], 6, 6) == false)
	{
		// If load fails exit
		return 0;
	}
	myMaze.SolveMaze();
	assert(myMaze.GetErrorCode() == ErrorNum::NoError);
	


	int grid1[] =
	{
		1, 2, 1, 1, 1, 1,
		1, 0, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 1,
		1, 1, 1, 0, 1, 1,
		1, 1, 1, 3, 1, 1,
	};

	// positive tests
	Maze myMaze1(2);
	if (myMaze1.LoadMaze(&grid1[0], 6, 6) == false)
	{
		// If load fails exit
		return 0;
	}
	myMaze1.SolveMaze();
	assert(myMaze1.GetErrorCode() == ErrorNum::NoError);
	

	int grid3[] =
	{
		1, 2, 1, 1, 1, 1,
		1, 0, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 1,
		1, 1, 1, 0, 1, 1,
		1, 1, 1, 1, 1, 1,
	};

	// positive tests
	Maze myMaze3(2);
	if (myMaze3.LoadMaze(&grid3[0], 6, 6) == false)
	{
		// If load fails exit
		return 0;
	}
	myMaze3.SolveMaze();
	assert(myMaze3.GetErrorCode() == ErrorNum::NoTargetCell);

	return 0;
}
