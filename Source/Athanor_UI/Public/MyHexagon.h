// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TextRenderComponent.h"
#include "MyActor.h"
#include "HexagonCoordinates.h"
#include "MyHexagon.generated.h"


UCLASS()
class ATHANOR_UI_API AMyHexagon : public AMyActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyHexagon();
#pragma region Fields
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "_Fields")
	UStaticMeshComponent* _Mesh_1;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "_Fields")
	UStaticMeshComponent* _Mesh_2;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "_Fields")
	UStaticMeshComponent* _Mesh_3;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "_Fields")
	UTextRenderComponent* _Text;
#pragma endregion Fields

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, Category = "Custom")
	FHexagonCoordinates ComputeCoordinate(int row, int column);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "_Fields")
	FHexagonCoordinates HexCoords;

	UFUNCTION(BlueprintCallable, Category = "Custom")
	static FString HexagonCoordinatesToString(const FHexagonCoordinates& Coordinates)
	{
		return FString::Printf(TEXT("[%s, %d]"), *Coordinates.Row, Coordinates.Column);
	}
};
