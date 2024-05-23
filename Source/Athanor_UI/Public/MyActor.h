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
	
	// Sets default values for this actor's properties
	AMyActor();
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category = "Player")
	FString Anthoneed;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION(BlueprintCallable, Category = "Custom")
	void changeBPname(const FString& newName);
	UFUNCTION(BlueprintCallable, Category = "Debug")
	static void PrintHelloWorld();
	

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "_Custom")
	int col;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "_Custom")
	int row;

};



