#ifndef __COMPASS_CONFIG_H__
#define __COMPASS_CONFIG_H__

/*	Defining the samples averaged per measurement output
	COMPASS_AVERAGE_SAMPLES can be defined with one of the following values:
	1) 1 sample averaged	-->		COMPASS_AVERAGE_SAMPLES_1
	2) 2 samples averaged	-->		COMPASS_AVERAGE_SAMPLES_2
	3) 4 samples averaged	-->		COMPASS_AVERAGE_SAMPLES_4
	4) 8 samples averaged	-->		COMPASS_AVERAGE_SAMPLES_8
	*/
#define COMPASS_AVERAGE_SAMPLES		COMPASS_AVERAGE_SAMPLES_1

/*	Defining the data output rate
	COMPASS_DATA_OUTPUT_RATE can be defined with one of the following values:
	1) 0.75 Hz				-->		COMPASS_DATA_OUTPUT_RATE_0_75
	2) 1.5 Hz				-->		COMPASS_DATA_OUTPUT_RATE_1_5
	3) 3 Hz					-->		COMPASS_DATA_OUTPUT_RATE_3
	4) 7.5 Hz				-->		COMPASS_DATA_OUTPUT_RATE_7_5
	5) 15 Hz				-->		COMPASS_DATA_OUTPUT_RATE_15
	6) 30 Hz				-->		COMPASS_DATA_OUTPUT_RATE_30
	7) 75 Hz				-->		COMPASS_DATA_OUTPUT_RATE_75
*/
#define COMPASS_DATA_OUTPUT_RATE	COMPASS_DATA_OUTPUT_RATE_15

/*	Defining the gain value
	The next table defines the recommended range with the gain
	-----------------------------------------------------------------------------
	|	Recommended Range (Ga)	|	Gain(LSB/Ga)	|	Resolution (mGa/LSB)	|	
	|---------------------------|-------------------|---------------------------|
	|		-0.88 to +0.88		|		1370		|			0.73			|
	|---------------------------|-------------------|---------------------------|

	|---------------------------|-------------------|---------------------------|
	
	|---------------------------|-------------------|---------------------------|
	
	|---------------------------|-------------------|---------------------------|
	
	|---------------------------|-------------------|---------------------------|
	
	|---------------------------|-------------------|---------------------------|
	
	|---------------------------|-------------------|---------------------------|
	
	|---------------------------|-------------------|---------------------------|
*/

#endif