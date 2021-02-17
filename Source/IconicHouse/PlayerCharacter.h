// Copyright IconicHouse Studios

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "PlayerCharacter.generated.h"

class UCameraComponent;

UCLASS()
class ICONICHOUSE_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCameraComponent* EyeCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Movement)
	float WalkSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Movement)
	float RunSpeed;

public:
	APlayerCharacter();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Val);
	void MoveRight(float Val);
};
