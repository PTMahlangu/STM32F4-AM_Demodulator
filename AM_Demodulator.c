
void AM_dem()
{
	__IO uint8_t uwADC1ConvertedValue;
	float OutputData[SAMPLES];                          /* Output filtered Data */

  	float temp[2*SAMPLES];
  	int i;

  	for (i = 0; i < 2*SAMPLES; i += 1){
		uwADC1ConvertedValue = (uhADCDualConvertedValue & 0x00FF);
		temp[i]=uwADC1ConvertedValue;
  ,temp,OutputData);

	
		if ((peak_value == 0) && ((temp[i]-hold)< 0)){
			 value = hold;
			 peak_value = 1;
		}
		if ((peak_value == 1) && ((temp[i]-hold)> 0)){
			 peak_value = 0;
		}
		hold = temp[i];
		TM_DAC_SetValue(TM_DAC2,10*value);
  	}
}