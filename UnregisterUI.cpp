#pragma once
#include "UnregisterUI.h"
#include "UnregisterControl.h"
#include "Ticket.h"
#include "TicketCollection.h"
#include "Reservation.h"
#include "ReservationCollection.h"
#include "Member.h"
#include "MemberCollection.h"

void UnregisterUI::callUnregister(UnregisterControl* unregisterControl, TicketCollection* ticketCollection, ReservationCollection* reservationCollection,
	MemberCollection* memberCollection)
{
	// Function: callUnregister(UnregisterControl* unregisterControl, TicketCollection* ticketCollection, ReservationCollection* reservationCollection, MemberCollection* memberCollection)
	// Description: callUnregister라는 함수는 Control에서 requestUnregister를 부르고 성공한다면 회원탈퇴 문구를 출력한다.
	// Created: 2019/06/02
	// Author: 이계웅

	cout << "1.2 회원탈퇴" << endl;
	unregisterControl->requestUnregister(ticketCollection, reservationCollection, memberCollection);

	if (unregisterControl->getCanUnregister())
	{
		cout << "> " << unregisterControl->getUnregisterId() << endl;
	}
	cout << endl;
}