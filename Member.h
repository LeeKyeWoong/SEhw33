#pragma once

#include "MemberCollection.h"
#include <stdio.h>
#include <tchar.h>
#include <string>
using namespace std;

class Member
{
	// Class: Member
	// Description: Member의 정보를 담고있는 class
	// Created: 2019/05/29
	// Author: 이계웅

private:
	string id;        // member id
	string password;  // password
	string name;      // 이름
	string idNum;     // 주민등록번호
	string memType;   // 멤버타입(판매자,구매자)
	bool sessionOn;   // 세션(로그인여부)

public:
	Member(); // 기본 생성자가 아닌, 아무 입력 없이 생성된 Member는 SessionOn 값을 False로 초기화 하는 생성자 
	Member(string id, string password, string name, string idNum, string memType, bool sessionOn);// 입력받은 값을 받아서 객체를 생성하는 생성자
	~Member(); // 소멸자
	
	void createMember(string id, string password, string name, string idNum, string memType, bool sessionOn); // 입력받은 값을 기반으로 객체를 생성하는 함수
	void deleteMember();   // 객체를 삭제하는 함수
	
	string getId();        // id를 얻는 함수
	string getPassword();  // Password 얻는 함수
	string getName();      // 이름을 얻는 함수
	string getIdNum();     // 주민번호를 얻는 함수
	string getMemType();   // 회원 타입(판매자, 구매자)를 얻는 함수
	bool getSessionOn();   // 로그인 여부를 얻는 함수
	void setId(string id);
	void setPassword(string pw);
	void setName(string n);
	void setIdNum(string idnum);
	void setMemType(string memType);    // 회원 타입을 Set하는 함수
	void setSessionOn(bool sessionOn);  // 로그인 여부를 Set하는 함수
};
