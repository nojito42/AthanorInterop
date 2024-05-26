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

void AMyGrid::SetupAthanGrids(bool IsPlayer, int Index, UMaterialInterface* M1, UMaterialInterface* M2)
{
	AMyHexagon* Hex = HexagonGrid[Index];

	if (IsPlayer)
	{
		SetupMeshForAthanGrid(GridPlayer1, Hex, M1, M2);
		SetupMeshForAthanGrid(GridPlayer2, Hex, M1, M2);
		SetupMeshForAthanGrid(GridPlayer3, Hex, M1, M2);
	}

	else
	{
		SetupMeshForAthanGrid(GridEnemy1, Hex, M1, M2);
		SetupMeshForAthanGrid(GridEnemy2, Hex, M1, M2);
		SetupMeshForAthanGrid(GridEnemy3, Hex, M1, M2);
	}



}



void AMyGrid::SetupMeshForAthanGrid(FHexaPairs& Pwn, AMyHexagon*& Hex, UMaterialInterface* M1, UMaterialInterface* M2)
{
	if (!Pwn.Coords.Contains(Hex->HexCoords)) return;

	Hex->_Mesh_1->SetMaterial(0, M1);
	Hex->_Mesh_2->SetMaterial(0, M2);

	Pwn.Hexagons.Add(Hex);
}
FTransform AMyGrid::ComputeTransform(int rowIndex, int colIndex, float margin) {
	float hexWidth = ComputeCoord(4.0f, 0.75f, margin);
	float halfHexHeight = ComputeCoord(3.0f, 0.5f, margin);
	float rowHeight = ComputeCoord(3.0f, rowIndex, margin);
	float totalWidth = colIndex * hexWidth;
	float totalHeight = halfHexHeight + rowHeight;

	return  (colIndex % 2 == 1) ? FTransform(FVector(totalHeight, totalWidth, 0)) : FTransform(FVector(rowHeight, totalWidth, 0));
}


float AMyGrid::ComputeCoord(float VtoSqrt, float Index,float margin)
{
	return (Scale * 100 + margin) * FMath::Sqrt(VtoSqrt) * Index;
}

