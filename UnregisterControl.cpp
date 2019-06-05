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
	// Description: canUnregister�� ���� True�� �����ϴ� ������
	// Created: 2019/06/02
	// Author: �̰��

	this->canUnregister = true;
}

void UnregisterControl::requestUnregister(TicketCollection* ticketCollection, ReservationCollection* reservationCollection, MemberCollection* memberCollection)
{
	// Function: requestUnregister(TicketCollection* ticketCollection, ReservationCollection* reservationCollection, MemberCollection* memberCollection)
	// Description: �ش� ȸ���� �����ϴ� �Լ�
	// Created: 2019/06/02
	// Author: �̰��

	if (memberCollection->currentSession() == NULL)
	{
		cout << "> ���� �α������� ���̵� �����ϴ�." << endl << endl;
		canUnregister = false;
	}
	else
	{
		string cntMemberID = memberCollection->currentSession()->getId(); // ���� �α����� ����� ���̵� ����

		if (memberCollection->currentSession()->getMemType().compare("seller") == 0) // ���࿡ �Ǹ��ڶ�� ��� ���� ���Ǹ� Ƽ���� ��������, Ż�� �����ϴ�.
		{
			int TicketCount = ticketCollection->getTicketCount(); // Ƽ���� �� ���� �޾Ƽ� 
			
			for (int i = 0; i < TicketCount; i++) // Ƽ�� ����ŭ �ݺ����� ������.
			{
				if((cntMemberID.compare(ticketCollection->getTicket(i)->getSellerId()) == 0) && (ticketCollection->getTicket(i)->getIsSold() == false))
					// ���Ǹ� Ƽ���� �ִ�. isSold���� False�̴�. 
				{
					this->canUnregister = false; // �Ǹ��ڰ� ȸ��Ż�� �� �� ����.
					break; // �ٷ� �ݺ��� ��������
				}
			}

			if(canUnregister) // �Ǹ��ڰ� ȸ�� Ż�� �� �� �ִٸ�
			{
				this->unregisterId = cntMemberID;
				memberCollection->deleteMember(memberCollection->getCurrentSessionIndex());
			}
			else // �Ǹ��ڰ� ȸ�� Ż�� �� �� ���ٸ�.
			{
				cout << "> ��ϵ� ���Ǹ� Ƽ���� �����Ͽ� Ż���� �� �����ϴ�." << endl;
			}
		}

		else if (memberCollection->currentSession()->getMemType().compare("buyer") == 0) // ���࿡ �����ڶ�� �׳� Ż�� �����ϴ�.
		{
			canUnregister = true;
			int reservationCount = reservationCollection->getReservationCount();
			
			for (int i = 0; i < reservationCount; i++)
			{
				if (cntMemberID.compare(reservationCollection->getReservation(i)->getBuyerID()) == 0)
				{
					reservationCollection->deleteReservation(i); // �����ڰ� �����ߴ� �������� �����Ѵ�.
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
	// Description: Ż�� ���� ���θ� ��ȯ�ϴ� �Լ�
	// Created: 2019/06/02
	// Author: �̰��
	
	return this->canUnregister;
}

string UnregisterControl::getUnregisterId()
{
	// Function: getCanUnregister()
	// Description: Ż���� ID�� ��ȯ�ϴ� �Լ�
	// Created: 2019/06/02
	// Author: �̰��

	return this->unregisterId;
}