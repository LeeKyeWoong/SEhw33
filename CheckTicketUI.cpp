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
	//Description: CheckTicketUI를 시작하는 함수, 출력하는 함수
	//Created: 2019/06/02
	//Author: 이계웅

	cout << "3.2 등록티켓 조회" << endl;
	if(ticketCount == 0)
	{
		cout << "> 판매자는 티켓을 등록하지 않았습니다." << endl;
	}
	for (int i = 0; i < ticketCount;i++) // 출력한다.
	{
		cout << "> " << sellerTicket[i]->getTicketPrice() << " " <<  sellerTicket[i]->getGameDateNTime() << " " << sellerTicket[i]->getHomeTeam() << " ";
		cout << sellerTicket[i]->getAwayTeam() << " " <<  sellerTicket[i]->getTicketSeatNum() << " " << sellerTicket[i]->getIsLimitedTimeAuction() << " ";
		cout << sellerTicket[i]->getIsSold() << endl;
	}
	cout << endl;
}