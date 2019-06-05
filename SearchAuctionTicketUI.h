#pragma once

#include <iostream>
#include <string>
using namespace std;

class TicketCollection;
class SearchAuctionTicketControl;
class MemberCollection;
class Timer;

class SearchAuctionTicketUI
{
	//Class: SearchAuctionTicketUI
	//Description: SearchAuctionTicket 의 boundary class
	//Created: 2019/6/2
	//Author: 홍지은

private:

public:
	void selectAuctionHomeTeam(SearchAuctionTicketControl* searchAuctionTicket, 
		TicketCollection* ticketCollection, MemberCollection* memberCollection, Timer* t);
	//홈팀을 선택하여 예약가능한 티켓을 조회한다. (4.1.)
};