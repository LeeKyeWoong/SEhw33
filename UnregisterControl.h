#pragma once

#include <iostream>
#include <string>

using namespace std;

class UnregisterUI;
class TicketCollection;
class ReservationCollection;
class MemberCollection;

class UnregisterControl
{
	// Class: UnregisterControl
	// Description: unregister�� control class
	// Created: 2019/06/02
	// Author: �̰��

private:
	bool canUnregister;   // ȸ�� Ż�� ���� ���θ� �����ϴ� ����
	string unregisterId;  // ȸ�� Ż���� ID���� �����ϴ� ����

public:
	UnregisterControl();  // canUnregister�� ���� true�� �����ϴ� ������
	void requestUnregister(TicketCollection* TicketCollection, ReservationCollection* reservationCollection, MemberCollection* memberCollection);  //�ش� ȸ���� �����ϴ� �Լ�
	bool getCanUnregister();  //Ż�� ���� ���θ� ��ȯ�ϴ� �Լ�
	string getUnregisterId();  //Ż���� ID�� ��ȯ�ϴ� �Լ�
};