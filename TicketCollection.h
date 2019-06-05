#pragma once

#include <iostream>
#include <string>
#include "Ticket.h"

#define MAX 50

using namespace std;

class TicketCollection {
	//Class : TicketCollection
	//Description : TicketCollection의 entity class
	//Created : 2019/05/28
	//Author : 홍지은

private:
	Ticket * ticketList[MAX];
	int ticketCount; //티켓의 개수

public:
	TicketCollection(Ticket ticketList[MAX]); //생성자
	void increaseTicketCount(); //티켓의 개수 증가
	int getTicketCount(); //티켓 개수 가져오기
	void deleteTicket(int deleteTicketIndex); //티켓 삭제
	void addTicket(int price, string gameDatenTime, string homeTeam, string awayTeam, string seatNum, 
		bool isLimitedTimeAuction, bool isSold, string sid, string registerTicketDate, string ticketType); //리스트에 티켓추가
	Ticket *getTicket(int ticketCount); //특정티켓 가져오는 함수

};
