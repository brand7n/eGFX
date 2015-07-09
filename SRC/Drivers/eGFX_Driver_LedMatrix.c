#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

#include "eGFX_DataTypes.h"
#include "eGFX.h"
#include "eGFX_Driver_LedMatrix.h"

static const char *device = "/dev/spidev32766.0";
static uint32_t mode;
static uint8_t bits = 8;
static uint32_t speed = 500000;
static uint16_t delay = 0;
int fd;

#define SIZE (eGFX_CALCULATE_8BPP_IMAGE_STORAGE_SPACE_SIZE(eGFX_PHYSICAL_SCREEN_SIZE_X, eGFX_PHYSICAL_SCREEN_SIZE_Y))
eGFX_ImagePlane eGFX_BackBuffer;

uint8_t BackBufferStore[SIZE];
uint8_t rxbuf[SIZE];
uint8_t cmdbuf[100];

static void transfer(int fd, uint8_t const *tx, uint8_t const *rx, size_t len)
{
	int ret;

	struct spi_ioc_transfer tr = {
		.tx_buf = (unsigned long)tx,
		.rx_buf = (unsigned long)rx,
		.len = len,
		.delay_usecs = delay,
		.speed_hz = speed,
		.bits_per_word = bits,
	};

	ret = ioctl(fd, SPI_IOC_MESSAGE(1), &tr);
	printf("transfer %d\r\n", ret);
}

void eGFX_InitDriver()
{
	int ret;

	eGFX_ImagePlaneInit(&eGFX_BackBuffer, BackBufferStore, eGFX_PHYSICAL_SCREEN_SIZE_X, eGFX_PHYSICAL_SCREEN_SIZE_Y, eGFX_IMAGE_PLANE_8BPP);
	fd = open(device, O_RDWR);
	printf("open %d\r\n", fd);
	ret = ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits);
	printf("bits %d\r\n", ret);
	ret = ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
	printf("speed %d\r\n", ret);
}

void eGFX_Dump(eGFX_ImagePlane *Image)
{
	cmdbuf[0] = 'w';
	cmdbuf[1] = 0;
	cmdbuf[2] = 0;
	cmdbuf[3] = (0xff00 & SIZE) >> 8;
	cmdbuf[4] = (0x00ff & SIZE);
	transfer(fd, cmdbuf, rxbuf, 5);
	transfer(fd, BackBufferStore, rxbuf, SIZE);
}

