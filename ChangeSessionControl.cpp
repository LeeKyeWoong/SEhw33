#include "ChangeSessionControl.h"

void ChangeSessionControl::changeSession(string newID, MemberCollection *mc) {
	// Function: void changeSession(string newID, MemberCollection *mc)
	// Description: ���� ���� ������ ���̵� �޾Ƽ�, �ش� ���̵� ������ ��� ��ü�� SessionOn ���� true�� �����ϰ� ���� ������ �Ѵ�.
	// Parameters: string newID - ���� ���� �����ϱ� ���� ���� ���̵� ��
	//						MemberCollection *mc - ���� ������ �� ��� ��ü�� ������ ������Ʈ �ϱ� ���� �ʿ��� �Ű�����
	// Created: 2019/05/31
	// Author: ��¿�

	int memberCount = mc->getMemberNumber(); // ���� ����� ����� �ִ����� �޴´�

	int nextSessionOnIndex;
	bool findIndex = false;

	for (int i = 0; i < memberCount; i++)
	{
		if (mc->getMember(i)->getId().compare(newID) == 0)
		{
			nextSessionOnIndex = i; // ���Ӱ� ���� ������ �� ���̵� ������ �ִ� ��ü�� �ε��� ���� �޴´�.
			findIndex = true;
			break;
		}
	}

	int cntSessionIndex = mc->getCurrentSessionIndex();

	if (findIndex) {
		mc->getMember(cntSessionIndex)->setSessionOn(false);

		mc->getMember(nextSessionOnIndex)->setSessionOn(true);
	}
	else { // �Է¹��� ���̵� ��� ��ü �迭�� ���� ��쿡�� �׳� ���� ������ �����Ѵ�.
		cout << "�׷� ���̵�� �����ϴ�." << endl;
		newID = mc->getMember(cntSessionIndex)->getId();
	}

	cout << "6.1 Session ����" << endl;
	cout << ">" << newID << endl;
	cout << endl;

}