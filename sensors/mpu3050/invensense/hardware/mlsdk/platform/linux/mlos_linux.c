/*
 $License:
    Copyright (C) 2010 InvenSense Corporation, All Rights Reserved.
 $
 */
/*******************************************************************************
 *
 * $Id: mlos_linux.c 4736 2011-02-08 19:07:53Z mcaramello $
 *
 *******************************************************************************/

/**
 *  @defgroup MLOS
 *  @brief OS Interface.
 *
 *  @{
 *      @file mlos.c
 *      @brief OS Interface.
**/

/* ------------- */
/* - Includes. - */
/* ------------- */

#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#include "stdint_invensense.h"

#include "mlos.h"
#include <errno.h>


/* -------------- */
/* - Functions. - */
/* -------------- */

/**
 *  @brief  Allocate space
 *  @param  numBytes  number of bytes
 *  @return pointer to allocated space
**/
void *MLOSMalloc(unsigned int numBytes)
{
    // Allocate space.
    void *allocPtr = malloc(numBytes);
    return allocPtr;
}


/**
 *  @brief  Free allocated space
 *  @param  ptr pointer to space to deallocate
 *  @return error code.
**/
tMLError MLOSFree(void *ptr)
{
    // Deallocate space.
    free(ptr);

    return ML_SUCCESS;
}


/**
 *  @brief  Mutex create function
 *  @param  mutex   pointer to mutex handle
 *  @return error code.
 */
tMLError MLOSCreateMutex(HANDLE *mutex)
{
    int res;
    pthread_mutex_t *pm = malloc(sizeof(pthread_mutex_t));
    if(pm == NULL) 
        return ML_ERROR;

    res = pthread_mutex_init(pm, NULL);
    if(res == -1) {
        free(pm);
        return ML_ERROR_OS_CREATE_FAILED;
    }

    *mutex = (HANDLE)pm;

    return ML_SUCCESS;
}


/**
 *  @brief  Mutex lock function
 *  @param  mutex   Mutex handle
 *  @return error code.
 */
tMLError MLOSLockMutex(HANDLE mutex)
{
    int res;
    pthread_mutex_t *pm = (pthread_mutex_t*)mutex;

    res = pthread_mutex_lock(pm);
    if(res == -1) 
        return ML_ERROR_OS_LOCK_FAILED;

    return ML_SUCCESS;
}


/**
 *  @brief  Mutex unlock function
 *  @param  mutex   mutex handle
 *  @return error code.
**/
tMLError MLOSUnlockMutex(HANDLE mutex)
{
    int res;
    pthread_mutex_t *pm = (pthread_mutex_t*)mutex;

    res = pthread_mutex_unlock(pm);
    if(res == -1) 
        return ML_ERROR_OS_LOCK_FAILED;

    return ML_SUCCESS;
}


/**
 *  @brief  open file
 *  @param  filename    name of the file to open.
 *  @return error code.
 */
FILE *MLOSFOpen(char *filename)
{
    FILE *fp = fopen(filename,"r");
    return fp;
}


/**
 *  @brief  close the file.
 *  @param  fp  handle to file to close.
 *  @return error code.
 */
void MLOSFClose(FILE *fp)
{
    fclose(fp);
}

/**
 *  @brief  Close Handle
 *  @param  handle  handle to the resource.
 *  @return Zero if success, an error code otherwise.
 */
tMLError MLOSDestroyMutex(HANDLE handle)
{
    int error;
    pthread_mutex_t *pm = (pthread_mutex_t*)handle;
    error = pthread_mutex_destroy(pm);
    if (error) {
        return errno;
    }
    free((void*) handle);
    
    return ML_SUCCESS;}


/**
 *  @brief  Sleep function.
 */
void MLOSSleep(int mSecs)
{
    usleep(mSecs*1000);
}


/**
 *  @brief  get system's internal tick count.
 *          Used for time reference.
 *  @return current tick count.
 */
unsigned long MLOSGetTickCount()
{
    struct timeval tv;

    if (gettimeofday(&tv, NULL) !=0)
        return 0;

    return (long)((tv.tv_sec * 1000000LL + tv.tv_usec) / 1000LL);
}

  /**********************/
 /** @} */ /* defgroup */
/**********************/

