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

	/******************/
	/*     Test 1     */
	/******************/
	cout << endl << "/*     Test 1     */" << endl;
	int grid[] =
	{
		1, 2, 1, 1, 1, 1,
		1, 0, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 3, 1,
	};

	Maze myMaze(2);
	if (myMaze.LoadMaze(&grid[0], 6, 6) == false)
	{
		// If load fails exit
		return 0;
	}
	myMaze.SolveMaze();
	assert(myMaze.GetErrorCode() == ErrorNum::NoError);

	/******************/
	/*     Test 2     */
	/******************/
	cout << endl << "/*     Test 2     */" << endl;
	int grid1[] =
	{
		2, 1, 1, 1, 1, 1,
		0, 1, 1, 1, 1, 1,
		0, 0, 0, 0, 0, 1,
		0, 0, 0, 0, 0, 1,
		0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 3, 1,
	};


	Maze myMaze1(2);
	if (myMaze1.LoadMaze(&grid1[0], 6, 6) == false)
	{
		// If load fails exit
		return 0;
	}
	myMaze1.SolveMaze();
	assert(myMaze1.GetErrorCode() == ErrorNum::NoError);

	/******************/
	/*     Test 3     */
	/******************/
	cout << endl << "/*     Test 3     */" << endl;
	int grid2[] =
	{
		1, 1, 1, 2, 1, 1,
		1, 1, 1, 0, 1, 1,
		1, 1, 1, 0, 0, 0,
		1, 1, 1, 0, 0, 0,
		1, 1, 1, 0, 0, 0,
		1, 1, 1, 1, 1, 3,
	};


	Maze myMaze2(2);
	if (myMaze2.LoadMaze(&grid2[0], 6, 6) == false)
	{
		// If load fails exit
		return 0;
	}
	myMaze2.SolveMaze();
	assert(myMaze2.GetErrorCode() == ErrorNum::NoError);


	/******************/
	/*     Test 4     */
	/******************/
	cout << endl << "/*     Test 4     */" << endl;

	// negative tests
	int grid3[] =
	{
		1, 2, 1, 1, 1, 1,
		1, 0, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 1,
		1, 1, 1, 0, 1, 1,
		1, 1, 1, 3, 1, 1,
	};


	Maze myMaze3(2);
	if (myMaze3.LoadMaze(&grid3[0], 6, 6) == false)
	{
		// If load fails exit
		return 0;
	}
	myMaze3.SolveMaze();
	assert(myMaze3.GetErrorCode() == ErrorNum::CW_CCWTurnsDone);

	/******************/
	/*     Test 5     */
	/******************/
	cout << endl << "/*     Test 5     */" << endl;
	int grid4[] =
	{
		1, 2, 1, 1, 1, 1,
		1, 0, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 1,
		1, 1, 1, 0, 1, 1,
		1, 1, 1, 1, 1, 1,
	};

	// positive tests
	Maze myMaze4(2);
	if (myMaze4.LoadMaze(&grid4[0], 6, 6) == false)
	{
		// If load fails exit
		return 0;
	}
	myMaze4.SolveMaze();
	assert(myMaze4.GetErrorCode() == ErrorNum::CW_CCWTurnsDone);

	return 0;
}
