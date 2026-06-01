#pragma once
#define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY

#define EE_HANDS
// #define DEBUG
#define SPLIT_USB_DETECT
#define SPLIT_TRANSPORT_SERIAL
#define MASTER_LEFT
#define USE_SERIAL_PD2
#define USB_SUSPEND_WAKEUP_DELAY 0

// PMW33xx sensor configuration

#define PMW33XX_CS_PIN GP13

#define PMW33XX_RESET_PIN GP9

#define PMW33XX_MOTION_PIN GP12

#define SPI_SCK_PIN GP10
#define SPI_MOSI_PIN GP11
#define SPI_MISO_PIN GP8

// Conservative SPI speed for bring-up/debugging
#define PMW33XX_SPI_DIVISOR 256

#define RP_SPI_USE_SPI0 TRUE
#define RP_SPI_USE_SPI1 FALSE

// Default CPI
#define PMW33XX_CPI 800

// Debug
#define POINTING_DEVICE_DEBUG
