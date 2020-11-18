/*
 * rd_sensor_tx.c
 *
 *  Created on: Sep 5, 2020
 *      Author: Smart5
 */

#include "../../proj_lib/sig_mesh/app_mesh.h"
#include "rd_sensor_tx.h"

void RD_Poll_SenData(void){

//	static u8 test_count = 0;
//	u8 SendDataCount[16];
//	sprintf(SendDataCount, "IS: %4d", test_count++);
//	mesh_tx_cmd2normal_primary(RD_OPCODE_RSP, SendDataCount, 8, 0x0001, 2);

	unsigned char i2c_rx_buff[BUFF_DATA_LEN] = {0xC6, 0x01};
	i2c_gpio_set(I2C_GPIO_GROUP_C0C1);
	i2c_master_init(0x44<<1, (unsigned char)(CLOCK_SYS_CLOCK_HZ/(4*I2C_CLK_SPEED)));
	i2c_write_series(0x01, 1, (unsigned char *)(i2c_rx_buff), 2);
	i2c_read_series(0x00, 1, (unsigned char *)(i2c_rx_buff), 2);

	float LuxConv;
	uint16_t Mantissa;
	uint16_t Exponent;
	Mantissa = ((uint16_t)(i2c_rx_buff[0]&0x0f)<<8) | (uint16_t)i2c_rx_buff[1];
	Exponent = (i2c_rx_buff[0]>>4)&0x0F;
	LuxConv = (float)(1<<Exponent) * (float)(Mantissa/100.0);
	u8 SendDataCount[10];
	my_sprintf(SendDataCount, "%d", (unsigned int)LuxConv);
	mesh_tx_cmd2normal_primary(RD_OPCODE_RSP, SendDataCount, 6, 0x0001, 2);

}

void RD_I2C_SenData(void){

	unsigned char i2c_rx_buff[BUFF_DATA_LEN] = {0xC6, 0x01};
	i2c_gpio_set(I2C_GPIO_GROUP_C0C1);
	i2c_master_init(0x44<<1, (unsigned char)(CLOCK_SYS_CLOCK_HZ/(4*I2C_CLK_SPEED)));
	i2c_write_series(0x01, 1, (unsigned char *)(i2c_rx_buff), 2);
	i2c_read_series(0x00, 1, (unsigned char *)(i2c_rx_buff), 2);

	mesh_tx_cmd2normal_primary(RD_OPCODE_RSP, i2c_rx_buff, BUFF_DATA_LEN, 0x0001, 2);
//
//	gpio_set_func(GPIO_LED, AS_GPIO);
//	gpio_set_output_en(GPIO_LED, 1);
//	gpio_set_input_en(GPIO_LED, 0);
//	gpio_write(GPIO_LED, 0);
}
