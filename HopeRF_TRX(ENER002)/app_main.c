#include "app_main.h"
#include "dev_HRF.h"
#include <stdio.h>
#include <string.h>
#include <bcm2835.h>
#include <stdbool.h>
uint8_t relayState;

int main(int argc, char **argv){
	if (!bcm2835_init())
		return 1;

	// SPI INIT
	bcm2835_spi_begin();
	bcm2835_spi_setClockDivider(SPI_CLOCK_DIVIDER_26); 			// 250MHz / 26 = 9.6MHz
	bcm2835_spi_setDataMode(BCM2835_SPI_MODE0); 				// CPOL = 0, CPHA = 0
	bcm2835_spi_chipSelect(BCM2835_SPI_CS1);					// chip select 1

	HRF_config_FSK();
	HRF_wait_for(ADDR_IRQFLAGS1, MASK_MODEREADY, true);			// wait until ready after mode switching
	HRF_clr_fifo();


	printf("send LEGACY message:\t");
	static bool switchState = false;
	switchState = !switchState;
	bcm2835_gpio_write(LEDR, switchState);

	// THE MAGIC LINE
	relayState = 0;												//0 = s1 on, 1 = s1 off, 2 = s2 on, 3 = s2 off (I think)
	// END MAGIC LINE

	HRF_send_OOK_msg(relayState);

	bcm2835_spi_end();
	return 0;
}