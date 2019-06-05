#pragma once

#include <iostream>
#include <string>
using namespace std;

#define MAX 50

class SearchTicketUI;
class TicketCollection;
class MemberCollection;
class Ticket;

class SearchTicketControl
{
	//Class: SearchTicketControl
	//Description: SearchTicket�� control class
	//Created: 2019/05/31
	//Author: ȫ����

private:
	Ticket *temp[MAX];
	//�˻��� Ƽ�ϵ��� ��⳯¥ �� �ð��� ���� Ƽ�Ϻ��� �����ؼ� �����ֱ� ���� �ӽð�ü
	int tempCount;

public:
	SearchTicketControl();
	void showBuyerWantTicket(string homeTeam, TicketCollection* ticketCollection, MemberCollection* memberCollection);
	//�����ڰ� ���ϴ� Ƽ�� ����� ���ĵ� ���·� �����ִ� �Լ�
	Ticket* getSortedList(int ticketCount);
	//��⳯¥ �� �ð��� ���� Ƽ������ ���ĵ� ����Ʈ�� ��ȯ�ϴ� �Լ�
	int getTempCount();
};