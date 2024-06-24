/*
 * App_Event_Manager_Api.h
 *
 *  Created on: 06-Apr-2024
 *      Author: win10
 */

#ifndef APP_APP_EVENT_MANAGER_APP_EVENT_MANAGER_API_H_
#define APP_APP_EVENT_MANAGER_APP_EVENT_MANAGER_API_H_

#include "stdbool.h"
#include "stdint.h"
#include "types.h"

/*------------------------User type defined-------------------------*/
/*Event manager structure*/
typedef struct
{

	uint32_t Hardware_Dependency;
	uint32_t System_dependency_1;
	uint32_t System_dependency_2;
	uint32_t Ok_Counter_Max;
	uint32_t Ng_Counter_Max;
	uint32_t *Ok_Counter;
	uint32_t *Ng_Counter;
	void (*CallbackFunction)(void);
	uint32_t status;

}Event_Manager_t;
/*----------------------User Defined Macros-------------------------*/
#define EVENT_SET                     1
#define EVENT_RESET 	              0
#define EVENT_ERROR                   ((uint32_t)0xFFFF)
#define MAX_HARDWARE_EVENT_NUMBER     28u
#define MAX_SYSTEM_EVENT_1_NUMBER     59u


/*----------------------Global Variables--------------------------- */

/*----------------------Extern function--------------------------- */

/*
 * function brief: This function returns the hardware event status
 */
extern uint32_t App_event_mgr_get_hdr_status(void);

/*
 * function brief: This function returns the system event status 1
 */
extern uint32_t App_event_mgr_get_system_status_1(void);

/*
 * function brief: This function returns the system event status 2
 */
extern uint32_t App_event_mgr_get_system_status_2(void);

/*
*  Function brief: This is a wrapper function to get the maximum number of events
*/
extern uint32_t App_evt_mgr_get_max_evt_no(void);

/*
 * function brief: This function set or reset the event status variables
 */
extern void App_evt_mgr_update_event_status(uint32_t Event_number, uint8_t Event_state);

/*
 * function brief: This function returns the ref of the event table based on the
 *                  event number
 */
extern Event_Manager_t* App_event_mgr_get_event_table_ref(uint32_t lu32_Event_number);
#endif /* APP_APP_EVENT_MANAGER_APP_EVENT_MANAGER_API_H_ */

