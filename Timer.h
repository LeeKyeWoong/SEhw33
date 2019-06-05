#pragma once

#include <iostream>
#include <string>
#include "Ticket.h"
#include <sstream>

using namespace std;

class Timer {
	// Class: Timer
	// Description: �ð��� ���õ� ����� ������ �� �ʿ��� entity Ŭ����
	// Created: 2019/05/30
	// Author: ��¿�

private:
	string currentTime; // ���� �ð��� ������ ����

public:
	void setCurrentTime(string cntTime);
	string getCurrentTime();
	bool checkTimeToDeleteTicket(string registerTime);
	void checkTimeToConvertIntoAuction(Ticket *tk);
	string returnRemainAuctionTime(Ticket *tk);
};