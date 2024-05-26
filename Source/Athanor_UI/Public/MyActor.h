// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/Engine.h"
#include "MyActor.generated.h"


UCLASS()
class ATHANOR_UI_API AMyActor : public AActor
{
	GENERATED_BODY()
public:
	UWorld* World = GetWorld(); // Get the UWorld instance

	// Sets default values for this actor's properties
	AMyActor();
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category = "Player")
	FString Anthoneed;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, Category = "Custom")
	void Print(FString Text, FColor Color = FColor::Cyan, float Duration = 2.0f);
	virtual void OnConstruction(const FTransform& Transform) override;
	UFUNCTION(BlueprintCallable, Category = "Custom")
	void ChangeBpName(const FString& newName);

	
};
