#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h" // AActor가 정의된 헤더 포함
#include "MyActor1.generated.h"

UCLASS()
class AMyActor1 : public AActor
{
    GENERATED_BODY() // Unreal Engine 클래스 매크로

public:
    // 생성자
    AMyActor1();

protected:
    // 현재 위치
    FVector2D CurrentPosition;

    // BeginPlay 함수 오버라이드
    virtual void BeginPlay() override;

public:
    // 랜덤으로 0 또는 1 반환
    int32 Step();

    // 랜덤 이동 함수
    void Move();
};