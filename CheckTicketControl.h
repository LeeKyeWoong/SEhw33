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
	// Description: CheckTicket�� control class
	// Created: 2019/06/02
	// Author: �̰��
	
private:
	Ticket * sellerTicketList[MAX];  // Ư�� seller�� TicketList�� �����ϴ� ����
	int sellerTicketNumber;

public:
	CheckTicketControl();  // sellerTicketList NULL���� �Է��ϴ� �ϴ� ������
	void getSellerTicket(CheckTicketUI *checkTicketUI, TicketCollection *ticketCollection, MemberCollection *memberCollection);
};