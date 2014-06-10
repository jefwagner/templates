/*!*******************************************************************
 * \author Your Name
 * \email your_email@example.com
 *********************************************************************
 * Short file description.
 *
 * Long file description.
 */
#ifndef JW_TEMPLATE_HEADER
#define JW_TEMPLATE_HEADER

/*!
 * A enum for yes or no answers.
 */
typedef enum{
  yes, no
} yesno;

/*!
 * The message structure.
 *
 * The message structure needs be able to indicate if a message is
 * valid, and hold a c string of the message.
 */
typedef struct{
  yesno is_valid;
  char message[80];
} message;

/*!
 * get_message prototype.
 *
 * This function returns a message.
 */
message get_message();

#endif