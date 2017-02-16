// Copyright (c) Parallel Thinking Ltd 2016

#include "S05TestingGroundsFPS.h"
#include "PatrollingGuard.h"

TArray<AActor*> APatrollingGuard::GetPatrolPoints()
{
	return PatrolPointsCPP;
}
