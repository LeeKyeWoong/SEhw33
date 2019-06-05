#pragma once
#include <string>
using namespace std;


class Ticket {
	//Class : Ticket
	//Description : Ticket�� ������ ��Ÿ���� entity class
	//Created : 2019/05/28
	//Author : ȫ����
	
private:
	int price; //Ƽ���� ����
	string gameDateNTime; //���� ���۳�¥�� �ð�
	string homeTeam; //Ȩ��
	string awayTeam; //������� 
	string seatNum; //Ƽ���� �¼�
	bool isLimitedTimeAuction; //Ƽ���� ��ŷ� �ѱ�������� ����
	
	bool isSold; //�ȷȴ����� ����
	bool canSell; // �ǸŰ����� �Ⱓ������ ���� ����
	string sid; //seller�� ID
	string registerTicketDate; //Ƽ�� ��� ��¥ -> ������� 1���� ���� Ƽ�� �񱳸� ����
	string ticketType; //Ƽ���� Ÿ�� -> �Ϲ����� �������
	

public:
	Ticket(); //������
	void addNewTicket(int price, string gameDateNTime, string homeTeam, string awayTeam, string seatNum,
		bool isLimitedTimeAuction, bool isSold, string sid, string registerTicketDate, string ticketType ); //Ƽ�� ����
	void removeTicket();

	bool getReservable(); //Ƽ���� ����Ǿ������� ���� Ȯ��
	void setReservable(bool pSold); //���� Ȥ�� �̿��� ����
	string getSellerId(); //�Ǹ����� ���̵� ��������
	string getHomeTeam(); //Ȩ�� ��������
	string getAwayTeam();
	int getTicketPrice();
	string getTicketRegisterDate();  //Ƽ�� ��ϳ�¥ ��������
	string getTicketSeatNum(); // Ƽ���¼� �������� 
	string getGameDateNTime();
	bool getIsLimitedTimeAuction(); //��� ���� ������ �Ǿ��ִ��� Ȯ���ϱ�
	bool getCanSell();
	bool getIsSold();
	void setCanSell(bool can);
	string getTicketType();
	void setTicketType(string type);
};