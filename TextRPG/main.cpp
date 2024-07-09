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
	string className;
	int level;
	int exp;
	int maxhp;
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
void EnterUpgrade();

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
		if (playerClass == NULL)
			SelectPlayer();
		cout << "■■■■ PLAYER STAT ■■■■" << endl;
		cout << "        CLASS : " << playerStat.className << "" << endl;
		cout << "          LEVEL : " << playerStat.level << "" << endl;
		cout << "           HP : " << playerStat.hp << "" << endl;
		cout << "           ATK : " << playerStat.attack << "" << endl;
		cout << "           DEF : " << playerStat.defence << "" << endl;
		cout << "           EXP : " << playerStat.exp << "" << endl;
		cout << "■■■■■■■■■■■■■■■" << endl;
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
			if (playerStat.level >= 5)
			{
				EnterUpgrade();
			}
			else
			{
				cout << "2차 전직은 레벨 5 이상부터 가능합니다." << endl;
				WaitKey();
			}
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
			playerStat.className = "전사";
			playerStat.level = 1;
			playerStat.exp = 0;
			playerStat.maxhp = 200;
			playerStat.hp = 200;
			playerStat.defence = 20;
			playerStat.attack = 10;
			playerClass = PC_Warrior;
			break;
		}
		else if (classNum == PC_Mage)
		{
			cout << "마법사로 시작합니다.." << endl;
			playerStat.className = "마법사";
			playerStat.level = 1;
			playerStat.exp = 0;
			playerStat.maxhp = 100;
			playerStat.hp = 100;
			playerStat.defence = 1;
			playerStat.attack = 50;
			playerClass = PC_Mage;
			break;
		}
		else if (classNum == PC_Archer)
		{
			cout << "궁수로 시작합니다.." << endl;
			playerStat.className = "궁수";
			playerStat.level = 1;
			playerStat.exp = 0;
			playerStat.maxhp = 150;
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
	system("cls");
	while (true)
	{
		cout << "------------------------------" << endl;
		cout << "던전에 입장했습니다 !" << endl;
		cout << "------------------------------" << endl;
		cout << "■■■■ PLAYER STAT ■■■■" << endl;
		cout << "        CLASS : " << playerStat.className << "" << endl;
		cout << "          LEVEL : " << playerStat.level << "" << endl;
		cout << "           HP : " << playerStat.hp << "" << endl;
		cout << "           ATK : " << playerStat.attack << "" << endl;
		cout << "           DEF : " << playerStat.defence << "" << endl;
		cout << "           EXP : " << playerStat.exp << "" << endl;
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
			system("cls");
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
	int temp = 15;
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
			if (playerStat.exp >= (playerStat.level * temp))
			{
				cout << "레벨업 했습니다 !!" << endl;
				playerStat.level++;
				playerStat.maxhp += 30;
				playerStat.hp = playerStat.maxhp;
				playerStat.attack += 10;
				playerStat.defence += 2;
			}
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

void EnterUpgrade()
{
	cout << "------------------------------" << endl;
	cout << "2차 전직을 선택해주세요." << endl;
	cout << "------------------------------" << endl;
	if (playerClass == PC_Warrior)
	{
		cout << "[1] 팔라딘 [2] 용기사" << endl;
		cout << ">> ";
		int num;
		cin >> num;
		switch (num)
		{
		case 1:
			break;
		case 2:
			
			break;
		default:
			return;
		}
	}
	else if (playerClass == PC_Mage)
	{
		cout << "[1] 소서리스 [2] 프리스트" << endl;
		cout << ">> ";
		int num;
		cin >> num;
		switch (num)
		{
		case 1:
			cout << "소서리스로 전직했습니다" << endl;
			playerStat.className = "소서리스";
			playerStat.maxhp += playerStat.maxhp / 10;
			playerStat.hp = playerStat.maxhp;
			playerStat.defence += playerStat.defence / 10;
			playerStat.attack += playerStat.attack / 10;
			break;
		case 2:
			cout << "프리스트로 전직했습니다" << endl;
			playerStat.className = "프리스트";
			playerStat.maxhp += playerStat.maxhp / 10;
			playerStat.hp = playerStat.maxhp;
			playerStat.defence += playerStat.defence / 10;
			playerStat.attack += playerStat.attack / 10;
			break;
		default:
			return;
		}
	}
	else if (playerClass == PC_Archer)
	{
		cout << "[1] 헌터 [2] 저격수" << endl;
		cout << ">> ";
		int num;
		cin >> num;
		switch (num)
		{
		case 1:
			break;
		case 2:
			break;
		default:
			return;
		}
	}
}
