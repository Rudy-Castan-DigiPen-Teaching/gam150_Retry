#pragma once
#include "../Engine/Object.h"

class DataBox : public Retry::Object {
public:
	enum class DataKinds {
		RED,
		GREEN,
		BLUE
	};
	DataBox(DataKinds dataKind);

	void Load() override;
	void Update() override;
	void Draw() const override;
private:
	DataKinds dataKind;

	bool isStacked;
	bool isOnBoard;
};