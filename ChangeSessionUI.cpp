#include "ChangeSessionUI.h"

void ChangeSessionUI::startInterface(ChangeSessionControl *ctl, MemberCollection *mcollection) {
	// Function: void startInterface(ChangeSessionControl *ctl, MemberCollection *mcollection)
	// Description: 세션 변경 인터페이스
	// Created: 2019/05/31
	// Author: 김승연

	string ID;
	cin >> ID;

	ctl->changeSession(ID, mcollection);
	
}