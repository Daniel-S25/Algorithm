#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h" // AActor�� ���ǵ� ��� ����
#include "MyActor1.generated.h"

UCLASS()
class AMyActor1 : public AActor
{
    GENERATED_BODY() // Unreal Engine Ŭ���� ��ũ��

public:
    // ������
    AMyActor1();

protected:
    // ���� ��ġ
    FVector2D CurrentPosition;

    // BeginPlay �Լ� �������̵�
    virtual void BeginPlay() override;

public:
    // �������� 0 �Ǵ� 1 ��ȯ
    int32 Step();

    // ���� �̵� �Լ�
    void Move();
};