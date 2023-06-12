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



// 2 is the start cell and 3 is the 
int grid[] =
{
	1, 2, 1, 1, 1, 1,
	1, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 0, 1,
	1, 1, 1, 1, 3, 1,
};

int grid1[] =
{
	1, 2, 1, 1, 1, 1,
	1, 0, 1, 1, 1, 1,
	1, 0, 1, 1, 1, 1,
	1, 0, 1, 1, 1, 1,
	1, 0, 1, 1, 1, 1,
	1, 3, 1, 1, 1, 1,
};

int grid2[] =
{
	1, 1, 2, 1, 1, 1,
	1, 1, 0, 1, 1, 1,
	1, 1, 0, 1, 1, 1,
	1, 1, 0, 1, 1, 1,
	1, 1, 0, 1, 1, 1,
	1, 1, 3, 1, 1, 1,
};

int grid3[] =
{
	1, 1, 1, 2, 1, 1,
	1, 1, 1, 0, 1, 1,
	1, 1, 1, 0, 1, 1,
	1, 1, 1, 0, 1, 1,
	1, 1, 1, 0, 1, 1,
	1, 1, 1, 3, 1, 1,
};

int grid4[] =
{
	1, 1, 1, 1, 2, 1,
	1, 1, 1, 1, 0, 1,
	1, 1, 1, 1, 0, 1,
	1, 1, 1, 1, 0, 1,
	1, 1, 1, 1, 0, 1,
	1, 1, 1, 1, 3, 1,
};

int grid5[] =
{
	1, 1, 1, 1, 1, 2,
	1, 1, 1, 1, 1, 0,
	1, 1, 1, 1, 1, 0,
	1, 1, 1, 1, 1, 0,
	1, 1, 1, 1, 1, 0,
	1, 1, 1, 1, 1, 3,
};

int grid6[] =
{
	1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 0,
	1, 1, 1, 1, 1, 0,
	1, 1, 1, 1, 1, 0,
	1, 1, 1, 1, 1, 0,
	1, 1, 1, 1, 1, 3,
};

int grid7[] =
{
	1, 1, 1, 1, 1, 0,
	1, 1, 1, 1, 1, 0,
	1, 1, 1, 1, 1, 0,
	1, 1, 1, 1, 1, 0,
	1, 1, 1, 1, 1, 0,
	1, 1, 1, 1, 1, 3,
};

int grid8[] =
{
	1, 1, 1, 1, 1, 2,
	1, 1, 1, 1, 1, 0,
	1, 1, 1, 1, 1, 0,
	1, 1, 1, 1, 1, 0,
	1, 1, 1, 1, 1, 0,
	1, 1, 1, 1, 1, 1,
};

int grid9[] =
{
	1, 1, 1, 1, 1, 2,
	1, 1, 1, 1, 1, 0,
	1, 1, 1, 1, 1, 0,
	1, 1, 1, 1, 1, 0,
	1, 1, 1, 1, 1, 0,
	1, 1, 1, 1, 1, 0,
};



int main()
{

	Maze myMaze(2);
	if (myMaze.LoadMaze(&grid[0], 6, 6) == false)
	{
		// If load fails exit
		return 0;
	}
	myMaze.Solve();

	/*
	Maze myMaze1(2);
	if (myMaze1.LoadMaze(&grid1[0], 6, 6) == false)
	{
		// If load fails exit
		return 0;
	}
	myMaze1.FindHallwayPath();
	assert(myMaze1.GetErrorCode() == ErrorNum::NoError);

	Maze myMaze2(2);
	if (myMaze2.LoadMaze(&grid2[0], 6, 6) == false)
	{
		// If load fails exit
		return 0;
	}
	myMaze2.FindHallwayPath();
	assert(myMaze2.GetErrorCode() == ErrorNum::NoError);

	Maze myMaze3(2);
	if (myMaze3.LoadMaze(&grid3[0], 6, 6) == false)
	{
		// If load fails exit
		return 0;
	}
	myMaze3.FindHallwayPath();
	assert(myMaze3.GetErrorCode() == ErrorNum::NoError);

	Maze myMaze4(2);
	if (myMaze4.LoadMaze(&grid4[0], 6, 6) == false)
	{
		// If load fails exit
		return 0;
	}
	myMaze4.FindHallwayPath();
	assert(myMaze4.GetErrorCode() == ErrorNum::NoError);


	Maze myMaze5(2);
	if (myMaze5.LoadMaze(&grid5[0], 6, 6) == false)
	{
		// If load fails exit
		return 0;
	}
	myMaze5.FindHallwayPath();
	assert(myMaze5.GetErrorCode() == ErrorNum::NoError);


	Maze myMaze6(2);
	myMaze6.LoadMaze(&grid6[0], 6, 6);
	assert(myMaze6.GetErrorCode() == ErrorNum::NoStartCell);


	Maze myMaze7(2);
	myMaze7.LoadMaze(&grid7[0], 6, 6);
	assert(myMaze7.GetErrorCode() == ErrorNum::NoStartCell);

	Maze myMaze8(2);
	if (myMaze8.LoadMaze(&grid8[0], 6, 6) == false)
	{

	}
	myMaze8.FindHallwayPath();
	assert(myMaze8.GetErrorCode() == ErrorNum::NoTargetCell);

	Maze myMaze9(2);
	if (myMaze9.LoadMaze(&grid9[0], 6, 6) == false)
	{

	}
	myMaze9.FindHallwayPath();
	assert(myMaze9.GetErrorCode() == ErrorNum::NoTargetCell);
	*/
	return 0;
}
