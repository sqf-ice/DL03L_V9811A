/*
*****************Copyright (c)*************************************
**      Hangzhou Xili Watthour Meter Manufacture Co., Ltd. 
**--------------file info--------------------------------------------
**name			: Drv_KEY_IO.c
**Author		: maji
**date			: 2016-04-20 
**description	: MCU KEYL类似内核模块的硬件驱动C代码
**note			: V9811A ，MERTER FOR DL03C
**--------------------Version History -------------------------------------
** NO. Date         Ver      By         Description 
**==============================================================
** 1   2016-04-26   v01.00   sosomj     1. frist version                             
**
**==============================================================
*/

#include <MyIncludes_H.h>


/*******************************************************************************************
** 函数名称: Judge_PRO_key
** 函数描述: 判断编程清零口电平状态
** 输入参数: =TRUE 编程口短接有效；=FALSE 编程口未短接
** 输出参数: 无 
** 说明    : 短接电平为0，未短接为1
*******************************************************************************************/
uint8 Judge_PRO_key(void)
{
	uint8 i;

	KEY_PROG_INITLIZE();
	for(i=0;i<10;i++)
	{
		if(KEY_READ_PROG != FALSE)   break;
	}

	if(i>7)
	{
		return (TRUE); 
	}
	else
	{
		return(FALSE);
	}
                       
}                  


uint8 Judge_ERR_COVER_key(void)
{
	uint8 i;
  KEY_ERR_COVER_INITLIZE() ;	
	Lib_Delay_ms(2);
	for(i=0;i<10;i++)
	{
		if(KEY_READ_ERR_COVER != FALSE)   break;
	}

	if(i>7)
	{
		
		return (TRUE); 
	}
	else
	{			
		return(FALSE);
	}
                       
} 


/*******************************************************************************************
** 函数名称: Judge_DIS_key
** 函数描述: 判断显示口电平状态
** 输入参数: =TRUE 按键按下有效；=FALSE 按键按下无效
** 输出参数: 无 
** 说明    : 短接电平为0，未短接为1
*******************************************************************************************/
uint8 Judge_DIS_key(void)
{
	uint8 i;

	//KEY_DIS_INITLIZE();
	for(i=0;i<10;i++)
	{
		if(KEY_READ_DIS() != FALSE)   break;
	}

	if(i>7)
	{
		return (TRUE); 
	}
	else
	{
		return(FALSE);
	}
                       
}                  


/*******************************************************************************************
** 函数名称: Judge_ERR_ADJ_key
** 函数描述: 判断硬件校表短接点电平状态
** 输入参数: =TRUE 短接有效；=FALSE 未短接
** 输出参数: 无 
** 说明    : 短接电平为0，未短接为1
*******************************************************************************************/
uint8 Judge_ERR_ADJ_key(void)
{
	uint8 i;

	KEY_ERR_ADJ_INITLIZE();
	for(i=0;i<10;i++)
	{
		if(KEY_READ_ERR_ADJ != FALSE)   break;
	}

	if(i>7)
	{
		return (TRUE); 
	}
	else
	{
		return(FALSE);
	}
                       
}                  


/*******************************************************************************************
**    END
*******************************************************************************************/
