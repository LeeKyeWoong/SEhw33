#pragma once
#include "main.h"
#define MAX 50
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
using namespace std;

int main()
{
	// Function: Main()
	// Description: Ƽ�� ���� ���α׷� main�Լ�
	// Created: 2019/05/29
	// Author: �̰��
	// Revsions : 
	// 1. When & Who : 2019/05/30 by �̰��
	//    What : signupInterface() �Լ� ����
	// 1. When & Who : 2019/05/31 by ��¿�
	//    What : setCurrentTimeInterface() �Լ�, changeSessionInterface() �Լ� ����
	// 1. When & Who : 2019/05/31 by �̰��
	//    What : loginInterface(), logoutInterface(), registerTicketInterface(), exitProgram() �Լ� ����
	// 2. When & Who : 2019/06/01 by ȫ����
	//    What : searchTicketInterface() �Լ�����
	// 3. When & Who : 2019/06/02 by ȫ����
	//    What : searchAutionTicketInterface() �Լ�, checkReservationInterface()�Լ�, reserveGeneralTicketInterface()�Լ� ����
	// 1. When & Who : 2019/06/02 by �̰��
	//    What : unregisterInterface() �Լ�, checkTicketInterface() �Լ� ����
	// 4. When & Who: 2019/06/03 by ��¿�
	//    What : participateAuctionTicketInterface() �Լ� ����, guest session ���� ��� ����

	Member member[MAX];             // ��� ��ü ���� 
	Timer timer;					// Ÿ�̸� ��ü ���� 
	Reservation reservation[MAX];	// ���� ��ü ����
	Ticket ticket[MAX];				// Ƽ�� ��ü ����

	ReservationCollection reservationCollection(reservation);  // ���� ����
	TicketCollection ticketCollection(ticket);                 // Ƽ�� ����
	MemberCollection memberCollection(member);				   // ��� ����

	FILE* in_fp;
	FILE* out_fp;

	in_fp = fopen(INPUT_FILE_NAME, "r+");   
	out_fp = fopen(OUTPUT_FILE_NAME, "w+");

	while (1)
	{
		// �� ���� �޴��� ���� ���� 
		int menu_1 = 0;
		int menu_2 = 0;

		// �Է����Ͽ��� �޴� ���� 2���� �б�
 		cin >> menu_1 >> menu_2;

		// �޴� ���� �� �ش� ���� ����
		switch(menu_1)
		{
			case 1: 
			{
				switch(menu_2)
				{
					case 1: {	// 1.1. ȸ������
						signupInterface(&memberCollection);
						break;
					}
					case 2: {	// 1.2. ȸ��Ż�� 
						unregisterInterface(&ticketCollection, &reservationCollection, &memberCollection);
						break;
					}
				}
				break;
			}
			case 2:
			{
				switch(menu_2)
				{
					case 1: {	// 2.1. �α���
						loginInterface(&memberCollection);
						break;
					}
					case 2: {	// 2.2. �α׾ƿ�
						logoutInterface(&memberCollection);
						break;
					}
				}
				break;
			}
			case 3: 
			{
				switch(menu_2) 
				{
					case 1: {   // 3.1. �Ǹ�Ƽ�� ���
						registerTicketInterface(&ticketCollection, &memberCollection, &timer);
						break;
					}
					case 2: {   // 3.2. ���Ƽ�� ��ȸ
						checkTicketInterface(&ticketCollection, &memberCollection);
						break;
					}
				}
				break;
			}
			case 4: 
			{
				switch(menu_2) 
				{
					case 1: {   // 4.1. Ƽ�� �˻�
						searchTicketInterface(&ticketCollection, &memberCollection);
						break;
					}
					case 2: {   // 4.2. Ƽ�� ����
						reserveGeneralTicketInterface(&reservationCollection, &ticketCollection, &memberCollection, &timer);
						break;
					}
					case 3: {   // 4.3. ��� ���� Ƽ�� �˻�
						searchAutionTicketInterface(&ticketCollection, &memberCollection, &timer);
						break;
					}
					case 4: {   // 4.4. ��� ����
						participateAuctionTicketInterface(&reservationCollection, &ticketCollection, &memberCollection, &timer);
						break;
					}
					case 5: {   // 4.5. ���� ���� ��ȸ
						checkReservationInterface(&reservationCollection, &memberCollection);
						break;
					}
				}
				break;
			}
			case 5:
			{
				switch(menu_2) 
				{
					case 1: {	 // 5.1. ����ð� ����
						setCurrentTimeInterface(&timer, &ticketCollection);
						break;
					}
				}	
				break;
			}
			case 6: 
			{
				switch(menu_2) 
				{
					case 1: {	 // 6.1. session ����
						changeSessionInterface(&memberCollection);
						break;
					}
					case 2: {	// 6.2. guest session���� ����
						guestSession(&memberCollection);
						break;
					}
				}
				break;
			}
			case 7: 
			{
				switch(menu_2) 
				{
					case 1: {   // 7.1. ����
						exitProgram();	//exitProgram() �Լ����� �ش� ��� ����
						break;
					}
				}
				break;
			}
		}
		//cout << endl;
	}
	return 0;
}

void signupInterface(MemberCollection* memberCollection) // 1.1 ȸ������ �������̽� 
{
	// Function : void signupInterface()
	// Description: ȸ�������� �ϴ� �������̽�
	// Created: 2019/05/30
	// Author: �̰��

	SignUpUI userInterface;
	SignUpControl control;
	userInterface.inputInfo(&control, memberCollection); // ������
}

void unregisterInterface(TicketCollection* ticketCollection, ReservationCollection* reservationCollection, MemberCollection* memberCollection) // 1.2 ȸ��Ż�� �������̽�
{
	// Function: void unregisterInterface()
	// Description: ȸ��Ż�� �ϴ� �������̽�
	// Created: 2019/06/02
	// Author: �̰��

	UnregisterUI userInterface;
	UnregisterControl control;
	userInterface.callUnregister(&control, ticketCollection, reservationCollection, memberCollection);

	if (control.getCanUnregister()) {
		guestSession(memberCollection); // ȸ��Ż�� �����Ƿ� guest session���� �����ؾ� �Ѵ�.
	}
}


void loginInterface(MemberCollection* memberCollection) //2.1 �α��� �������̽�
{
	//Function: void loginInterface()
	//Description: �α��� �ϴ� �������̽�
	//Created: 2019/05/31
	//Author: �̰��

	LoginUI userInterface;
	LoginControl control;
	userInterface.inputLogin(&control, memberCollection);
}

void logoutInterface(MemberCollection* memberCollection) //2.2 �α׾ƿ� �������̽�
{
	//Function: void logoutInterface()
	//Description: �α׾ƿ� �ϴ� �������̽�
	//Created: 2019/05/31
	//Author: �̰��

	LogoutUI userInterface;
	LogoutControl control;
	userInterface.callLogout(&control, memberCollection);
}

void registerTicketInterface(TicketCollection* ticketCollection, MemberCollection* memberCollection, Timer *timer) // 3.1 �Ǹ�Ƽ�� ��� �������̽�
{
	// Function: void registerTicketInterface()
	// Description: ���ο� Ƽ���� ����ϴ� �������̽�
	// Created: 2019/05/31
	// Author: �̰��

	RegisterTicketUI userInterface;
	RegisterTicketControl control;
	userInterface.inputRegisterNewTicket(&control, ticketCollection, memberCollection, timer);
}

void checkTicketInterface(TicketCollection* ticketCollection, MemberCollection* memberCollection) // 3.2. ���Ƽ�� ��ȸ �������̽�
{
	//Function: void checkTicketInterface()
	//Description: ����� Ƽ�� ��ȸ �������̽�
	//Created: 2019/06/02
	//Author: �̰��

	CheckTicketUI userInterface;
	CheckTicketControl control;
	control.getSellerTicket(&userInterface, ticketCollection, memberCollection);
}

void searchTicketInterface(TicketCollection* ticketCollection, MemberCollection* memberCollection)  // 4.1. Ƽ�� �˻� �������̽�
{
	// Function: void searchTicketInterface()
	// Description: �Ϲ�Ƽ���� ��ȸ�ϱ� ���� �������̽�
	// Created: 2019/06/01
	// Author: ȫ����

	SearchTicketUI userInterface;
	SearchTicketControl control;
	userInterface.selectHomeTeam(&control, ticketCollection, memberCollection);
}


void reserveGeneralTicketInterface(ReservationCollection* reservationCollection, TicketCollection* ticketCollection, MemberCollection* memberCollection, Timer* timer) // 4.2. Ƽ�� ���� �������̽�
{
	// Function: void reserveGeneralTicketInterface()
	// Description: Ƽ���� �����ϱ� ���� �������̽�
	// Created: 2019/06/02
	// Author: ȫ����

	ReserveGeneralTicketUI userInterface;
	ReserveGeneralTicketControl control;
	userInterface.reserveGeneralTicket(&control, reservationCollection, ticketCollection, memberCollection, timer);
}

void searchAutionTicketInterface(TicketCollection* ticketCollection, MemberCollection* memberCollection, Timer* t) // 4.3. ��� ���� Ƽ�� �˻� �������̽� 
{
	// Function: void searchAuctionTicketInterface()
	// Description: ���Ƽ���� ��ȸ�ϱ� ���� �������̽�
	// Created: 2019/06/02
	// Author: ȫ����

	SearchAuctionTicketUI userInterface;
	SearchAuctionTicketControl control;
	userInterface.selectAuctionHomeTeam(&control, ticketCollection, memberCollection, t);
}


void participateAuctionTicketInterface(ReservationCollection* reservationCollection, TicketCollection* ticketCollection, MemberCollection* memberCollection, Timer *timer) // 4.4. ��� ���� �������̽�
{
	// Function: void participateAuctionTicketInterface()
	// Description: ��� ������ ���� �������̽��� ȣ��
	// Created: 2019/06/03
	// Author: ��¿�

	ParticipateAuctionTicketUI userInterface;
	ParticipateAuctionTicketControl control;
	userInterface.participateAuctionInterface(&control, reservationCollection, memberCollection, ticketCollection, timer);
}

void checkReservationInterface(ReservationCollection* reservationCollection, MemberCollection* memberCollection)  // 4.5. ���� ���� ��ȸ
{
	// Function: void checkReservationInterface()
	// Description: ���������� ��ȸ�ϱ� ���� �������̽�
	// Created: 2019/06/02
	// Author: ȫ����
	CheckReservationInfoUI userInterface;
	CheckReservationInfoControl control;
	userInterface.showReservationInfo(&control, reservationCollection, memberCollection);
}


void setCurrentTimeInterface(Timer* timer, TicketCollection* ticketCollection) // 5.1 ����ð����� �������̽�
{
	// Function: void setCurrentTimeInterface(Timer* timer, TicketCollection* TicketCollection, MemberCollection* memberCollection)
	// Description: ����ð����� �������̽��� ȣ���ϴ� �Լ��̴�.
	// Parameters: Timer* timer - ����ð��� �����ϱ� ���� Timer ��ü
	//					TicketCollection* ticketCollection - ����ð��� �ٲ�� ���� �� ���� ���� Ƽ���� �����ϱ� ���� �ʿ��� TicketCollection ��ü
	// Created: 2019/05/31
	// Author: ��¿�

	SetCurrentTimeUI userInterface;
	SetCurrentTimeControl control;
	userInterface.startInterface(&control, timer, ticketCollection);
}


void changeSessionInterface(MemberCollection* mCollection) // 6.1 Session����
{
	// Function: void changeSession(MemberCollection* mCollection)
	// Description: Session�� �����ϱ� ���� �������̽��� ȣ���ϴ� �Լ�
	// Parameter: MemberCollection* mCollection - ���� ������ �� �� ��� ��ü�鿡 �����ϱ� ���� �ʿ�
	// Created: 2019/05/31
	// Author: ��¿�

	ChangeSessionUI userInterface;
	ChangeSessionControl control;
	userInterface.startInterface(&control, mCollection);
}


void guestSession(MemberCollection* memcoll)  // 6.2. guest session���� ����
{
	// Function :guestSession(MemberCollection* membercollection)
	// Description: guest session���� �����Ѵ�. 
	//				�������� �α��� �� ���°� �ƴ϶�� �ƹ� �ϵ� �������� �ʰ�, �α��ε� �����̸� sessionOn = false�� �ٲ۴�.
	// Created: 2019/06/02
	// Author: ��¿�

	Member *tmp;
	tmp = memcoll->currentSession();
	if (tmp == NULL) {}
	else {
		tmp->setSessionOn(false);
	}
	cout << "6.2 Guest Session���� ����" << endl;
	cout << endl;
}

void exitProgram() {  // 7.1 ���� �������̽�

	// Function :exitProgram()
	// Description: ���α׷� ����
	// Created: 2019/05/31
	// Author: �̰��

	cout << "7.1 ����";
	exit(0);
}
