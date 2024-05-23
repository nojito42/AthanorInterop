// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
	this->bIsEditorOnlyActor = true;
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->bEditable = true;
	this->bActorLabelEditable = true;
	this->bIsEditorOnlyActor = false;
	
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
}
                            
void AMyActor::OnConstruction(const FTransform& Transform)
{
	bIsEditorOnlyActor = false;
	Super::OnConstruction(Transform);
	bIsEditorOnlyActor = false;
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{                              
	Super::Tick(DeltaTime);

}

void AMyActor::changeBPname(const FString& newName)
{
	this->ClearActorLabel();
	this->SetActorLabel(newName);
}

void AMyActor::PrintHelloWorld()
{
	UE_LOG(LogTemp, Warning, TEXT("Hello World!"));
}


