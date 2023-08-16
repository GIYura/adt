#ifndef BUFFER_STATS_H
#define BUFFER_STATS_H

#include <stdbool.h>
#include <stdint.h>

#include "buffer.h"

typedef struct
{
    float value;
    uint32_t weight;
} BufferStats_WeightedData_t;

/**
 * @brief   Retrieves the minimum value from a basic-type buffer
 * @param   buffer: Handle to basic-type buffer (ie. float, uint8_t, uint16_t, uint32_t)
 * @return  minimum
 */
float BufferStats_GetMin(const Buffer* const buffer);

/**
 * @brief   Retrieves the maximum value from a basic-type buffer
 * @param   buffer: Handle to basic-type buffer (ie. float, uint8_t, uint16_t, uint32_t)
 * @return  maximum
 */
float BufferStats_GetMax(const Buffer* const buffer);

/**
 * @brief   Retrieves the median value from a basic-type buffer
 * @param   buffer: Handle to basic-type buffer (ie. float, uint8_t, uint16_t, uint32_t)
 * @return  median
 */
float BufferStats_GetMedian(const Buffer* const buffer);

/**
 * @brief   Retrieve the mean from a basic-type buffer
 * @param   buffer: Handle to basic-type buffer (ie. float, uint8_t, uint16_t, uint32_t)
 * @param   ignoreZeros: set true to ignore zero values; false otherwise [deprecated]
 * @return  average
 */
float BufferStats_GetMean(Buffer* const buffer, bool ignoreZeros);

/**
 * @brief   Retrieve the weighted mean from a buffer of type BufferStats_WeightedData_t
 * @param   buffer: Handle to buffer of type BufferStats_WeightedData_t
 * @param   ignoreZeros: set true to ignore zero values; false otherwise [deprecated]
 * @return  weighted mean
 */
float BufferStats_GetWeightedMean(Buffer* const buffer, bool ignoreZeros);

#endif /* BUFFER_STATS_H */

