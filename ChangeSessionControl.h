#pragma once
#include <iostream>
#include <string>
#include "MemberCollection.h"

using namespace std;

class ChangeSessionControl {
	// Class: ChangeSessionControl
	// Description: ���� ������ �����ϱ� ���� control class
	// Created: 2019/05/31
	// Author: ��¿�

public:
	void changeSession(string newID, MemberCollection *mc);
};