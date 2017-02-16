// Copyright (c) Parallel Thinking Ltd 2016

#include "S05TestingGroundsFPS.h"
#include "CHooseNextWaypoint.h"

EBTNodeResult::Type UCHooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UE_LOG(LogTemp, Warning, TEXT("Hello!"));
	return EBTNodeResult::Succeeded;
}
