#pragma once

#include<iostream>
#include "Member.h"
#include "MemberCollection.h"
#include "RegisterTicketUI.h"
#include "RegisterTicketControl.h"

using namespace std;

void RegisterTicketUI::inputRegisterNewTicket(RegisterTicketControl * registerTicketControl, TicketCollection *ticketCollection,  MemberCollection * memberCollection, Timer * timer)
{
	// Function: inputRegisterNewTicket(RegisterTicketControl * registerTicketControl,TicketCollection *ticketCollection,  MemberCollection * memberCollection, Timer * timer)
	// Description: 새 Ticket 정보를 입력하는 함수
	// Created: 2019/05/31
	// Author: 이계웅


	string homeTeam; 			//홈팀
	string awayTeam; 			//어웨이팀 
	int price; 					//티켓의 가격
	string gameDatenTime; 		//게임 시작날짜와 시간
	string seatNum; 			//티켓의 좌석
	bool isLimitedTimeAuction;  //티켓을 경매로 넘길것인지의 여부
	
	cin >> price >> gameDatenTime >> homeTeam >> awayTeam >> seatNum >> isLimitedTimeAuction;

	registerTicketControl->registerNewTicket(price, gameDatenTime, homeTeam, awayTeam, seatNum, isLimitedTimeAuction, ticketCollection, memberCollection, timer);
	
	if(registerTicketControl->getCheckRegister())
	{
		cout << "3.1 판매티켓 등록" << endl; // 출력한다.
		cout << "> " << price << " " << gameDatenTime << " " << homeTeam << " " << awayTeam << " " << seatNum <<  " " << isLimitedTimeAuction << endl; // 출력한다.
		cout << endl;	
	}

}

