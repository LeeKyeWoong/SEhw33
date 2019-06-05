#include "ChangeSessionControl.h"

void ChangeSessionControl::changeSession(string newID, MemberCollection *mc) {
	// Function: void changeSession(string newID, MemberCollection *mc)
	// Description: 새로 세션 변경할 아이디를 받아서, 해당 아이디를 가지는 멤버 객체의 SessionOn 값을 true로 변경하고 세션 변경을 한다.
	// Parameters: string newID - 새로 세션 변경하기 위해 받은 아이디 값
	//						MemberCollection *mc - 세션 변경할 때 멤버 객체에 정보를 업데이트 하기 위해 필요한 매개변수
	// Created: 2019/05/31
	// Author: 김승연

	int memberCount = mc->getMemberNumber(); // 현재 몇명의 멤버가 있는지를 받는다

	int nextSessionOnIndex;
	bool findIndex = false;

	for (int i = 0; i < memberCount; i++)
	{
		if (mc->getMember(i)->getId().compare(newID) == 0)
		{
			nextSessionOnIndex = i; // 새롭게 세션 변경을 할 아이디를 가지고 있는 객체의 인덱스 값을 받는다.
			findIndex = true;
			break;
		}
	}

	int cntSessionIndex = mc->getCurrentSessionIndex();

	if (findIndex) {
		mc->getMember(cntSessionIndex)->setSessionOn(false);

		mc->getMember(nextSessionOnIndex)->setSessionOn(true);
	}
	else { // 입력받은 아이디가 멤버 객체 배열에 없는 경우에는 그냥 기존 세션을 유지한다.
		cout << "그런 아이디는 없습니다." << endl;
		newID = mc->getMember(cntSessionIndex)->getId();
	}

	cout << "6.1 Session 변경" << endl;
	cout << ">" << newID << endl;
	cout << endl;

}