#include "MyActor1.h"
#include "Math/UnrealMathUtility.h"
#include "Engine/Engine.h"

// 생성자: 기본값 설정
AMyActor1::AMyActor1()
{
    PrimaryActorTick.bCanEverTick = false; // Tick 비활성화
    CurrentPosition = FVector2D(0, 0);    // 시작 위치 (0,0)
}

// BeginPlay: 액터 스폰 시 호출
void AMyActor1::BeginPlay()
{
    Super::BeginPlay();

    // 랜덤 이동 함수 호출
    Move();
}

// Step: 랜덤으로 0 또는 1 반환
int32 AMyActor1::Step()
{
    return FMath::RandRange(0, 1); // 0 또는 1 반환
}

// Move: 10회 랜덤 이동 및 로그 출력
void AMyActor1::Move()
{
    UE_LOG(LogTemp, Log, TEXT("Starting position: (%f, %f)"), CurrentPosition.X, CurrentPosition.Y);

    for (int32 i = 0; i < 10; ++i)
    {
        int32 xStep = Step();
        int32 yStep = Step();

        // 이동 조건 확인
        if (xStep >= 2 || yStep >= 2)
        {
            UE_LOG(LogTemp, Warning, TEXT("Invalid move detected: step too large."));
            continue; // 무효한 이동 건너뜀
        }

        // 이동 수행
        CurrentPosition.X += xStep;
        CurrentPosition.Y += yStep;

        // 현재 좌표 출력
        UE_LOG(LogTemp, Log, TEXT("Step %d: Moved to (%f, %f)"), i + 1, CurrentPosition.X, CurrentPosition.Y);
    }
}
