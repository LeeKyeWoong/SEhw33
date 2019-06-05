#pragma once

#include <iostream>
#include <string>
using namespace std;

class TicketCollection;
class SearchTicketControl;
class MemberCollection;

class SearchTicketUI
{
	//Class: SearchTicketUI
	//Description: SearchTicket 의 boundary class
	//Created: 2019/05/31
	//Author: 홍지은

private:

public:
	void selectHomeTeam(SearchTicketControl* searchTicket, TicketCollection* ticketCollection, MemberCollection* memberCollection);
	//홈팀을 선택하여 예약가능한 티켓을 조회한다. (4.1.)
};