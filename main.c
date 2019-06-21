/*
 * main.c
 *
 *	Optimizied for speed as telled in this guide:
 *	https://www.codeproject.com/Articles/6154/Writing-Efficient-C-and-C-Code-Optimization
 *
 *  Created on: 18.12.2018
 *      Author: rafael
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdint.h>
#include "defence.h"



int main(int argc, char** argv) {

	char* dice_type = malloc(sizeof(char) * 10);
	unsigned int dice_type_l;
	char* dice_amount = malloc(sizeof(char) * 100);
	unsigned int dice_amount_i;
	unsigned int i;
	unsigned int act;
	unsigned int result;

	printf("Willkommen zum Wuerfeln!\n");

	while (1) {

		result = 0;
		printf(">");
		srand(time(NULL));
		scanf("%9s", dice_type);

		if (dice_type[0] == 'e' || dice_type[0] == 'E') {
			printf("%s", "Bye\n");
			return 0;
		} else if (dice_type[0] == 'w' || dice_type[0] == 'W') {
			printf("Nope, sorry Phillip\n");
			continue;
		} else if (dice_type[0] == '0') {
			printf("Nope\n");
			continue;
		} else if (dice_type[0] == 'c' || dice_type[0] == 'C') {
			char* color = malloc(sizeof(char) * 7);
			c_wuerfel *colored_dices[4];
			unsigned int menge = 0;
			printf("Mögliche Farben: Rosa, Gruen, Schwarz und Weiß\n");
			printf("Bitte immer nur die Anfangsbuchstaben eingeben\n");
			printf("Farbe: ");
			scanf("%9s", color);

			int i = 0;
			while (color[i] != '\0') {
				printf("Wie viele Wuerfel?:");
				scanf("%ui", &menge);
				colored_dices[i] = create_colored_dice(&color[i], menge);
				i++;
			}

			colored_dices[0]->count;



		}



		//FIXME you can input normal characters

		dice_type_l = strtol(dice_type, NULL, 10);
		if (dice_type_l == 0 || dice_type_l == UINT_MAX) {
			printf("How do you wanna do that?\n");
			continue;
		}


		printf("Menge: ");
		scanf("%99s", dice_amount);
		dice_amount_i = strtol(dice_amount, NULL, 10);
		if (dice_amount_i == 0) {
			printf("How do you wanna do that?\n");
			continue;
		}

		unsigned int *dice_results = malloc(dice_type_l * sizeof(int));
		for (i = 0; i < dice_type_l; i++) {
			dice_results[i] = 0;
		}
		i = 0;
		act = 0;
		unsigned int twenty = 0;
		unsigned int one = 0;
		//alle außer 6 addieren
		switch (dice_type_l) {
		case 2:
			printf("----------------------------------\n");
			for (i = dice_amount_i; i--;) {
				act = rand() % 2;
				dice_results[act]++;
			}

			printf("Wuerfel:\n1: %i\n2: %i\n", dice_results[1],
					dice_results[0]);
			printf("Ergebnis: %i\n", dice_results[1] + dice_results[0] * 2);
			break;
		case 3:
			printf("----------------------------------\n");
			for (i = dice_amount_i; i--;) {
				act = rand() % 3;
				dice_results[act]++;
			}
			printf("Wuerfel:\n1: %i\n2: %i\n3: %i\n", dice_results[1],
					dice_results[2], dice_results[0]);
			printf("Ergebnis: %i\n", dice_results[1] +
					dice_results[2] * 2 + dice_results[0] * 3);
			break;
		case 4:
			printf("----------------------------------\n");
			for (i = dice_amount_i; i--;) {
				act = rand() % 4;
				dice_results[act]++;
			}
			printf("Wuerfel:\n1: %i\n2: %i\n3: %i\n4: %i\n",
					dice_results[1], dice_results[2],
					dice_results[3], dice_results[0]);
			printf("Ergebnis: %i\n", dice_results[1] + dice_results[2] * 2+
					dice_results[3] * 3 + dice_results[0] * 4);
			break;
		case 6:
			for (i = dice_amount_i; i--;) {
				act = rand() % 6;
				dice_results[act]++;
			}

			printf("Wuerfel:\n1: %i\n2: %i\n3: %i\n4: %i\n5: %i\n6: %i\n",
					dice_results[1], dice_results[2],
					dice_results[3], dice_results[4],
					dice_results[5], dice_results[0]);
			printf("Misserfolge: %i\nErfolge: %i\n", dice_results[1] + dice_results[2], dice_results[5] + dice_results[0]);
			break;
		case 8:
			printf("----------------------------------\n");
			for (i = 0; i < 8; i++) {
				if (i) {
					dice_results[i] = 0;
				}
			}

			for (i = 0; i < dice_amount_i; i++) {
				act = rand() % 8;
				dice_results[act]++;
				if (!act) {
					result += 8;
				} else {
					 result += act;
				}
			}

			printf("Wuerfel:\n1: %u\n2: %u\n3: %u\n4: %u\n5: %u\n6: %u\n7: %u\n8: %u\n",
					dice_results[1], dice_results[2],
					dice_results[3], dice_results[4],
					dice_results[5], dice_results[6],
					dice_results[7], dice_results[0]);
			printf("Ergebnis: %i\n", result);
			return 0;
			break;
		case 10:
			printf("----------------------------------\n");
			for (i = 0; i < 10; i++) {
				if (i) {
					dice_results[i] = 0;
				}
			}

			for (i = dice_amount_i; i--;) {
				act = rand() % 10;
				dice_results[act]++;
				if (!act) {
					result += 10;
				} else {
					result += act;
				}
			}

			printf(
					"Wuerfel:\n1: %i\n2: %i\n3: %i\n4: %i\n5: %i\n6: %i\n7: %i\n8: %i\n9: %i\n10: %i\n",
					dice_results[1], dice_results[2],
					dice_results[3], dice_results[4],
					dice_results[5], dice_results[6],
					dice_results[7], dice_results[8],
					dice_results[9], dice_results[0]);
			printf("Ergebnis: %i\n", result);
			break;
		case 12:
			printf("----------------------------------\n");
			for (i = 0; i < 12; i++) {
				if (i) {
					dice_results[i] = 0;
				}
			}

			for (i = dice_amount_i; i--;) {
				act = rand() % 12;
				dice_results[act]++;
				result += act;
			}

			printf(
					"Wuerfel:\n1: %i\n2: %i\n3: %i\n4: %i\n5: %i\n6: %i\n7: %i\n8: %i\n9: %i\n10: %i\n11: %i\n12: %i\n",
					dice_results[1], dice_results[2],
					dice_results[3], dice_results[4],
					dice_results[5], dice_results[6],
					dice_results[7], dice_results[8],
					dice_results[9], dice_results[10],
					dice_results[11], dice_results[0]);
			printf("Ergebnis: %i\n", result);
			break;
		case 20:
			printf("----------------------------------\n");
			for (i = 0; i < dice_type_l; i++) {
				if (i) {
					dice_results[i] = 0;
				}
			}
			for (i = dice_amount_i; i--;) {
				act = rand() % 20;
				dice_results[act]++;

				if (act == 0) { //Because of index 0 is one
					one++;
				} else if (act == 19) {//Because of index 19 is twenty
					twenty++;
				}
			}

			for (i = 0; i < dice_type_l; i++) {

				if (dice_results[i] == 0) {
					continue;
				}
				printf("%i: %i\n", i + 1, dice_results[i]);
				result += dice_results[i] * (i+1);
			}

			printf("\n1: %i\n20: %i\n", one, twenty);
			printf("Ergebnis: %i\n", result);
			break;
		case 100:
			printf("----------------------------------\n");
			for (i = dice_amount_i; i--;) {
				act = rand() % 100;
				dice_results[act]++;
				result += act++;
			}

			printf("Ergebnis: %i\n", result);
			break;
		default:
			printf("----------------------------------\n");
			unsigned int c_act = 0;
			unsigned int custom_result[dice_type_l];

			for (i = dice_type_l; i--;) {
				custom_result[i] = 0;
			}

			for (i = 0; i < dice_amount_i; i++) {
				c_act = rand() % dice_type_l;
				custom_result[c_act]++;
				if (c_act == 0) {
					result += dice_type_l;
				} else {
					result += c_act + 1;
				}
			}

			for (i = 0; i < dice_type_l; i++) {
				if (custom_result[i] != 0) {
					printf("Augenzahl %i: %i mal\n", i + 1, custom_result[i]);
				}
			}
			printf("Ergebnis: %i\n", result);
			break;
		}
	}
	return 0;
}
