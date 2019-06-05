#pragma once
#include <iostream>
#include <string>
#include "ChangeSessionControl.h"
#include "MemberCollection.h"
using namespace std;

class ChangeSessionControl;
class MemberCollection;

class ChangeSessionUI {
	// Class: ChangeSessionUI
	// Description: 세션 변경을 수행하기 위한 boundary class
	// Created: 2019/05/31
	// Author: 김승연

public:
	void startInterface(ChangeSessionControl *ctl, MemberCollection *mcollection);
};
