#pragma once

#include <iostream>
#include <string>
#include "main.h"

using namespace std;

class MemberCollection;
class TicketCollection;
class Timer;

class RegisterTicketControl
{
	// Class: RegisterTicketControl
	// Description: 티켓등록정보를 입력받고 처리하는 클래스
	// Created: 2019/05/31
	// Author: 이계웅

private:
	bool checkRegister;

public:
	RegisterTicketControl();
	void registerNewTicket(int price, string gameDatenTime, string homeTeam, string awayTeam, string seatNum, bool isLimitedTimeAuction, 
		TicketCollection *pticketCollection, MemberCollection * pmemberCollection ,Timer * ptimer);  //  TicketCollection에 티켓을 추가하는함수
	bool getCheckRegister(); // 티켓등록을 시도하는 티켓의 중복 여부를 반환하는 함수
};

