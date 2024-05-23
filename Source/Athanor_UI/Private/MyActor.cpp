// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
	/*try
	{
		Print("Kappa", FColor::Red, 2.0f);
		if (World)
		{
			if (World->IsInstanced())
			{
			
				
				
				Print("PlayingMOdeXDLOLI", FColor::Red);
			}
			else
			{
				bActorLabelEditable = true;
				bEditable = true;
				bIsEditorOnlyActor = true;
				Print("Geditor+", FColor::Green, 1.0f);
				
			}
		}
		else
		{
			Print("notWorld");
			bIsEditorOnlyActor = false;

		}
		
	}
	catch(std::exception& e)
	{
		Print(e.what(), FColor::Red);
	}*/
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	/*bIsEditorOnlyActor = false;*/

	Super::BeginPlay();
}
                            

void AMyActor::PreInitializeComponents()
{
	//Print("PreInitializeComponents", FColor::Green, 1.0f);
	/*bActorLabelEditable = true;
	bEditable = true;
	bIsEditorOnlyActor = false;*/

	Super::PreInitializeComponents();
	/*bIsEditorOnlyActor = false;*/

}

void AMyActor::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	
	/*if (!GetWorld())return;
	if (GetWorld()->IsPlayInEditor())
	{
		Print("PlayingMOdeXDLOLI", FColor::Green, 1.0f);
	}
	else
	{
		bActorLabelEditable = true;
		bEditable = true;
		bIsEditorOnlyActor = true;
		Print("Geditor+", FColor::Green, 1.0f);
	}*/
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
	
		FColor myColor = FColor(FMath::FRandRange(0.0f, 255.0f), FMath::FRandRange(0.0f, 255.0f), FMath::FRandRange(0.0f, 255.0f), FMath::FRandRange(0.0f, 255.0f));
		
		GEngine->AddOnScreenDebugMessage(-1, Duration, myColor, Text);
		

		

	}
}

void AMyActor::OnConstruction(const FTransform& Transform)
{
	/*bActorLabelEditable = true;
	bEditable = true;*/
	Super::OnConstruction(Transform);
	
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


