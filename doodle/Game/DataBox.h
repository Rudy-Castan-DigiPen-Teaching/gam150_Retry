/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: DataBox.h
Project: GAM150_Networker
Author: Team RETRY - Yeongju Lee
Creation date: 04/01/2021
-----------------------------------------------------------------*/
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
	DataBox(DataType dataKind);

	void Load() override;
	void Update() override;
	void Draw() const override;

	DataType GetDataType() const { return dataType; }

	bool isStacked;
	bool isOnBoard;
	bool isTransfered;

	DataBox& operator=(const DataBox&) = default;
private:
	DataType dataType;
};