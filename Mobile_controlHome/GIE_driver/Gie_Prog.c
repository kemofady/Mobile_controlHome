/*
 *GIE
 *
 *      Author: karim fady
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Driver includes */
#include "GIE_Interface.h"
#include "GIE_Reg.h"
#include "GIE_Cfg.h"

void GIE_voidEnable(void)
{
	SET_BIT(SREG , SREG_I);
}

void GIE_voidDisable(void)
{
	CLR_BIT(SREG , SREG_I);
}



