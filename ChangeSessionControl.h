#pragma once
#include <iostream>
#include <string>
#include "MemberCollection.h"

using namespace std;

class ChangeSessionControl {
	// Class: ChangeSessionControl
	// Description: 세션 변경을 수행하기 위한 control class
	// Created: 2019/05/31
	// Author: 김승연

public:
	void changeSession(string newID, MemberCollection *mc);
};