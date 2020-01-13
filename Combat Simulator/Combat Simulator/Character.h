#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "Combat.h"
class Character
{
public:
	Character(int hp, int attack, int defense, int speed, ModuleCombat* combat);
	void Attack(Character* rival);
	void Death();
	void Heal();

public:
	ModuleCombat* combat = nullptr;
	int hp = 0;
	int attack = 0;
	int defense = 0;
	int speed = 0;

};

#endif // !__CHARACTER_H__
