#pragma once

#include <cstddef>
#include <cstdint>
#include "PairXY.h"
#include <SFML/System/Time.hpp>
#include <utility>

struct AnimationSpeed
{
	sf::Time animation;
	sf::Time walk;

	AnimationSpeed() noexcept : animation(sf::microseconds(200000)), walk(sf::microseconds(40000)) {}
	AnimationSpeed(sf::Time animation_, sf::Time walk_) noexcept : animation(animation_), walk(walk_) {}
};

enum class InventoryPosition : uint32_t
{
	TopLeft,
	TopRight,
	BottomLeft,
	BottomRight,
	Size
};

typedef int32_t LevelObjValue;
typedef std::pair<uint16_t, LevelObjValue> LevelObjProperty;

enum class PlayerDirection : uint32_t
{
	Front,
	FrontLeft,
	Left,
	BackLeft,
	Back,
	BackRight,
	Right,
	FrontRight,
	All,
	Size
};

enum class PlayerInventory : uint32_t
{
	Body,
	Belt,
	Stash,
	Size
};

enum class PlayerItemMount : uint32_t
{
	LeftHand,
	RightHand,
	Armor,
	Helmet,
	Amulet,
	LeftRing,
	RightRing,
	Size
};

enum class PlayerStatus : uint32_t
{
	Stand,
	Walk,
	Attack,
	Dead,
	Size
};

enum class PlayerAnimation : uint32_t
{
	Stand1,
	Stand2,
	Walk1,
	Walk2,
	Attack1,
	Attack2,
	Attack3,
	Attack4,
	Defend1,
	Defend2,
	Defend3,
	Defend4,
	Hit1,
	Hit2,
	Die1,
	Die2,
	Size
};

PlayerDirection getPlayerDirection(const PairFloat& currPos, const PairFloat& newPos) noexcept;
