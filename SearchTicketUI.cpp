#pragma once
#include "SearchTicketUI.h"
#include "SearchTicketControl.h"
#include "Ticket.h"
#include "TicketCollection.h"
#include "Member.h"
#include "MemberCollection.h"

void SearchTicketUI::selectHomeTeam(SearchTicketControl* searchTicket, TicketCollection* ticketCollection, MemberCollection* memberCollection)
{
	//Function: selectHomeTeam(SearchTicketControl* searchTicket, TicketCollection* ticketCollection, MemberCollection* memberCollection)
	//Description: �����ڰ� Ȩ���� �����ϴ� UI�� �����ϰ� �� Ȩ���� ���� Ƽ���� �����ش�.
	//Created: 2019/6/1
	//Author: ȫ����

	string homeTeam; //Ȩ��
	cin >> homeTeam;

	searchTicket->showBuyerWantTicket(homeTeam, ticketCollection, memberCollection);

	int ticketCount = searchTicket->getTempCount(); //�ӽ� Ƽ�� ������ ���� 

	if (ticketCount == 0)//������ Ƽ���� ���ٸ�
	{
		cout << "4.1. Ƽ�� �˻�" << endl;
		cout << "> " << endl;
	}

	else
	{
		cout << "4.1. Ƽ�� �˻�" << endl;
		for (int i = 0; i < ticketCount; i++)
		{
			cout << "> " << searchTicket->getSortedList(i)->getTicketPrice() << " ";
			cout << searchTicket->getSortedList(i)->getGameDateNTime() << " ";
			cout << searchTicket->getSortedList(i)->getHomeTeam() << " ";
			cout << searchTicket->getSortedList(i)->getAwayTeam() << " ";
			cout << searchTicket->getSortedList(i)->getTicketSeatNum() << " ";
			cout << endl;
		}
		cout << endl;
	}
}