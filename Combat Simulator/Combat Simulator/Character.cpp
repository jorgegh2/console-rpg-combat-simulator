#include "Character.h"
#include "Combat.h"
#include <stdio.h>
#include <iostream>

Character::Character(int hp, int attack, int defense, int speed, ModuleCombat* combat) : hp(hp), attack(attack), defense(defense), speed(speed), combat(combat) {}

void Character::Attack(Character* rival)
{


	int damage = attack - rival->defense;
	rival->hp -= damage;

	combat->CleanAndPrintStats();

	if (rival->hp <= 0)
		rival->Death();
	else
		printf("\n\nYou Attack!\nYou did %i of damage!\n", damage);

}
void Character::Death()
{
	printf("DEAAAD!");
	combat->in_combat = false;
}

void Character::Heal()
{
	printf("\n\nYou Heal\n\n");


}