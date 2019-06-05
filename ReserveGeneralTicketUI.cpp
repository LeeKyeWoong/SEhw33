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
	//Description: ��¥�ð�, �������, �¼���ġ�� �Է� �� Ƽ���� �����ϴ� �Լ�
	//Created: 2019/6/2
	//Author: ȫ����


	string gameDateTime;
	string awayTeam;
	string seatNum;
	cin >> gameDateTime >> awayTeam>> seatNum;

	reserveGeneralTicket->makeGeneralReservation(gameDateTime, awayTeam, seatNum, 
		reserveGeneralTicket, reservationCollection, ticketCollection, memberCollection, timer);

	if (reserveGeneralTicket->getReservedTicket() == NULL)
	{
		cout << "4.2. Ƽ�� ����" << endl;
		cout << ">" << endl;
	}
	else
	{
		cout << "4.2. Ƽ�� ����" << endl;
		cout << ">" << reserveGeneralTicket->getReservedTicket()->getTicketPrice() << " "
			<< reserveGeneralTicket->getReservedTicket()->getGameDateNTime() << " "
			<< reserveGeneralTicket->getReservedTicket()->getHomeTeam()
			<< " " << reserveGeneralTicket->getReservedTicket()->getAwayTeam() << " "
			<< reserveGeneralTicket->getReservedTicket()->getTicketSeatNum() << endl << endl;
	}

}

