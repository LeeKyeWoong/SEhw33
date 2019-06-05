#include "ParticipateAuctionTicketControl.h"

void ParticipateAuctionTicketControl::participateAuction(string date, string awayTeam, string seatNum, int bidPrice,
	ReservationCollection *resCollect,	MemberCollection *memCollect, TicketCollection *tkCollect, Timer *Tmr) {
	// Function: void participateAuction()
	// Description: �Ű������� ���� [��¥-�ð�] [�������] [�¼���ġ] [�����ݾ�] ������ ����, ���� SessionOn�� ������ ����� ��� ������ �����Ѵ�.
	// Created: 2019/06/03
	// Auther: ��¿�

	Member *cntMember = memCollect->currentSession();
	if (cntMember->getMemType() == "seller") {
		cout << "seller�� ��� ������ �Ұ����մϴ�." << endl;
		return;
	}

	int TicketNum = tkCollect->getTicketCount();
	for (int i = 0; i < TicketNum; i++) {
		Ticket *cntTicket = tkCollect->getTicket(i);
		if (cntTicket->getTicketType() == "A") { // ���� Ƽ�� ��
			if (cntTicket->getCanSell()) { // ���� ��� ���� ������ Ƽ�ϵ鿡 ����

				if (cntTicket->getGameDateNTime() == date && cntTicket->getAwayTeam() == awayTeam && cntTicket->getTicketSeatNum() == seatNum) {
					// �Է� ���� ����� ��ġ�ϴ� Ƽ�Ͽ� ������ �Ѵ�.

					if (  ( ( cntTicket->getTicketPrice() ) / 2 ) > bidPrice) {
						cout << "���� �ݾ׺��� �� ���� ���� �ݾ��� �Է��ϼ̽��ϴ�." << endl;
						return;
					}

					int reserveCount = resCollect->getReservationCount();
					for (int j = 0; j < reserveCount; j++) {
						Reservation *cntRes = resCollect->getReservation(j);
						if (cntRes->getGameDate() == date && cntRes->getAwayTeam() == awayTeam && cntRes->getSeatNumber() == seatNum) {

							cout << bidPrice << endl;

							// �̹� �������� �� Ƽ�Ͽ� ���� ������ �� ���� �ִٸ� ���������� ���ؼ� reservation ������ �� ���� ���������� ������ ����� ������ �ٲ۴�.
							if (cntRes->getReservePrice() < bidPrice) {
								cntRes->changeAuctionBuyer(cntMember->getId(), bidPrice, Tmr->getCurrentTime());
								
								return;
							}
						}
					}
					// ��� ������ ����� ���� Ƽ���� ��� ���� ���� ��ü�� �����Ѵ�.
					resCollect->addReservation(cntTicket->getSellerId(), cntMember->getId(), bidPrice, Tmr->getCurrentTime(),
						cntTicket->getGameDateNTime(), cntTicket->getHomeTeam(), awayTeam, seatNum);

					cout << bidPrice << endl;
					return; // ��� ������ �������Ƿ� �Լ��� �ٷ� ������.
				}

			}
		}
	}
	cout << "��� ������ �����߽��ϴ�.(������ �߸� �Է�)" << endl;



}