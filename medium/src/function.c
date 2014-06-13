/*!*******************************************************************
 * \author Your Name
 * \email your_email@example.com
 *********************************************************************
 * Short file description.
 *
 * Long file description.
 */
#include <string.h>

#include "dep.h"

/*!
 * Return a "Hello World!" message.
 *
 * This function simply returns a hello world message.
 */
message get_message(){
  message m;
  m.is_valid = yes;
  strcpy( m.message, "Hello World!\n");
  return m;
}
