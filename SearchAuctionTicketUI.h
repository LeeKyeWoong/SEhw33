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
	//Description: SearchAuctionTicket �� boundary class
	//Created: 2019/6/2
	//Author: ȫ����

private:

public:
	void selectAuctionHomeTeam(SearchAuctionTicketControl* searchAuctionTicket, 
		TicketCollection* ticketCollection, MemberCollection* memberCollection, Timer* t);
	//Ȩ���� �����Ͽ� ���డ���� Ƽ���� ��ȸ�Ѵ�. (4.1.)
};