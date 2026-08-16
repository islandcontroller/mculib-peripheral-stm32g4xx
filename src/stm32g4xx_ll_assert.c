/*!****************************************************************************
 * @file
 * stm32g4xx_ll_assert.c
 *
 * @brief
 * Assert function
 *
 * @date  16.08.2026
 ******************************************************************************/

/*- Header files -------------------------------------------------------------*/
#include "stm32g4xx_ll_assert.h"


#ifdef USE_FULL_ASSERT
/*- Global Variables ---------------------------------------------------------*/
/// Assertion file name (debugger access)
volatile const char* LL_Assert_FileName = NULL;

/// Assertion line number (debugger access)
volatile uint32_t LL_Assert_LineNumber = 0u;


/*!*****************************************************************************
 * @brief
 * Assertion failure
 *
 * Set "ulContinue" variable to nonzero value in order to continue execution.
 * 
 * @param[in] pszFile Source file name
 * @param[in] ulLine  Source file line number
 * @date  16.08.2026
 ******************************************************************************/
__weak void LL_Assert_Failed(const char* pszFile, uint32_t ulLine)
{
  // Ensure file name and line number are saved
  LL_Assert_FileName = pszFile;
  LL_Assert_LineNumber = ulLine;

  // Trigger debugger breakpoint
  volatile uint32_t ulContinue = 0uL;
  __BKPT();

  // Endless loop until "continue" variable is set
  while(ulContinue == 0uL);
}
#endif // USE_FULL_ASSERT
