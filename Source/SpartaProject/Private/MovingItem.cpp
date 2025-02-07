#include "MovingItem.h"

AMovingItem::AMovingItem()
{
		SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
		SetRootComponent(SceneRoot);

		StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
		StaticMeshComp->SetupAttachment(SceneRoot);

		static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/Pillar_50x500.Pillar_50x500"));
		if (MeshAsset.Succeeded())
		{
			StaticMeshComp->SetStaticMesh(MeshAsset.Object);
		}

		static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Props/Materials/M_Bush.M_Bush"));
		if (MaterialAsset.Succeeded())
		{
			StaticMeshComp->SetMaterial(0, MaterialAsset.Object);

		}

		PrimaryActorTick.bCanEverTick = true;
		RotationSpeed = 90.0f;

}

void AMovingItem::BeginPlay()
{
    Super::BeginPlay();
	SetActorLocation(FVector(300.0f, 200.0f, 450.0f));
	SetActorRotation(FRotator(0.0f, 90.0f, 0.0f));
	SetActorScale3D(FVector(1.0f));
}

void AMovingItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	AddActorLocalRotation(FRotator( 0.0f, 0.0f, RotationSpeed * DeltaTime));

}
