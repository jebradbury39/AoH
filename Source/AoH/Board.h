// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HexagonTile.h"
#include "Board.generated.h"

UCLASS()
class AOH_API ABoard : public AActor
{
	GENERATED_BODY()

	/** Dummy root component */
	UPROPERTY(Category = Grid, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USceneComponent* DummyRoot;

	/** Text component for the score */
	UPROPERTY(Category = Grid, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UTextRenderComponent* ScoreText;
	
public:	
	// Sets default values for this actor's properties
	ABoard();
	ABoard(int rows, int columns, int numBodiesOfWater, int sizeBodiesOfWater);
 
	const int BOARD_SIZE_SMALL = 0;
	const int BOARD_SIZE_MEDIUM = 1;
	const int BOARD_SIZE_LARGE = 2;
	const int TILE_RADIUS = 40.0;

	/** How many blocks have been clicked */
	int32 Score;

	/** Number of blocks along each side of grid */
	UPROPERTY(Category = Grid, EditAnywhere, BlueprintReadOnly)
		int32 Size;

	/** Spacing of blocks */
	UPROPERTY(Category = Grid, EditAnywhere, BlueprintReadOnly)
		float BlockSpacing;

private:
	int rows;
	int columns;
	int numBodiesOfWater;
	int sizeBodiesOfWater;
	double tileWidth;
	double tileRowHeight;
	std::vector<AHexagonTile *> tiles; //Cannot init AHexagonTile without spawn()

protected:
	// Begin AActor interface
	virtual void BeginPlay() override;
	// End AActor interface

public:	
	/** Handle the block being clicked */
	void AddScore();

	void initializeTileDimensions();

	/** Returns DummyRoot subobject **/
	FORCEINLINE class USceneComponent* GetDummyRoot() const { return DummyRoot; }
	/** Returns ScoreText subobject **/
	FORCEINLINE class UTextRenderComponent* GetScoreText() const { return ScoreText; }
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
