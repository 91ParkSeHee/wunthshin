#pragma once

#include "Enums.generated.h"

UENUM()
enum class EItemType : uint8 
{
	Consumable,
	Weapon
};

UENUM()
enum class EWeaponType : uint8
{
	Melee,
	Range
};

UENUM()
enum class EItemActionType : uint8
{
	Self,		// 자기자신
	Cone,		// 부채꼴 범위
	AoE,		// 지정된 포지션에서 원형범위
	Linear,		// 직사각형
	Projectile,	// 투사체
	TargetInstant,	// 타겟팅
};

UENUM()
enum class EEffectType : uint8
{
	Heal,
	Damage,

};

UENUM()
enum class EActivationType : uint8
{
	Instant,		// 즉시
	Casted,	// 시간 초과시 발동
	Channeled, // 시간동안 계속 발동
	Charged,	// 모으는 시간에 따라 수치 변동
};