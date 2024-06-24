/*
 * Event_Manager.c
 *
 *  Created on: 02-Apr-2024
 *      Author: Nilesh
 */

/*------------------------Include files------------------------------*/
#include "Event_Manager.h"
#include "types.h"
#include "App_Event_Manager_api.h"

/*----------------------User Defined Macros-------------------------*/


/*----------------------Global Variables--------------------------- */


/*--------------------------------------------------------------------
 *  Function uint32_t Event_Mgr_Get_Event_Status(uint32_t Event_Number)
 *
 *  Purpose:  This Function provides the status of the argument Event number
 *
 *  Parameters:
 *      Input parameters: uint32_t Event_Number
 *
 *  Returns:This function returns true if the Event is set else returns
 *          false.
 -------------------------------------------------------------------*/

uint32_t Event_Mgr_Get_Event_Status(uint32_t lu32_Event_Number)
{
	Event_Manager_t *Event_ptr = NULL;
	uint32_t lu32_Event_Status = false;

	if(lu32_Event_Number < App_evt_mgr_get_max_evt_no())
	{
		Event_ptr = App_event_mgr_get_event_table_ref(lu32_Event_Number);
		lu32_Event_Status = Event_ptr->status;
	}
	else
	{
		lu32_Event_Status = EVENT_ERROR;
	}

	return lu32_Event_Status;
}

/*--------------------------------------------------------------------
 *  Function bool Event_Mgr_Set_Event_Debounce(uint32_t Event_Number)
 *
 *  Purpose:  This Function set the Error event if the condition for
 *            event met and the event stays for the NG time
 *
 *  Parameters:
 *      Input parameters: uint32_t Event_Number
 *
 *  Returns:Event Set status, this function returns true if the function
 *          Event Set executed without error else returns false.
 -------------------------------------------------------------------*/

bool Event_Mgr_Set_Event_Debounce(uint32_t lu32_Event_Number)
{
	Event_Manager_t *Event_ptr = NULL;
	bool lb_Event_Set_Status = false;

	/*Get the status of hardware events*/
	uint32_t lu32_Event_Mgr_Hardware_Status = App_event_mgr_get_hdr_status();

	/*Get the status of System Events*/
	uint32_t lu32_Event_Mgr_System_Status_1 = App_event_mgr_get_system_status_1();

	/*Get the status of System Events*/
	uint32_t lu32_Event_Mgr_System_Status_2 = App_event_mgr_get_system_status_2();

	/*Check whether the event number is valid or not*/
	if(lu32_Event_Number < App_evt_mgr_get_max_evt_no())
	{
		Event_ptr = App_event_mgr_get_event_table_ref(lu32_Event_Number);

		/*reset the OK counter in case of occurrence of Event*/
		Event_ptr->Ok_Counter = 0u;

		if(((0u !=(Event_ptr->Hardware_Dependency & lu32_Event_Mgr_Hardware_Status))
		  ||(0u!= (Event_ptr->System_dependency_1 & lu32_Event_Mgr_System_Status_1)))
		  ||(0u!= (Event_ptr->System_dependency_2 & lu32_Event_Mgr_System_Status_2)))
		{
			/*Don't perform any action as the higher priority Event is
			 * already set*/
		}
		else
		{
			/*Check whether the event setting time is expired or not*/
			if((uint32_t)Event_ptr->Ng_Counter < Event_ptr->Ng_Counter_Max)
			{
				/*increment the counter if the event setting time is not
				 * not met
				 */
				Event_ptr->Ng_Counter++;

			}
			else
			{
				/*set the Event status, execute the callback function,
				 * set the hardware or event dependency variable
				 */
				Event_ptr->status = (uint32_t)EVENT_SET;

				/*Check whether the event is having the callback for performing
				 * certain action or not
				 */
				if(Event_ptr->CallbackFunction != NULL)
				{
					/*execute the call back */
				   Event_ptr->CallbackFunction();
				}
				else
				{
					/*if the event is not having the callback no action
					 * is required
					 */
				}

				/*logic for setting the dependency variable*/
				App_evt_mgr_update_event_status(lu32_Event_Number,(uint8_t)EVENT_SET);

			}

		}

		lb_Event_Set_Status = true;

	}
	else
	{
		/*No Action*/

	}

    return lb_Event_Set_Status;
}

/*--------------------------------------------------------------------
 *  Function bool Event_Mgr_Reset_Event_Debounce(uint32_t Event_Number)
 *
 *  Purpose:  This Function reset the Error event if the condition for resetting
 *            the event stays for the OK time of that particular event
 *
 *  Parameters:
 *      Input parameters: uint32_t Event_Number
 *
 *  Returns:Event reset status, this function returns true if the function
 *          Event reset executed without error else returns false.
 -------------------------------------------------------------------*/
bool Event_Mgr_Reset_Event_Debounce(uint32_t lu32_Event_Number)
{
	Event_Manager_t *Event_ptr = NULL;
	bool lb_Event_reset_Status = false;

	/*Check whether the event number is valid or not*/
	if(lu32_Event_Number < App_evt_mgr_get_max_evt_no())
	{
		Event_ptr = App_event_mgr_get_event_table_ref(lu32_Event_Number);

		/*reset the OK counter in case of occurrence of Event*/
		Event_ptr->Ng_Counter = 0u;

		/*Check whether the event reset time is expired or not*/
		if((uint32_t)Event_ptr->Ok_Counter < Event_ptr->Ok_Counter_Max)
		{
			/*
			 * increment the counter if the event reset time is not over
			 */
			Event_ptr->Ok_Counter++;

		}
		else
		{
			/*set the Event status, execute the callback function,
			 * set the hardware or event dependency variable
			 */
			Event_ptr->status = (uint32_t)EVENT_RESET;

			/*logic for setting the dependency variable*/
			App_evt_mgr_update_event_status(lu32_Event_Number,(uint8_t)EVENT_RESET);

		}

		lb_Event_reset_Status = true;

	}
	else
	{
		/*No Action*/
	}

	return lb_Event_reset_Status;

}

/*--------------------------------------------------------------------
 *  Function bool Event_Mgr_Set_Event(uint32_t lu32_Event_Number)
 *
 *  Purpose:  This Function set the Error event if the condition for
 *            event met without wait period
 *
 *  Parameters:
 *      Input parameters: uint32_t Event_Number
 *
 *  Returns:Event Set status, this function returns true if the function
 *          Event Set executed without error else returns false.
 -------------------------------------------------------------------*/
bool Event_Mgr_Set_Event(uint32_t lu32_Event_Number)
{
	Event_Manager_t *Event_ptr = NULL;
	bool lb_Event_Set_Status = false;

	/*Get the status of hardware events*/
	uint32_t lu32_Event_Mgr_Hardware_Status = App_event_mgr_get_hdr_status();

	/*Get the status of System Events*/
	uint32_t lu32_Event_Mgr_System_Status_1 = App_event_mgr_get_system_status_1();

	/*Get the status of System Events*/
	uint32_t lu32_Event_Mgr_System_Status_2 = App_event_mgr_get_system_status_2();

	/*Check whether the event number is valid or not*/
	if(lu32_Event_Number < App_evt_mgr_get_max_evt_no())
	{
		Event_ptr = App_event_mgr_get_event_table_ref(lu32_Event_Number);

		/*reset the OK counter in case of occurrence of Event*/
		Event_ptr->Ok_Counter = 0u;

		if(((0u !=(Event_ptr->Hardware_Dependency & lu32_Event_Mgr_Hardware_Status))
		  ||(0u!= (Event_ptr->System_dependency_1 & lu32_Event_Mgr_System_Status_1)))
		  ||(0u!= (Event_ptr->System_dependency_2 & lu32_Event_Mgr_System_Status_2)))
		{
			/*Don't perform any action as the higher priority Event is
			 * already set*/
		}
		else
		{
		   /*set the Event status, execute the callback function,
		    * set the hardware or event dependency variable
		    */
		   Event_ptr->status = (uint32_t)EVENT_SET;

		   /*Check whether the event is having the callback for performing
		    * certain action or not
		    */
		   if(Event_ptr->CallbackFunction != NULL)
		   {
		   	/*execute the call back */
		      Event_ptr->CallbackFunction();
		   }
		   else
		   {
		   	/*if the event is not having the callback no action
		   	 * is required
		   	 */
		   }

		   /*logic for setting the dependency variable*/
		   App_evt_mgr_update_event_status(lu32_Event_Number,(uint8_t)EVENT_SET);

		 }

		 lb_Event_Set_Status = true;

	}
	else
	{
		/*No Action*/

	}

    return lb_Event_Set_Status;
}


/*--------------------------------------------------------------------
 *  Function bool Event_Mgr_Reset_Event(uint32_t Event_Number)
 *
 *  Purpose:  This Function reset the Error event without waiting for OK time
 *
 *  Parameters:
 *      Input parameters: uint32_t Event_Number
 *
 *  Returns:Event reset status, this function returns true if the function
 *          Event reset executed without error else returns false.
 -------------------------------------------------------------------*/
bool Event_Mgr_Reset_Event(uint32_t lu32_Event_Number)
{
	Event_Manager_t *Event_ptr = NULL;
	bool lb_Event_reset_Status = false;

	/*Check whether the event number is valid or not*/
	if(lu32_Event_Number < App_evt_mgr_get_max_evt_no())
	{
		Event_ptr = App_event_mgr_get_event_table_ref(lu32_Event_Number);

		/*reset the OK counter in case of occurrence of Event*/
		Event_ptr->Ng_Counter = 0u;


		/*set the Event status, execute the callback function,
		 * set the hardware or event dependency variable
		 */
		Event_ptr->status = (uint32_t)EVENT_RESET;

		/*logic for setting the dependency variable*/
		App_evt_mgr_update_event_status(lu32_Event_Number,(uint8_t)EVENT_RESET);

		lb_Event_reset_Status = true;

    }
	else
	{
		/*No Action*/
	}

	return lb_Event_reset_Status;

}


