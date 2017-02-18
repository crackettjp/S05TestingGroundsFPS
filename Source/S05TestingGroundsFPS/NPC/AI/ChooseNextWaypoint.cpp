// Copyright (c) Parallel Thinking Ltd 2016

#include "S05TestingGroundsFPS.h"
#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolRoute.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Get the Patrol Points.
	UPatrolRoute* PatrolRoute = OwnerComp.GetAIOwner()->GetPawn()->FindComponentByClass<UPatrolRoute>();
	if (!ensure(PatrolRoute))
	{
		return EBTNodeResult::Failed;
	}
	TArray<AActor*> PatrolPoints = PatrolRoute->GetPatrolPoints();
	if (PatrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s PatrolRoute component has no patrol points"), *OwnerComp.GetAIOwner()->GetPawn()->GetName());
		return EBTNodeResult::Failed;
	}

	// Set the next way point.
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	int32 Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	// Cycle the way point.
	Index += 1;
	Index = Index % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, Index);

	return EBTNodeResult::Succeeded;
}
