// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldPossition.h"

// Sets default values for this component's properties
UWorldPossition::UWorldPossition()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWorldPossition::BeginPlay()
{
	Super::BeginPlay();

	FString Log = TEXT("Hello!");
	FString* PtrLog = &Log; // pointer PtrLog ukazuje na adresu Logu
	PtrLog->Len();

	UE_LOG(LogTemp, Warning, TEXT("%s"), *Log);
	UE_LOG(LogTemp, Warning, TEXT("%s"), **PtrLog); //ukayatel na string a ukayatel na prvni symbol


	FString ObjectName = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("Object name is: %s"), *ObjectName); //FString ObjectName = GetOwner()->GetName(); 

	FString WorldPossition = GetOwner()->GetActorLocation().ToString();
	
	UE_LOG(LogTemp, Warning, TEXT("%s position is: %s"), *ObjectName, *WorldPossition); 

	
}


// Called every frame
void UWorldPossition::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

