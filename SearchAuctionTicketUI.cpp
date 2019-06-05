#pragma once
#include "SearchAuctionTicketUI.h"
#include "SearchAuctionTicketControl.h"
#include "Ticket.h"
#include "TicketCollection.h"
#include "Member.h"
#include "MemberCollection.h"
#include "Timer.h"

void SearchAuctionTicketUI::selectAuctionHomeTeam(SearchAuctionTicketControl* searchAuctionTicket,
	TicketCollection* ticketCollection, MemberCollection* memberCollection, Timer* t)
{
	//Function: selectHomeTeam(SearchTicketControl* searchTicket, TicketCollection* ticketCollection, MemberCollection* memberCollection, Timer* t)
	//Description: 구매자가 홈팀을 선택하는 UI를 제공하고 그 홈팀에 대한 경매 중인 티켓을 보여준다.
	//Created: 2019/6/2
	//Author: 홍지은

	string homeTeam; //홈팀
	cin >> homeTeam;

	searchAuctionTicket->showBuyerWantAuctionTicket(homeTeam, ticketCollection, memberCollection, t);

	int ticketCount = searchAuctionTicket->getTempCount(); //임시 티켓 저장한 개수 

	if (ticketCount == 0)//가져올 티켓이 없다면
	{
		cout << "4.3. 경매 중인 티켓 검색" << endl;
		cout << ">" << endl;
	}

	else
	{
		cout << "4.3. 경매 중인 티켓 검색" << endl;
		for (int i = 0; i < ticketCount; i++)
		{
			cout << searchAuctionTicket->getSortedList(i)->getGameDateNTime() << " ";
			cout << searchAuctionTicket->getSortedList(i)->getHomeTeam() << " ";
			cout << searchAuctionTicket->getSortedList(i)->getAwayTeam() << " ";
			cout << searchAuctionTicket->getSortedList(i)->getTicketSeatNum() << " ";
			//마감까지 남은 시간 출력
			cout << t->returnRemainAuctionTime(searchAuctionTicket->getSortedList(i));
			cout << endl;
		}
	}
	cout << endl;
}