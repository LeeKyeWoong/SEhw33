#pragma once

#include <iostream>
#include "Ticket.h"
using namespace std;


Ticket::Ticket()
{

	//Function: Ticket()
	//Description:Ticket�� ������ �� �ʱ�ȭ
	//Created: 2019/5/28
	//Author: ȫ����


	this->sid = "";
	this->homeTeam = "";
	this->awayTeam = "";
	this->price = 0;
	this->gameDateNTime = "";
	this->registerTicketDate = "";
	this->seatNum = "";
	this->isSold = false;
	this->ticketType = "";
	this->isLimitedTimeAuction = false;
	this->canSell = true;
}

void Ticket::addNewTicket(int price, string gameDateNTime, string homeTeam, string awayTeam, string seatNum, bool isLimitedTimeAuction, bool isSold, string sid, string registerTicketDate, string ticketType )
{
	//Function: addNewTicket(int price, string gameDateNTime, string homeTeam, string awayTeam, string seatNum, bool isLimitedTimeAuction, bool isSold, string sid, string registerTicketDate, string ticketType )
	//Description: ���ο� Ƽ���� �߰��Ѵ�.
	//Created: 2019/5/28
	//Author: ȫ����

	this->price = price;
	this->homeTeam = homeTeam;
	this->awayTeam = awayTeam;
	this->gameDateNTime = gameDateNTime;
	this->seatNum = seatNum;
	this->isLimitedTimeAuction = isLimitedTimeAuction;
	this->isSold = false; //���� ���� Ƽ���� ���� �ȸ��� ��������!
	this->sid = sid;	
	this->registerTicketDate = registerTicketDate;
	this->ticketType = ticketType;
}

void Ticket::removeTicket()
{
	//Function: removeTicket()
	//Description: Ƽ���� �����Ѵ�.
	//Created: 2019/6/1
	//Author: ȫ����

	this->price = 0; //����
	this->homeTeam = ""; //Ȩ��
	this->awayTeam = ""; //�������
	this->gameDateNTime = ""; //���ӽð�
	this->seatNum = ""; //�¼�
	this->isLimitedTimeAuction = false; //��ſ���
	this->isSold = false; //�ȷȴ���
	this->canSell = true; //��� �Ǹ� ���ɱⰣ����
	this->sid = ""; //�Ǹ��� ���̵�
	this->registerTicketDate = ""; //��ϳ�¥
	this->ticketType = ""; //Ƽ��Ÿ��
}

bool Ticket::getReservable()
{

	//Function: getReservable()
	//Description: ���డ�������� ���� ���θ� ��ȯ�Ѵ�. getReservable�� Ʈ���̸� ������ �����ϴٴ� ���̰� isSold�� false�̴�.
	//Created: 2019/5/28
	//Author: ȫ����

	return !isSold;
}

void Ticket::setReservable(bool pSold)
{
	//Function: setReservable(bool pSold)
	//Description: setReservable�� true�� Ƽ���� �ٽ� ���డ���� ���°� �ǵ��� �Ѵ�.
	//Created: 2019/5/28
	//Author: ȫ����

	isSold = !pSold;

	//���� pSold�� true�̸� ���� ���ȷȴٴ� ���̹Ƿ� isSold�� false�� �ȴ�
	//�ݴ�� pSold�� false�̸� �ȷȴٴ� ���̹Ƿ� isSold�� true�� �Ǿ��Ѵ�.
}

string Ticket::getSellerId()
{
	//Function: getSellerId()
	//Description: seller�� id�� ��ȯ�Ѵ�.
	//Created: 2019/5/28
	//Author: ȫ����

	return this->sid;
}

string Ticket::getHomeTeam()
{
	//Function: getHomeTeam()
	//Description: Ȩ���� ��ȯ�Ѵ�.
	//Created: 2019/5/28
	//Author: ȫ����

	return this->homeTeam;
}

string Ticket::getAwayTeam()
{
	//Function: getAwayTeam()
	//Description: ��������� ��ȯ�Ѵ�.
	//Created: 2019/5/28
	//Author: ȫ����

	return this->awayTeam;
}

int Ticket::getTicketPrice()
{
	//Function: getTicketPrice()
	//Description: Ƽ���� ������ ��ȯ�Ѵ�.
	//Created: 2019/5/28
	//Author: ȫ����

	return this->price;
}

string Ticket::getTicketRegisterDate()
{
	//Function: getTicketRegisterDate()
	//Description: Ƽ���� ��ϳ�¥�� ��ȯ�Ѵ�.
	//Created: 2019/5/28
	//Author: ȫ����

	return this->registerTicketDate;
}

string Ticket::getTicketSeatNum()
{
	//Function: getTicketSeatNum()
	//Description: �¼��� ��ȯ�Ѵ�.
	//Created: 2019/5/28
	//Author: ȫ����

	return this->seatNum;
}

string Ticket::getGameDateNTime()
{
	//Function: getGameDateNTime()
	//Description: ���ӳ�¥�� �ð��� ��ȯ�Ѵ�.
	//Created: 2019/6/1
	//Author: ȫ����
	return this->gameDateNTime;
}

bool Ticket::getIsLimitedTimeAuction()
{
	//Function: getGameDateNTime()
	//Description: ���ӳ�¥�� �ð��� ��ȯ�Ѵ�.
	//Created: 2019/6/1
	//Author: ȫ����

	return this->isLimitedTimeAuction;
}

bool Ticket::getIsSold()
{
	//Function: getIsSold()
	//Description: �Ǹſ��θ� ��ȯ�Ѵ�.
	//Created: 2019/6/2
	//Author: �̰��

	return this->isSold;
}

bool Ticket::getCanSell() {
	//Function: getCanSell()
	//Description: �ǸűⰣ�� �����ִ� Ƽ���� ��� true�� �����ϴ� �Լ��̴�.
	//Created: 2019/06/02
	//Author: ��¿�

	return this->canSell;
}

void Ticket::setCanSell(bool can) {
	//Function: setCanSell(bool can)
	//Description: �ǸŰ��ɱⰣ�� �����ִ��� ���θ� ������ �� ���� �Լ��̴�.
	//Created: 2019/06/02
	//Author: ��¿�

	this->canSell = can;
}

string Ticket::getTicketType() {
	//Function: getTicketType()
	//Description: ticketType�� �����ϴ� �Լ��̴�.
	//Created: 2019/06/02
	//Author: ��¿�

	return this->ticketType;
}

void Ticket::setTicketType(string type) {
	//Function: setTicketType(string type)
	//Description: ticketType�� �ٲ� �� ���� �Լ��̴�.
	//Created: 2019/06/02
	//Author: ��¿�

	ticketType = type;
}