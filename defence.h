/*
 * defence.h
 *
 *  Created on: 20.06.2019
 *      Author: rafael
 */

#ifndef DEFENCE_H_
#define DEFENCE_H_


typedef struct color_wuerfel c_wuerfel;
void roll_colored_dice(c_wuerfel* w);
c_wuerfel* create_colored_dice (const char* color, int amount);


#endif /* DEFENCE_H_ */
