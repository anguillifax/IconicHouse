// Copyright IconicHouse Studios

#pragma once

#include "Components/SceneCaptureComponent2D.h"
#include "CoreMinimal.h"

#include "ViewerSceneCaptureComponent2D.generated.h"

/**
 *
 */
UCLASS(ClassGroup=(Iconic), meta=(BlueprintSpawnableComponent))
class UViewerSceneCaptureComponent2D : public USceneCaptureComponent2D
{
	GENERATED_BODY()

public:
	virtual const AActor* GetViewOwner() const override
	{
		return GetOwner();
	}
};
