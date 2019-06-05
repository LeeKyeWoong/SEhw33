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
	// Description: 현재시간 설정 기능을 수행하기 위한 boundary class
	// Created: 2019/05/31
	// Author: 김승연

public:
	void startInterface(SetCurrentTimeControl* control, Timer* timer, TicketCollection* ticketCollection, ReservationCollection *reservationCollection);
};