#include "stdafx.h"
#include "PlayerDataClass.h"

PlayerDataClass::PlayerDataClass()
{
	NowScene		= SN_splash;

	this->stat.passion			= 0;
	this->stat.endurence		= 0;
	this->stat.intelligent		= 0;
	this->stat.extroverted		= 0;

	this->stat.independent		= 0;
	this->stat.naive			= 0;
	this->stat.optimism		    = 0;
	this->stat.resistance		= 0;
}


PlayerDataClass::~PlayerDataClass()
{

}

void PlayerDataClass::PlayerLoadFromFile()
{
	//SAVE 파일에서 플레이어 정보를 불러옴.
}

void PlayerDataClass::DiaryLoadFromFile()
{
	//SAVE 파일에서 기록 정보를 불러옴.
}

