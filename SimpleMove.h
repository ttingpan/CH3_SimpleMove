// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SimpleMove.generated.h"

UCLASS()
class CH3_SIMPLEMOVE_API ASimpleMove : public AActor
{
	GENERATED_BODY()

private:
	// 시작점 좌표
	FVector2d start;
	// 총 이벤트 발생 횟수
	int evCnt;
	// 총 이동 거리
	float totDist;
	
public:	
	// Sets default values for this actor's properties
	ASimpleMove();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 0혹은 1을 랜덤으로 반환
	int Step();
	
	// 움직이면서 현재 좌표를 출력
	void Move(const int& Count);

	// 두 좌표간 거리
	float Distance(const FVector2D& First, const FVector2D& Second);

	// 이벤트 발생
	// Probability : 발생 확률
	void CreateEvent(const float& Probability, const float& Dist);
};
