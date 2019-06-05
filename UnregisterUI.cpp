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
	// Description: callUnregister��� �Լ��� Control���� requestUnregister�� �θ��� �����Ѵٸ� ȸ��Ż�� ������ ����Ѵ�.
	// Created: 2019/06/02
	// Author: �̰��

	cout << "1.2 ȸ��Ż��" << endl;
	unregisterControl->requestUnregister(ticketCollection, reservationCollection, memberCollection);

	if (unregisterControl->getCanUnregister())
	{
		cout << "> " << unregisterControl->getUnregisterId() << endl;
	}
	cout << endl;
}