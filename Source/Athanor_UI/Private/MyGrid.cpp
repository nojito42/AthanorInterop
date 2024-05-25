// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGrid.h"

AMyGrid::AMyGrid()
{
	AddCoordinates(GridPlayer1,
		FHexagonCoordinates("B", 7),
		FHexagonCoordinates("A", 8),
		FHexagonCoordinates("B", 9),
		FHexagonCoordinates("B", 8));
	AddCoordinates(GridEnemy1,
		FHexagonCoordinates("B", 13),
		FHexagonCoordinates("A", 14),
		FHexagonCoordinates("B", 15),
		FHexagonCoordinates("B", 14));

	AddCoordinates(GridPlayer2,
		FHexagonCoordinates("E", 3),
		FHexagonCoordinates("D", 4),
		FHexagonCoordinates("E", 5),
		FHexagonCoordinates("E", 4));
	AddCoordinates(GridEnemy2,
		FHexagonCoordinates("D", 16),
		FHexagonCoordinates("D", 17),
		FHexagonCoordinates("D", 18),
		FHexagonCoordinates("E", 17));

	AddCoordinates(GridPlayer3,
		FHexagonCoordinates("G", 7),
		FHexagonCoordinates("F", 8),
		FHexagonCoordinates("G", 9),
		FHexagonCoordinates("G", 8));
	AddCoordinates(GridEnemy3,
		FHexagonCoordinates("G", 13),
		FHexagonCoordinates("F", 14),
		FHexagonCoordinates("G", 15),
		FHexagonCoordinates("G", 14));
}

void AMyGrid::ClearAllGrids()
{
	GridPlayer1.Hexagons.Empty();
	GridPlayer2.Hexagons.Empty();
	GridPlayer3.Hexagons.Empty();
	GridEnemy1.Hexagons.Empty();
	GridEnemy2.Hexagons.Empty();
	GridEnemy3.Hexagons.Empty();
	HexagonGrid.Empty();
}


template<typename T, typename... FHexagonCoordinates>
void AMyGrid::AddCoordinates(FHexaPairs& grid, T first, FHexagonCoordinates... rest)
{
	grid.Coords.Add(first);
	AddCoordinates(grid, rest...);


}
void AMyGrid::AddCoordinates(FHexaPairs& grid, FHexagonCoordinates last)
{
	grid.Coords.Add(last);
}

