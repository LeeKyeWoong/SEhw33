#pragma once

#include <iostream>
#include <string>
#include "TicketCollection.h"

TicketCollection::TicketCollection(Ticket ticketList[MAX])
{
	//Function: TicketCollection(Ticket ticketList[MAX])
	//Description: Ƽ�� ����Ʈ �ʱ�ȭ
	//Created: 2019/5/30
	//Author: ȫ����

	this->ticketCount = 0;
	for (int i = 0; i < MAX; i++)
	{
		this->ticketList[i] = &ticketList[i];
	}
}

void TicketCollection::increaseTicketCount()
{
	//Function: increaseTicketCount()
	//Description: Ƽ�� ���� ����
	//Created: 2019/5/30
	//Author: ȫ����

	this->ticketCount++;
}

int TicketCollection::getTicketCount()
{
	//Function: getTicketCount()
	//Description: Ƽ�� ���� ��ȯ
	//Created: 2019/5/30
	//Author: ȫ����

	return this->ticketCount;
}

void TicketCollection::deleteTicket(int deleteTicketIndex)
{
	//Function: deleteTicket()
	//Description: �Ű������� ���� �ε����� �ش��ϴ� Ƽ���� ����
	//Created: 2019/6/1
	//Author: ȫ����
	// Revsions : 
	// 1. When & Who : 2019/06/02 by ��¿�
	//    What : �߰��� �ִ� Ƽ�� ���� ��, ������ ������ �ʵ��� �ڿ� �ִ� ������ ������ ���ܿ�

	ticketList[deleteTicketIndex]->removeTicket();
	int num = this->ticketCount;
	for (int i = deleteTicketIndex; i < num - 1; i++) {
		this->ticketList[i] = this->ticketList[i + 1];
	}
	this->ticketList[num] = NULL;
}

void TicketCollection::addTicket(int price, string gameDatenTime, string homeTeam, string awayTeam, string seatNum, bool isLimitedTimeAuction, bool isSold, string sid, string registerTicketDate, string ticketType) // TicketList�� Ƽ�ϵ���Ѵ�.
{
	//Function: addTicket(int price, string gameDatenTime, string homeTeam, string awayTeam, string seatNum, bool isLimitedTimeAuction, bool isSold, string sid, string registerTicketDate, string ticketType)
	//Description: Ƽ�� �߰�
	//Created: 2019/5/30
	//Author: ȫ����

	int currenTicketCount = this->getTicketCount();
	this->ticketList[currenTicketCount]->addNewTicket(price, gameDatenTime, homeTeam, awayTeam, seatNum, isLimitedTimeAuction, isSold, sid, registerTicketDate, ticketType);
	this->increaseTicketCount();
}

Ticket * TicketCollection::getTicket(int ticketCount)
{
	//Function: getTicket(int ticketCount)
	//Description: ticketCount��° Ƽ���� ��ȯ
	//Created: 2019/5/30
	//Author: ȫ����

	return ticketList[ticketCount];
}