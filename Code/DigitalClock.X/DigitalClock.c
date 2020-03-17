/*
 * File:   DigitalClock.c
 * Author: IBRAHIM LABS
 *
 * Created on June 27, 2013, 4:50 AM
 */

#define CRYSTAL_FREQUENCY   10000000         // Crystal of 10MHz
#define FCY CRYSTAL_FREQUENCY/2UL            // Instruction Cycle Clock must be defined

#include <p24F16KA102.h>
#include "DigitalClock.h"
#include <libpic30.h>

/*  transistors to 7 segment display
    Warning !!! Common Anode    */
static unsigned int const Multiplexing[] = {
                                            0x0100,
                                            0x0200,
                                            0x0400,
                                            0x0800,
                                            0x1000,
                                            0x2000 };

struct Clock Time;

void InitializeDigitalClock(void)
{
    ANODE_BUS_DIRECTION = 0;
    LED_SECOND_DIRECTION = 0;

    LED_SECOND = 0;
    
    Time.Seconds = 0;
    Time.Minutes = 0;
    Time.Hours   = 0;
    UpdateDigitsOfHours();
    UpdateDigitsOfMinutes();
    UpdateDigitsOfSeconds();
}

void UpdateDigitsOfSeconds(void)
{
    unsigned char Temp = 0;

    Temp = Display7Segment_CommonAnode(Time.Seconds%100%10);
    ANODE_COMMON_BUS = (Multiplexing[0] | Temp);
    __delay_ms(50);
    Temp = Display7Segment_CommonAnode(Time.Seconds%100/10);
    ANODE_COMMON_BUS = (Multiplexing[1] | Temp);
    __delay_ms(50);
}

void UpdateDigitsOfMinutes(void)
{
    unsigned char Temp = 0;

    Temp = Display7Segment_CommonAnode(Time.Minutes%100%10);
    ANODE_COMMON_BUS = (Multiplexing[2] | Temp);
    __delay_ms(50);
    Temp = Display7Segment_CommonAnode(Time.Minutes%100/10);
    ANODE_COMMON_BUS = (Multiplexing[3] | Temp);
    __delay_ms(50);
}

void UpdateDigitsOfHours(void)
{
    unsigned char Temp = 0;

    Temp = Display7Segment_CommonAnode(Time.Hours%100%10);
    ANODE_COMMON_BUS = (Multiplexing[4] | Temp);
    __delay_ms(50);
    Temp = Display7Segment_CommonAnode(Time.Hours%100/10);
    ANODE_COMMON_BUS = (Multiplexing[5] | Temp);
    __delay_ms(50);
}

void DigitalClock(void)
{
    UpdateDigitsOfSeconds();
    UpdateDigitsOfMinutes();
    UpdateDigitsOfHours();
}

