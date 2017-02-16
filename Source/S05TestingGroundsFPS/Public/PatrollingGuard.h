// Copyright (c) Parallel Thinking Ltd 2016

#pragma once

#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "PatrollingGuard.generated.h"

/**
 *
 */
UCLASS()
class S05TESTINGGROUNDSFPS_API APatrollingGuard : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
		TArray<AActor*> PatrolPointsCPP;

	TArray<AActor*> GetPatrolPoints();
};
