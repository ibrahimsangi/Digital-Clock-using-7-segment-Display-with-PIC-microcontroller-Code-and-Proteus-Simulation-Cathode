/*
 * File:   7segment.c
 * Author: IBRAHIM LABS
 *
 * Created on June 22, 2013, 4:53 AM
 */

#define SEVEN_SEGMENT_DISPLAY_BUS LATB

#include <p24F16KA102.h>

unsigned char Display7Segment_CommonAnode(unsigned int Segment)
{
    /*  Warning !!! this function is for Common Cathode type only*/

    /*  hard coded these values called lookuptables     */

    unsigned char const Segments[] = {  0x3F,       //  For displaying 0
                                        0x06,       //  For displaying 1
                                        0x5B,       //  For displaying 2
                                        0x4F,       //  For displaying 3
                                        0x66,       //  For displaying 4
                                        0x6D,       //  For displaying 5
                                        0x7D,       //  For displaying 6
                                        0x07,       //  For displaying 7
                                        0x7F,       //  For displaying 8
                                        0x67};      //  For displaying 9

    static unsigned char Temp = 0;
    
    switch(Segment)
    {
        case 0:
            Temp = Segments[0];
            break;
        case 1:
            Temp = Segments[1];
            break;
        case 2:
            Temp = Segments[2];
            break;
        case 3:
            Temp = Segments[3];
            break;
        case 4:
            Temp = Segments[4];
            break;
        case 5:
            Temp = Segments[5];
            break;
        case 6:
            Temp = Segments[6];
            break;
        case 7:
            Temp = Segments[7];
            break;
        case 8:
            Temp = Segments[8];
            break;
        case 9:
            Temp = Segments[9];
            break;
        default:
            Temp = Segments[0];
            break;        
    }
    return Temp;
}
