
#pragma once

#include "CoreMinimal.h"
#include "HexagonCoordinates.generated.h"

USTRUCT(BlueprintType)
struct FHexagonCoordinates
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Hexagon")
	FString Row;

	UPROPERTY(BlueprintReadWrite, Category = "Hexagon")
	int32 Column;
};