// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHexagon.h"

// Sets default values
AMyHexagon::AMyHexagon()
{
    _Mesh_1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh_1"));
    _Mesh_2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh_2"));
    _Mesh_3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh_3"));
    _Text = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Text"));
    _Text->SetHorizontalAlignment(EHTA_Center);
    _Text->SetVerticalAlignment(EVRTA_TextCenter);
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    
    // Attach the mesh components to the root component
    _Mesh_1->SetupAttachment(RootComponent);
    _Text->SetupAttachment(_Mesh_1);
    _Mesh_2->SetupAttachment(_Mesh_1);
    _Mesh_3->SetupAttachment(_Mesh_1);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    FVector transformScale = GetTransform().GetScale3D();
    _Text->SetWorldScale3D(FVector(1 / transformScale.X, 1 / transformScale.Y, 1 / transformScale.Z));
  

}

// Called when the game starts or when spawned
void AMyHexagon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyHexagon::Tick(float DeltaTime)
{
   
	Super::Tick(DeltaTime);

}

FHexagonCoordinates AMyHexagon::ComputeCoordinate(int row, int column)
{
    FHexagonCoordinates coordinates;
    coordinates.Row = FString::Printf(TEXT("%c"), 'A' + row);
    coordinates.Column = column + 1;
    HexCoords = coordinates;
    _Text->SetText(FText::FromString(HexagonCoordinatesToString(coordinates)));
    this->ChangeBpName(HexagonCoordinatesToString(coordinates));
    return HexCoords;
}

