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
	// Description: ���� ������ �����ϱ� ���� boundary class
	// Created: 2019/05/31
	// Author: ��¿�

public:
	void startInterface(ChangeSessionControl *ctl, MemberCollection *mcollection);
};
