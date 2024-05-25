// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyActor.h"
#include "HexagonCoordinates.h"
#include "MyGrid.generated.h"

class AMyHexagon;
USTRUCT(BlueprintType)
struct FHexaPairs
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player")
	TArray<AMyHexagon*> Hexagons;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player")
	TArray<FHexagonCoordinates> Coords;
};
UCLASS()
class ATHANOR_UI_API AMyGrid : public AMyActor
{
	GENERATED_BODY()
	
public:
	AMyGrid();
#pragma region Grids
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Hexagons")
	TArray<AMyHexagon*> HexagonGrid;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player")
	FHexaPairs GridPlayer1;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player")
	FHexaPairs GridPlayer2;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player")
	FHexaPairs GridPlayer3;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Enemy")
	FHexaPairs GridEnemy1;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Enemy")
	FHexaPairs GridEnemy2;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Enemy")
	FHexaPairs GridEnemy3;


	UFUNCTION(BlueprintCallable, Category = "Custom")
	void ClearAllGrids();

	template<typename T, typename... FHexagonCoordinates>
	void AddCoordinates(FHexaPairs& grid, T first, FHexagonCoordinates... rest);

	void AddCoordinates(FHexaPairs& grid, FHexagonCoordinates last);
#pragma endregion
protected:
private:
};

