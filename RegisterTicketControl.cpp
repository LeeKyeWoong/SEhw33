#pragma once

#include <iostream>
#include <string>
#include "main.h"
#include "RegisterTicketControl.h"
using namespace std;

RegisterTicketControl::RegisterTicketControl()
{
	// Function : RegisterTicketControl()
	// Description: 객체의 checkRegister값을 true로 초기화 하는 생성자 ( true 는 중복이 없다는 것을 의미한다.)
	// Created: 2019/06/01
	// Author: 이계웅
	
	this->checkRegister = true; // 등록할 수 있다.
}

void RegisterTicketControl::registerNewTicket(int price, string gameDatenTime, string homeTeam, string awayTeam, string seatNum, bool isLimitedTimeAuction,
	TicketCollection *ticketCollection, MemberCollection * memberCollection ,Timer * timer)
{
	// Function: void registerNewTicket(int price, string gameDatenTime, string homeTeam, string awayTeam, string seatNum, bool isLimitedTimeAuction, TicketCollection *ticketCollection, MemberCollection * memberCollection ,Timer * timer)
	// Description: 티켓정보들과 TicketCollection, MemberCollection, Timer을 인자로 받아 티켓을 추가하는함수
	// Created: 2019/05/31
	// Author: 이계웅

	bool isSold;
	string sellerId;
	string registerTicketDate;
	string ticketType;

	if(memberCollection->currentSession() == NULL)  // 세션ON인 멤버가 없다.
	{
		cout << "> 현재 SessionOn 인 멤버가 없습니다" << endl << endl;
		this->checkRegister = false;
	}
	else // 세션ON인 멤버가 있다.
	{
		if((memberCollection->currentSession()->getMemType().compare("seller")) == 0) // 만약 판매자라면
		{
			int ticketNumber = ticketCollection->getTicketCount();
			for(int i = 0; i < ticketNumber; i++) // 티켓수만큼 반복한다.
			{	
				if( (homeTeam.compare(ticketCollection->getTicket(i)->getHomeTeam()) == 0)&&
				    (awayTeam.compare(ticketCollection->getTicket(i)->getAwayTeam()) == 0)&&
				    (gameDatenTime.compare(ticketCollection->getTicket(i)->getGameDateNTime()) == 0)&&
				    (seatNum.compare(ticketCollection->getTicket(i)->getTicketSeatNum()) ==0 ) )
				{
					this->checkRegister = false; // 티켓을 등록할 수 없다. (중복티켓)
				}
			}
			if(this->checkRegister) // 등록할 수 있다면 
			{
				isSold = false;											// 판매여부는 false로 한다.
				sellerId = memberCollection->currentSession()->getId(); 		// 아이디를 받는다.
				registerTicketDate = timer->getCurrentTime();           // 현재시간을 받는다.
				if(isLimitedTimeAuction) // 만약 경매 티켓이라면 
				{
					//ticketType = "A"; // 티켓타입을 옥션으로 한다.
				}
				else
				{
					ticketType = "G"; // 티켓타입을 일반티켓으로 한다.
				}
				ticketCollection->addTicket(price, gameDatenTime, homeTeam, awayTeam, seatNum, isLimitedTimeAuction, isSold, sellerId, registerTicketDate, ticketType);  // TicketList에 티켓등록
			}
			else // 날짜,홈팀, 어웨이팀,날짜시간 모두 겹치는 것이 없다.
			{
				cout << "> 동일한 티켓은 등록할 수 없습니다." << endl << endl;
			}
		}
		else // 만약 구매자라면 
		{
			cout << "> 구매자는 티켓을 등록할 수 없습니다" << endl << endl;
			this->checkRegister = false;
		}
	}
}

bool RegisterTicketControl::getCheckRegister()
{
	// Function : getCheckRegister()
	// Description: 객체의 checkRegister값을 return한다.
	// Created: 2019/6/1
	// Author: 이계웅

	return this->checkRegister;
}