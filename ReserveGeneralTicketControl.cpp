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

ReserveGeneralTicketControl::ReserveGeneralTicketControl()
{
	//Function: ReserveGeneralTicketControl()
	//Description: 임시 티켓 객체인 tempTicket을 초기화 한다.
	//Created: 2019/6/2
	//Author: 홍지은

	tempTicket = NULL;
}

void ReserveGeneralTicketControl::makeGeneralReservation(string gameDateTime, string awayTeam, string seatNum, ReserveGeneralTicketControl* reserveGeneralTicket, ReservationCollection* reservationCollection,
	TicketCollection* ticketCollection, MemberCollection* memberCollection, Timer* t)
{
	//Function: makeGeneralReservation(string gameDateTime, string awayTeam, string seatNum, ReserveGeneralTicketControl* reserveGeneralTicket, ReservationCollection* reservationCollection, TicketCollection* ticketCollection, MemberCollection* memberCollection)
	//Description: 게임날짜 및 시간, 어웨이팀, 좌석위치에 부합하는 티켓을 예약한다.
	//Created: 2019/6/2
	//Author: 홍지은

	// 현재 세션 확인
	if (memberCollection->currentSession() == NULL) {}

	else
	{
		// 구매자인지 확인
		if (memberCollection->currentSession()->getMemType().compare("buyer") == 0)
		{
			int ticketCount = ticketCollection->getTicketCount(); //티켓 개수 확인

			//bool existTicket = false; //티켓이 존재하는지 확인할 변수

			for (int i = 0; i < ticketCount; i++)
			{
				if (ticketCollection->getTicket(i)->getTicketType() == "G") { //일반티켓이고
					if ((ticketCollection->getTicket(i)->getGameDateNTime() == gameDateTime) &&
						(ticketCollection->getTicket(i)->getAwayTeam() == awayTeam) &&
						(ticketCollection->getTicket(i)->getTicketSeatNum() == seatNum)) //입력한 정보들을 비교해 맞다면
					{
						if (ticketCollection->getTicket(i)->getReservable() == true) //예약이 가능한 티켓에 대해
						{
							tempTicket = ticketCollection->getTicket(i);
							//existTicket = true; //위의 날짜및 시간, 어웨이팀, 좌석위치에 해당하는 티켓이 존재.
							break;
						}
					}
				}

			}

			// 그런 티켓이 있으면 티켓을 예약
			if (tempTicket != NULL)
			{
				tempTicket->setReservable(false);
				//예약 콜렉션에 예약을 추가한다.
				reservationCollection->addReservation(tempTicket->getSellerId(), memberCollection->currentSession()->getId(),
					tempTicket->getTicketPrice(), t->getCurrentTime(), tempTicket->getGameDateNTime(),
					tempTicket->getHomeTeam(), tempTicket->getAwayTeam(), tempTicket->getTicketSeatNum());
			}
			else
			{
			}
		}
	}
}

Ticket* ReserveGeneralTicketControl::getReservedTicket()
{
	//Function: getReservedTicket()
	//Description: 티켓 예약 후, 예약결과를 반환하는 함수
	//Created: 2019/6/2
	//Author: 홍지은

	return tempTicket;
}