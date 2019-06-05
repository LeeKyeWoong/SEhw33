#pragma once
#include "SignUpUI.h"
#include "SignUpControl.h"
#include "Member.h"
#include "MemberCollection.h"

SignUpControl::SignUpControl()
{
	// Function : SignUpControl()
	// Description: ��ü�� checkID���� true�� �ʱ�ȭ �ϴ� ������ ( true �� �ߺ��� ���ٴ� ���� �ǹ��Ѵ�.)
	// Created: 2019/5/30
	// Author: �̰��

	this->checkId = true;
}

void SignUpControl::createAccount(string id, string password, string name, string idNum, string memType, bool sessionOn, MemberCollection* memberCollection)
{
	// Function : createAccount(string id, string password, string name, string idNum, string memType, bool sessionOn, MemberCollection* memberCollection)
	// Description: �� Account�� �����ϸ�, �Էµ� ID�� �ߺ� ���θ� Ȯ���ϴ� �Լ�
	// Created: 2019/5/30
	// Author: �̰��

	int memberCount = memberCollection->getMemberNumber(); // ������ �޾ƿ´�.

	for (int i = 0; i < memberCount; i++)
	{
		if (id.compare(memberCollection->getMember(i)->getId()) == 0) // ���ڿ��� ������ 0�̴�.
		{
			this->checkId = false; // ���ڿ��� ������ False�̴�.
		}
	}
	
	if(this->checkId) // ���ڿ��� ������ ���� ����. ��, true�̴�.
	{
		memberCollection->addMember(id, password, name, idNum, memType, sessionOn);
	}
	else // ���ڿ��� �����Ѱ��� �ִ�.
	{
		// �ƹ��ϵ� ���� �ʴ´�.
	}
	
}

bool SignUpControl::getCheckId()
{
	// Function : getCheckId()
	// Description: ȸ�� ������ �õ��ϴ� ID�� �ߺ� ���θ� ��ȯ�ϴ� �Լ�
	// Created: 2019/5/30
	// Author: �̰��

	return this->checkId;
}