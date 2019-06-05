#pragma once

#include <iostream>
#include <string>
using namespace std;

#define MAX 50

class SearchAuctionTicketUI;
class TicketCollection;
class MemberCollection;
class Ticket;
class Timer;

class SearchAuctionTicketControl
{
	//Class: SearchAuctionTicketControl
	//Description: SearchAuctionTicket의 control class
	//Created: 2019/6/2
	//Author: 홍지은

private:
	Ticket *temp[MAX];
	//검색된 경매 중인 티켓들을 경기날짜 및 시간이 빠른 티켓부터 정렬해서 보여주기 위한 임시객체
	int tempCount;

public:
	SearchAuctionTicketControl();
	void showBuyerWantAuctionTicket(string homeTeam, TicketCollection* ticketCollection, MemberCollection* memberCollection, Timer* t);
	//구매자가 원하는 경매중인 티켓 목록을 정렬된 상태로 보여주는 함수
	Ticket* getSortedList(int ticketCount);
	//경기날짜 및 시간이 빠른 티켓으로 정렬된 리스트를 반환하는 함수
	int getTempCount();
};