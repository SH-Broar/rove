#pragma once

//Scene
//0 : Splash
//1 : title
//2 : GamestartScene

typedef struct _PlayerState
{
	// main 4 stat
	int passion;			// -미온적 / +열성적
	int endurence;			// -기분파 / +참을성 강함
	int intelligent;		// -감성적 / +지성적
	int extroverted;		// -내향적 / +외향적

	// hidden 4 stat
	int independent;		// -의존적 / +독립적
	int naive;				// -타산적 / +순진함
	int optimism;			// -비관적 / +낙관적
	int resistance;			// -순종적 / +반항적
}PlayerState;

class PlayerDataClass
{
private:
	
public:
	int NowScene;
	bool ending[30];
	PlayerState stat;

	PlayerDataClass();
	~PlayerDataClass();

	void PlayerLoadFromFile();
	void DiaryLoadFromFile();
};

