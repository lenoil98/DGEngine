#pragma once

#include "Json/JsonParser.h"
#include <memory>

class Animation;
class Game;

namespace Parser
{
	std::shared_ptr<Animation> parseAnimationObj(Game& game, const rapidjson::Value& elem);
	void parseAnimation(Game& game, const rapidjson::Value& elem);
}
