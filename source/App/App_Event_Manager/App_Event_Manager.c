/*
 * App_Event_Manager.c
 *
 *  Created on: 06-Apr-2024
 *      Author: Nilesh
 */

/*---------------------------Include files------------------------------*/

#include "App_Event_Manager.h"
#include "App_Event_Manager_api.h"


/*------------------------User Defined Macros----------------------------*/

/*------------------------User type defined------------------------------*/
typedef uint32_t (*App_event_mgr_event_update_f)(uint32_t lu32_App_Event_var,
		                                       uint32_t lu32_App_Event_Number);


typedef enum
{
	e_ROM_DIAG                              = 0u,   //ROM Diag
	e_RAM_DIAG                              = 1u,   //RAM Diag
	e_ALU_DIAG                              = 2u,   //ALU Diag
	e_ADC_DIAG                              = 3u,   //ADC Diag
	e_UART_DIAG                             = 4u,   //UART Diag
	e_SPI_DIAG                              = 5u,   //SPI Diag
	e_CLOCK_DIAG                            = 6u,   //Clock Diag
	e_5V_REF_DIAG                           = 7u,   //5V ref diag
	e_3_3V_REF_DIAG                         = 8u,   //3.3V ref
	e_1_5V_REF_DIAG                         = 9u,   //1.5 V ref
	e_STACK_OVERFLOW_DIAG                   = 10u,  //Stack overflow Diag
	e_RESERVED_1                            = 11u,  //Reserved
	e_RESERVED_2                            = 12u,  //Reserved
	e_TEMPERATURE_SENSOR_DIAG               = 13u,  //Temp Sens Diag
	e_R_PHASE_VOLTAGE_SENSOR_DIAG           = 14u,  //R phase Volt  sensor Diag
	e_Y_PHASE_VOLTAGE_SENSOR_DIAG           = 15u,  //Y phase Volt  Sens Diag
	e_B_PHASE_VOLTAGE_SENSOR_DIAG           = 16u,  //B phase Volt  Sens Diag
	e_R_PHASE_CURRENT_SENSOR_DIAG           = 17u,  //R phase Curr Sens Diag
	e_Y_PHASE_CURRENT_SENSOR_DIAG           = 18u,  //Y phase Curr  Sens Diag
	e_B_PHASE_CURRENT_SENSOR_DIAG           = 19u,  //B phase Curr Sens Diag
	e_EARTH_VOLTAGE_SENSOR_DIAG             = 20u,  //Earth Volt  Sens Diag
	e_EARTH_CURRENT_SENSOR_DIAG             = 21u,  //Earth Curr  Sens Diag
	e_R_PHASE_ARCING_SENSOR_DIAG            = 22u,  //R phase arcing sens Diag
	e_Y_PHASE_ARCING_SENSOR_DIAG            = 23u,  //Y phase arcing sens Diag
	e_B_PHASE_ARCING_SENSOR_DIAG            = 24u,  //B phase arcing sens Diag
	e_RESERVED_3                            = 25u,  //Reserved
	e_RESERVED_4                            = 26u,  //Reserved
	e_RESERVED_5                            = 27u,  //Reserved
	e_R_PHASE_HIGH_VOLTAGE_DIAG             = 28u,  //R phase  high voltage diag
	e_Y_PHASE_HIGH_VOLTAGE_DIAG             = 29u,  //Y phase  high voltage diag
	e_B_PHASE_HIGH_VOLTAGE_DIAG             = 30u,  //B phase  high voltage diag
	e_R_PHASE_LOW_VOLTAGE_DIAG              = 31u,  //R phase  low voltage diag
	e_Y_PHASE_LOW_VOLTAGE_DIAG              = 32u,  //Y phase  low voltage diag
	e_B_PHASE_LOW_VOLTAGE_DIAG              = 33u,  //B phase  low voltage diag
	e_R_PHASE_HIGH_VOLTAGE_WARNING          = 34u,  //R phase  high voltage Warning
	e_Y_PHASE_HIGH_VOLTAGE_WARNING          = 35u,  //Y phase  high voltage Warning
	e_B_PHASE_HIGH_VOLTAGE_WARNING          = 36u,  //B phase  high voltage Warning
	e_R_PHASE_LOW_VOLTAGE_WARNING           = 37u,  //R phase  low voltage Warning
	e_Y_PHASE_LOW_VOLTAGE_WARNING           = 38u,  //Y phase  low voltage Warning
	e_B_PHASE_LOW_VOLTAGE_WARNING           = 39u,  //B phase  low voltage Warning
	e_R_PHASE_VOLTAGE_SURGE_DIAG            = 40u,  //R phase voltage surge diag
	e_Y_PHASE_VOLTAGE_SURGE_DIAG            = 41u,  //Y phase voltage surge diag
	e_B_PHASE_VOLTAGE_SURGE_DIAG            = 42u,  //B phase voltage surge diag
	e_R_PHASE_VOLTAGE_INTR_WARNING          = 43u,  //R phase voltage interruption Warning
	e_Y_PHASE_VOLTAGE_INTR_WARNING          = 44u,  //Y phase voltage interruption Warning
	e_B_PHASE_VOLTAGE_INTR_WARNING          = 45u,  //B phase voltage interruption Warning
	e_R_PHASE_VOLTAGE_VAR_WARNING           = 46u,  //R phase voltage variation Warning
	e_Y_PHASE_VOLTAGE_VAR_WARNING           = 47u,  //Y phase voltage variation Warning
	e_B_PHASE_VOLTAGE_VAR_WARNING           = 48u,  //B phase voltage variation Warning
	e_R_PHASE_HIGH_VOLT_HARM_WAR            = 49u,  //R phase high voltage harmonics Warning
	e_Y_PHASE_HIGH_VOLT_HARM_WAR            = 50u,  //Y phase high voltage harmonics Warning
	e_B_PHASE_HIGH_VOLT_HARM_WAR            = 51u,  //B phase high voltage harmonics Warning
	e_R_PHASE_LOSS_DIAG                     = 52u,  //R phase loss diag
	e_Y_PHASE_LOSS_DIAG                     = 53u,  //Y phase loss diag
	e_B_PHASE_LOSS_DIAG                     = 54u,  //B phase loss diag
	e_R_PHASE_HIGH_CURRENT_WARNING          = 55u,  //R phase High  curr diag
	e_Y_PHASE_HIGH_CURRENT_WARNING          = 56u,  //Y phase High  curr diag
	e_B_PHASE_HIGH_CURRENT_WARNING          = 57u,  //B phase High  curr diag
	e_R_PHASE_INRUSH_CURRENT_WARNING        = 58u,  //R phase Inrush curr Warning
	e_Y_PHASE_INRUSH_CURRENT_WARNING        = 59u,  //Y phase Inrush curr Warning
	e_B_PHASE_INRUSH_CURRENT_WARNING        = 60u,  //B phase Inrush curr Warning
	e_R_PHASE_CURRENT_UNBALANCE_WARNING     = 61u,  //R phase current Unbalance Warning
	e_Y_PHASE_CURRENT_UNBALANCE_WARNING     = 62u,  //Y phase current Unbalance Warning
	e_B_PHASE_CURRENT_UNBALANCE_WARNING     = 63u,  //B phase current Unbalance warning
	e_R_PHASE_HIGH_CUR_HARMONICS_WAR        = 64u,  //R phase high current harmonics Warning
	e_Y_PHASE_HIGH_CUR_HARMONICS_WAR        = 65u,  //Y phase high current harmonics Warning
	e_B_PHASE_HIGH_CUR_HARMONICS_WAR        = 66u,  //B phase high current harmonics Warning
	e_EARTH_HIGH_CURRENT_DIAG               = 67u,  //Earth High curr Diag
	e_EARTH_HIGH_VOLTAGE_DIAG               = 68u,  //Earth High Volt Diag
	e_R_PHASE_SHORT_CIRCUIT_DIAG            = 69u,  //R phase Short circuit diag
	e_Y_PHASE_SHORT_CIRCUIT_DIAG            = 70u,  //Y phase Short circuit diag
	e_B_PHASE_SHORT_CIRCUIT_DIAG            = 71u,  //B phase Short circuit diag
	e_EEPROM_WRITE_DIAG                     = 72u,  //EEPROM Write Diag
	e_EEPROM_READ_DIAG                      = 73u,  //EEPROM Read Diag
	e_WIFI_COMMUNICATON_DIAG                = 74u,  //WiFi Comm Diag
	e_WIFI_FRAME_DIAG                       = 75u,  //WiFi frame error
	e_R_PHASE_ARCING_DIAG                   = 76u,  //R phase Arcing Diag
	e_Y_PHASE_ARCING_DIAG                   = 77u,  //Y phase Arcing Diag
	e_B_PHASE_ARCING_DIAG                   = 78u,  //B phase Arcing Diag
	e_R_PHASE_LOW_POWER_FACTOR_WARNING      = 79u,  //R phase low Power Factor Warning
	e_Y_PHASE_LOW_POWER_FACTOR_WARNING      = 80u,  //Y phase low Power Factor Warning
	e_B_PHASE_LOW_POWER_FACTOR_WARNING      = 81u,  //B phase low Power Factor Warning
	e_NEUTRAL_LOSS                          = 82u,  //Neutral Loss
	e_POWER_OUTAGE                          = 83u,  //Power Outage
	e_PHASE_REVERSAL                        = 84u,  //Phase Reverse
	e_MAX_EVENT_NUMBER                      = 85u
}ge_App_event_mgr_table;


/*---------------------------Static Variables--------------------------- */
static uint32_t gu32_App_event_hdr_status = 0u;
static uint32_t gu32_App_event_system_status_1 = 0u;
static uint32_t gu32_App_event_system_status_2 = 0u;

/*---------------- Variables Related with Event Counter----------------- */
static uint32_t App_evt_mgr_ok_rom_ctr = 0u; //ROM Diag
static uint32_t App_evt_mgr_ok_ram_ctr = 0u; //RAM Diag
static uint32_t App_evt_mgr_ok_alu_ctr = 0u; //ALU Diag
static uint32_t App_evt_mgr_ok_adc_ctr = 0u; //ADC Diag
static uint32_t App_evt_mgr_ok_uart_ctr = 0u; //UART Diag
static uint32_t App_evt_mgr_ok_spi_ctr = 0u; //SPI Diag
static uint32_t App_evt_mgr_ok_clock_ctr = 0u; //Clock Diag
static uint32_t App_evt_mgr_ok_5v_ref_ctr = 0u; //5V ref diag
static uint32_t App_evt_mgr_ok_3_3v_ref_ctr = 0u; //3.3V ref
static uint32_t App_evt_mgr_ok_1_5v_ref_ctr = 0u; //1.5 V ref
static uint32_t App_evt_mgr_ok_stack_ctr = 0u; //Stack overflow Diag
static uint32_t App_evt_mgr_ok_temp_sens_ctr = 0u; //Temp Sens Diag
static uint32_t App_evt_mgr_ok_R_vtg_sens_ctr = 0u; //R phase Volt  sensor Diag
static uint32_t App_evt_mgr_ok_Y_vtg_sens_ctr = 0u; //Y phase Volt  Sens Diag
static uint32_t App_evt_mgr_ok_B_vtg_sens_ctr = 0u; //B phase Volt  Sens Diag
static uint32_t App_evt_mgr_ok_R_curr_sens_ctr = 0u; //R phase Curr Sens Diag
static uint32_t App_evt_mgr_ok_Y_curr_sens_ctr = 0u; //Y phase Curr  Sens Diag
static uint32_t App_evt_mgr_ok_B_curr_sens_ctr = 0u; //B phase Curr Sens Diag
static uint32_t App_evt_mgr_ok_E_vtg_sens_ctr = 0u; //Earth Volt  Sens Diag
static uint32_t App_evt_mgr_ok_E_curr_sens_ctr = 0u; //Earth Curr  Sens Diag
static uint32_t App_evt_mgr_ok_R_arc_sens_ctr = 0u; //R phase arcing sens Diag
static uint32_t App_evt_mgr_ok_Y_arc_sens_ctr = 0u; //Y phase arcing sens Diag
static uint32_t App_evt_mgr_ok_B_arc_sens_ctr = 0u; //B phase arcing sens Diag
static uint32_t App_evt_mgr_ok_R_high_vtg_ctr = 0u; //R phase  high voltage diag
static uint32_t App_evt_mgr_ok_Y_high_vtg_ctr = 0u; //Y phase  high voltage diag
static uint32_t App_evt_mgr_ok_B_high_vtg_ctr = 0u; //B phase  high voltage diag
static uint32_t App_evt_mgr_ok_R_low_vtg_ctr = 0u; //R phase  low voltage diag
static uint32_t App_evt_mgr_ok_Y_low_vtg_ctr = 0u; //Y phase  low voltage diag
static uint32_t App_evt_mgr_ok_B_low_vtg_ctr = 0u; //B phase  low voltage diag
static uint32_t App_evt_mgr_ok_R_high_vtg_war_ctr = 0u; //R phase  high voltage Warning
static uint32_t App_evt_mgr_ok_Y_high_vtg_war_ctr = 0u; //Y phase  high voltage Warning
static uint32_t App_evt_mgr_ok_B_high_vtg_war_ctr = 0u; //B phase  high voltage Warning
static uint32_t App_evt_mgr_ok_R_low_vtg_war_ctr = 0u; //R phase  low voltage Warning
static uint32_t App_evt_mgr_ok_Y_low_vtg_war_ctr = 0u; //Y phase  low voltage Warning
static uint32_t App_evt_mgr_ok_B_low_vtg_war_ctr = 0u; //B phase  low voltage Warning
static uint32_t App_evt_mgr_ok_R_vtg_surge_ctr = 0u; //R phase voltage surge diag
static uint32_t App_evt_mgr_ok_Y_vtg_surge_ctr = 0u; //Y phase voltage surge diag
static uint32_t App_evt_mgr_ok_B_vtg_surge_ctr = 0u; //B phase voltage surge diag
static uint32_t App_evt_mgr_ok_R_intrpt_war_ctr = 0u; //R phase voltage interruption Warning
static uint32_t App_evt_mgr_ok_Y_intrpt_war_ctr = 0u; //Y phase voltage interruption Warning
static uint32_t App_evt_mgr_ok_B_intrpt_war_ctr = 0u; //B phase voltage interruption Warning
static uint32_t App_evt_mgr_ok_R_vtg_var_war_ctr = 0u; //R phase voltage variation Warning
static uint32_t App_evt_mgr_ok_Y_vtg_var_war_ctr = 0u; //Y phase voltage variation Warning
static uint32_t App_evt_mgr_ok_B_vtg_var_war_ctr = 0u; //B phase voltage variation Warning
static uint32_t App_evt_mgr_ok_R_vtg_hrm_war = 0u; //R phase high voltage harmonics Warning
static uint32_t App_evt_mgr_ok_Y_vtg_hrm_war = 0u; //Y phase high voltage harmonics Warning
static uint32_t App_evt_mgr_ok_B_vtg_hrm_war = 0u; //B phase high voltage harmonics Warning
static uint32_t App_evt_mgr_ok_R_phase_loss_ctr = 0u; //R phase loss diag
static uint32_t App_evt_mgr_ok_Y_phase_loss_ctr = 0u; //Y phase loss diag
static uint32_t App_evt_mgr_ok_B_phase_loss_ctr = 0u; //B phase loss diag
static uint32_t App_evt_mgr_ok_R_phase_curr_ctr = 0u; //R phase High  curr diag
static uint32_t App_evt_mgr_ok_Y_phase_curr_ctr = 0u; //Y phase High  curr diag
static uint32_t App_evt_mgr_ok_B_phase_curr_ctr = 0u; //B phase High  curr diag
static uint32_t App_evt_mgr_ok_R_inrush_war_ctr = 0u; //R phase Inrush curr Warning
static uint32_t App_evt_mgr_ok_Y_inrush_war_ctr = 0u; //Y phase Inrush curr Warning
static uint32_t App_evt_mgr_ok_B_inrush_war_ctr = 0u; //B phase Inrush curr Warning
static uint32_t App_evt_mgr_ok_R_curr_unbal_ctr = 0u; //R phase current Unbalance Warning
static uint32_t App_evt_mgr_ok_Y_curr_unbal_ctr = 0u; //Y phase current Unbalance Warning
static uint32_t App_evt_mgr_ok_B_curr_unbal_ctr = 0u; //B phase current Unbalance warning
static uint32_t App_evt_mgr_ok_R_curr_har_war_ctr = 0u; //R phase high current harmonics Warning
static uint32_t App_evt_mgr_ok_Y_curr_har_war_ctr = 0u; //Y phase high current harmonics Warning
static uint32_t App_evt_mgr_ok_B_curr_har_war_ctr = 0u; //B phase high current harmonics Warning
static uint32_t App_evt_mgr_ok_E_curr_ctr = 0u; //Earth High curr Diag
static uint32_t App_evt_mgr_ok_E_vtg_ctr = 0u; //Earth High Volt Diag
static uint32_t App_evt_mgr_ok_R_short_ckt_ctr = 0u; //R phase Short circuit diag
static uint32_t App_evt_mgr_ok_Y_short_ckt_ctr = 0u; //Y phase Short circuit diag
static uint32_t App_evt_mgr_ok_B_short_ckt_ctr = 0u; //B phase Short circuit diag
static uint32_t App_evt_mgr_ok_EEP_wrt_ctr = 0u; //EEPROM Write Diag
static uint32_t App_evt_mgr_ok_EEP_read_ctr = 0u; //EEPROM Read Diag
static uint32_t App_evt_mgr_ok_WiFi_comm_ctr = 0u; //WiFi Comm Diag
static uint32_t App_evt_mgr_ok_WiFi_frame_ctr = 0u; //WiFi frame error
static uint32_t App_evt_mgr_ok_R_arc_ctr = 0u; //R phase Arcing Diag
static uint32_t App_evt_mgr_ok_Y_arc_ctr = 0u; //Y phase Arcing Diag
static uint32_t App_evt_mgr_ok_B_arc_ctr = 0u; //B phase Arcing Diag
static uint32_t App_evt_mgr_ok_R_low_PF_war_ctr = 0u; //R phase low Power Factor Warning
static uint32_t App_evt_mgr_ok_Y_low_PF_war_ctr = 0u; //Y phase low Power Factor Warning
static uint32_t App_evt_mgr_ok_B_low_PF_war_ctr = 0u; //B phase low Power Factor Warning
static uint32_t App_evt_mgr_ok_neutral_loss_ctr = 0u; //Neutral Loss
static uint32_t App_evt_mgr_ok_pwr_out_ctr = 0u; //Power Outage
static uint32_t App_evt_mgr_ok_phase_rev_ctr = 0u; //Phase Reverse
static uint32_t App_evt_mgr_ng_rom_ctr = 0u; //ROM Diag
static uint32_t App_evt_mgr_ng_ram_ctr = 0u; //RAM Diag
static uint32_t App_evt_mgr_ng_alu_ctr = 0u; //ALU Diag
static uint32_t App_evt_mgr_ng_adc_ctr = 0u; //ADC Diag
static uint32_t App_evt_mgr_ng_uart_ctr = 0u; //UART Diag
static uint32_t App_evt_mgr_ng_spi_ctr = 0u; //SPI Diag
static uint32_t App_evt_mgr_ng_clock_ctr = 0u; //Clock Diag
static uint32_t App_evt_mgr_ng_5v_ref_ctr = 0u; //5V ref diag
static uint32_t App_evt_mgr_ng_3_3v_ref_ctr = 0u; //3.3V ref
static uint32_t App_evt_mgr_ng_1_5v_ref_ctr = 0u; //1.5 V ref
static uint32_t App_evt_mgr_ng_stack_ctr = 0u; //Stack overflow Diag
static uint32_t App_evt_mgr_ng_temp_sens_ctr = 0u; //Temp Sens Diag
static uint32_t App_evt_mgr_ng_R_vtg_sens_ctr = 0u; //R phase Volt  sensor Diag
static uint32_t App_evt_mgr_ng_Y_vtg_sens_ctr = 0u; //Y phase Volt  Sens Diag
static uint32_t App_evt_mgr_ng_B_vtg_sens_ctr = 0u; //B phase Volt  Sens Diag
static uint32_t App_evt_mgr_ng_R_curr_sens_ctr = 0u; //R phase Curr Sens Diag
static uint32_t App_evt_mgr_ng_Y_curr_sens_ctr = 0u; //Y phase Curr  Sens Diag
static uint32_t App_evt_mgr_ng_B_curr_sens_ctr = 0u; //B phase Curr Sens Diag
static uint32_t App_evt_mgr_ng_E_vtg_sens_ctr = 0u; //Earth Volt  Sens Diag
static uint32_t App_evt_mgr_ng_E_curr_sens_ctr = 0u; //Earth Curr  Sens Diag
static uint32_t App_evt_mgr_ng_R_arc_sens_ctr = 0u; //R phase arcing sens Diag
static uint32_t App_evt_mgr_ng_Y_arc_sens_ctr = 0u; //Y phase arcing sens Diag
static uint32_t App_evt_mgr_ng_B_arc_sens_ctr = 0u; //B phase arcing sens Diag
static uint32_t App_evt_mgr_ng_R_high_vtg_ctr = 0u; //R phase  high voltage diag
static uint32_t App_evt_mgr_ng_Y_high_vtg_ctr = 0u; //Y phase  high voltage diag
static uint32_t App_evt_mgr_ng_B_high_vtg_ctr = 0u; //B phase  high voltage diag
static uint32_t App_evt_mgr_ng_R_low_vtg_ctr = 0u; //R phase  low voltage diag
static uint32_t App_evt_mgr_ng_Y_low_vtg_ctr = 0u; //Y phase  low voltage diag
static uint32_t App_evt_mgr_ng_B_low_vtg_ctr = 0u; //B phase  low voltage diag
static uint32_t App_evt_mgr_ng_R_high_vtg_war_ctr = 0u; //R phase  high voltage Warning
static uint32_t App_evt_mgr_ng_Y_high_vtg_war_ctr = 0u; //Y phase  high voltage Warning
static uint32_t App_evt_mgr_ng_B_high_vtg_war_ctr = 0u; //B phase  high voltage Warning
static uint32_t App_evt_mgr_ng_R_low_vtg_war_ctr = 0u; //R phase  low voltage Warning
static uint32_t App_evt_mgr_ng_Y_low_vtg_war_ctr = 0u; //Y phase  low voltage Warning
static uint32_t App_evt_mgr_ng_B_low_vtg_war_ctr = 0u; //B phase  low voltage Warning
static uint32_t App_evt_mgr_ng_R_vtg_surge_ctr = 0u; //R phase voltage surge diag
static uint32_t App_evt_mgr_ng_Y_vtg_surge_ctr = 0u; //Y phase voltage surge diag
static uint32_t App_evt_mgr_ng_B_vtg_surge_ctr = 0u; //B phase voltage surge diag
static uint32_t App_evt_mgr_ng_R_intrpt_war_ctr = 0u; //R phase voltage interruption Warning
static uint32_t App_evt_mgr_ng_Y_intrpt_war_ctr = 0u; //Y phase voltage interruption Warning
static uint32_t App_evt_mgr_ng_B_intrpt_war_ctr = 0u; //B phase voltage interruption Warning
static uint32_t App_evt_mgr_ng_R_vtg_var_war_ctr = 0u; //R phase voltage variation Warning
static uint32_t App_evt_mgr_ng_Y_vtg_var_war_ctr = 0u; //Y phase voltage variation Warning
static uint32_t App_evt_mgr_ng_B_vtg_var_war_ctr = 0u; //B phase voltage variation Warning
static uint32_t App_evt_mgr_ng_R_vtg_hrm_war = 0u; //R phase high voltage harmonics Warning
static uint32_t App_evt_mgr_ng_Y_vtg_hrm_war = 0u; //Y phase high voltage harmonics Warning
static uint32_t App_evt_mgr_ng_B_vtg_hrm_war = 0u; //B phase high voltage harmonics Warning
static uint32_t App_evt_mgr_ng_R_phase_loss_ctr = 0u; //R phase loss diag
static uint32_t App_evt_mgr_ng_Y_phase_loss_ctr = 0u; //Y phase loss diag
static uint32_t App_evt_mgr_ng_B_phase_loss_ctr = 0u; //B phase loss diag
static uint32_t App_evt_mgr_ng_R_phase_curr_ctr = 0u; //R phase High  curr diag
static uint32_t App_evt_mgr_ng_Y_phase_curr_ctr = 0u; //Y phase High  curr diag
static uint32_t App_evt_mgr_ng_B_phase_curr_ctr = 0u; //B phase High  curr diag
static uint32_t App_evt_mgr_ng_R_inrush_war_ctr = 0u; //R phase Inrush curr Warning
static uint32_t App_evt_mgr_ng_Y_inrush_war_ctr = 0u; //Y phase Inrush curr Warning
static uint32_t App_evt_mgr_ng_B_inrush_war_ctr = 0u; //B phase Inrush curr Warning
static uint32_t App_evt_mgr_ng_R_curr_unbal_ctr = 0u; //R phase current Unbalance Warning
static uint32_t App_evt_mgr_ng_Y_curr_unbal_ctr = 0u; //Y phase current Unbalance Warning
static uint32_t App_evt_mgr_ng_B_curr_unbal_ctr = 0u; //B phase current Unbalance warning
static uint32_t App_evt_mgr_ng_R_curr_har_war_ctr = 0u; //R phase high current harmonics Warning
static uint32_t App_evt_mgr_ng_Y_curr_har_war_ctr = 0u; //Y phase high current harmonics Warning
static uint32_t App_evt_mgr_ng_B_curr_har_war_ctr = 0u; //B phase high current harmonics Warning
static uint32_t App_evt_mgr_ng_E_curr_ctr = 0u; //Earth High curr Diag
static uint32_t App_evt_mgr_ng_E_vtg_ctr = 0u; //Earth High Volt Diag
static uint32_t App_evt_mgr_ng_R_short_ckt_ctr = 0u; //R phase Short circuit diag
static uint32_t App_evt_mgr_ng_Y_short_ckt_ctr = 0u; //Y phase Short circuit diag
static uint32_t App_evt_mgr_ng_B_short_ckt_ctr = 0u; //B phase Short circuit diag
static uint32_t App_evt_mgr_ng_EEP_wrt_ctr = 0u; //EEPROM Write Diag
static uint32_t App_evt_mgr_ng_EEP_read_ctr = 0u; //EEPROM Read Diag
static uint32_t App_evt_mgr_ng_WiFi_comm_ctr = 0u; //WiFi Comm Diag
static uint32_t App_evt_mgr_ng_WiFi_frame_ctr = 0u; //WiFi frame error
static uint32_t App_evt_mgr_ng_R_arc_ctr = 0u; //R phase Arcing Diag
static uint32_t App_evt_mgr_ng_Y_arc_ctr = 0u; //Y phase Arcing Diag
static uint32_t App_evt_mgr_ng_B_arc_ctr = 0u; //B phase Arcing Diag
static uint32_t App_evt_mgr_ng_R_low_PF_war_ctr = 0u; //R phase low Power Factor Warning
static uint32_t App_evt_mgr_ng_Y_low_PF_war_ctr = 0u; //Y phase low Power Factor Warning
static uint32_t App_evt_mgr_ng_B_low_PF_war_ctr = 0u; //B phase low Power Factor Warning
static uint32_t App_evt_mgr_ng_neutral_loss_ctr = 0u; //Neutral Loss
static uint32_t App_evt_mgr_ng_pwr_out_ctr = 0u; //Power Outage
static uint32_t App_evt_mgr_ng_phase_rev_ctr = 0u; //Phase Reverse

static Event_Manager_t Event_Manager_Table[e_MAX_EVENT_NUMBER] =
{/*Hdr Dep  |System Dep1   | System Dep 2 |OK counter Max | NG Counter Max  | OK counter Var                  | NG counter Var           | call back function | status */
{0x1,         0x0,             0x0,         60000,             20000,       &App_evt_mgr_ok_rom_ctr,           &App_evt_mgr_ng_rom_ctr,            NULL,          false},   //ROM Diag
{0x2,         0x0,             0x0,         60000,             20000,       &App_evt_mgr_ok_ram_ctr,           &App_evt_mgr_ng_ram_ctr,            NULL,          false},   //RAM Diag
{0x7,         0x0,             0x0,         60000,             20000,       &App_evt_mgr_ok_alu_ctr,           &App_evt_mgr_ng_alu_ctr,            NULL,          false},   //ALU Diag
{0x8,         0x0,             0x0,         60000,             20000,       &App_evt_mgr_ok_adc_ctr,           &App_evt_mgr_ng_adc_ctr,            NULL,          false},   //ADC Diag
{0x10,        0x0,             0x0,         60000,             20000,       &App_evt_mgr_ok_uart_ctr,          &App_evt_mgr_ng_uart_ctr,           NULL,          false},   //UART Diag
{0x20,        0x0,             0x0,         60000,             20000,       &App_evt_mgr_ok_spi_ctr,           &App_evt_mgr_ng_spi_ctr,            NULL,          false},   //SPI Diag
{0x40,        0x0,             0x0,         60000,             20000,       &App_evt_mgr_ok_clock_ctr,         &App_evt_mgr_ng_clock_ctr,          NULL,          false},   //Clock Diag
{0x8B,        0x0,             0x0,         60000,             20000,       &App_evt_mgr_ok_5v_ref_ctr,        &App_evt_mgr_ng_5v_ref_ctr,         NULL,          false},   //5V ref diag
{0x10B,       0x0,             0x0,         60000,             20000,       &App_evt_mgr_ok_3_3v_ref_ctr,      &App_evt_mgr_ng_3_3v_ref_ctr,       NULL,          false},   //3.3V ref
{0x20B,       0x0,             0x0,         60000,             20000,       &App_evt_mgr_ok_1_5v_ref_ctr,      &App_evt_mgr_ng_1_5v_ref_ctr,       NULL,          false},   //1.5 V ref
{0x402,       0x0,             0x0,         60000,             20000,       &App_evt_mgr_ok_stack_ctr,         &App_evt_mgr_ng_stack_ctr,          NULL,          false},   //Stack overflow Diag
{0x0,         0x0,             0x0,         60000,             20000,       NULL,                              NULL,                               NULL,          false},   //Reserved
{0x0,         0x0,             0x0,         60000,             20000,       NULL,                              NULL,                               NULL,          false},   //Reserved
{0x240B,      0x0,             0x0,         60000,             20000,       &App_evt_mgr_ok_temp_sens_ctr,     &App_evt_mgr_ng_temp_sens_ctr,      NULL,          false},   //Temp Sens Diag
{0x440B,      0x0,             0x0,         60000,             20000,       &App_evt_mgr_ok_R_vtg_sens_ctr,    &App_evt_mgr_ng_R_vtg_sens_ctr,     NULL,          false},   //R phase Volt  sensor Diag
{0x840B,      0x0,             0x0,         60000,             20000,       &App_evt_mgr_ok_Y_vtg_sens_ctr,    &App_evt_mgr_ng_Y_vtg_sens_ctr,     NULL,          false},   //Y phase Volt  Sens Diag
{0x1040B,     0x0,             0x0,         60000,             20000,       &App_evt_mgr_ok_B_vtg_sens_ctr,    &App_evt_mgr_ng_B_vtg_sens_ctr,     NULL,          false},   //B phase Volt  Sens Diag
{0x2040B,     0x0,             0x0,         60000,             20000,       &App_evt_mgr_ok_R_curr_sens_ctr,   &App_evt_mgr_ng_R_curr_sens_ctr,    NULL,          false},   //R phase Curr Sens Diag
{0x4040B,     0x0,             0x0,         60000,             20000,       &App_evt_mgr_ok_Y_curr_sens_ctr,   &App_evt_mgr_ng_Y_curr_sens_ctr,    NULL,          false},   //Y phase Curr  Sens Diag
{0x8040B,     0x0,             0x0,         60000,             20000,       &App_evt_mgr_ok_B_curr_sens_ctr,   &App_evt_mgr_ng_B_curr_sens_ctr,    NULL,          false},   //B phase Curr Sens Diag
{0x10040B,    0x0,             0x0,         60000,             20000,       &App_evt_mgr_ok_E_vtg_sens_ctr,    &App_evt_mgr_ng_E_vtg_sens_ctr,     NULL,          false},   //Earth Volt  Sens Diag
{0x20040B,    0x0,             0x0,         60000,             20000,       &App_evt_mgr_ok_E_curr_sens_ctr,   &App_evt_mgr_ng_E_curr_sens_ctr,    NULL,          false},   //Earth Curr  Sens Diag
{0x40040B,    0x0,             0x0,         60000,             20000,       &App_evt_mgr_ok_R_arc_sens_ctr,    &App_evt_mgr_ng_R_arc_sens_ctr,     NULL,          false},   //R phase arcing sens Diag
{0x80040B,    0x0,             0x0,         60000,             20000,       &App_evt_mgr_ok_Y_arc_sens_ctr,    &App_evt_mgr_ng_Y_arc_sens_ctr,     NULL,          false},   //Y phase arcing sens Diag
{0x100040B,   0x0,             0x0,         60000,             20000,       &App_evt_mgr_ok_B_arc_sens_ctr,    &App_evt_mgr_ng_B_arc_sens_ctr,     NULL,          false},   //B phase arcing sens Diag
{0x0,         0x0,             0x0,         60000,             20000,       NULL,                              NULL,                               NULL,          false},   //Reserved
{0x0,         0x0,             0x0,         60000,             20000,       NULL,                              NULL,                               NULL,          false},   //Reserved
{0x0,         0x0,             0x0,         60000,             20000,       NULL,                              NULL,                               NULL,          false},   //Reserved
{0x470F,      0x9,             0x0,         60000,             20000,       &App_evt_mgr_ok_R_high_vtg_ctr,    &App_evt_mgr_ng_R_high_vtg_ctr,     NULL,          false},   //R phase  high voltage diag
{0x870F,      0x12,            0x0,         60000,             20000,       &App_evt_mgr_ok_Y_high_vtg_ctr,    &App_evt_mgr_ng_Y_high_vtg_ctr,     NULL,          false},   //Y phase  high voltage diag
{0x1070F,     0x24,            0x0,         60000,             20000,       &App_evt_mgr_ok_B_high_vtg_ctr,    &App_evt_mgr_ng_B_high_vtg_ctr,     NULL,          false},   //B phase  high voltage diag
{0x470F,      0x9,             0x0,         60000,             20000,       &App_evt_mgr_ok_R_low_vtg_ctr,     &App_evt_mgr_ng_R_low_vtg_ctr,      NULL,          false},   //R phase  low voltage diag
{0x870F,      0x12,            0x0,         60000,             20000,       &App_evt_mgr_ok_Y_low_vtg_ctr,     &App_evt_mgr_ng_Y_low_vtg_ctr,      NULL,          false},   //Y phase  low voltage diag
{0x1070F,     0x24,            0x0,         60000,             20000,       &App_evt_mgr_ok_B_low_vtg_ctr,     &App_evt_mgr_ng_B_low_vtg_ctr,      NULL,          false},   //B phase  low voltage diag
{0x470F,      0x249,           0x0,         60000,             20000,       &App_evt_mgr_ok_R_high_vtg_war_ctr,&App_evt_mgr_ng_R_high_vtg_war_ctr, NULL,          false},   //R phase  high voltage Warning
{0x870F,      0x492,           0x0,         60000,             20000,       &App_evt_mgr_ok_Y_high_vtg_war_ctr,&App_evt_mgr_ng_Y_high_vtg_war_ctr, NULL,          false},   //Y phase  high voltage Warning
{0x1070F,     0x924,           0x0,         60000,             20000,       &App_evt_mgr_ok_B_high_vtg_war_ctr,&App_evt_mgr_ng_B_high_vtg_war_ctr, NULL,          false},   //B phase  high voltage Warning
{0x470F,      0x249,           0x0,         60000,             20000,       &App_evt_mgr_ok_R_low_vtg_war_ctr, &App_evt_mgr_ng_R_low_vtg_war_ctr,  NULL,          false},   //R phase  low voltage Warning
{0x870F,      0x492,           0x0,         60000,             20000,       &App_evt_mgr_ok_Y_low_vtg_war_ctr, &App_evt_mgr_ng_Y_low_vtg_war_ctr,  NULL,          false},   //Y phase  low voltage Warning
{0x1070F,     0x924,           0x0,         60000,             20000,       &App_evt_mgr_ok_B_low_vtg_war_ctr, &App_evt_mgr_ng_B_low_vtg_war_ctr,  NULL,          false},   //B phase  low voltage Warning
{0x470F,      0x1000,          0x0,         60000,             20000,       &App_evt_mgr_ok_R_vtg_surge_ctr,   &App_evt_mgr_ng_R_vtg_surge_ctr,    NULL,          false},   //R phase voltage surge diag
{0x870F,      0x2000,          0x0,         60000,             20000,       &App_evt_mgr_ok_Y_vtg_surge_ctr,   &App_evt_mgr_ng_Y_vtg_surge_ctr,    NULL,          false},   //Y phase voltage surge diag
{0x1070F,     0x4000,          0x0,         60000,             20000,       &App_evt_mgr_ok_B_vtg_surge_ctr,   &App_evt_mgr_ng_B_vtg_surge_ctr,    NULL,          false},   //B phase voltage surge diag
{0x470F,      0x8000,          0x0,         60000,             20000,       &App_evt_mgr_ok_R_intrpt_war_ctr,  &App_evt_mgr_ng_R_intrpt_war_ctr,   NULL,          false},   //R phase voltage interruption Warning
{0x870F,      0x10000,         0x0,         60000,             20000,       &App_evt_mgr_ok_Y_intrpt_war_ctr,  &App_evt_mgr_ng_Y_intrpt_war_ctr,   NULL,          false},   //Y phase voltage interruption Warning
{0x1070F,     0x20000,         0x0,         60000,             20000,       &App_evt_mgr_ok_B_intrpt_war_ctr,  &App_evt_mgr_ng_B_intrpt_war_ctr,   NULL,          false},   //B phase voltage interruption Warning
{0x470F,      0x40000,         0x0,         60000,             20000,       &App_evt_mgr_ok_R_vtg_var_war_ctr, &App_evt_mgr_ng_R_vtg_var_war_ctr,  NULL,          false},   //R phase voltage variation Warning
{0x870F,      0x80000,         0x0,         60000,             20000,       &App_evt_mgr_ok_Y_vtg_var_war_ctr, &App_evt_mgr_ng_Y_vtg_var_war_ctr,  NULL,          false},   //Y phase voltage variation Warning
{0x1070F,     0x100000,        0x0,         60000,             20000,       &App_evt_mgr_ok_B_vtg_var_war_ctr, &App_evt_mgr_ng_B_vtg_var_war_ctr,  NULL,          false},   //B phase voltage variation Warning
{0x470F,      0x200000,        0x0,         60000,             20000,       &App_evt_mgr_ok_R_vtg_hrm_war,     &App_evt_mgr_ng_R_vtg_hrm_war,      NULL,          false},   //R phase high voltage harmonics Warning
{0x870F,      0x400000,        0x0,         60000,             20000,       &App_evt_mgr_ok_Y_vtg_hrm_war,     &App_evt_mgr_ng_Y_vtg_hrm_war,      NULL,          false},   //Y phase high voltage harmonics Warning
{0x1070F,     0x800000,        0x0,         60000,             20000,       &App_evt_mgr_ok_B_vtg_hrm_war,     &App_evt_mgr_ng_B_vtg_hrm_war,      NULL,          false},   //B phase high voltage harmonics Warning
{0x470F,      0x1000000,       0x0,         60000,             20000,       &App_evt_mgr_ok_R_phase_loss_ctr,  &App_evt_mgr_ng_R_phase_loss_ctr,   NULL,          false},   //R phase loss diag
{0x870F,      0x2000000,       0x0,         60000,             20000,       &App_evt_mgr_ok_Y_phase_loss_ctr,  &App_evt_mgr_ng_Y_phase_loss_ctr,   NULL,          false},   //Y phase loss diag
{0x1070F,     0x4000000,       0x0,         60000,             20000,       &App_evt_mgr_ok_B_phase_loss_ctr,  &App_evt_mgr_ng_B_phase_loss_ctr,   NULL,          false},   //B phase loss diag
{0x2070F,     0x8000000,       0x0,         60000,             20000,       &App_evt_mgr_ok_R_phase_curr_ctr,  &App_evt_mgr_ng_R_phase_curr_ctr,   NULL,          false},   //R phase High  curr diag
{0x4070F,     0x10000000,      0x0,         60000,             20000,       &App_evt_mgr_ok_Y_phase_curr_ctr,  &App_evt_mgr_ng_Y_phase_curr_ctr,   NULL,          false},   //Y phase High  curr diag
{0x8070F,     0x20000000,      0x0,         60000,             20000,       &App_evt_mgr_ok_B_phase_curr_ctr,  &App_evt_mgr_ng_B_phase_curr_ctr,   NULL,          false},   //B phase High  curr diag
{0x2070F,     0x40000000,      0x0,         60000,             20000,       &App_evt_mgr_ok_R_inrush_war_ctr,  &App_evt_mgr_ng_R_inrush_war_ctr,   NULL,          false},   //R phase Inrush curr Warning
{0x4070F,     0x0,             0x1,         60000,             20000,       &App_evt_mgr_ok_Y_inrush_war_ctr,  &App_evt_mgr_ng_Y_inrush_war_ctr,   NULL,          false},   //Y phase Inrush curr Warning
{0x8070F,     0x0,             0x2,         60000,             20000,       &App_evt_mgr_ok_B_inrush_war_ctr,  &App_evt_mgr_ng_B_inrush_war_ctr,   NULL,          false},   //B phase Inrush curr Warning
{0xE070F,     0x0,             0x4,         60000,             20000,       &App_evt_mgr_ok_R_curr_unbal_ctr,  &App_evt_mgr_ng_R_curr_unbal_ctr,   NULL,          false},   //R phase current Unbalance Warning
{0xE070F,     0x0,             0x8,         60000,             20000,       &App_evt_mgr_ok_Y_curr_unbal_ctr,  &App_evt_mgr_ng_Y_curr_unbal_ctr,   NULL,          false},   //Y phase current Unbalance Warning
{0xE070F,     0x0,             0x10,        60000,             20000,       &App_evt_mgr_ok_B_curr_unbal_ctr,  &App_evt_mgr_ng_B_curr_unbal_ctr,   NULL,          false},   //B phase current Unbalance warning
{0x2070F,     0x0,             0x20,        60000,             20000,       &App_evt_mgr_ok_R_curr_har_war_ctr,&App_evt_mgr_ng_R_curr_har_war_ctr, NULL,          false},   //R phase high current harmonics Warning
{0x4070F,     0x0,             0x40,        60000,             20000,       &App_evt_mgr_ok_Y_curr_har_war_ctr,&App_evt_mgr_ng_Y_curr_har_war_ctr, NULL,          false},   //Y phase high current harmonics Warning
{0x8070F,     0x0,             0x80,        60000,             20000,       &App_evt_mgr_ok_B_curr_har_war_ctr,&App_evt_mgr_ng_B_curr_har_war_ctr, NULL,          false},   //B phase high current harmonics Warning
{0x20070F,    0x0,             0x100,       60000,             20000,       &App_evt_mgr_ok_E_curr_ctr,        &App_evt_mgr_ng_E_curr_ctr,         NULL,          false},   //Earth High curr Diag
{0x10070F,    0x0,             0x200,       60000,             20000,       &App_evt_mgr_ok_E_vtg_ctr,         &App_evt_mgr_ng_E_vtg_ctr,          NULL,          false},   //Earth High Volt Diag
{0x2070F,     0x0,             0x400,       60000,             20000,       &App_evt_mgr_ok_R_short_ckt_ctr,   &App_evt_mgr_ng_R_short_ckt_ctr,    NULL,          false},   //R phase Short circuit diag
{0x4070F,     0x0,             0x800,       60000,             20000,       &App_evt_mgr_ok_Y_short_ckt_ctr,   &App_evt_mgr_ng_Y_short_ckt_ctr,    NULL,          false},   //Y phase Short circuit diag
{0x8070F,     0x0,             0x1000,      60000,             20000,       &App_evt_mgr_ok_B_short_ckt_ctr,   &App_evt_mgr_ng_B_short_ckt_ctr,    NULL,          false},   //B phase Short circuit diag
{0x427,       0x0,             0x2000,      60000,             20000,       &App_evt_mgr_ok_EEP_wrt_ctr,       &App_evt_mgr_ng_EEP_wrt_ctr,        NULL,          false},   //EEPROM Write Diag
{0x427,       0x0,             0x4000,      60000,             20000,       &App_evt_mgr_ok_EEP_read_ctr,      &App_evt_mgr_ng_EEP_read_ctr,       NULL,          false},   //EEPROM Read Diag
{0x413,       0x0,             0x8000,      60000,             20000,       &App_evt_mgr_ok_WiFi_comm_ctr,     &App_evt_mgr_ng_WiFi_comm_ctr,      NULL,          false},   //WiFi Comm Diag
{0x413,       0x0,             0x10000,     60000,             20000,       &App_evt_mgr_ok_WiFi_frame_ctr,    &App_evt_mgr_ng_WiFi_frame_ctr,     NULL,          false},   //WiFi frame error
{0x400407,    0x0,             0x20000,     60000,             20000,       &App_evt_mgr_ok_R_arc_ctr,         &App_evt_mgr_ng_R_arc_ctr,          NULL,          false},   //R phase Arcing Diag
{0x800407,    0x0,             0x40000,     60000,             20000,       &App_evt_mgr_ok_Y_arc_ctr,         &App_evt_mgr_ng_Y_arc_ctr,          NULL,          false},   //Y phase Arcing Diag
{0x1000407,   0x0,             0x80000,     60000,             20000,       &App_evt_mgr_ok_B_arc_ctr,         &App_evt_mgr_ng_B_arc_ctr,          NULL,          false},   //B phase Arcing Diag
{0x2470F,     0x0,             0x100000,    60000,             20000,       &App_evt_mgr_ok_R_low_PF_war_ctr,  &App_evt_mgr_ng_R_low_PF_war_ctr,   NULL,          false},   //R phase low Power Factor Warning
{0x4870F,     0x0,             0x200000,    60000,             20000,       &App_evt_mgr_ok_Y_low_PF_war_ctr,  &App_evt_mgr_ng_Y_low_PF_war_ctr,   NULL,          false},   //Y phase low Power Factor Warning
{0x9070F,     0x0,             0x400000,    60000,             20000,       &App_evt_mgr_ok_B_low_PF_war_ctr,  &App_evt_mgr_ng_B_low_PF_war_ctr,   NULL,          false},   //B phase low Power Factor Warning
{0x11C707,    0x0,             0x800000,    60000,             20000,       &App_evt_mgr_ok_neutral_loss_ctr,  &App_evt_mgr_ng_neutral_loss_ctr,   NULL,          false},   //Neutral Loss
{0x1C70F,     0x0,             0x800000,    60000,             20000,       &App_evt_mgr_ok_pwr_out_ctr,       &App_evt_mgr_ng_pwr_out_ctr,        NULL,          false},   //Power Outage
{0x1C70F,     0x0,             0x1000000,   60000,             20000,       &App_evt_mgr_ok_phase_rev_ctr,     &App_evt_mgr_ng_phase_rev_ctr,      NULL,          false}    //Phase Reverse

};


/*----------------------static function prototype----------------------- */


/*----------------------Function Definition-------------------------------*/
/*--------------------------------------------------------------------
 *  Function: uint32_t App_event_mgr_get_hdr_status(void)
 *
 *  Purpose: This is a wrapper function to get the status of the
 *           hardware events
 *
 *
 *  Parameters:
 *      Input parameters: none
 *
 *  Returns: The status of the hardware event
 -------------------------------------------------------------------*/
uint32_t App_event_mgr_get_hdr_status(void)
{
	return gu32_App_event_hdr_status;
}

/*--------------------------------------------------------------------
 *  Function: uint32_t App_event_mgr_get_system_status_1(void)
 *
 *  Purpose: This is a wrapper function to get the status of the
 *           system events
 *
 *
 *  Parameters:
 *      Input parameters: none
 *
 *  Returns: The status of the system event
 -------------------------------------------------------------------*/
uint32_t App_event_mgr_get_system_status_1(void)
{
	return gu32_App_event_system_status_1;
}

/*--------------------------------------------------------------------
 *  Function: uint32_t App_event_mgr_get_system_status_2(void)
 *
 *  Purpose: This is a wrapper function to get the status of the
 *           system events
 *
 *
 *  Parameters:
 *      Input parameters: none
 *
 *  Returns: The status of the system event
 -------------------------------------------------------------------*/
uint32_t App_event_mgr_get_system_status_2(void)
{
	return gu32_App_event_system_status_2;
}

/*--------------------------------------------------------------------
 *  Function: uint32_t App_evt_mgr_get_max_evt_no(void)
 *
 *  Purpose: This is a wrapper function to get the maximum number of events
 *
 *
 *  Parameters:
 *      Input parameters: none
 *
 *  Returns: max event number
 -------------------------------------------------------------------*/
uint32_t App_evt_mgr_get_max_evt_no(void)
{
	return (uint32_t)e_MAX_EVENT_NUMBER;
}



/*--------------------------------------------------------------------
 *  Function: uint32_t App_event_mgr_set_event(uint32_t lu32_App_event_mgr_var,
		                                uint32_t lu32_App_Event_Number)
 *
 *  Purpose: This function update the event variable status, i.e. set the event
 *           bit depending upon the event number
 *
 *  Parameters:
 *      Input parameters: event variable and event number
 *
 *  Returns: Updated event variable
 -------------------------------------------------------------------*/
static uint32_t App_event_mgr_set_event(uint32_t lu32_App_event_mgr_var,
		                                uint32_t lu32_App_Event_Number)
{
	return (lu32_App_event_mgr_var | (1u<<lu32_App_Event_Number));
}

/*--------------------------------------------------------------------
 *  Function: uint32_t App_event_mgr_reset_event(uint32_t lu32_App_event_mgr_var,
		                                uint32_t lu32_App_Event_Number)
 *
 *  Purpose: This function update the event variable status, i.e. reset the event
 *           bit depending upon the event number
 *
 *  Parameters:
 *      Input parameters: event variable and event number
 *
 *  Returns: Updated event variable
 -------------------------------------------------------------------*/
static uint32_t App_event_mgr_reset_event(uint32_t lu32_App_event_mgr_var,
		                                uint32_t lu32_App_Event_Number)
{
	return (lu32_App_event_mgr_var & (~(1u<<lu32_App_Event_Number)));
}



/*--------------------------------------------------------------------
 *  Function: void App_evt_mgr_update_event_status(uint32_t Event_number, uint8_t Event_state)
 *
 *  Purpose: This function set or reset the event status variables
 *
 *  Parameters:
 *      Input parameters: Event number
 *                        Event_state (EVENT_SET/EVENT_RESET)
 *
 *  Returns: none
 -------------------------------------------------------------------*/
void App_evt_mgr_update_event_status(uint32_t lu32_Event_Number, uint8_t lu8_Event_state)
{
	App_event_mgr_event_update_f App_event_mgr_event_update[2] =
	{
	  &App_event_mgr_reset_event,
	  &App_event_mgr_set_event,
	};



	if(lu32_Event_Number < MAX_HARDWARE_EVENT_NUMBER)
	{
		gu32_App_event_hdr_status = App_event_mgr_event_update[lu8_Event_state]
				                  (gu32_App_event_hdr_status,lu32_Event_Number);

	}
	else if(lu32_Event_Number < MAX_SYSTEM_EVENT_1_NUMBER)
	{
		gu32_App_event_system_status_1 =
		     App_event_mgr_event_update[lu8_Event_state]
			 (gu32_App_event_system_status_1,(lu32_Event_Number - MAX_HARDWARE_EVENT_NUMBER));

	}
	else
	{
		gu32_App_event_system_status_2 =
			App_event_mgr_event_update[lu8_Event_state]
		   (gu32_App_event_system_status_2,(lu32_Event_Number - MAX_SYSTEM_EVENT_1_NUMBER));
	}

}

/*--------------------------------------------------------------------
 *  Function:  Event_Manager_t* App_event_mgr_get_event_table_ref(uint32_t Event_number)
 *
 *  Purpose: This function returns the ref of the event table based on the
 *           event number
 *
 *  Parameters:
 *      Input parameters: None
 *
 *  Returns: ref of the event manager table
 -------------------------------------------------------------------*/

Event_Manager_t* App_event_mgr_get_event_table_ref(uint32_t lu32_Event_number)
{
     return &Event_Manager_Table[lu32_Event_number];
}
