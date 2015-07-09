#!/bin/sh

~/toradex/gcc-linaro/bin/arm-linux-gnueabihf-gcc -I /media/psf/Home/projects/eGFX/SRC/ -I /media/psf/Home/projects/eGFX/SRC/Drivers -o test test.c eGFX.c Drivers/eGFX_Driver_LedMatrix.c
