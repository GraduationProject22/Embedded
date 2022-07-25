#ifndef __COMPASS_H__
#define __COMPASS_H__

/*Includes*/

#include "compass_reg.h"
#include "compass_config.h"

/*End of includes*/

/*Exported constants*/

#define COMPASS_ADDR		0x3C

#define COMPASS_AVERAGE_SAMPLES_1	0x00UL
#define COMPASS_AVERAGE_SAMPLES_2	0x01UL
#define COMPASS_AVERAGE_SAMPLES_4	0x02UL
#define COMPASS_AVERAGE_SAMPLES_8	0x03UL

#define COMPASS_DATA_OUTPUT_RATE_0_75	0x00UL
#define COMPASS_DATA_OUTPUT_RATE_1_5	0x01UL
#define COMPASS_DATA_OUTPUT_RATE_3		0x02UL
#define COMPASS_DATA_OUTPUT_RATE_7_5	0x03UL
#define COMPASS_DATA_OUTPUT_RATE_15		0x04UL
#define COMPASS_DATA_OUTPUT_RATE_30		0x05UL
#define COMPASS_DATA_OUTPUT_RATE_75		0x06UL



/*End of exported constants*/

#endif