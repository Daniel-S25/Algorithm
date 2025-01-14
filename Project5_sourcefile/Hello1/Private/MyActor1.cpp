#include "MyActor1.h"
#include "Math/UnrealMathUtility.h"
#include "Engine/Engine.h"

// ������: �⺻�� ����
AMyActor1::AMyActor1()
{
    PrimaryActorTick.bCanEverTick = false; // Tick ��Ȱ��ȭ
    CurrentPosition = FVector2D(0, 0);    // ���� ��ġ (0,0)
}

// BeginPlay: ���� ���� �� ȣ��
void AMyActor1::BeginPlay()
{
    Super::BeginPlay();

    // ���� �̵� �Լ� ȣ��
    Move();
}

// Step: �������� 0 �Ǵ� 1 ��ȯ
int32 AMyActor1::Step()
{
    return FMath::RandRange(0, 1); // 0 �Ǵ� 1 ��ȯ
}

// Move: 10ȸ ���� �̵� �� �α� ���
void AMyActor1::Move()
{
    UE_LOG(LogTemp, Log, TEXT("Starting position: (%f, %f)"), CurrentPosition.X, CurrentPosition.Y);

    for (int32 i = 0; i < 10; ++i)
    {
        int32 xStep = Step();
        int32 yStep = Step();

        // �̵� ���� Ȯ��
        if (xStep >= 2 || yStep >= 2)
        {
            UE_LOG(LogTemp, Warning, TEXT("Invalid move detected: step too large."));
            continue; // ��ȿ�� �̵� �ǳʶ�
        }

        // �̵� ����
        CurrentPosition.X += xStep;
        CurrentPosition.Y += yStep;

        // ���� ��ǥ ���
        UE_LOG(LogTemp, Log, TEXT("Step %d: Moved to (%f, %f)"), i + 1, CurrentPosition.X, CurrentPosition.Y);
    }
}
