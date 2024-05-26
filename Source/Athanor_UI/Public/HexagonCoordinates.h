
#pragma once

#include "CoreMinimal.h"
#include "HexagonCoordinates.generated.h"

USTRUCT(BlueprintType)
struct FHexagonCoordinates
{
	GENERATED_BODY()
public:
	FHexagonCoordinates();
	FHexagonCoordinates(FString r, int32 c);

	UPROPERTY(BlueprintReadWrite, Category = "Hexagon")
	FString Row;

	UPROPERTY(BlueprintReadWrite, Category = "Hexagon")
	int32 Column;

	bool operator==(const FHexagonCoordinates& Other) const
	{
		return Row == Other.Row && Column == Other.Column;
	}
};