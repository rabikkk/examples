/** Generated by YAKINDU Statechart Tools code generator. */

#ifndef BLINK_H_
#define BLINK_H_

#ifdef __cplusplus
extern "C" { 
#endif

/*!
* Forward declaration for the Blink state machine.
*/
typedef struct Blink Blink;

/*!
* Forward declaration of the data structure for the BlinkInternal interface scope.
*/
typedef struct BlinkInternal BlinkInternal;

/*!
* Forward declaration of the data structure for the BlinkIface interface scope.
*/
typedef struct BlinkIface BlinkIface;

/*!
* Forward declaration of the data structure for the BlinkTimeEvents interface scope.
*/
typedef struct BlinkTimeEvents BlinkTimeEvents;

#ifdef __cplusplus
}
#endif

#include "base/sc_tracing.h"
#include "base/sc_types.h"

#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'blink'.
*/

#ifndef SC_INVALID_EVENT_VALUE
#define SC_INVALID_EVENT_VALUE 0
#endif
/*! Define number of states in the state enum */

#define BLINK_STATE_COUNT 4

/*! Define dimension of the state configuration vector for orthogonal states. */
#define BLINK_MAX_ORTHOGONAL_STATES 1

/*! Define maximum number of time events that can be active at once */
#define BLINK_MAX_PARALLEL_TIME_EVENTS 1

/*! Define indices of states in the StateConfVector */
#define SCVI_BLINK_RASPBERRY_PI_BLINK 0
#define SCVI_BLINK_RASPBERRY_PI_BLINK_BLINKY_ON 0
#define SCVI_BLINK_RASPBERRY_PI_BLINK_BLINKY_OFF 0
#define SCVI_BLINK_RASPBERRY_PI_IDLE 0



/*! Enumeration of all states */ 
typedef enum
{
	Blink_last_state,
	Blink_raspberry_pi_Blink,
	Blink_raspberry_pi_Blink_blinky_On,
	Blink_raspberry_pi_Blink_blinky_Off,
	Blink_raspberry_pi_Idle
} BlinkStates;
		
/*! Enumeration of all features of the statechart */ 
typedef enum
{
	blink_no_feature = SC_NO_EVENT,
	blinkIface_low,
	blinkIface_high,
	blinkIface_output,
	blinkIface_led_pin,
	blinkIface_delay,
	blinkIface_toggle
} BlinkFeature;

/*! Type declaration of the data structure for the BlinkInternal interface scope. */
struct BlinkInternal
{
	sc_integer low;
	sc_integer high;
	sc_integer output;
	sc_integer led_pin;
};



/*! Type declaration of the data structure for the BlinkIface interface scope. */
struct BlinkIface
{
	sc_integer delay;
	sc_boolean toggle_raised;
};



/*! Type declaration of the data structure for the BlinkTimeEvents interface scope. */
struct BlinkTimeEvents
{
	sc_boolean blink_raspberry_pi_Blink_blinky_On_tev0_raised;
	sc_boolean blink_raspberry_pi_Blink_blinky_Off_tev0_raised;
};




/*! 
 * Type declaration of the data structure for the Blink state machine.
 * This data structure has to be allocated by the client code. 
 */
struct Blink
{
	BlinkStates stateConfVector[BLINK_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	BlinkInternal internal;
	BlinkIface iface;
	BlinkTimeEvents timeEvents;
	sc_trace_handler *trace_handler;
};


/*! Initializes the Blink state machine data structures. Must be called before first usage.*/
extern void blink_initWithTracing(Blink* handle, sc_trace_handler* trace_handler);

/*! Sets the trace handler. Can be called any time. */
extern void blink_setTraceHandler(Blink* handle, sc_trace_handler* trace_handler);

/*! Initializes the Blink state machine data structures. Must be called before first usage.*/
extern void blink_init(Blink* handle);

/*! Activates the state machine */
extern void blink_enter(Blink* handle);

/*! Deactivates the state machine */
extern void blink_exit(Blink* handle);

/*! Performs a 'run to completion' step. */
extern void blink_runCycle(Blink* handle);

/*! Raises a time event. */
extern void blink_raiseTimeEvent(Blink* handle, sc_eventid evid);

/*! Gets the value of the variable 'delay' that is defined in the default interface scope. */ 
extern sc_integer blinkIface_get_delay(const Blink* handle);
/*! Sets the value of the variable 'delay' that is defined in the default interface scope. */ 
extern void blinkIface_set_delay(Blink* handle, sc_integer value);
/*! Raises the in event 'toggle' that is defined in the default interface scope. */ 
extern void blinkIface_raise_toggle(Blink* handle);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean blink_isActive(const Blink* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean blink_isFinal(const Blink* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean blink_isStateActive(const Blink* handle, BlinkStates state);


#ifdef __cplusplus
}
#endif 

#endif /* BLINK_H_ */
