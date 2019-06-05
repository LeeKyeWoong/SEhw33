#pragma once

#include "ReserveGeneralTicketUI.h"
#include "ReserveGeneralTicketControl.h"
#include "Reservation.h"
#include "ReservationCollection.h"
#include "Ticket.h"
#include "TicketCollection.h"
#include "Member.h"
#include "MemberCollection.h"
#include "Timer.h"

void ReserveGeneralTicketUI::reserveGeneralTicket(ReserveGeneralTicketControl* reserveGeneralTicket, ReservationCollection* reservationCollection,
	TicketCollection* ticketCollection, MemberCollection* memberCollection, Timer* timer)
{
	//Function: reserveGeneralTicket(ReserveGeneralTicketControl* reserveGeneralTicket, ReservationCollection* reservationCollection, TicketCollection* ticketCollection, MemberCollection* memberCollection)
	//Description: 날짜시간, 어웨이팀, 좌석위치를 입력 해 티켓을 예약하는 함수
	//Created: 2019/6/2
	//Author: 홍지은


	string gameDateTime;
	string awayTeam;
	string seatNum;
	cin >> gameDateTime >> awayTeam>> seatNum;

	reserveGeneralTicket->makeGeneralReservation(gameDateTime, awayTeam, seatNum, 
		reserveGeneralTicket, reservationCollection, ticketCollection, memberCollection, timer);

	if (reserveGeneralTicket->getReservedTicket() == NULL)
	{
		cout << "4.2. 티켓 예약" << endl;
		cout << ">" << endl;
	}
	else
	{
		cout << "4.2. 티켓 예약" << endl;
		cout << ">" << reserveGeneralTicket->getReservedTicket()->getTicketPrice() << " "
			<< reserveGeneralTicket->getReservedTicket()->getGameDateNTime() << " "
			<< reserveGeneralTicket->getReservedTicket()->getHomeTeam()
			<< " " << reserveGeneralTicket->getReservedTicket()->getAwayTeam() << " "
			<< reserveGeneralTicket->getReservedTicket()->getTicketSeatNum() << endl << endl;
	}

}

