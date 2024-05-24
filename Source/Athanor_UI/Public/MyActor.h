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
	virtual void PreInitializeComponents() override;
	virtual void PostInitializeComponents() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Print(FString Text, FColor Color = FColor(0x9480C5), float Duration = 2.0f);
	virtual void OnConstruction(const FTransform& Transform) override;
	UFUNCTION(BlueprintCallable, Category = "Custom")
	void changeBPname(const FString& newName);
	UFUNCTION(BlueprintCallable, Category = "Debug")
	static void PrintHelloWorld();
	

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "_Custom")
	int col = 0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "_Custom")
	int row = 0;

};


