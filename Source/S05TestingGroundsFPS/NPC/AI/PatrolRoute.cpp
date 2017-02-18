// Copyright (c) Parallel Thinking Ltd 2016

#include "S05TestingGroundsFPS.h"
#include "PatrolRoute.h"

TArray<AActor*> UPatrolRoute::GetPatrolPoints() const
{
	return PatrolPoints;
}
