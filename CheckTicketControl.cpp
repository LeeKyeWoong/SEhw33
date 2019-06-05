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
	// Description: CheckTicketControl �� ������
	// Created: 2019/06/02
	// Author: �̰��

	this->sellerTicketNumber = 0;

	for (int i = 0; i < MAX; i++)
		this->sellerTicketList[i] = NULL;
}

void CheckTicketControl::getSellerTicket(CheckTicketUI *checkTicketUI, TicketCollection *ticketCollection, MemberCollection *memberCollection)
{
	// Function: getSellerTicket(CheckTicketUI *checkTicketUI, TicketCollection *ticketCollection, MemberCollection *memberCollection)
	// Description: Ư�� seller�� Ticket �� �����ͼ� Sort�Ѵ�.
	// Created: 2019/06/02
	// Author: �̰��

	if(memberCollection->currentSession() == NULL) // ���� ���ǿ��� ����� �����ϴ�.
	{
		cout << "> ���� Session�� �������� �ʽ��ϴ�." << endl << endl;
	}
	else // ������ �ִٸ�
	{
		if (memberCollection->currentSession()->getMemType().compare("seller") == 0) // �Ǹ��ڶ�� 
		{
			int ticketNumber = ticketCollection->getTicketCount(); // ��ü Ƽ�� ���� �����´�.
			string sellerId = memberCollection->currentSession()->getId();  // �Ǹ��� ID �� �޾ƿ´�. 
			
			for (int i = 0; i < ticketNumber; i++) // ��ü Ƽ�� ����ŭ �ݺ����� ������.
			{	
				if(sellerId.compare(ticketCollection->getTicket(i)->getSellerId()) == 0) // ���� ���Ǿ��̵�� �Ǹ��� ���̵�� ���ٸ�
				{
					this->sellerTicketList[this->sellerTicketNumber] = ticketCollection->getTicket(i); // �ϳ��� �־��
					this->sellerTicketNumber++;
				}
			}// �� �־���
			for (int i = 0; i < (this->sellerTicketNumber - 1); i++) // ��⳯¥ �� �ð��� ���� Ƽ�Ϻ��� �����Ѵ�.
         	{ 
            	for (int j = 0; j < (this->sellerTicketNumber - 1 - i); j++) // ��⳯¥ �� �ð��� ���� Ƽ�Ϻ��� �����Ѵ�.
	            {
               		if(strcmp(this->sellerTicketList[j]->getGameDateNTime().c_str(), this->sellerTicketList[j + 1]->getGameDateNTime().c_str()) > 0)
               		{
                  		Ticket* tempTicket = this->sellerTicketList[j];
                  		this->sellerTicketList[j] = this->sellerTicketList[j + 1];
                  		this->sellerTicketList[j + 1] = tempTicket;
               		}
            	}
        	}// Sort�� ������.
        	checkTicketUI->startInterface(this->sellerTicketNumber, this->sellerTicketList);
		}
		else // �����ڶ��
		{
			cout << "> �����ڴ� ���Ƽ�� ��ȸ�� �� �� �����ϴ�." << endl << endl;
		}
	}
	
}
