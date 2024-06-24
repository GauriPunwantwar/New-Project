/*
 * Event_Manager_api.h
 *
 *  Created on: 14-Apr-2024
 *      Author: Nilesh
 */

#ifndef EVENT_MANAGER_EVENT_MANAGER_API_H_
#define EVENT_MANAGER_EVENT_MANAGER_API_H_

/*
 * function brief: This Function provides the status of the argument Event number
 */
extern uint32_t Event_Mgr_Get_Event_Status(uint32_t lu32_Event_Number);

/*
 * function brief: This Function set the Error event if the condition for
 *                 event met and the event stays for the NG time
 */
extern bool Event_Mgr_Set_Event_Debounce(uint32_t lu32_Event_Number);

/*
 * function brief: This Function reset the Error event if the condition for resetting
 *            the event stays for the OK time of that particular event
 */
extern bool Event_Mgr_Reset_Event_Debounce(uint32_t lu32_Event_Number);

/*
 * function brief: This Function set the Error event if the condition for
 *            event met without wait period
 */
extern bool Event_Mgr_Set_Event(uint32_t lu32_Event_Number);

/*
 * function brief: This Function reset the Error event without waiting for OK time
 */
extern bool Event_Mgr_Reset_Event(uint32_t lu32_Event_Number);


#endif /* EVENT_MANAGER_EVENT_MANAGER_API_H_ */
