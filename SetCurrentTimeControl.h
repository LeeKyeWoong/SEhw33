#pragma once
#include <iostream>
#include <string>
#include "TicketCollection.h"
#include "Timer.h"

using namespace std;

class Timer;
class TicketCollection;

class SetCurrentTimeControl {
	// Class : SetCurrentTimeControl
	// Description: ����ð� ���� ����� �����ϱ� ���� control class
	// Created: 2019/05/31
	// Author: ��¿�

public:
	void setCurrentTime(Timer *t, string time, TicketCollection *tc);
};
