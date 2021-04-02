#pragma once
#include "../Engine/Object.h"

class Player;

class DataBox : public Retry::Object {
public:
	enum class DataType {
		RED,
		GREEN,
		BLUE
	};
	DataBox(DataType dataKind, const Player& player);

	void Load() override;
	void Update() override;
	void Draw() const override;

	bool isStacked;
	bool isOnBoard;

private:
	DataType dataType;

	const Player& player;


};