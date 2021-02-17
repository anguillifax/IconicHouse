// Copyright IconicHouse Studios

#include "PlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	RunSpeed = 1000.f;
	WalkSpeed = 500.0f;

	EyeCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("EyeCamera"));
	EyeCamera->SetupAttachment(GetCapsuleComponent());
	EyeCamera->SetRelativeLocation(FVector(0, 0, 64.f));
	EyeCamera->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
}

void APlayerCharacter::MoveForward(float Val)
{
	if (Val != 0.0f) {
		AddMovementInput(GetActorForwardVector(), Val);
	}
}

void APlayerCharacter::MoveRight(float Val)
{
	if (Val != 0.0f) {
		AddMovementInput(GetActorRightVector(), Val);
	}
}
