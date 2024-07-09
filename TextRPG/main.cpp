#include <iostream>

using namespace std;

enum PlayerClass
{
	PC_None = 0,
	PC_Warrior = 1,
	PC_Mage = 2,
	PC_Archer = 3,
};

enum MonsterClass
{
	MC_None = 0,
	MC_Slime = 1,
	MC_Goblin = 2,
	MC_Orc = 3,
};

struct StatInfo
{
	int level;
	int exp;
	int hp;
	int attack;
	int defence;
};

PlayerClass playerClass;
StatInfo playerStat;

MonsterClass monsterClass;
StatInfo monsterStat;

void EnterLobby();
void SelectPlayer();
void EnterDungeon();
void SpawnMonster();
void EnterBattle();
void WaitKey();

int main()
{
	srand(time(0));
	EnterLobby();
}

void EnterLobby()
{
	while (true)
	{
		cout << "------------------------------" << endl;
		cout << "로비에 입장했습니다 !" << endl;
		cout << "------------------------------" << endl;
		SelectPlayer();

		cout << "------------------------------" << endl;
		cout << "[1] 던전 입장 [2] 2차 전직 [3] 게임 종료" << endl;
		cout << "------------------------------" << endl;
		cout << ">> ";

		int num;
		cin >> num;

		if (num == 1)
		{
			EnterDungeon();
		}
		else if (num == 2)
		{
		
		}
		else
		{

		}
	}
}

void SelectPlayer()
{
	while (true)
	{
		cout << "------------------------------" << endl;
		cout << "직업을 골라주세요 !" << endl;
		cout << "[1] 전사 [2] 마법사 [3] 궁수" << endl;
		cout << "------------------------------" << endl;
		cout << ">> ";

		int classNum;
		cin >> classNum;

		if (classNum == PC_Warrior)
		{
			cout << "전사로 시작합니다.." << endl;
			playerStat.level = 1;
			playerStat.exp = 0;
			playerStat.hp = 200;
			playerStat.defence = 20;
			playerStat.attack = 10;
			playerClass = PC_Warrior;
			break;
		}
		else if (classNum == PC_Mage)
		{
			cout << "마법사로 시작합니다.." << endl;
			playerStat.level = 1;
			playerStat.exp = 0;
			playerStat.hp = 100;
			playerStat.defence = 1;
			playerStat.attack = 50;
			playerClass = PC_Mage;
			break;
		}
		else if (classNum == PC_Archer)
		{
			cout << "궁수로 시작합니다.." << endl;
			playerStat.level = 1;
			playerStat.exp = 0;
			playerStat.hp = 150;
			playerStat.defence = 5;
			playerStat.attack = 20;
			playerClass = PC_Archer;
			break;
		}
	}
}

void EnterDungeon()
{
	while (true)
	{
		cout << "------------------------------" << endl;
		cout << "던전에 입장했습니다 !" << endl;
		cout << "------------------------------" << endl;
		cout << "■■■■ PLAYER STAT ■■■■" << endl;
		cout << "          LEVEL : " << playerStat.level << "" << endl;
		cout << "           HP : " << playerStat.hp << "" << endl;
		cout << "          ATT : " << playerStat.attack << "" << endl;
		cout << "          DEF : " << playerStat.defence << "" << endl;
		cout << "          EXP : " << playerStat.exp << "" << endl;
		cout << "■■■■■■■■■■■■■■■" << endl;
		cout << ">> ";

		SpawnMonster();

		cout << "------------------------------" << endl;
		cout << "[1] 싸우기 [2] 도망가기" << endl;
		cout << "------------------------------" << endl;
		cout << ">> ";

		int num;
		cin >> num;

		if (num == 1)
		{
			EnterBattle();

			if (playerStat.hp == 0)
				return;
		}
		else
		{
			return;
		}
	}
}

void SpawnMonster()
{
	int random = 1 + (rand() % 3);

	switch (random)
	{
	case MC_Slime:
		cout << "슬라임이 등장했습니다 ! (HP:30 / ATK:2 / DEF:0)" << endl;
		monsterStat.hp = 100;
		monsterStat.attack = 2;
		monsterStat.defence = 0;
		monsterStat.exp = 2;
		break;
	case MC_Goblin:
		cout << "고블린이 등장했습니다 ! (HP:30 / ATK:5 / DEF:3)" << endl;
		monsterStat.hp = 50;
		monsterStat.attack = 15;
		monsterStat.defence = 3;
		monsterStat.exp = 15;
		break;
	case MC_Orc:
		cout << "오크가 등장했습니다 ! (HP:50/ ATK:12 / DEF:10)" << endl;
		monsterStat.hp = 150;
		monsterStat.attack = 30;
		monsterStat.defence = 15;
		monsterStat.exp = 30;
		break;
	}
}

void EnterBattle()
{
	while (true)
	{
		int damage = playerStat.attack - monsterStat.defence;
		if (damage < 0)
			damage = 0;

		monsterStat.hp -= damage;
		if (monsterStat.hp < 0)
			monsterStat.hp = 0;

		cout << "몬스터 남은 체력 : " << monsterStat.hp << endl;

		if (monsterStat.hp == 0)
		{
			cout << "몬스터를 처치했습니다 !" << endl;
			playerStat.exp += monsterStat.exp;
			WaitKey();
			return;
		}

		damage = monsterStat.attack - playerStat.defence;
		if (damage < 0)
			damage = 0;

		playerStat.hp -= damage;
		if (playerStat.hp < 0)
			playerStat.hp = 0;

		cout << "플레이어 남은 체력 : " << playerStat.hp << endl;

		if (playerStat.hp == 0)
		{
			cout << "[GAME OVER] 플레이어가 사망했습니다 [GAME OVER]" << endl;
			WaitKey();
			return;
		}
	}
}

void WaitKey()
{
	cout << "계속하시려면 아무키나 눌러주세요" << endl;
	cout << ">> ";
	int num;
	cin >> num;
	system("cls");
}
