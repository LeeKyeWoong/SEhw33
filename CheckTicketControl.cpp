#pragma once

#include <iostream>
#include <string>
#include "CheckTicketControl.h"
#include "CheckTicketUI.h"
#include "TicketCollection.h"
#include "Ticket.h"
#include "MemberCollection.h"
#include "Member.h"
#define MAX 50
using namespace std;

CheckTicketControl::CheckTicketControl()
{
	// Function: CheckTicketControl()
	// Description: CheckTicketControl 의 생성자
	// Created: 2019/06/02
	// Author: 이계웅

	this->sellerTicketNumber = 0;

	for (int i = 0; i < MAX; i++)
		this->sellerTicketList[i] = NULL;
}

void CheckTicketControl::getSellerTicket(CheckTicketUI *checkTicketUI, TicketCollection *ticketCollection, MemberCollection *memberCollection)
{
	// Function: getSellerTicket(CheckTicketUI *checkTicketUI, TicketCollection *ticketCollection, MemberCollection *memberCollection)
	// Description: 특정 seller의 Ticket 을 가져와서 Sort한다.
	// Created: 2019/06/02
	// Author: 이계웅

	if(memberCollection->currentSession() == NULL) // 현재 세션온인 멤버가 없습니다.
	{
		cout << "> 현재 Session은 존재하지 않습니다." << endl << endl;
	}
	else // 세션이 있다면
	{
		if (memberCollection->currentSession()->getMemType().compare("seller") == 0) // 판매자라면 
		{
			int ticketNumber = ticketCollection->getTicketCount(); // 전체 티켓 수를 가져온다.
			string sellerId = memberCollection->currentSession()->getId();  // 판매자 ID 를 받아온다. 
			
			for (int i = 0; i < ticketNumber; i++) // 전체 티켓 수만큼 반복문을 돌린다.
			{	
				if(sellerId.compare(ticketCollection->getTicket(i)->getSellerId()) == 0) // 현재 세션아이디와 판매자 아이디와 같다면
				{
					this->sellerTicketList[this->sellerTicketNumber] = ticketCollection->getTicket(i); // 하나씩 넣어라
					this->sellerTicketNumber++;
				}
			}// 다 넣었다
			for (int i = 0; i < (this->sellerTicketNumber - 1); i++) // 경기날짜 및 시각이 빠른 티켓부터 정렬한다.
         	{ 
            	for (int j = 0; j < (this->sellerTicketNumber - 1 - i); j++) // 경기날짜 및 시각이 빠른 티켓부터 정렬한다.
	            {
               		if(strcmp(this->sellerTicketList[j]->getGameDateNTime().c_str(), this->sellerTicketList[j + 1]->getGameDateNTime().c_str()) > 0)
               		{
                  		Ticket* tempTicket = this->sellerTicketList[j];
                  		this->sellerTicketList[j] = this->sellerTicketList[j + 1];
                  		this->sellerTicketList[j + 1] = tempTicket;
               		}
            	}
        	}// Sort가 끝났다.
        	checkTicketUI->startInterface(this->sellerTicketNumber, this->sellerTicketList);
		}
		else // 구매자라면
		{
			cout << "> 구매자는 등록티켓 조회를 할 수 없습니다." << endl << endl;
		}
	}
	
}
