#include "Timer.h"
#include "ReservationCollection.h"
#include "TicketCollection.h"
#include "Ticket.h"
void Timer::setCurrentTime(string cntTime) {
	// Function: void setCurrentTime(string cntTime)
	// Description: 매개변수로 받은 시간을 멤버변수인 currentTime에 저장하는 함수이다.
	// Parameter: string cntTime - 새로운 현재시간으로 설정하기 위해 받은 값
	// Created: 2019/05/30
	// Author: 김승연

	this->currentTime = cntTime;
}

string Timer::getCurrentTime() {
	// Function: string getCurrentTime()
	// Description: 멤버변수인 currentTime의 값을 리턴하는 함수이다.
	// Return value: 현재 시간
	// Created: 2019/05/30
	// Author: 김승연

	return this->currentTime;
}

bool Timer::checkTimeToDeleteTicket(string registerTime) {
	// Function: bool checkTimeToDeleteTicket(string registerTime)
	// Description: 티켓이 등록된 시간과 현재시간을 비교하여 티켓을 삭제할지 결정하는 함수이다.
	// Parameter: string registerTime - 티켓이 등록된 시간
	// Return value: 티켓이 등록된 지 1년 이상 된 경우 true를, 그렇지 않은 경우 false를 리턴한다.
	// Created: 2019/05/30
	// Author: 김승연

	/*
	매개변수로 받은 registerTime이 string형으로 ????:??:??:??:?? 형식이기 때문에
	':'를 제외하고 년월일까지를 따로 임시 변수 tmp_registerTime에 저장을 한다.
	그래서 2019:05:30:12:23 이란 시간을 tmp_registerTime에 20190530 으로 저장한다.
	그러고나서 이 string으로 된 것을 int형으로 변환을 한다.
	이는 currentTime의 경우에도 동일하다.

	티켓 삭제는 등록된 지 1년 지났을 때 이루어지기 때문에, 현재시간과 티켓 등록 시간의 차이가 10000 이상이 되는 경우 삭제하면 된다.
	*/
	if (registerTime == "") {
		cout << "error: 티켓 등록 날짜가 설정되어있지 않습니다. ""6.1 현재시간 설정""을 먼저한 후 티켓 등록을 해주세요!" << endl;
		return false;
	}
	else {
		string tmp_registerTime, tmp_currentTime;
		tmp_registerTime.append(registerTime, 0, 4);
		tmp_registerTime.append(registerTime, 5, 2);
		tmp_registerTime.append(registerTime, 8, 2);
		tmp_currentTime.append(this->currentTime, 0, 4);
		tmp_currentTime.append(this->currentTime, 5, 2);
		tmp_currentTime.append(this->currentTime, 8, 2);

		int regTime, cntTime;
		regTime = stoi(tmp_registerTime);
		cntTime = stoi(tmp_currentTime);

		if (cntTime - regTime > 10000) return true;
		else return false;
	}
}

void Timer::checkTimeToConvertIntoAuction(Ticket * tk) {
	// Function: bool checkTimeToConvertIntoAuction(Ticket * tk)
	// Description: 경기 시작 시간과 현재 시간을 비교해 경기 시작 24시간 전인 티켓 중 경매전환 옵션을 선택한 티켓은 ticketType을 A로 바꾼다.
	//						그리고 경기 시작 6시간 전이 되면 경매 종료가 되므로 판매 불가하다는 의미의 canSell=false로 설정한다.
	// Parameter: Ticket* tk - 시간을 비교할 티켓
	// Created: 2019/06/02
	// Author: 김승연

	bool isLimited = tk->getIsLimitedTimeAuction();
	string gameTime = tk->getGameDateNTime();
	string temp_crD, temp_gD, temp_crT, temp_gT;
	temp_crD.append(currentTime, 0, 4).append(currentTime, 5, 2).append(currentTime, 8, 2);
	temp_gD.append(gameTime, 0, 4).append(gameTime, 5, 2).append(gameTime, 8, 2);
	temp_crT.append(currentTime, 11, 2).append(currentTime, 14, 2);
	temp_gT.append(gameTime, 11, 2).append(gameTime, 14, 2);

	int cD = stoi(temp_crD);
	int gD = stoi(temp_gD);
	int cT = stoi(temp_crT);
	int gT = stoi(temp_gT);
	int compareDate = gD - cD;
	int compareTime = gT - cT;
	
	long long compare = compareDate * 10000 + compareTime;
	if (compareDate >= 0) {

		if (compare <= 10000 && tk->getIsLimitedTimeAuction()) { // 경기시작 24시간 전인 경우
			tk->setTicketType("A");
		}

		if (gT < cT) {
			compareTime = 2400 + gT - cT;
		}
		else compareTime = gT - cT;

		if (compareTime <= 600) { // 경기시작 6시간 전인 경우 경매 종료
			tk->setCanSell(false);
		}
	}
	else {
		tk->setCanSell(false);
	}
}

string Timer::returnRemainAuctionTime(Ticket* tk) {
	// Function: string returnRemainAuctionTime(Ticket* tk)
	// Description: 경매종료까지 얼마나 남았는지를 리턴하는 함수이다.
	// Parameter: Ticket* tk - 시간을 비교할 티켓
	// Created: 2019/06/02
	// Author: 김승연

	if (tk->getCanSell() && tk->getTicketType() == "A") {
		string temp_crT[2], temp_gT[2];
		string gameTime = tk->getGameDateNTime();
		temp_crT[0].append(currentTime, 11, 2);
		temp_crT[1].append(currentTime, 14, 2);
		temp_gT[0].append(gameTime, 11, 2);
		temp_gT[1].append(gameTime, 14, 2);
		// 0은 시간, 1은 분
		int cT0 = stoi(temp_crT[0]);
		int cT1 = stoi(temp_crT[1]);
		int gT0 = stoi(temp_gT[0]);
		int gT1 = stoi(temp_gT[1]);

		int cT = cT0 * 60 + cT1;
		int gT = gT0 * 60 + gT1;

		int compareTime;
		if (gT < cT) {
			compareTime = 24 * 60 + gT - cT;
		}
		else compareTime = gT - cT;

		string remainHour, remainMin1, remainMin2;
		int oo1, oo21, oo22;
		oo1 = compareTime / 60;
		oo21 = compareTime % 60 / 10;
		oo22 = compareTime % 10;
		ostringstream o1, o2_1, o2_2;
		o1 << oo1;
		o2_1 << oo21;
		o2_2 << oo22;
		remainHour = o1.str();
		remainMin1 = o2_1.str();
		remainMin2 = o2_2.str();

		string remainTime = "";
		remainTime.append(remainHour);
		remainTime.append(":");
		remainTime.append(remainMin1);
		remainTime.append(remainMin2);
		
		return remainTime;
	}

	else {
		return "경매참여 불가 티켓";
	}
	
}

void Timer::changeCanShow(ReservationCollection *reservationCollection, TicketCollection *ticketCollection) {
	// Function: void changeCanShow(ReservationCollection * reservationCollection)
	// Description: 경기시작 6시간 전이 되면 경매 종료가 되므로 낙찰이 되어서 canShow하고 isSold 하자 
	// Created: 2019/06/06
	// Author: 김승연

	int count = reservationCollection->getReservationCount();
	int ticketCount = ticketCollection->getTicketCount();

	for(int i = 0; i < count; i++) // 모든 예약건에 대해서
	{
		Reservation *reservation = reservationCollection->getReservation(i); // 예약정보를 가져온다.

		if (reservation->getCanShow() == false) // 만약에 보여주면 안되는 false인 티켓이다. 즉, 경매가 진행중인 티켓이다.
		{
			string gameTime = reservation->getGameDate();
			string temp_crD, temp_gD, temp_crT, temp_gT;
			temp_crD.append(currentTime, 0, 4).append(currentTime, 5, 2).append(currentTime, 8, 2);
			temp_gD.append(gameTime, 0, 4).append(gameTime, 5, 2).append(gameTime, 8, 2);
			temp_crT.append(currentTime, 11, 2).append(currentTime, 14, 2);
			temp_gT.append(gameTime, 11, 2).append(gameTime, 14, 2);

			int cD = stoi(temp_crD);
			int gD = stoi(temp_gD);
			int cT = stoi(temp_crT);
			int gT = stoi(temp_gT);
			int compareDate = gD - cD;
			int compareTime = gT - cT;

			long long compare = compareDate * 10000 + compareTime;
			if (compareDate >= 0) {

				if (gT < cT) {
					compareTime = 2400 + gT - cT;
				}
				else compareTime = gT - cT;

				if (compareTime <= 600) { // 경기시작 6시간 전인 경우 경매 종료
					reservation->setCanShow(true);
					string sellerid = reservation->getSellerID();
					string homeTeam = reservation->getHomeTeam();
					string awayTeam = reservation->getAwayTeam();
					string time = reservation->getGameDate();
					string seat = reservation->getSeatNumber();
					for (int j = 0; j < ticketCount; j++)
					{
						if (sellerid.compare(ticketCollection->getTicket(j)->getSellerId()) == 0 &&
							homeTeam.compare(ticketCollection->getTicket(j)->getHomeTeam())==0 &&
							awayTeam.compare(ticketCollection->getTicket(j)->getAwayTeam())==0 &&
							time.compare(ticketCollection->getTicket(j)->getGameDateNTime())==0 &&
							seat.compare(ticketCollection->getTicket(j)->getTicketSeatNum())==0 )
						{
							ticketCollection->getTicket(j)->setReservable(false);
							break;
						}
					}
				}
			}
			else {
				reservation->setCanShow(true);
				string sellerid = reservation->getSellerID();
				string homeTeam = reservation->getHomeTeam();
				string awayTeam = reservation->getAwayTeam();
				string time = reservation->getGameDate();
				string seat = reservation->getSeatNumber();
				for (int j = 0; j < ticketCount; j++)
				{
					if (sellerid.compare(ticketCollection->getTicket(j)->getSellerId()) == 0 &&
						homeTeam.compare(ticketCollection->getTicket(j)->getHomeTeam()) == 0 &&
						awayTeam.compare(ticketCollection->getTicket(j)->getAwayTeam()) == 0 &&
						time.compare(ticketCollection->getTicket(j)->getGameDateNTime()) == 0 &&
						seat.compare(ticketCollection->getTicket(j)->getTicketSeatNum()) == 0)
					{
						ticketCollection->getTicket(j)->setReservable(false);
						break;
					}
				}
			}
		}
	}
}