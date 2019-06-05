#pragma once
#include "UnregisterUI.h"
#include "UnregisterControl.h"
#include "Ticket.h"
#include "TicketCollection.h"
#include "Reservation.h"
#include "ReservationCollection.h"
#include "Member.h"
#include "MemberCollection.h"

UnregisterControl::UnregisterControl()
{
	// Function: UnregisterControl()
	// Description: canUnregister의 값을 True로 설정하는 생성자
	// Created: 2019/06/02
	// Author: 이계웅

	this->canUnregister = true;
}

void UnregisterControl::requestUnregister(TicketCollection* ticketCollection, ReservationCollection* reservationCollection, MemberCollection* memberCollection)
{
	// Function: requestUnregister(TicketCollection* ticketCollection, ReservationCollection* reservationCollection, MemberCollection* memberCollection)
	// Description: 해당 회원을 삭제하는 함수
	// Created: 2019/06/02
	// Author: 이계웅

	if (memberCollection->currentSession() == NULL)
	{
		cout << "> 현재 로그인중인 아이디가 없습니다." << endl << endl;
		canUnregister = false;
	}
	else
	{
		string cntMemberID = memberCollection->currentSession()->getId(); // 현재 로그인한 멤버의 아이디를 저장

		if (memberCollection->currentSession()->getMemType().compare("seller") == 0) // 만약에 판매자라면 등록 중인 미판매 티켓이 없을때만, 탈퇴가 가능하다.
		{
			int TicketCount = ticketCollection->getTicketCount(); // 티켓의 총 수를 받아서 
			
			for (int i = 0; i < TicketCount; i++) // 티켓 수만큼 반복문을 돌린다.
			{
				if((cntMemberID.compare(ticketCollection->getTicket(i)->getSellerId()) == 0) && (ticketCollection->getTicket(i)->getIsSold() == false))
					// 미판매 티켓이 있다. isSold값이 False이다. 
				{
					this->canUnregister = false; // 판매자가 회원탈퇴를 할 수 없다.
					break; // 바로 반복문 빠져나감
				}
			}

			if(canUnregister) // 판매자가 회원 탈퇴를 할 수 있다면
			{
				this->unregisterId = cntMemberID;
				memberCollection->deleteMember(memberCollection->getCurrentSessionIndex());
			}
			else // 판매자가 회원 탈퇴를 할 수 없다면.
			{
				cout << "> 등록된 미판매 티켓이 존재하여 탈퇴할 수 없습니다." << endl;
			}
		}

		else if (memberCollection->currentSession()->getMemType().compare("buyer") == 0) // 만약에 구매자라면 그냥 탈퇴가 가능하다.
		{
			canUnregister = true;
			int reservationCount = reservationCollection->getReservationCount();
			
			for (int i = 0; i < reservationCount; i++)
			{
				if (cntMemberID.compare(reservationCollection->getReservation(i)->getBuyerID()) == 0)
				{
					reservationCollection->deleteReservation(i); // 구매자가 예약했던 내역들을 삭제한다.
				}
			}

			if (canUnregister)
			{
				unregisterId = cntMemberID;
				memberCollection->deleteMember(memberCollection->getCurrentSessionIndex());
			}
		}
	}
}

bool UnregisterControl::getCanUnregister()
{
	// Function: getCanUnregister()
	// Description: 탈퇴 가능 여부를 반환하는 함수
	// Created: 2019/06/02
	// Author: 이계웅
	
	return this->canUnregister;
}

string UnregisterControl::getUnregisterId()
{
	// Function: getCanUnregister()
	// Description: 탈퇴한 ID를 반환하는 함수
	// Created: 2019/06/02
	// Author: 이계웅

	return this->unregisterId;
}