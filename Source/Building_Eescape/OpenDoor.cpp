// Copyright Valter Ronisch 2021


#include "OpenDoor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	FRotator CurrentRotation = GetOwner()->GetActorRotation();
	StartingYaw = CurrentRotation.Yaw;
	CurrentYaw = StartingYaw;
	TargetYaw += StartingYaw;

	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PreassurePlate)
	{
		UE_LOG(LogTemp, Error, TEXT("Actor %s has Open Door on it but no PreassurePlate assigned"), *GetOwner()->GetName());
	}
	// ...
	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PreassurePlate && PreassurePlate->IsOverlappingActor(ActorThatOpens))
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlaping"));
		OpenDoor(DeltaTime);
		DoorLastOpened = GetWorld()->GetTimeSeconds();
	}
	else
	{
		if (GetWorld()->GetTimeSeconds() - DoorLastOpened > DoorCloseDelay)
		{
			CloseDoor(DeltaTime);
		}
	}

	//UE_LOG(LogTemp, Warning, TEXT("Yaw is: %f"), GetOwner()->GetActorRotation().Yaw);


	// ...
}

void UOpenDoor::OpenDoor(float DeltaTime)
{
	CurrentYaw = FMath::Lerp(CurrentYaw, TargetYaw, DeltaTime * DoorOpenSpeed);
	FRotator CurrentRotation = GetOwner()->GetActorRotation();
	CurrentRotation.Yaw = CurrentYaw;

	GetOwner()->SetActorRotation(CurrentRotation);
}

void UOpenDoor::CloseDoor(float DeltaTime)
{
	CurrentYaw = FMath::Lerp(CurrentYaw, StartingYaw, DeltaTime * DoorCloseSpeed);
	FRotator CurrentRotation = GetOwner()->GetActorRotation();
	CurrentRotation.Yaw = CurrentYaw;

	GetOwner()->SetActorRotation(CurrentRotation);
}

