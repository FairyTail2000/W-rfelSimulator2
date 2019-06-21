/*
 * defence.h
 *
 *  Created on: 20.06.2019
 *      Author: rafael
 */

#ifndef DEFENCE_H_
#define DEFENCE_H_


typedef struct c_wuerfel {
	struct {
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
void roll_colored_dice(c_wuerfel* w);
c_wuerfel* create_colored_dice (const char* color, int amount);


#endif /* DEFENCE_H_ */
