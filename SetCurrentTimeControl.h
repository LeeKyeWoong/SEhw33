#pragma once
#include <iostream>
#include <string>
#include "TicketCollection.h"
#include "Timer.h"
#include "ReservationCollection.h"

using namespace std;

class Timer;
class TicketCollection;

class SetCurrentTimeControl {
	// Class : SetCurrentTimeControl
	// Description: 현재시간 설정 기능을 수행하기 위한 control class
	// Created: 2019/05/31
	// Author: 김승연

public:
	void setCurrentTime(Timer *t, string time, TicketCollection *tc, ReservationCollection* rc);
};
