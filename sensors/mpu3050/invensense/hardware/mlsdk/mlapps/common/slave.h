/*
 $License:
    Copyright (C) 2010 InvenSense Corporation, All Rights Reserved.
 $
 */
/*******************************************************************************
 *
 * $Id: slave.h 5108 2011-03-31 16:49:11Z nroyer $
 *
 *******************************************************************************/

#ifndef SLAVE_H
#define SLAVE_H

/**
 *  @addtogroup SLAVEDL
 *
 *  @{
 *      @file     slave.h
 *      @brief    Top level descriptions for Accelerometer support
 *
 */

#include "mltypes.h"
#include "mpu.h"

    /* ------------ */
    /* - Defines. - */
    /* ------------ */

/*--- default accel support - selection ---*/
#define ACCEL_ST_LIS331                 0
#define ACCEL_KIONIX_KXTF9              1
#define ACCEL_BOSCH                     0
#define ACCEL_ADI                       0

#define ACCEL_SLAVEADDR_INVALID         0x00

#define ACCEL_SLAVEADDR_LIS331          0x18
#define ACCEL_SLAVEADDR_LSM303          0x18
#define ACCEL_SLAVEADDR_LIS3DH          0x18
#define ACCEL_SLAVEADDR_KXSD9           0x18
#define ACCEL_SLAVEADDR_KXTF9           0x0F
#define ACCEL_SLAVEADDR_BMA150          0x38
#define ACCEL_SLAVEADDR_BMA222          0x08
#define ACCEL_SLAVEADDR_ADI346          0x53
#define ACCEL_SLAVEADDR_ADI346_ALT      0x1D // alternative addr
#define ACCEL_SLAVEADDR_MMA8450         0x1C
#define ACCEL_SLAVEADDR_MMA845X         0x1C

#define ACCEL_SLAVEADDR_INVENSENSE      0x68
/*
    Define default accelerometer to use if no selection is made
*/
#if ACCEL_ST_LIS331
#define DEFAULT_ACCEL_SLAVEADDR           ACCEL_SLAVEADDR_LIS331
#define DEFAULT_ACCEL_ID                  ACCEL_ID_LIS331
#endif

#if ACCEL_ST_LSM303
#define DEFAULT_ACCEL_SLAVEADDR           ACCEL_SLAVEADDR_LSM303
#define DEFAULT_ACCEL_ID                  ACCEL_ID_LSM303
#endif

#if ACCEL_KIONIX_KXSD9
#define DEFAULT_ACCEL_SLAVEADDR           ACCEL_SLAVEADDR_KXSD9
#define DEFAULT_ACCEL_ID                  ACCEL_ID_KXSD9
#endif

#if ACCEL_KIONIX_KXTF9
#define DEFAULT_ACCEL_SLAVEADDR           ACCEL_SLAVEADDR_KXTF9
#define DEFAULT_ACCEL_ID                  ACCEL_ID_KXTF9
#endif

#if ACCEL_BOSCH
#define DEFAULT_ACCEL_SLAVEADDR           ACCEL_SLAVEADDR_BMA150
#define DEFAULT_ACCEL_ID                  ACCEL_ID_BMA150
#endif

#if ACCEL_BMA222
#define DEFAULT_ACCEL_SLAVEADDR           ACCEL_SLAVEADDR_BMA222
#define DEFAULT_ACCEL_ID                  ACCEL_ID_BMA222
#endif

#if ACCEL_ADI
#define DEFAULT_ACCEL_SLAVEADDR           ACCEL_SLAVEADDR_ADI346
#define DEFAULT_ACCEL_ID                  ACCEL_ID_ADI346
#endif

#if ACCEL_MMA8450
#define DEFAULT_ACCEL_SLAVEADDR           ACCEL_SLAVEADDR_MMA8450
#define DEFAULT_ACCEL_ID                  ACCEL_ID_MMA8450
#endif

#if ACCEL_MMA845X
#define DEFAULT_ACCEL_SLAVEADDR           ACCEL_SLAVEADDR_MMA845X
#define DEFAULT_ACCEL_ID                  ACCEL_ID_MMA845X
#endif

/*--- if no default accelerometer was selected ---*/
#ifndef DEFAULT_ACCEL_SLAVEADDR
#define DEFAULT_ACCEL_SLAVEADDR           ACCEL_SLAVEADDR_INVALID
#endif

#define USE_COMPASS_AICHI                  0
#define USE_COMPASS_AKM                    0
#define USE_COMPASS_YAS529                 0
#define USE_COMPASS_YAS530                 0
#define USE_COMPASS_HMC5883                0
#define USE_COMPASS_MMC314X                0
#define USE_COMPASS_MMC328X                1
#define USE_COMPASS_HSCDTD002B             0
#define USE_COMPASS_HSCDTD004A             0

#define COMPASS_SLAVEADDR_INVALID          0x00
#define COMPASS_SLAVEADDR_AKM_BASE         0x0C
#define COMPASS_SLAVEADDR_AKM              0x0E
#define COMPASS_SLAVEADDR_AMI304           0x0E
#define COMPASS_SLAVEADDR_AMI30X           0x0F /*Slave address for AMI 305/306*/
#define COMPASS_SLAVEADDR_YAS529           0x2E
#define COMPASS_SLAVEADDR_YAS530           0x2E
#define COMPASS_SLAVEADDR_HMC5883          0x1E
#define COMPASS_SLAVEADDR_MMC314X          0x30
#define COMPASS_SLAVEADDR_MMC328X          0x30
#define COMPASS_SLAVEADDR_HSCDTD00XX       0x0C

/*
    Define default compass to use if no selection is made
*/
 #if USE_COMPASS_AKM
 #define DEFAULT_COMPASS_TYPE              COMPASS_ID_AKM
 #endif

 #if USE_COMPASS_AICHI
 #define DEFAULT_COMPASS_TYPE              COMPASS_ID_AMI30X
 #endif

 #if USE_COMPASS_YAS529
 #define DEFAULT_COMPASS_TYPE              COMPASS_ID_YAS529
 #endif

 #if USE_COMPASS_YAS530
 #define DEFAULT_COMPASS_TYPE              COMPASS_ID_YAS530
 #endif

 #if USE_COMPASS_HMC5883
 #define DEFAULT_COMPASS_TYPE              COMPASS_ID_HMC5883
 #endif

#if USE_COMPASS_MMC314X
#define DEFAULT_COMPASS_TYPE              COMPASS_ID_MMC314X
#endif

#if USE_COMPASS_MMC328X
#define DEFAULT_COMPASS_TYPE              COMPASS_ID_MMC328X
#endif

#if USE_COMPASS_HSCDTD002B
#define DEFAULT_COMPASS_TYPE              COMPASS_ID_HSCDTD002B
#endif

#if USE_COMPASS_HSCDTD004A
#define DEFAULT_COMPASS_TYPE              COMPASS_ID_HSCDTD004A
#endif

#ifndef DEFAULT_COMPASS_TYPE                
#define DEFAULT_COMPASS_TYPE               ID_INVALID
#endif


#endif // SLAVE_H

/**
 *  @}
 */
