// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyActor.h"
#include "HexagonCoordinates.h"
#include "MyHexagon.h"
#include "MyGrid.generated.h"

USTRUCT(BlueprintType)
struct FHexaPairs
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player")
	TArray<AMyHexagon*> Hexagons;

	UPROPERTY(BlueprintReadWrite, Category = "Player")
	TArray<FHexagonCoordinates> Coords;
};
UCLASS()
class ATHANOR_UI_API AMyGrid : public AMyActor
{
	GENERATED_BODY()

public:
	AMyGrid();
#pragma region Grids
#pragma region Fields

#pragma region GridFields

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Grid")
	TArray<AMyHexagon*> HexagonGrid;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Grid")
	int Columns;


	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Grid")
	int Rows;


	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Grid")
	float Scale;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Grid")
	float Offset;


#pragma endregion


#pragma region AthanGrid
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Grid/Player")
	FHexaPairs GridPlayer1;


	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Grid/Player")
	FHexaPairs GridPlayer2;


	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Grid/Player")
	FHexaPairs GridPlayer3;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Grid/Enemy")
	FHexaPairs GridEnemy1;


	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Grid/Enemy")
	FHexaPairs GridEnemy2;


	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Grid/Enemy")
	FHexaPairs GridEnemy3;
#pragma endregion

#pragma endregion
#pragma region Methods
	UFUNCTION(BlueprintCallable, Category = "Grid")
	void ClearAllGrids();

	UFUNCTION(BlueprintCallable, Category = "Grid")
	void SetupAthanGrids(bool IsPlayer,int Index,UMaterialInterface* M1, UMaterialInterface* M2);



	UFUNCTION(BlueprintCallable, Category = "Grid")
	FTransform ComputeTransform(int IndexRaws, int IndexCols,float margin);






private:
	void SetupMeshForAthanGrid(FHexaPairs& Pwn, AMyHexagon*& Hex, UMaterialInterface* M1, UMaterialInterface* M2);
	float ComputeCoord(float VtoSqrt, float index,float margin);
#pragma endregion
#pragma endregion


protected:
private:
};

