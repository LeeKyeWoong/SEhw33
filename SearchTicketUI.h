#pragma once

#include <iostream>
#include <string>
using namespace std;

class TicketCollection;
class SearchTicketControl;
class MemberCollection;

class SearchTicketUI
{
	//Class: SearchTicketUI
	//Description: SearchTicket �� boundary class
	//Created: 2019/05/31
	//Author: ȫ����

private:

public:
	void selectHomeTeam(SearchTicketControl* searchTicket, TicketCollection* ticketCollection, MemberCollection* memberCollection);
	//Ȩ���� �����Ͽ� ���డ���� Ƽ���� ��ȸ�Ѵ�. (4.1.)
};