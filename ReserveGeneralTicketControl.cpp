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
	//Description: �ӽ� Ƽ�� ��ü�� tempTicket�� �ʱ�ȭ �Ѵ�.
	//Created: 2019/6/2
	//Author: ȫ����

	tempTicket = NULL;
}

void ReserveGeneralTicketControl::makeGeneralReservation(string gameDateTime, string awayTeam, string seatNum, ReserveGeneralTicketControl* reserveGeneralTicket, ReservationCollection* reservationCollection,
	TicketCollection* ticketCollection, MemberCollection* memberCollection, Timer* t)
{
	//Function: makeGeneralReservation(string gameDateTime, string awayTeam, string seatNum, ReserveGeneralTicketControl* reserveGeneralTicket, ReservationCollection* reservationCollection, TicketCollection* ticketCollection, MemberCollection* memberCollection)
	//Description: ���ӳ�¥ �� �ð�, �������, �¼���ġ�� �����ϴ� Ƽ���� �����Ѵ�.
	//Created: 2019/6/2
	//Author: ȫ����

	// ���� ���� Ȯ��
	if (memberCollection->currentSession() == NULL) {}

	else
	{
		// ���������� Ȯ��
		if (memberCollection->currentSession()->getMemType().compare("buyer") == 0)
		{
			int ticketCount = ticketCollection->getTicketCount(); //Ƽ�� ���� Ȯ��

			//bool existTicket = false; //Ƽ���� �����ϴ��� Ȯ���� ����

			for (int i = 0; i < ticketCount; i++)
			{
				if (ticketCollection->getTicket(i)->getTicketType() == "G") { //�Ϲ�Ƽ���̰�
					if ((ticketCollection->getTicket(i)->getGameDateNTime() == gameDateTime) &&
						(ticketCollection->getTicket(i)->getAwayTeam() == awayTeam) &&
						(ticketCollection->getTicket(i)->getTicketSeatNum() == seatNum)) //�Է��� �������� ���� �´ٸ�
					{
						if (ticketCollection->getTicket(i)->getReservable() == true) //������ ������ Ƽ�Ͽ� ����
						{
							tempTicket = ticketCollection->getTicket(i);
							//existTicket = true; //���� ��¥�� �ð�, �������, �¼���ġ�� �ش��ϴ� Ƽ���� ����.
							break;
						}
					}
				}

			}

			// �׷� Ƽ���� ������ Ƽ���� ����
			if (tempTicket != NULL)
			{
				tempTicket->setReservable(false);
				//���� �ݷ��ǿ� ������ �߰��Ѵ�.
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
	//Description: Ƽ�� ���� ��, �������� ��ȯ�ϴ� �Լ�
	//Created: 2019/6/2
	//Author: ȫ����

	return tempTicket;
}