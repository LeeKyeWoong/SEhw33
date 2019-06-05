#pragma once

#include <iostream>
#include <string>
#include "Ticket.h"
#include <sstream>

using namespace std;

class Timer {
	// Class: Timer
	// Description: 시간과 관련된 기능을 수행할 시 필요한 entity 클래스
	// Created: 2019/05/30
	// Author: 김승연

private:
	string currentTime; // 현재 시간을 저장할 변수

public:
	void setCurrentTime(string cntTime);
	string getCurrentTime();
	bool checkTimeToDeleteTicket(string registerTime);
	void checkTimeToConvertIntoAuction(Ticket *tk);
	string returnRemainAuctionTime(Ticket *tk);
};