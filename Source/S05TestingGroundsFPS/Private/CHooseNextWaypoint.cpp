// Copyright (c) Parallel Thinking Ltd 2016

#include "S05TestingGroundsFPS.h"
#include "CHooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrollingGuard.h" // FIXIT remove coupling

EBTNodeResult::Type UCHooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Get the Patrol Points.
	APatrollingGuard* ControlledGuard = Cast<APatrollingGuard>(OwnerComp.GetAIOwner()->GetPawn());
	TArray<AActor*> PatrolPoints = ControlledGuard->GetPatrolPoints();

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	int32 Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	if (PatrolPoints.Num() > 0)
	{
		BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);
		Index += 1;
		Index = Index % PatrolPoints.Num();
		BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, Index);
	}

	return EBTNodeResult::Succeeded;
}
