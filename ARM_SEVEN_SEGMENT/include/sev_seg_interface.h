/*********************************************************************************/
/* Author    : Ahmed Elbadry                                                     */
/* Version   : V01                                                               */
/* Date      : 16 August 2020                                                    */
/*********************************************************************************/
#ifndef SEV_SEG_INTERFACE_H
#define    SEV_SEG_INTERFACE_H

#define CommonAnode     1
#define CommonCathode   0


#define ZERO        0
#define ONE         1
#define TWO         2
#define THREE       3
#define FOUR        4
#define FIVE        5
#define SIX         6
#define SEVEN       7
#define EIGHT       8
#define NINE        9

/* for port A (A0 -> A6) */
/* connections:
                A0 -> segment_pin_A
                A1 -> segment_pin_B
                A2 -> segment_pin_C
                A3 -> segment_pin_D
                A4 -> segment_pin_E
                A5 -> segment_pin_F
                A6 -> segment_pin_G
*/

//example: SEV_SEG_Display(CommonAnode,FOUR);
void SEV_SEG_Display(u8 Copy_U8Common_Type ,u8 Copy_U8Number );




#endif