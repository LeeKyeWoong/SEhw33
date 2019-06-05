#pragma once

#include <iostream>
#include <string>
#include "CheckTicketControl.h"
#include "Ticket.h"

using namespace std;

class Ticket;
class CheckTicketControl;
void CheckTicketUI::startInterface(int ticketCount, Ticket *sellerTicket[])
{
	//Function: startInterface(int ticketCount, Ticket ** sellerTicket)
	//Description: CheckTicketUI�� �����ϴ� �Լ�, ����ϴ� �Լ�
	//Created: 2019/06/02
	//Author: �̰��

	cout << "3.2 ���Ƽ�� ��ȸ" << endl;
	if(ticketCount == 0)
	{
		cout << "> �Ǹ��ڴ� Ƽ���� ������� �ʾҽ��ϴ�." << endl;
	}
	for (int i = 0; i < ticketCount;i++) // ����Ѵ�.
	{
		cout << "> " << sellerTicket[i]->getTicketPrice() << " " <<  sellerTicket[i]->getGameDateNTime() << " " << sellerTicket[i]->getHomeTeam() << " ";
		cout << sellerTicket[i]->getAwayTeam() << " " <<  sellerTicket[i]->getTicketSeatNum() << " " << sellerTicket[i]->getIsLimitedTimeAuction() << " ";
		cout << sellerTicket[i]->getIsSold() << endl;
	}
	cout << endl;
}