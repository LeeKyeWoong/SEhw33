#pragma once

#include "Member.h"

Member::Member()
{
	// Function: Member()
	// Description: 아무 입력 없이 생성된 Member는 SessionOn 값을 False로 초기화 하는 생성자
	// Created: 2019/05/29
	// Author: 이계웅
	
	this->sessionOn = false;
}

Member::Member(string id, string password, string name, string idNum, string memType, bool sessionOn)
{
	// Function: Member(string id, string password, string name, string idNum, string memType, bool sessionOn)
	// Description: 입력받은 값을 받아서 객체를 생성하는 생성자
	// Created: 2019/05/29
	// Author: 이계웅

	this->id = id;
	this->password = password;
	this->name = name;
	this->idNum = idNum;
	this->memType = memType;
	this->sessionOn = sessionOn;
}

Member::~Member()
{
	// Function: ~Member()
	// Description: 소멸자
	// Created: 2019/05/29
	// Author: 이계웅
}

void Member::createMember(string id, string password, string name, string idNum, string memType, bool sessionOn)
{
	// Function: createMember(string id, string password, string name, string idNum, string memType, bool sessionOn)
	// Description: 입력받은 값을 받아서 객체를 생성하는 함수
	// Created: 2019/05/29
	// Author: 이계웅
	
	this->id = id;
	this->password = password;
	this->name = name;
	this->idNum = idNum;
	this->memType = memType;
	this->sessionOn = sessionOn;
	
}

void Member::deleteMember()
{
	// Function: deleteMember()
	// Description: Member를 삭제하는 함수
	// Created: 2019/05/29
	// Author: 이계웅

	this->id = "";
	this->password = "";
	this->name = "";
	this->idNum = "";
	this->memType = "";
	this->sessionOn = false;

}

string Member::getId()
{
	// Function: getId()
	// Description: id를 반환하는 함수
	// Created: 2019/05/29
	// Author: 이계웅

	return this->id;
}

string Member::getPassword() 
{
	// Function: getPassword() 
	// Description: 비밀번호를 반환하는 함수
	// Created: 2019/05/29
	// Author: 이계웅

	return this->password;
}

string Member::getName()
{
	// Function: getName()
	// Description: 이름을 반환하는 함수
	// Created: 2019/05/29
	// Author: 이계웅

	return this->name;
}

string Member::getIdNum()
{
	// Function: getIdNum()
	// Description: 주민번호를 반환하는 함수
	// Created: 2019/05/29
	// Author: 이계웅

	return this->idNum;
}

string Member::getMemType()
{
	// Function: getMemType()
	// Description: 회원 타입을 반환하는 함수
	// Created: 2019/05/29
	// Author: 이계웅

	return this->memType;
}

bool Member::getSessionOn()
{
	// Function: getSessionOn()
	// Description: session 사용 여부를 반환하는 함수
	// Created: 2019/05/29
	// Author: 이계웅

	return this->sessionOn;
}

void Member::setMemType(string memType)
{
	// Function: setMemType(string memType)
	// Description: 회원 타입을 저장하는 함수
	// Created: 2019/05/29
	// Author: 이계웅

	this->memType = memType;
}

void Member::setSessionOn(bool sessionOn)
{
	// Function: setSessionOn(bool sessionOn)
	// Description: 세션 사용 여부를 저장하는 함수
	// Created: 2019/05/29
	// Author: 이계웅
	
	this->sessionOn = sessionOn;
}
