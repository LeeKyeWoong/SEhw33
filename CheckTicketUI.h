#pragma once

#include <iostream>
#include <string>
#include "CheckTicketControl.h"

using namespace std;

class CheckTicketControl;
class MemberCollection;

class CheckTicketUI
{
	//Class: CheckTicketClass
	//Description: CheckTicket�� boundary class
	//Created: 2019/06/02
	//Author: �̰��

private:

public:
	void startInterface(int ticketCount, Ticket *sellerTicket[]); // ���� seller�� Ƽ�ϵ��� ������ ������ִ� �Լ�
};