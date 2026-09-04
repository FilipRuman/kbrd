#pragma once
#define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY

#define EE_HANDS
#define DEBUG
#define SPLIT_USB_DETECT
#define SPLIT_TRANSPORT_SERIAL
#define MASTER_LEFT
#define USE_SERIAL_PD2
#define USB_SUSPEND_WAKEUP_DELAY 0

#define SPI_DRIVER SPID0

#define SPI_SCK_PIN GP2
#define SPI_MOSI_PIN GP3
#define SPI_MISO_PIN GP4
#define PMW33XX_CS_PIN GP5

#define PMW33XX_MOTION_PIN GP6

// PMW33xx sensor configuration

// // Chip select on Pro Micro pin "9" (PB5)
// #define PMW33XX_CS_PIN B5
//
// // Optional reset pin on Pro Micro pin "8" (PB4)
// #define PMW33XX_RESET_PIN B4
//
// // Motion interrupt on Pro Micro pin "3" (PD1)
// #define PMW33XX_MOTION_PIN D0
//
// // Hardware SPI pins on ATmega32U4
// #define SPI_SCK_PIN B1
// #define SPI_MOSI_PIN B2
// #define SPI_MISO_PIN B3
//
// // Conservative SPI speed for bring-up/debugging
// #define PMW33XX_SPI_DIVISOR 64
//
// // Default CPI
// #define PMW33XX_CPI 800
//
// // Debug
// #define POINTING_DEVICE_DEBUG
