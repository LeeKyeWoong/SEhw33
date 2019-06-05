#pragma once
#include "main.h"
#define MAX 50
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
using namespace std;

int main()
{
	// Function: Main()
	// Description: 티켓 예약 프로그램 main함수
	// Created: 2019/05/29
	// Author: 이계웅
	// Revsions : 
	// 1. When & Who : 2019/05/30 by 이계웅
	//    What : signupInterface() 함수 구현
	// 1. When & Who : 2019/05/31 by 김승연
	//    What : setCurrentTimeInterface() 함수, changeSessionInterface() 함수 구현
	// 1. When & Who : 2019/05/31 by 이계웅
	//    What : loginInterface(), logoutInterface(), registerTicketInterface(), exitProgram() 함수 구현
	// 2. When & Who : 2019/06/01 by 홍지은
	//    What : searchTicketInterface() 함수구현
	// 3. When & Who : 2019/06/02 by 홍지은
	//    What : searchAutionTicketInterface() 함수, checkReservationInterface()함수, reserveGeneralTicketInterface()함수 구현
	// 1. When & Who : 2019/06/02 by 이계웅
	//    What : unregisterInterface() 함수, checkTicketInterface() 함수 구현
	// 4. When & Who: 2019/06/03 by 김승연
	//    What : participateAuctionTicketInterface() 함수 구현, guest session 변경 기능 구현

	Member member[MAX];             // 멤버 객체 생성 
	Timer timer;					// 타이머 객체 생성 
	Reservation reservation[MAX];	// 예약 객체 생성
	Ticket ticket[MAX];				// 티켓 객체 생성

	ReservationCollection reservationCollection(reservation);  // 예약 생성
	TicketCollection ticketCollection(ticket);                 // 티켓 생성
	MemberCollection memberCollection(member);				   // 멤버 생성

	FILE* in_fp;
	FILE* out_fp;

	in_fp = fopen(INPUT_FILE_NAME, "r+");   
	out_fp = fopen(OUTPUT_FILE_NAME, "w+");

	while (1)
	{
		// 두 개의 메뉴를 위한 변수 
		int menu_1 = 0;
		int menu_2 = 0;

		// 입력파일에서 메뉴 숫자 2개를 읽기
 		cin >> menu_1 >> menu_2;

		// 메뉴 구분 및 해당 연산 수행
		switch(menu_1)
		{
			case 1: 
			{
				switch(menu_2)
				{
					case 1: {	// 1.1. 회원가입
						signupInterface(&memberCollection);
						break;
					}
					case 2: {	// 1.2. 회원탈퇴 
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
					case 1: {	// 2.1. 로그인
						loginInterface(&memberCollection);
						break;
					}
					case 2: {	// 2.2. 로그아웃
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
					case 1: {   // 3.1. 판매티켓 등록
						registerTicketInterface(&ticketCollection, &memberCollection, &timer);
						break;
					}
					case 2: {   // 3.2. 등록티켓 조회
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
					case 1: {   // 4.1. 티켓 검색
						searchTicketInterface(&ticketCollection, &memberCollection);
						break;
					}
					case 2: {   // 4.2. 티켓 예약
						reserveGeneralTicketInterface(&reservationCollection, &ticketCollection, &memberCollection, &timer);
						break;
					}
					case 3: {   // 4.3. 경매 중인 티켓 검색
						searchAutionTicketInterface(&ticketCollection, &memberCollection, &timer);
						break;
					}
					case 4: {   // 4.4. 경매 참여
						participateAuctionTicketInterface(&reservationCollection, &ticketCollection, &memberCollection, &timer);
						break;
					}
					case 5: {   // 4.5. 예약 정보 조회
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
					case 1: {	 // 5.1. 현재시간 설정
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
					case 1: {	 // 6.1. session 변경
						changeSessionInterface(&memberCollection);
						break;
					}
					case 2: {	// 6.2. guest session으로 변경
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
					case 1: {   // 7.1. 종료
						exitProgram();	//exitProgram() 함수에서 해당 기능 수행
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

void signupInterface(MemberCollection* memberCollection) // 1.1 회원가입 인터페이스 
{
	// Function : void signupInterface()
	// Description: 회원가입을 하는 인터페이스
	// Created: 2019/05/30
	// Author: 이계웅

	SignUpUI userInterface;
	SignUpControl control;
	userInterface.inputInfo(&control, memberCollection); // 포인터
}

void unregisterInterface(TicketCollection* ticketCollection, ReservationCollection* reservationCollection, MemberCollection* memberCollection) // 1.2 회원탈퇴 인터페이스
{
	// Function: void unregisterInterface()
	// Description: 회원탈퇴를 하는 인터페이스
	// Created: 2019/06/02
	// Author: 이계웅

	UnregisterUI userInterface;
	UnregisterControl control;
	userInterface.callUnregister(&control, ticketCollection, reservationCollection, memberCollection);

	if (control.getCanUnregister()) {
		guestSession(memberCollection); // 회원탈퇴를 했으므로 guest session으로 변경해야 한다.
	}
}


void loginInterface(MemberCollection* memberCollection) //2.1 로그인 인터페이스
{
	//Function: void loginInterface()
	//Description: 로그인 하는 인터페이스
	//Created: 2019/05/31
	//Author: 이계웅

	LoginUI userInterface;
	LoginControl control;
	userInterface.inputLogin(&control, memberCollection);
}

void logoutInterface(MemberCollection* memberCollection) //2.2 로그아웃 인터페이스
{
	//Function: void logoutInterface()
	//Description: 로그아웃 하는 인터페이스
	//Created: 2019/05/31
	//Author: 이계웅

	LogoutUI userInterface;
	LogoutControl control;
	userInterface.callLogout(&control, memberCollection);
}

void registerTicketInterface(TicketCollection* ticketCollection, MemberCollection* memberCollection, Timer *timer) // 3.1 판매티켓 등록 인터페이스
{
	// Function: void registerTicketInterface()
	// Description: 새로운 티켓을 등록하는 인터페이스
	// Created: 2019/05/31
	// Author: 이계웅

	RegisterTicketUI userInterface;
	RegisterTicketControl control;
	userInterface.inputRegisterNewTicket(&control, ticketCollection, memberCollection, timer);
}

void checkTicketInterface(TicketCollection* ticketCollection, MemberCollection* memberCollection) // 3.2. 등록티켓 조회 인터페이스
{
	//Function: void checkTicketInterface()
	//Description: 등록한 티켓 조회 인터페이스
	//Created: 2019/06/02
	//Author: 이계웅

	CheckTicketUI userInterface;
	CheckTicketControl control;
	control.getSellerTicket(&userInterface, ticketCollection, memberCollection);
}

void searchTicketInterface(TicketCollection* ticketCollection, MemberCollection* memberCollection)  // 4.1. 티켓 검색 인터페이스
{
	// Function: void searchTicketInterface()
	// Description: 일반티켓을 조회하기 위한 인터페이스
	// Created: 2019/06/01
	// Author: 홍지은

	SearchTicketUI userInterface;
	SearchTicketControl control;
	userInterface.selectHomeTeam(&control, ticketCollection, memberCollection);
}


void reserveGeneralTicketInterface(ReservationCollection* reservationCollection, TicketCollection* ticketCollection, MemberCollection* memberCollection, Timer* timer) // 4.2. 티켓 예약 인터페이스
{
	// Function: void reserveGeneralTicketInterface()
	// Description: 티켓을 예약하기 위한 인터페이스
	// Created: 2019/06/02
	// Author: 홍지은

	ReserveGeneralTicketUI userInterface;
	ReserveGeneralTicketControl control;
	userInterface.reserveGeneralTicket(&control, reservationCollection, ticketCollection, memberCollection, timer);
}

void searchAutionTicketInterface(TicketCollection* ticketCollection, MemberCollection* memberCollection, Timer* t) // 4.3. 경매 중인 티켓 검색 인터페이스 
{
	// Function: void searchAuctionTicketInterface()
	// Description: 경매티켓을 조회하기 위한 인터페이스
	// Created: 2019/06/02
	// Author: 홍지은

	SearchAuctionTicketUI userInterface;
	SearchAuctionTicketControl control;
	userInterface.selectAuctionHomeTeam(&control, ticketCollection, memberCollection, t);
}


void participateAuctionTicketInterface(ReservationCollection* reservationCollection, TicketCollection* ticketCollection, MemberCollection* memberCollection, Timer *timer) // 4.4. 경매 참여 인터페이스
{
	// Function: void participateAuctionTicketInterface()
	// Description: 경매 참여를 위한 인터페이스를 호출
	// Created: 2019/06/03
	// Author: 김승연

	ParticipateAuctionTicketUI userInterface;
	ParticipateAuctionTicketControl control;
	userInterface.participateAuctionInterface(&control, reservationCollection, memberCollection, ticketCollection, timer);
}

void checkReservationInterface(ReservationCollection* reservationCollection, MemberCollection* memberCollection)  // 4.5. 예약 정보 조회
{
	// Function: void checkReservationInterface()
	// Description: 예약정보를 조회하기 위한 인터페이스
	// Created: 2019/06/02
	// Author: 홍지은
	CheckReservationInfoUI userInterface;
	CheckReservationInfoControl control;
	userInterface.showReservationInfo(&control, reservationCollection, memberCollection);
}


void setCurrentTimeInterface(Timer* timer, TicketCollection* ticketCollection) // 5.1 현재시간설정 인터페이스
{
	// Function: void setCurrentTimeInterface(Timer* timer, TicketCollection* TicketCollection, MemberCollection* memberCollection)
	// Description: 현재시간설정 인터페이스를 호출하는 함수이다.
	// Parameters: Timer* timer - 현재시간을 저장하기 위한 Timer 객체
	//					TicketCollection* ticketCollection - 현재시간이 바뀌고 나서 일 년이 지난 티켓을 삭제하기 위해 필요한 TicketCollection 객체
	// Created: 2019/05/31
	// Author: 김승연

	SetCurrentTimeUI userInterface;
	SetCurrentTimeControl control;
	userInterface.startInterface(&control, timer, ticketCollection);
}


void changeSessionInterface(MemberCollection* mCollection) // 6.1 Session변경
{
	// Function: void changeSession(MemberCollection* mCollection)
	// Description: Session을 변경하기 위해 인터페이스를 호출하는 함수
	// Parameter: MemberCollection* mCollection - 세션 변경을 할 때 멤버 객체들에 접근하기 위해 필요
	// Created: 2019/05/31
	// Author: 김승연

	ChangeSessionUI userInterface;
	ChangeSessionControl control;
	userInterface.startInterface(&control, mCollection);
}


void guestSession(MemberCollection* memcoll)  // 6.2. guest session으로 변경
{
	// Function :guestSession(MemberCollection* membercollection)
	// Description: guest session으로 변경한다. 
	//				누군가가 로그인 된 상태가 아니라면 아무 일도 수행하지 않고, 로그인된 상태이면 sessionOn = false로 바꾼다.
	// Created: 2019/06/02
	// Author: 김승연

	Member *tmp;
	tmp = memcoll->currentSession();
	if (tmp == NULL) {}
	else {
		tmp->setSessionOn(false);
	}
	cout << "6.2 Guest Session으로 변경" << endl;
	cout << endl;
}

void exitProgram() {  // 7.1 종료 인터페이스

	// Function :exitProgram()
	// Description: 프로그램 종료
	// Created: 2019/05/31
	// Author: 이계웅

	cout << "7.1 종료";
	exit(0);
}
