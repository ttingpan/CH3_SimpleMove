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
	int Step()
	{
		// 최솟값 ~ 최대값 사이 값 랜덤으로 반환
		return FMath::RandRange(0, 1);
	}
	
	// 움직이면서 현재 좌표를 출력
	void Move(const int& Count)
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

	// 두 좌표간 거리
	float Distance(const FVector2D& First, const FVector2D& Second)
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

	// 이벤트 발생
	// Probability : 발생 확률
	void CreateEvent(const float& Probability, const float& Dist)
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
};
