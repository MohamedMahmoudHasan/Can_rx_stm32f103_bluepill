#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STK_Interface.h"
#include "STK_Config.h"
#include "STK_Private.h"

/* Define Callback Global Variable */
static void(*MSTK_CallBack)(void);
/*************************************************************************************/
                             /*****Functions Definitions********/
/**************************************************************************************/
void MSTK_voidInit(void)
{               
  
    //Disable STK , Disable STK Interrupt , Set Clock to AHB/8	
   STK->CTRL = STK_Init ;
	
}

void MSTK_voidSetBusyWait( u32 Copy_u32Ticks )
{
	/* Load ticks to load register */
	STK -> LOAD = Copy_u32Ticks;

	/* Start Timer */
	SET_BIT(STK->CTRL, 0);

	/* Wait till flag is raised */
	while( (GET_BIT(STK->CTRL,16)) == 0);

	/* Stop Timer */
	CLR_BIT(STK->CTRL, 0);
	STK -> LOAD = 0;
	STK -> VAL  = 0;

}

void STK_voidSetBusyWait(uint32 copy_DelayValue){      /*DELAY FUNCTION USING STK*/
	                           
	     STK->LOAD = copy_DelayValue; /*LOAD THE COUNTER VALUE BY US */
	
	    SET_BIT( STK->CTRL,STK_EN); /*ENABLE STK*/
	
	     while(WAIT_COUNT_FINISH){} /*WAIT TILL STK CURRENT VALUE COUNTER REACH TO ZERO*/
										
			  CLR_BIT( STK->CTRL,STK_EN); /*DISABLE STK*/
										
				                       /*WE PUT ZERO IN RELOAD AND CURRENT REGISTER TO BE READUY FOR NEXT DELAY */
			STK->LOAD  = 0;    
			STK->VAL = 0;   
				 
 }

void MSTK_voidSetIntervalSingle  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{ 
	
	//Load counter register by input ticks 																	 
	STK -> LOAD = Copy_u32Ticks;           
	
        // Start count
	SET_BIT(STK -> CTRL , EN);          
	
	// Save call back address
	MSTK_CallBack = Copy_ptr;             
	
	//Enable STK interrupt
	SET_BIT(STK -> CTRL , INT_EN);           
} 

void MSTK_voidStopInterval(void)          
{
	// Disable STK Interrupt
	CLR_BIT( STK -> CTRL , INT_EN);      
	
	// Stop timer
	CLR_BIT( STK -> CTRL , EN);         
	
	// Clear loaded register
	STK -> LOAD   = 0;
	
	// Clear value register
	STK -> VAL  = 0;            
}

void SysTick_Handler(void)  	
{
	//Disable interrupt
        CLR_BIT( STK -> CTRL , INT_EN);    
	
      //Stop timer
      SET_BIT( STK -> CTRL , EN);         
		
      // Clear loaded register
      STK -> LOAD = 0;  
	
     // Clear value register
     STK -> VAL  = 0;                
 		
      // Notify call back function	
      MSTK_CallBack();                 
	
}
