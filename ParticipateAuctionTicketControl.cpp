#include "ParticipateAuctionTicketControl.h"

void ParticipateAuctionTicketControl::participateAuction(string date, string awayTeam, string seatNum, int bidPrice,
	ReservationCollection *resCollect,	MemberCollection *memCollect, TicketCollection *tkCollect, Timer *Tmr) {
	// Function: void participateAuction()
	// Description: 매개변수로 받은 [날짜-시간] [어웨이팀] [좌석위치] [입찰금액] 정보를 토대로, 현재 SessionOn인 구매자 멤버의 경매 참여를 진행한다.
	// Created: 2019/06/03
	// Auther: 김승연

	Member *cntMember = memCollect->currentSession();
	if (cntMember->getMemType() == "seller") {
		cout << "seller는 경매 참여가 불가능합니다." << endl;
		return;
	}

	int TicketNum = tkCollect->getTicketCount();
	for (int i = 0; i < TicketNum; i++) {
		Ticket *cntTicket = tkCollect->getTicket(i);
		if (cntTicket->getTicketType() == "A") { // 옥션 티켓 중
			if (cntTicket->getCanSell()) { // 아직 경매 참여 가능한 티켓들에 대해

				if (cntTicket->getGameDateNTime() == date && cntTicket->getAwayTeam() == awayTeam && cntTicket->getTicketSeatNum() == seatNum) {
					// 입력 받은 값들과 일치하는 티켓에 입찰을 한다.

					if (  ( ( cntTicket->getTicketPrice() ) / 2 ) > bidPrice) {
						cout << "기준 금액보다 더 낮은 입찰 금액을 입력하셨습니다." << endl;
						return;
					}

					int reserveCount = resCollect->getReservationCount();
					for (int j = 0; j < reserveCount; j++) {
						Reservation *cntRes = resCollect->getReservation(j);
						if (cntRes->getGameDate() == date && cntRes->getAwayTeam() == awayTeam && cntRes->getSeatNumber() == seatNum) {

							cout << bidPrice << endl;

							// 이미 누군가가 이 티켓에 대해 입찰을 한 적이 있다면 입찰가격을 비교해서 reservation 정보를 더 높은 입찰가격을 제시한 사람의 정보로 바꾼다.
							if (cntRes->getReservePrice() < bidPrice) {
								cntRes->changeAuctionBuyer(cntMember->getId(), bidPrice, Tmr->getCurrentTime());
								
								return;
							}
						}
					}
					// 경매 참여한 사람이 없던 티켓의 경우 새로 예약 객체를 생성한다.
					resCollect->addReservation(cntTicket->getSellerId(), cntMember->getId(), bidPrice, Tmr->getCurrentTime(),
						cntTicket->getGameDateNTime(), cntTicket->getHomeTeam(), awayTeam, seatNum, false);

					cout << bidPrice << endl;
					return; // 경매 참여가 끝났으므로 함수를 바로 끝낸다.
				}

			}
		}
	}
	cout << "경매 참여에 실패했습니다.(정보를 잘못 입력)" << endl;



}