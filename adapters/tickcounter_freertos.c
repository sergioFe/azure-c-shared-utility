// Copyright (C) Firmwave Ltd., All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdlib.h>
#ifdef _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

#include "azure_c_shared_utility/gballoc.h"

#include <stdint.h>
#include <time.h>
#include "azure_c_shared_utility/tickcounter.h"
#include "azure_c_shared_utility/xlogging.h"

#include "os_port.h"

typedef struct TICK_COUNTER_INSTANCE_TAG
{
    unsigned char dummy;
} TICK_COUNTER_INSTANCE;

TICK_COUNTER_HANDLE tickcounter_create(void)
{
    TICK_COUNTER_INSTANCE* result = (TICK_COUNTER_INSTANCE*)malloc(sizeof(TICK_COUNTER_INSTANCE));
    if (result == NULL)
    {
        LogError("Failed creating tick counter");
    }
    return result;
}

void tickcounter_destroy(TICK_COUNTER_HANDLE tick_counter)
{
    if (tick_counter != NULL)
    {
        free(tick_counter);
    }
}

int tickcounter_get_current_ms(TICK_COUNTER_HANDLE tick_counter, uint64_t* current_ms)
{
    int result;

    if (tick_counter == NULL || current_ms == NULL)
    {
        LogError("tickcounter failed: Invalid Arguments.\r\n");
        result = __LINE__;
    }
    else
    {
        *current_ms = (uint64_t)xTaskGetTickCount();
        result = 0;
    }

    return result;
}
