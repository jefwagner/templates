/*!*******************************************************************
 * \author Your Name
 * \email your_email@example.com
 *********************************************************************
 * Short file description.
 *
 * Long file description.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dep.h"

/*!
 * Short description.
 *
 * This is a more in depth description of the programe. It can go on
 * for multiple lines, and include things like
 * - List,
 * - Inline equations \f$ \nabla \phi = 0 \f$,
 * - Displayed equations 
 *
 *  \f[ 
 *    \int_a^b \!\! \text{d}x \; 
 *    \frac{\partial}{\partial x} F(x) = 
 *    F(b)-F(a).
 *  \f]
 */
int main( int argc, char **argv){
  int i, n;
  message m;

  if( argc !=2 ){
    fprintf( stderr, "usage: %s num\n", argv[0]);
    return 1;
  }
  n = atoi( argv[1]);

  m = get_message();
  for( i=0; i<n; i++){
    if( m.is_valid == yes ){
      printf( "%s", m.message);
    }
  }

  return 0;
}