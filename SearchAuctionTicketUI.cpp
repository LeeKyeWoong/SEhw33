#pragma once
#include "SearchAuctionTicketUI.h"
#include "SearchAuctionTicketControl.h"
#include "Ticket.h"
#include "TicketCollection.h"
#include "Member.h"
#include "MemberCollection.h"
#include "Timer.h"

void SearchAuctionTicketUI::selectAuctionHomeTeam(SearchAuctionTicketControl* searchAuctionTicket,
	TicketCollection* ticketCollection, MemberCollection* memberCollection, Timer* t)
{
	//Function: selectHomeTeam(SearchTicketControl* searchTicket, TicketCollection* ticketCollection, MemberCollection* memberCollection, Timer* t)
	//Description: �����ڰ� Ȩ���� �����ϴ� UI�� �����ϰ� �� Ȩ���� ���� ��� ���� Ƽ���� �����ش�.
	//Created: 2019/6/2
	//Author: ȫ����

	string homeTeam; //Ȩ��
	cin >> homeTeam;

	searchAuctionTicket->showBuyerWantAuctionTicket(homeTeam, ticketCollection, memberCollection, t);

	int ticketCount = searchAuctionTicket->getTempCount(); //�ӽ� Ƽ�� ������ ���� 

	if (ticketCount == 0)//������ Ƽ���� ���ٸ�
	{
		cout << "4.3. ��� ���� Ƽ�� �˻�" << endl;
		cout << ">" << endl;
	}

	else
	{
		cout << "4.3. ��� ���� Ƽ�� �˻�" << endl;
		for (int i = 0; i < ticketCount; i++)
		{
			cout << searchAuctionTicket->getSortedList(i)->getGameDateNTime() << " ";
			cout << searchAuctionTicket->getSortedList(i)->getHomeTeam() << " ";
			cout << searchAuctionTicket->getSortedList(i)->getAwayTeam() << " ";
			cout << searchAuctionTicket->getSortedList(i)->getTicketSeatNum() << " ";
			//�������� ���� �ð� ���
			cout << t->returnRemainAuctionTime(searchAuctionTicket->getSortedList(i));
			cout << endl;
		}
	}
	cout << endl;
}