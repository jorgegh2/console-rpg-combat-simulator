#include "Combat.h"
#include "Character.h"
#include <stdio.h>
#include <iostream>
void ModuleCombat::StartCombat()
{
	system("cls");
	character1 = new Character(6, 150, 80, 30, 70, this);
	character2 = new Character(8, 350, 110, 45, 90, this);

	in_combat = true;
}

void ModuleCombat::EndCombat()
{
	delete character1;
	character1 = nullptr;

	delete character2;
	character2 = nullptr;
}

void ModuleCombat::PrintStats()
{
	printf("Player:\n    HP: %i\n    Attack: %i\n    Defense: %i\n    Speed: %i\n", character1->hp, character1->attack, character1->defense, character1->speed);
	printf("\n\nEnemy:\n    HP: %i\n    Attack: %i\n    Defense: %i\n    Speed: %i\n", character2->hp, character2->attack, character2->defense, character2->speed);
}

void ModuleCombat::InCombat()
{
	character1->dice = rand() % 6 + 1;
	character2->dice = rand() % 6 + 1;

	int player_final_speed = character1->speed * character1->lvl * character1->dice * 0.001;
	int enemy_final_speed = character2->speed * character2->lvl * character2->dice * 0.001;

	PrintStats();
	if (player_final_speed >= enemy_final_speed)
	{
		character1->first = true;
		character2->first = false;
		printf("\nYou go first, player!");
		PlayerTurn();
		system("pause");
		EnemyTurn();
	}
	else
	{
		character1->first = false;
		character2->first = true;
		printf("\nYou go second, player!");
		EnemyTurn();
		PlayerTurn();
	}

	system("pause");
}

void ModuleCombat::EnemyTurn()
{
	if (character2->hp > 0)
	{
		int enemy_action = rand() % 2;//TODO 3 debe de ser.
		if (character2->hp == character2->maxhp)
			enemy_action = 0;
		switch (enemy_action)
		{
		case 0:
			printf("\nEnemy attacks you!\n");
			character2->Attack(character1);
			break;
		case 1:
			printf("\nEnemy heals himself!\n");
			character2->Heal();
			break;
		}
	}
}

void ModuleCombat::PlayerTurn()
{
	if (character1->hp > 0)
	{
		int action = 0;
		bool action_valid = false;
		while (!action_valid)
		{
			printf("\n\nActions:");
			printf("\n    1. Attack.\n    2. Heal(%i).\n\nSelect your action: ", character1->uses_health);
			scanf_s("%i", &action);
		
			RewriteInCombat();
			if (action == 1)
			{
				character1->Attack(character2);
				action_valid = true;
			}
			else if (action == 2 && character1->uses_health > 0)
			{
				character1->Heal();
				action_valid = true;
			}
			else
				printf("\nThis Action is not valid!");
		}

	}
}

void ModuleCombat::RewriteInCombat()
{
	system("cls");
	PrintStats();
	if(character1->first)
		printf("\nYou go first, player!");
	else
		printf("\nYou go second, player!");

}
