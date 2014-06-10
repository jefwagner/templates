/*!*******************************************************************
 * \author Your Name
 * \email your_email@example.com
 *********************************************************************
 * Short file description.
 *
 * Long file description.
 */
#include <stdio.h>

#include "c_programe_template.c"

/*!
 * get_message test.
 *
 * This function calls get message, confirms that the message is
 * valid, and confirms that it matches the expected "Hello World!"
 */
void get_message_test(){
  int status;
  message m;
  fprintf( stdout, "Testing get_message: ");
  m = get_message();
  if( m.is_valid == yes ){
    status++;
  }
  if( strcmp( m.message, "Hello World!\n")){
    status++;
  }
  if( status == 0){
    fprintf( stdout, "pass\n");
  }else{
    fprintf( stdout, "fail\n");
  }
}

/*!
 * run all the test
 */
int main(){
  get_message_test();
  return 0;
}