// Copyright Valter Ronisch 2021

#include "DrawDebugHelpers.h"

#include "Grabber.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Grabber initiated"));
	FindPhysicsHandle();
	InitiateInputComponent();


	
	// ...
	
}
void UGrabber::InitiateInputComponent()
{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s: InputComponent found!"), *GetOwner()->GetName());
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s: InputComponent missing!"), *GetOwner()->GetName());

	}
}

void UGrabber::FindPhysicsHandle() 
{
	PhysicsHandler = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandler)
	{
		//physics is found
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s error: PhysicsHandle not initialised"), *GetOwner()->GetName())
	}
}

void UGrabber::Grab()
{
	UE_LOG(LogTemp, Warning, TEXT("%s: Grabber pressed!"), *GetOwner()->GetName());
	GetFirstPhysicsBodyInReach();
}

void UGrabber::Release()
{
	UE_LOG(LogTemp, Warning, TEXT("%s: Grabber released!"), *GetOwner()->GetName());
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//GetFirstPhysicsBodyInReach();
	/*if (InputComponent->)
	{

	}*/
	
}

FHitResult UGrabber::GetFirstPhysicsBodyInReach() const
{
	FVector Location;
	FRotator Rotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT Location,
		OUT Rotation
	);

	// UE_LOG(LogTemp, Warning, TEXT("Location : %s; rotation: %s"), *Location.ToString(), *Rotation.ToString()); vypisuju location a rottation


	//draw a line 
	FVector LineTraceEnd = Location + Rotation.Vector() * Reach; ///100 cm do vysky
	DrawDebugLine(
		GetWorld(),
		Location,
		LineTraceEnd,
		FColor(0, 255, 0), //zelená
		false, //true pokud by trvala nìjakou dobu
		0.f,
		0,
		5.f
	);

	//kontrola hitu

	FHitResult Hit;

	FCollisionQueryParams TraceParagrams(FName(TEXT("")), false, GetOwner());

	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		Location,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParagrams

	);

	AActor* ActorHit = Hit.GetActor();

	if (ActorHit)
	{
		ActorHit = Hit.GetActor();
		UE_LOG(LogTemp, Warning, TEXT("Actor hit name: %s"), *ActorHit->GetName());
	}

	return Hit;
	// ...
}

