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

int ASimpleMove::Step()
{
	// 최솟값 ~ 최대값 사이 값 랜덤으로 반환
	return FMath::RandRange(0, 1);
}

void ASimpleMove::Move(const int& Count)
{
	UE_LOG(LogTemp, Warning, TEXT("%d회 이동 시작. 현재 위치: (%d, %d)"), Count, (int)start.X, (int)start.Y);
		
	for (int i = 0; i < Count; i++)
	{
		// 움직이기 전 좌표
		float startX = start.X;
		float startY = start.Y;

		// x, y 각각 랜덤으로 이동 거리 지정
		int dx = Step();
		int dy = Step();
		start.X += dx;
		start.Y += dy;

		UE_LOG(LogTemp, Warning, TEXT("x = %d, y = %d 이동. 현재 위치: (%d, %d)"), dx, dy, (int)start.X, (int)start.Y);

		// 현재 이동한 거리 계산
		float dist = Distance(FVector2d(startX, startY), start);

		// 50% 확률로 이벤트 발생
		CreateEvent(50.0f, dist);
	}

	UE_LOG(LogTemp, Warning, TEXT("총 발생한 이벤트 횟수 : %d"), evCnt);
	UE_LOG(LogTemp, Warning, TEXT("총 이동한 거리 : %.2f"), totDist);
}

float ASimpleMove::Distance(const FVector2D& First, const FVector2D& Second)
{
	// a^2 + b^2 = c^2 (피타고라스 정리)
	// a = x값의 차
	float dx = First.X - Second.X;
	// b = y값의 차
	float dy = First.Y - Second.Y;
	// c = 각 값을 제곱하고 더한 다음 루트를 씌워서 구함
	float dist = FMath::Sqrt(dx*dx + dy*dy);
		
	// 총 이동 거리에 현재 이동한 거리 추가
	totDist += dist;
		
	return dist;
}

void ASimpleMove::CreateEvent(const float& Probability, const float& Dist)
{
	int RandomValue = FMath::RandRange(1, 100); // 1 ~ 100의 난수 생성
	if (RandomValue <= Probability) // 이벤트 발생
	{
		// 총 이벤트 발생 횟수 증가
		evCnt++;
		UE_LOG(LogTemp, Warning, TEXT("이벤트가 발생 했습니다!"));

		// 이동한 거리 출력
		UE_LOG(LogTemp, Warning, TEXT("이동한 거리 : %.2f"), Dist);
	}
	else // 이벤트 미발생
	{
		UE_LOG(LogTemp, Warning, TEXT("이벤트가 발생하지 않았습니다."));
	}
}


