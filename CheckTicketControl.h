#pragma once

#include <iostream>
#include <string>

#include "TicketCollection.h"
#include "CheckTicketUI.h"
#include "Ticket.h"
#define MAX 50

using namespace std;

class CheckTicketUI;
class MemberCollection;
class Ticket;
class TicketCollection;

class CheckTicketControl {

	// Class: CheckTicketControl
	// Description: CheckTicket의 control class
	// Created: 2019/06/02
	// Author: 이계웅
	
private:
	Ticket * sellerTicketList[MAX];  // 특정 seller의 TicketList를 저장하는 변수
	int sellerTicketNumber;

public:
	CheckTicketControl();  // sellerTicketList NULL값을 입력하는 하는 생성자
	void getSellerTicket(CheckTicketUI *checkTicketUI, TicketCollection *ticketCollection, MemberCollection *memberCollection);
};