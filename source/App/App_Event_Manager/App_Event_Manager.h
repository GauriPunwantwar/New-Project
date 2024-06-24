/*
 * App_Event_Manager.h
 *
 *  Created on: 06-Apr-2024
 *      Author: Nilesh
 */

#ifndef APP_APP_EVENT_MANAGER_APP_EVENT_MANAGER_H_
#define APP_APP_EVENT_MANAGER_APP_EVENT_MANAGER_H_

#include<stdint.h>
#include "App_Event_Manager_api.h"

/*------------------------User type defined------------------------------*/

/*
 * function brief: This function returns the hardware event status
 */
uint32_t App_event_mgr_get_hdr_status(void);

/*
 * function brief: This function returns the system event status 1
 */
uint32_t App_event_mgr_get_system_status_1(void);

/*
 * function brief: This function returns the system event status 2
 */
uint32_t App_event_mgr_get_system_status_2(void);

/*
*  Function brief: This is a wrapper function to get the maximum number of events
*/
uint32_t App_evt_mgr_get_max_evt_no(void);

/*
 * function brief: This function set or reset the event status variables
 */
void App_evt_mgr_update_event_status(uint32_t Event_number, uint8_t Event_state);

/*
 * function brief: This function returns the ref of the event table based on the
 *                  event number
 */
Event_Manager_t* App_event_mgr_get_event_table_ref(uint32_t lu32_Event_number);

#endif /* APP_APP_EVENT_MANAGER_APP_EVENT_MANAGER_H_ */
