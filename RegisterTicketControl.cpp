#pragma once

#include <iostream>
#include <string>
#include "main.h"
#include "RegisterTicketControl.h"
using namespace std;

RegisterTicketControl::RegisterTicketControl()
{
	// Function : RegisterTicketControl()
	// Description: ��ü�� checkRegister���� true�� �ʱ�ȭ �ϴ� ������ ( true �� �ߺ��� ���ٴ� ���� �ǹ��Ѵ�.)
	// Created: 2019/06/01
	// Author: �̰��
	
	this->checkRegister = true; // ����� �� �ִ�.
}

void RegisterTicketControl::registerNewTicket(int price, string gameDatenTime, string homeTeam, string awayTeam, string seatNum, bool isLimitedTimeAuction,
	TicketCollection *ticketCollection, MemberCollection * memberCollection ,Timer * timer)
{
	// Function: void registerNewTicket(int price, string gameDatenTime, string homeTeam, string awayTeam, string seatNum, bool isLimitedTimeAuction, TicketCollection *ticketCollection, MemberCollection * memberCollection ,Timer * timer)
	// Description: Ƽ��������� TicketCollection, MemberCollection, Timer�� ���ڷ� �޾� Ƽ���� �߰��ϴ��Լ�
	// Created: 2019/05/31
	// Author: �̰��

	bool isSold;
	string sid;
	string registerTicketDate;
	string ticketType;

	if(memberCollection->currentSession() == NULL)  // ����ON�� ����� ����.
	{
		cout << "> ���� SessionOn �� ����� �����ϴ�" << endl << endl;
		this->checkRegister = false;
	}
	else // ����ON�� ����� �ִ�.
	{
		if((memberCollection->currentSession()->getMemType().compare("seller")) == 0) // ���� �Ǹ��ڶ��
		{
			int ticketNumber = ticketCollection->getTicketCount();
			for(int i = 0; i < ticketNumber; i++) // Ƽ�ϼ���ŭ �ݺ��Ѵ�.
			{	
				if( (homeTeam.compare(ticketCollection->getTicket(i)->getHomeTeam()) == 0)&&
				    (awayTeam.compare(ticketCollection->getTicket(i)->getAwayTeam()) == 0)&&
				    (gameDatenTime.compare(ticketCollection->getTicket(i)->getGameDateNTime()) == 0)&&
				    (seatNum.compare(ticketCollection->getTicket(i)->getTicketSeatNum()) ==0 ) )
				{
					this->checkRegister = false; // Ƽ���� ����� �� ����. (�ߺ�Ƽ��)
				}
			}
			if(this->checkRegister) // ����� �� �ִٸ� 
			{
				isSold = false;											// �Ǹſ��δ� false�� �Ѵ�.
				sid = memberCollection->currentSession()->getId(); 		// ���̵� �޴´�.
				registerTicketDate = timer->getCurrentTime();           // ����ð��� �޴´�.
				if(isLimitedTimeAuction) // ���� ��� Ƽ���̶�� 
				{
					ticketType = "A"; // Ƽ��Ÿ���� �������� �Ѵ�.
				}
				else
				{
					ticketType = "G"; // Ƽ��Ÿ���� �Ϲ�Ƽ������ �Ѵ�.
				}
				ticketCollection->addTicket(price, gameDatenTime, homeTeam, awayTeam, seatNum, isLimitedTimeAuction, isSold, sid, registerTicketDate, ticketType);  // TicketList�� Ƽ�ϵ��
			}
			else // ��¥,Ȩ��, �������,��¥�ð� ��� ��ġ�� ���� ����.
			{
				cout << "> ������ Ƽ���� ����� �� �����ϴ�." << endl << endl;
			}
		}
		else // ���� �����ڶ�� 
		{
			cout << "> �����ڴ� Ƽ���� ����� �� �����ϴ�" << endl << endl;
			this->checkRegister = false;
		}
	}
}

bool RegisterTicketControl::getCheckRegister()
{
	// Function : getCheckRegister()
	// Description: ��ü�� checkRegister���� return�Ѵ�.
	// Created: 2019/6/1
	// Author: �̰��

	return this->checkRegister;
}