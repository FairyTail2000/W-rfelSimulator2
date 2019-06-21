/*
 * defense.c
 *
 *  Created on: 20.06.2019
 *      Author: rafael
 */

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define ARR_SIZE(arr) ( sizeof((arr)) / sizeof((arr[0])) )
#define ss (unsigned char) 225
#define AE (unsigned char) 142
#define ae (unsigned char) 132
#define OE (unsigned char) 153
#define oe (unsigned char) 148
#define UE (unsigned char) 154
#define ue (unsigned char) 129


typedef struct c_wuerfel {
	struct colors {
		unsigned int rosa[6];
		unsigned int gruen[6];
		unsigned int weis[6];
		unsigned int schwarz[6];
	} colors;
	unsigned int result;
	unsigned int color[6];
	unsigned int count;
	char color_c;
} c_wuerfel;



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
		#ifdef WINDOWS
		printf("Unbekannte W%crfelfarbe %s\n", ue,  color);
				printf("Rosa wurde automatisch ausgew%chlt", ae);
		#else
				printf("Unbekannte Würfelfarbe %s\n", color);
				printf("Rosa wurde automatisch ausgewählt");
		#endif

		for (int i = 0; i < 6; i++) {
			act->color[i] = act->colors.rosa[i];
		}
		act->color_c = 'r';
	}
	return act;
}

void print_result (c_wuerfel* w) {
	switch (w->color_c) {

	#ifdef WINDOWS

		case 'r':
			printf("Rosa W%crfel: %u\n", ue, w->result);
			break;
		case 'g':
			printf("Gr%cner W%crfel: %u\n", ue, ue, w->result);
			break;
		case 'w':
			printf("Wei%cer W%crfel: %u\n", ss, ue, w->result);
			break;
		case 's':
			printf("Schwarzer W%crfel: %u\n", ue, w->result);
			break;
		default:
			printf("How did I got to this point? %c\n", w->color_c);
			break;
	#else
		case 'r':
					printf("Rosa Würfel: %u\n", w->result);
					break;
				case 'g':
					printf("Gruener Würfel: %u\n", w->result);
					break;
				case 'w':
					printf("Weißer Würfel: %u\n", w->result);
					break;
				case 's':
					printf("Schwarzer Würfel: %u\n", w->result);
					break;
				default:
					printf("How did I got to this point? %c\n", w->color_c);
					break;
	#endif
	}
}

