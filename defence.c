/*
 * defense.c
 *
 *  Created on: 20.06.2019
 *      Author: rafael
 */

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "defence.h"

#define ARR_SIZE(arr) ( sizeof((arr)) / sizeof((arr[0])) )

void roll_colored_dice (c_wuerfel* w) {
	srand(time(NULL));
	for (int i = 0; i < w->count; i++) {
		w->result += w->color[rand() % ARR_SIZE(w->color)];
	}
}

c_wuerfel* create_colored_dice (const char* color, int amount) {
	c_wuerfel* act = malloc(sizeof (c_wuerfel));

	act->result = 0;
	act->color_c = ' ';
	act->count = 0;

	act->colors.rosa[0] = 0;
	act->colors.rosa[1] = 0;
	act->colors.rosa[2] = 0;
	act->colors.rosa[3] = 1;
	act->colors.rosa[4] = 1;
	act->colors.rosa[5] = 2;

	act->colors.gruen[0] = 0;
	act->colors.gruen[1] = 0;
	act->colors.gruen[2] = 1;
	act->colors.gruen[3] = 1;
	act->colors.gruen[4] = 2;
	act->colors.gruen[5] = 2;

	act->colors.weis[0] = 0;
	act->colors.weis[1] = 1;
	act->colors.weis[2] = 2;
	act->colors.weis[3] = 2;
	act->colors.weis[4] = 2;
	act->colors.weis[5] = 3;

	act->colors.schwarz[0] = 0;
	act->colors.schwarz[1] = 1;
	act->colors.schwarz[2] = 2;
	act->colors.schwarz[3] = 2;
	act->colors.schwarz[4] = 3;
	act->colors.schwarz[5] = 4;

	act->count = amount;
	if (color[0] == 'r' || color[0] == 'R') {
		for (int i = 0; i < 6; i++) {
			act->color[i] = act->colors.rosa[i];
		}
		act->color_c = 'r';
	} else if (color[0] == 'g' || color[0] == 'G') {
		for (int i = 0; i < 6; i++) {
			act->color[i] = act->colors.gruen[i];
		}

		act->color_c = 'g';
	} else if (color[0] == 'w' || color[0] == 'W') {
		for (int i = 0; i < 6; i++) {
			act->color[i] = act->colors.weis[i];
		}

		act->color_c = 'w';
	} else if (color[0] == 's' || color[0] == 'S') {
		for (int i = 0; i < 6; i++) {
			act->color[i] = act->colors.schwarz[i];
		}

		act->color_c = 's';
	} else {
		printf("Unbekannte Wuerfelfarbe %s\n", color);
		printf("Rosa wurde automatisch ausgewählt");
		for (int i = 0; i < 6; i++) {
			act->color[i] = act->colors.rosa[i];
		}
		act->color_c = 'r';
	}
	return act;
}

void print_result (c_wuerfel* w) {
	switch (w->color_c) {
		case 'r':
			printf("Rosa Wuerfel: %u\n", w->result);
			break;
		case 'g':
			printf("Gruener Wuerfel: %u\n", w->result);
			break;
		case 'w':
			printf("Weißer Wuerfel: %u\n", w->result);
			break;
		case 's':
			printf("Schwarzer Wuerfel: %u\n", w->result);
			break;
		default:
			printf("How did I got to this point? %c\n", w->color_c);
			break;
	}
}

