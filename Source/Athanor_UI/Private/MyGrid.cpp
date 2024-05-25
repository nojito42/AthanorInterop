// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGrid.h"

AMyGrid::AMyGrid()
{
	GridPlayer1.Coords = {
		FHexagonCoordinates("B", 7),
		FHexagonCoordinates("A", 8),
		FHexagonCoordinates("B", 9),
		FHexagonCoordinates("B", 8)
	};
	GridEnemy1.Coords = {
		FHexagonCoordinates("B", 13),
		FHexagonCoordinates("A", 14),
		FHexagonCoordinates("B", 15),
		FHexagonCoordinates("B", 14) };

	GridPlayer2.Coords = {
		FHexagonCoordinates("E", 3),
		FHexagonCoordinates("D", 4),
		FHexagonCoordinates("E", 5),
		FHexagonCoordinates("E", 4) };
	GridEnemy2.Coords = {
		FHexagonCoordinates("D", 16),
		FHexagonCoordinates("D", 17),
		FHexagonCoordinates("D", 18),
		FHexagonCoordinates("E", 17) };

	GridPlayer3.Coords = {
		FHexagonCoordinates("G", 7),
		FHexagonCoordinates("F", 8),
		FHexagonCoordinates("G", 9),
		FHexagonCoordinates("G", 8) };
	GridEnemy3.Coords = {
		FHexagonCoordinates("G", 13),
		FHexagonCoordinates("F", 14),
		FHexagonCoordinates("G", 15),
		FHexagonCoordinates("G", 14) };
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

