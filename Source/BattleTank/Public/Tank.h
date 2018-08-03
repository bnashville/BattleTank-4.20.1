// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// forward declarations
class UTankBarrel;
class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Firing)
		void Fire();

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

private:
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

	UPROPERTY(EditDefaultsOnly, Category = "Firing") 
		float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTimeInSeconds = 2;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;

	UTankBarrel* Barrel = nullptr; // TODO Remove

	double LastFireTime = 0;

};
