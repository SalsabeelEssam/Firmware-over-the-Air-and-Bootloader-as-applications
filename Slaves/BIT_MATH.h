#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(var,bitno) ((var) |= ((u32)(0x01<<bitno)))
#define CLR_BIT(var,bitno) ((var) &= ~((u32)(0x01<<bitno)))
#define TOGGLE_BIT(var,bitno) ((var) ^= ((u32)(0x01<<bitno)))
#define GET_BIT(var,bitno) ((var>>bitno) & (0x01))

#define SET_PORT(portno) ( (portno) = (u32)(0xffffffff) )
#define CLR_PORT(portno) ( (portno) = (u32)(0x00000000) )
#define TOGGLE_PORT(portno) ( (portno) = ~(portno) )

#endif
