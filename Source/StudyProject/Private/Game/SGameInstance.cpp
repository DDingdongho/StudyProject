#include "Game/SGameInstance.h"
#include "SUnrealObjectClass.h"
#include "Examples/SFlyable.h"
#include "Examples/SPigeon.h"
#include "JsonObjectConverter.h"
#include "UObject/SavePackage.h"

USGameInstance::USGameInstance()
{
    UE_LOG(LogTemp, Log, TEXT("USGameInstance::USGameInstance() has been called."));

    Name = TEXT("USGameInstance Class Default Object");
    // CDO의 Name 속성에 저장됨.
    // 중단점을 걸어보면 언리얼 에디터가 실행되기 전에 호출됨을 알 수 있음.
}

void USGameInstance::Init()
{
    Super::Init(); // 엔진 업데이트 루틴을 지키기 위해서, 언리얼 엔지니어가 작성한 코드가 먼저 실행되게끔 하기 위함.

    TMap<int32, FString> BirdMap;
    BirdMap.Add(5, TEXT("Pigeon"));
    BirdMap.Add(2, TEXT("Owl"));
    BirdMap.Add(7, TEXT("Albatross"));
    // BirdMap == [
    //  { Key: 5, Value: "Pigeon"     },
    //  { Key: 2, Value: "Owl"        },
    //  { Key: 7, Value: "Albatross"  }
    // ]

    BirdMap.Add(2, TEXT("Penquin"));
    // BirdMap == [
    //  { Key: 5, Value: "Pigeon"     },
    //  { Key: 2, Value: "Penquin"    },
    //  { Key: 7, Value: "Albatross"  }
    // ]

    FString* BirdIn7 = BirdMap.Find(7);
    // *BirdIn7 == "Albatross"
    FString* BirdIn8 = BirdMap.Find(8);
    // *BirdIn8 == nullptr

}

void USGameInstance::Shutdown()
{
    Super::Shutdown();
}
