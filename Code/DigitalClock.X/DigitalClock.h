/* 
 * File:   DigitalClock.h
 * Author: IBRAHIMSANGI
 *
 * Created on June 27, 2013, 11:42 AM
 */

#ifndef DIGITALCLOCK_H
#define	DIGITALCLOCK_H

#ifdef	__cplusplus
extern "C" {
#endif


#define ANODE_BUS_DIRECTION TRISB
#define LED_SECOND_DIRECTION TRISAbits.TRISA0
    
#define ANODE_COMMON_BUS LATB
#define LED_SECOND LATAbits.LATA0

    struct Clock{

        unsigned char Seconds;
        unsigned char Minutes;
        unsigned char Hours;

    };

    void InitializeDigitalClock(void);
    void UpdateDigitsOfSeconds(void);
    void UpdateDigitsOfMinutes(void);
    void UpdateDigitsOfHours(void);
    void DigitalClock(void);


#ifdef	__cplusplus
}
#endif

#endif	/* DIGITALCLOCK_H */

