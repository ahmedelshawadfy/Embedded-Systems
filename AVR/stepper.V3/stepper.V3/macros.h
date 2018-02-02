/*
 * macros.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#ifndef MACROS_H_
#define MACROS_H_

#define set_Bit(Reg,Bit_num)  (Reg|=(1<<Bit_num))
#define clear_Bit(Reg,Bit_num)    (Reg&=~(1<<Bit_num))
#define get_Bit(Reg,Bit_num)  (Reg&(1<<Bit_num))
#define set_Direction_output(Reg,Bit_num)   (Reg|=(0<<Bit_num))
#define set_Direction_intput(Reg,Bit_num)   Reg |= (1<<Bit_num)


#endif /* MACROS_H_ */