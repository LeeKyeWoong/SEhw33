#pragma once
#include "SearchTicketUI.h"
#include "SearchTicketControl.h"
#include "Ticket.h"
#include "TicketCollection.h"
#include "Member.h"
#include "MemberCollection.h"

void SearchTicketUI::selectHomeTeam(SearchTicketControl* searchTicket, TicketCollection* ticketCollection, MemberCollection* memberCollection)
{
	//Function: selectHomeTeam(SearchTicketControl* searchTicket, TicketCollection* ticketCollection, MemberCollection* memberCollection)
	//Description: 구매자가 홈팀을 선택하는 UI를 제공하고 그 홈팀에 대한 티켓을 보여준다.
	//Created: 2019/6/1
	//Author: 홍지은

	string homeTeam; //홈팀
	cin >> homeTeam;

	searchTicket->showBuyerWantTicket(homeTeam, ticketCollection, memberCollection);

	int ticketCount = searchTicket->getTempCount(); //임시 티켓 저장한 개수 

	if (ticketCount == 0)//가져올 티켓이 없다면
	{
		cout << "4.1. 티켓 검색" << endl;
		cout << "> " << endl;
	}

	else
	{
		cout << "4.1. 티켓 검색" << endl;
		for (int i = 0; i < ticketCount; i++)
		{
			cout << "> " << searchTicket->getSortedList(i)->getTicketPrice() << " ";
			cout << searchTicket->getSortedList(i)->getGameDateNTime() << " ";
			cout << searchTicket->getSortedList(i)->getHomeTeam() << " ";
			cout << searchTicket->getSortedList(i)->getAwayTeam() << " ";
			cout << searchTicket->getSortedList(i)->getTicketSeatNum() << " ";
			cout << endl;
		}
		cout << endl;
	}
}