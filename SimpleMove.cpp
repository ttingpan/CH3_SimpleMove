// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleMove.h"

// Sets default values
ASimpleMove::ASimpleMove()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 시작점 (0,0) 초기화
	start = FVector2d::ZeroVector;
	// 총 이벤트 발생 횟수 초기화
	evCnt = 0;
	// 총 이동 거리 초기화
	totDist = 0;
}

// Called when the game starts or when spawned
void ASimpleMove::BeginPlay()
{
	Super::BeginPlay();
	// 10회 이동
	Move(10);
}

// Called every frame
void ASimpleMove::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

