/* 
 * File:   main.c
 * Author: IBRAHIM LABS
 *
 * Created on June 27, 2013, 4:48 AM
 */


#include <p24F16KA102.h>
#include "DigitalClock.h"

/******************************************************************************/

/*  *** Configuration Bits Setting  *** */

_FGS(GWRP_OFF & GCP_OFF)
_FOSCSEL(FNOSC_PRI & IESO_OFF)
_FOSC(POSCMOD_HS & OSCIOFNC_ON & POSCFREQ_HS & FCKSM_CSDCMD)
_FWDT(WINDIS_OFF & FWDTEN_OFF)
_FPOR(BOREN_BOR2 & PWRTEN_OFF  & MCLRE_ON)
_FDS(DSWDTEN_OFF)

/******************************************************************************/
extern struct Clock Time;

// Main function
int main()
{
    InitializeDigitalClock();
    InitializeTimer1();

    while(1)
    {
        DigitalClock(); /*  update data on 7segments    */
    }
    return 0;
}
/******************************************************************************/

// Timer1 ISR

void __attribute__((__interrupt__, __shadow__, auto_psv)) _T1Interrupt(void)
{
    LED_SECOND = ~LED_SECOND;       //  toggling LEDs after 0.5sec
    static unsigned char T = 0;
    if (T == 2)
    {
        T = 0;
        Time.Seconds++;             // this loop is 0.5 seconds and 2 times 0.5 = 1second perfect time
    }
    T++;
    
    if (Time.Seconds > 59)
    {
        Time.Seconds = 0;
        Time.Minutes++;
    }
    if (Time.Minutes > 59)
    {
        Time.Minutes = 0;
        Time.Hours++;
    }
    if (Time.Hours > 24)
    {
        Time.Hours = 0;
    }
    IFS0bits.T1IF = 0;      /*  always clear flags*/
}
/******************************************************************************/
