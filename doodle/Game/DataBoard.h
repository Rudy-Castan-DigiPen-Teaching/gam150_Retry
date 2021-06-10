/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: DataBoard.h
Project: GAM150_Networker
Author: Team RETRY - Yeongju Lee
Creation date: 04/05/2021
-----------------------------------------------------------------*/
#pragma once
#include "../Engine/Object.h"
#include "DataBox.h"

class DataBoard : public Retry::Object
{
public:
	DataBoard(double y, DataBox::DataType datatype);

	void Load() override;
	void Update() override;
	void Draw() override;

	void AddCurrDataNum(int i) { currDataNum += i; }
	int GetGoalDataNum() const { return goalDataNum; }
	int GetCurrDataNum() const { return currDataNum; }
	DataBox::DataType GetDataType() const { return dataType; }

	bool reachedGoal;
private:
	Retry::Sprite sprite;
	DataBox::DataType dataType;
	int goalDataNum;
	int currDataNum;

};