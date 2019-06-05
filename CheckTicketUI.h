#pragma once

#include <iostream>
#include <string>
#include "CheckTicketControl.h"

using namespace std;

class CheckTicketControl;
class MemberCollection;

class CheckTicketUI
{
	//Class: CheckTicketClass
	//Description: CheckTicket의 boundary class
	//Created: 2019/06/02
	//Author: 이계웅

private:

public:
	void startInterface(int ticketCount, Ticket *sellerTicket[]); // 받은 seller의 티켓들을 가지고 출력해주는 함수
};