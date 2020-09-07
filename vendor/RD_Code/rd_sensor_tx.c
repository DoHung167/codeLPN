/*
 * rd_sensor_tx.c
 *
 *  Created on: Sep 5, 2020
 *      Author: Smart5
 */

#include "../../proj_lib/sig_mesh/app_mesh.h"

void RD_Poll_SenData(void){
	static u8 test_count = 0;
	u8 SendDataCount[16];
	sprintf(SendDataCount, "IS: %4d", test_count++);
	mesh_tx_cmd2normal_primary(RD_OPCODE_RSP, SendDataCount, 8, 0x0001, 2);
}
