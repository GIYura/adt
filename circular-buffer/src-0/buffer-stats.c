#include "buffer-stats.h"

#include "assertion.h"
#include <stddef.h>
#include <stdlib.h>

#if !defined(TEST)
#include "arm_math.h"
#endif
#include "math.h"

/**
 * @brief   Compare function for qsort
 */
static int SortCompare(const void * a, const void * b)
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

#if !defined(TEST)
float BufferStats_GetMin( const Buffer* const buffer )
{
    float min = NAN;
    uint32_t count = Buffer_Count( buffer );
    if ( count > 0 )
    {
        uint32_t index;
        float array[count];
        Buffer_ToArray(buffer, array, count);
        arm_min_f32( array, count, &min, &index );
    }
    return min;
}

float BufferStats_GetMax( const Buffer* const buffer )
{
    float max = NAN;
    uint32_t count = Buffer_Count( buffer );
    if ( count > 0 )
    {
        uint32_t index;
        float array[count];

        Buffer_ToArray(buffer, array, count);
        arm_max_f32( array, count, &max, &index );
    }
    return max;
}
#endif

float BufferStats_GetMedian( const Buffer* const buffer )
{
    float median = 0.0;
    uint32_t count = Buffer_Count( buffer );
    if ( count != 0 )
    {
        float array[count];

        Buffer_ToArray(buffer, array, count);
        median = GetMedian(array, count);
    }
    return median;
}

float BufferStats_GetMean( Buffer* const buffer, bool ignoreZeros )
{
    float mean = 0.0;
    uint16_t count = Buffer_Count( buffer );
    uint16_t nonzeros = 0;  //number of nonzero samples (to be used for mean calculation)
    float total = 0.0;
    float array[count];

    Buffer_ToArray(buffer, array, count);
    for (uint8_t i = 0; i < count; i++)
    {
        if ( !ignoreZeros || array[i] != 0 )
        {
            total += array[i];
            nonzeros++;
        }
    }

    if ( nonzeros != 0 )
        mean = total / nonzeros;

    return mean;
}

float BufferStats_GetWeightedMean(Buffer* const buffer,  bool ignoreZeros )
{
    float mean = 0.0;
    uint16_t count = Buffer_Count( buffer );
    BufferStats_WeightedData_t array[count];

    Buffer_ToArray(buffer, array, count);

    /* Get total weight of buffer values */
    uint32_t weightTotal = 0;
    for (uint8_t i = 0; i < count; i++)
    {
       if ( !ignoreZeros || array[i].value != 0 )
           weightTotal += array[i].weight;
    }

    /* Get weighted mean of all values */
    for (uint8_t i = 0; i < count; i++)
    {
       if ( !ignoreZeros || array[i].value != 0 )
       {
           mean += array[i].value * ((float)array[i].weight / weightTotal);
       }
    }

    return mean;
}



