//#include <stdio.h>
#include <iostream>
#include "Combat.h"
#include "main.h"
#include <time.h>

void main()
{
	ModuleCombat* combat_system = new ModuleCombat();
	srand(time(NULL));

	while (combat_system->in_game)
	{
		system("cls");

		int option = 0;
		printf("Options:\n    1. Combat.\n    2. Increase 1 stat.\n\n Selecte the option: ");
		scanf_s("%i", &option);

		if (option == 1)
		{
			Combat(combat_system);
		}
		else if (option == 2)
		{
			printf("Select your stat to improve: (1: attack, 2: defense)");
			int stat_option = 0;
			int increased_number = 0;
			scanf_s("%i", &stat_option);
			switch (stat_option)
			{
			case 1:
				printf("Select how much the stat will increase: ");

				scanf_s("%i", &increased_number);
				combat_system->attack_modifier += increased_number;
				break;
			case 2: 
				printf("Select how much the stat will increase: ");
				scanf_s("%i", &increased_number);
				combat_system->defense_modifier += increased_number;
			default:
				break;
			}
			system("pause");
		}
	}

	system("pause");
	return;
}

void Combat(ModuleCombat * combat_system)
{
	combat_system->StartCombat();

	while (combat_system->in_combat)
	{
		combat_system->InCombat();

		system("cls");
	}
	combat_system->PrintStats();
	combat_system->EndCombat();
}
