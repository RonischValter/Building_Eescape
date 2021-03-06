// Copyright Valter Ronisch 2021

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h" 


#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDING_EESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);

private:
	float StartingYaw;
	float CurrentYaw;

	UPROPERTY(EditAnywhere)
	float TargetYaw = -90.f;
	
	UPROPERTY(EditAnywhere)
	ATriggerVolume * PreassurePlate;

	UPROPERTY(EditAnywhere)
	AActor	*ActorThatOpens;


	float DoorLastOpened = 0.0f;

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = .5f;

	UPROPERTY(EditAnywhere)
	float DoorOpenSpeed = 1.0f;

	UPROPERTY(EditAnywhere)
	float DoorCloseSpeed = 2.0f;



};
