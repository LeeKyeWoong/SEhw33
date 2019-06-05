#include "Timer.h"

void Timer::setCurrentTime(string cntTime) {
	// Function: void setCurrentTime(string cntTime)
	// Description: �Ű������� ���� �ð��� ��������� currentTime�� �����ϴ� �Լ��̴�.
	// Parameter: string cntTime - ���ο� ����ð����� �����ϱ� ���� ���� ��
	// Created: 2019/05/30
	// Author: ��¿�

	this->currentTime = cntTime;
}

string Timer::getCurrentTime() {
	// Function: string getCurrentTime()
	// Description: ��������� currentTime�� ���� �����ϴ� �Լ��̴�.
	// Return value: ���� �ð�
	// Created: 2019/05/30
	// Author: ��¿�

	return this->currentTime;
}

bool Timer::checkTimeToDeleteTicket(string registerTime) {
	// Function: bool checkTimeToDeleteTicket(string registerTime)
	// Description: Ƽ���� ��ϵ� �ð��� ����ð��� ���Ͽ� Ƽ���� �������� �����ϴ� �Լ��̴�.
	// Parameter: string registerTime - Ƽ���� ��ϵ� �ð�
	// Return value: Ƽ���� ��ϵ� �� 1�� �̻� �� ��� true��, �׷��� ���� ��� false�� �����Ѵ�.
	// Created: 2019/05/30
	// Author: ��¿�

	/*
	�Ű������� ���� registerTime�� string������ ????:??:??:??:?? �����̱� ������
	':'�� �����ϰ� ����ϱ����� ���� �ӽ� ���� tmp_registerTime�� ������ �Ѵ�.
	�׷��� 2019:05:30:12:23 �̶� �ð��� tmp_registerTime�� 20190530 ���� �����Ѵ�.
	�׷����� �� string���� �� ���� int������ ��ȯ�� �Ѵ�.
	�̴� currentTime�� ��쿡�� �����ϴ�.

	Ƽ�� ������ ��ϵ� �� 1�� ������ �� �̷������ ������, ����ð��� Ƽ�� ��� �ð��� ���̰� 10000 �̻��� �Ǵ� ��� �����ϸ� �ȴ�.
	*/
	if (registerTime == "") {
		cout << "error: Ƽ�� ��� ��¥�� �����Ǿ����� �ʽ��ϴ�. ""6.1 ����ð� ����""�� ������ �� Ƽ�� ����� ���ּ���!" << endl;
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
	// Description: ��� ���� �ð��� ���� �ð��� ���� ��� ���� 24�ð� ���� Ƽ�� �� �����ȯ �ɼ��� ������ Ƽ���� ticketType�� A�� �ٲ۴�.
	//						�׸��� ��� ���� 6�ð� ���� �Ǹ� ��� ���ᰡ �ǹǷ� �Ǹ� �Ұ��ϴٴ� �ǹ��� canSell=false�� �����Ѵ�.
	// Parameter: Ticket* tk - �ð��� ���� Ƽ��
	// Created: 2019/06/02
	// Author: ��¿�

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

		if (compare <= 10000 && tk->getIsLimitedTimeAuction()) { // ������ 24�ð� ���� ���
			tk->setTicketType("A");
		}

		if (gT < cT) {
			compareTime = 2400 + gT - cT;
		}
		else compareTime = gT - cT;

		if (compareTime <= 600) { // ������ 6�ð� ���� ��� ��� ����
			tk->setCanSell(false);
		}
	}
	else {
		tk->setCanSell(false);
	}
}

string Timer::returnRemainAuctionTime(Ticket* tk) {
	// Function: string returnRemainAuctionTime(Ticket* tk)
	// Description: ���������� �󸶳� ���Ҵ����� �����ϴ� �Լ��̴�.
	// Parameter: Ticket* tk - �ð��� ���� Ƽ��
	// Created: 2019/06/02
	// Author: ��¿�

	if (tk->getCanSell() && tk->getTicketType() == "A") {
		string temp_crT[2], temp_gT[2];
		string gameTime = tk->getGameDateNTime();
		temp_crT[0].append(currentTime, 11, 2);
		temp_crT[1].append(currentTime, 14, 2);
		temp_gT[0].append(gameTime, 11, 2);
		temp_gT[1].append(gameTime, 14, 2);
		// 0�� �ð�, 1�� ��
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
		return "������� �Ұ� Ƽ��";
	}
	
}