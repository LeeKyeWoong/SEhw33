#pragma once
#include <string>
using namespace std;


class Ticket {
	//Class : Ticket
	//Description : Ticket의 정보를 나타내는 entity class
	//Created : 2019/05/28
	//Author : 홍지은
	
private:
	int price; //티켓의 가격
	string gameDateNTime; //게임 시작날짜와 시간
	string homeTeam; //홈팀
	string awayTeam; //어웨이팀 
	string seatNum; //티켓의 좌석
	bool isLimitedTimeAuction; //티켓을 경매로 넘길것인지의 여부
	
	bool isSold; //팔렸는지의 여부
	bool canSell; // 판매가능한 기간인지에 대한 여부
	string sellerId; //seller의 ID
	string registerTicketDate; //티켓 등록 날짜 -> 등록한지 1년이 지난 티켓 비교를 위함
	string ticketType; //티켓의 타입 -> 일반인지 경매인지
	

public:
	Ticket(); //생성자
	void addNewTicket(int price, string gameDateNTime, string homeTeam, string awayTeam, string seatNum,
		bool isLimitedTimeAuction, bool isSold, string sellerId, string registerTicketDate, string ticketType ); //티켓 생성
	void removeTicket();

	bool getReservable(); //티켓이 예약되었는지의 여부 확인
	void setReservable(bool pSold); //예약 혹은 미예약 설정
	string getSellerId(); //판매자의 아이디 가져오기
	string getHomeTeam(); //홈팀 가져오기
	string getAwayTeam();
	int getTicketPrice();
	string getTicketRegisterDate();  //티켓 등록날짜 가져오기
	string getTicketSeatNum(); // 티켓좌석 가져오기 
	string getGameDateNTime();
	bool getIsLimitedTimeAuction(); //경매 여부 선택이 되어있는지 확인하기
	bool getCanSell();
	bool getIsSold();
	void setCanSell(bool can);
	string getTicketType();
	void setTicketType(string type);
};