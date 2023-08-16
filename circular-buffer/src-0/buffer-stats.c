#include "buffer-stats.h"

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief   Compare function for qsort
 */
static int SortCompare(const void* a, const void* b)
{
    const float aFloat = *(float *) a;
    const float bFloat = *(float *) b;
    return (aFloat > bFloat) - (aFloat < bFloat);
}

/**
 * @brief   Helper Function that gets median from an array
 * @param   array: Array to examine
 * @param   size:  Size of the array
 * @return  median
 */
static float GetMedian(float* array, uint32_t size)
{
    qsort(array, size, sizeof(float), SortCompare);
    uint32_t mid = size / 2;
    float median;

    if ( size % 2 == 1 )
       median = array[mid];
    else
       median = (array[mid] + array[mid - 1]) / 2;

    return median;
}

float BufferStatsGetMin(const Buffer_t* const buffer)
{
    float min = NAN;
    uint32_t count = BufferCount(buffer);
    if (count > 0)
    {
        uint32_t index;
        float array[count];
        BufferToArray(buffer, array, count);
/*TODO: */
#if 0
        arm_min_f32( array, count, &min, &index );
#endif
    }
    return min;
}

float BufferStatsGetMax(const Buffer_t* const buffer)
{
    float max = NAN;
    uint32_t count = BufferCount(buffer);
    if (count > 0)
    {
        uint32_t index;
        float array[count];

        BufferToArray(buffer, array, count);
/* TODO: */
#if 0
        arm_max_f32( array, count, &max, &index );
#endif
    }
    return max;
}

float BufferStatsGetMedian(const Buffer_t* const buffer)
{
    float median = 0.0;
    uint32_t count = BufferCount(buffer);
    if (count != 0)
    {
        float array[count];

        BufferToArray(buffer, array, count);
        median = GetMedian(array, count);
    }
    return median;
}

float BufferStatsGetMean(Buffer_t* const buffer, bool ignoreZeros)
{
    float mean = 0.0;
    uint16_t count = BufferCount(buffer);
    uint16_t nonzeros = 0;  //number of nonzero samples (to be used for mean calculation)
    float total = 0.0;
    float array[count];

    BufferToArray(buffer, array, count);
    for (uint8_t i = 0; i < count; i++)
    {
        if (!ignoreZeros || array[i] != 0)
        {
            total += array[i];
            nonzeros++;
        }
    }

    if (nonzeros != 0)
        mean = total / nonzeros;

    return mean;
}

float BufferStats_GetWeightedMean(Buffer_t* const buffer,  bool ignoreZeros)
{
    float mean = 0.0;
    uint16_t count = BufferCount(buffer);
    BufferStats_WeightedData_t array[count];

    BufferToArray(buffer, array, count);

    /* Get total weight of buffer values */
    uint32_t weightTotal = 0;
    for (uint8_t i = 0; i < count; i++)
    {
       if (!ignoreZeros || array[i].value != 0)
           weightTotal += array[i].weight;
    }

    /* Get weighted mean of all values */
    for (uint8_t i = 0; i < count; i++)
    {
       if (!ignoreZeros || array[i].value != 0)
       {
           mean += array[i].value * ((float)array[i].weight / weightTotal);
       }
    }
    return mean;
}

