#pragma once

#include <iostream>
#include <string>
#include "Timer.h"
#include "SetCurrentTimeControl.h"
using namespace std;

class Timer;
class SetCurrentTimeControl;
class TicketCollection;

class SetCurrentTimeUI {
	// Class: SetCurrentTimeUI
	// Description: ����ð� ���� ����� �����ϱ� ���� boundary class
	// Created: 2019/05/31
	// Author: ��¿�

public:
	void startInterface(SetCurrentTimeControl* control, Timer* timer, TicketCollection* ticketCollection);
};