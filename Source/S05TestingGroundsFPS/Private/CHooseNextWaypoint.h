// Copyright (c) Parallel Thinking Ltd 2016

#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "CHooseNextWaypoint.generated.h"

/**
 * 
 */
UCLASS()
class UCHooseNextWaypoint : public UBTTaskNode
{
	GENERATED_BODY()
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
