/*
 * Event_Manager.h
 *
 *  Created on: 02-Apr-2024
 *      Author: win10
 */

#ifndef EVENT_MANAGER_EVENT_MANAGER_H_
#define EVENT_MANAGER_EVENT_MANAGER_H_

#include <stdint.h>
#include "stdbool.h"

/*
 * function brief: This Function provides the status of the argument Event number
 */
uint32_t Event_Mgr_Get_Event_Status(uint32_t lu32_Event_Number);

/*
 * function brief: This Function set the Error event if the condition for
 *                 event met and the event stays for the NG time
 */
bool Event_Mgr_Set_Event_Debounce(uint32_t lu32_Event_Number);

/*
 * function brief: This Function reset the Error event if the condition for resetting
 *            the event stays for the OK time of that particular event
 */
bool Event_Mgr_Reset_Event_Debounce(uint32_t lu32_Event_Number);

/*
 * function brief: This Function set the Error event if the condition for
 *            event met without wait period
 */
bool Event_Mgr_Set_Event(uint32_t lu32_Event_Number);

/*
 * function brief: This Function reset the Error event without waiting for OK time
 */
bool Event_Mgr_Reset_Event(uint32_t lu32_Event_Number);

#endif /* EVENT_MANAGER_EVENT_MANAGER_H_ */
