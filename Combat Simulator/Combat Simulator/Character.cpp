#include "Character.h"
#include "Combat.h"
#include <stdio.h>
#include <iostream>

Character::Character(int lvl, int hp, int attack, int defense, int speed, ModuleCombat* combat) : lvl(lvl), hp(hp), maxhp(hp), attack(attack), defense(defense), speed(speed), combat(combat) { uses_health = 3; }

void Character::Attack(Character* rival)
{
	float my_attack = attack * lvl * dice;
	float defense_rival = rival->defense * rival->lvl * rival->dice;
	float d = my_attack / defense_rival;
	float damage =  d * 15;
	rival->hp -= (int)damage;

	combat->RewriteInCombat();

	if(rival == combat->character2)
		printf("\n\nYou Attack!\nYou did %i of damage!\n", (int)damage);
	else
		printf("\n\nThe enemy is attacking you!\nHe did %i of damage!\n", (int)damage);

	if (rival->hp <= 0)
		rival->Death();
}
void Character::Death()
{
	printf("DEAAAD!");
	combat->in_combat = false;
}

void Character::Heal()
{
	int hp_healed = maxhp / 3;

	if (hp + hp_healed > maxhp)
		hp = maxhp;
	else
		hp += hp_healed;

	--uses_health;

	combat->RewriteInCombat();

	printf("\n\nYou use one heal charge\n");
	printf("You healed %i of hp!\n", hp_healed);

}