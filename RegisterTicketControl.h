#pragma once

#include <iostream>
#include <string>
#include "main.h"

using namespace std;

class MemberCollection;
class TicketCollection;
class Timer;

class RegisterTicketControl
{
	// Class: RegisterTicketControl
	// Description: Ƽ�ϵ�������� �Է¹ް� ó���ϴ� Ŭ����
	// Created: 2019/05/31
	// Author: �̰��

private:
	bool checkRegister;

public:
	RegisterTicketControl();
	void registerNewTicket(int price, string gameDatenTime, string homeTeam, string awayTeam, string seatNum, bool isLimitedTimeAuction, 
		TicketCollection *pticketCollection, MemberCollection * pmemberCollection ,Timer * ptimer);  //  TicketCollection�� Ƽ���� �߰��ϴ��Լ�
	bool getCheckRegister(); // Ƽ�ϵ���� �õ��ϴ� Ƽ���� �ߺ� ���θ� ��ȯ�ϴ� �Լ�
};

