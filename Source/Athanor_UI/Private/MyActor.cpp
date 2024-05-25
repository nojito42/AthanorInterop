// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
	bActorLabelEditable = true;
	bRunConstructionScriptOnDrag = false;
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
}
                            
// Called every frame
void AMyActor::Tick(float DeltaTime)
{ 
	
	Super::Tick(DeltaTime);

}

void AMyActor::Print(FString Text, FColor Color, float Duration)
{
	if (GEngine)
	{
	
		FColor myColor = FColor(FMath::FRandRange(0.0f, 255.0f), FMath::FRandRange(0.0f, 255.0f), FMath::FRandRange(0.0f, 255.0f), FMath::FRandRange(200.0f, 255.0f));
		
		GEngine->AddOnScreenDebugMessage(-1, Duration, myColor, Text);			

	}
}

void AMyActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	
}

void AMyActor::ChangeBpName(const FString& newName)
{
	bIsEditorOnlyActor = true;
	this->ClearActorLabel();
	this->SetActorLabel(newName);
	bIsEditorOnlyActor = false;
}





