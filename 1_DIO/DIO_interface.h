/*****************************************************************/
/*****************************************************************/
/* Author: 	Ahmed Mohsen	                                     */
/* Layer: 	MCAL		                                         */
/* SWC: 	DIO			                                         */
/* Date: 	24-5-2022	                                         */
/* Version: 1.00		                                         */
/*****************************************************************/
/*****************************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


/*****************************************************************/
/* name             : 	DIO_u8SetPinDirection	                 */
/* discription      : 	set pin direction	                     */
/* parameter 1      : 	Copy_u8Port -> port name		         */
/* parameter 2      :	Copy_u8Pin  -> pin number	             */
/* parameter 3      :   Copy_u8Direction  -> input or output     */
/* Return           :   u8 indication for error		             */
/*****************************************************************/
u8 DIO_u8SetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin, u8 Copy_u8Direction);

/*****************************************************************/
/* name             : 	DIO_u8SetPortDirection	                 */
/* discription      : 	set port direction	                     */
/* parameter 1      : 	Copy_u8Port -> port name (a,b,c,d)		 */
/* parameter 3      :   Copy_u8Direction  -> input or output     */
/* Return           :   u8 indication for error		             */
/*****************************************************************/
u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);


/*****************************************************************/
/* name             : 	DIO_u8SetPinValue	                 */
/* discription      : 	set pin value high or low	                     */
/* parameter 1      : 	Copy_u8Port -> port name		         */
/* parameter 2      :	Copy_u8Pin  -> pin number	             */
/* parameter 3      :   Copy_u8Value  -> high or low     */
/* Return           :   u8 indication for error		             */
/*****************************************************************/
u8 DIO_u8SetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin, u8 Copy_u8Value);


/*****************************************************************/
/* name             : 	DIO_u8SetPortValue	                 */
/* discription      : 	set port value 0xFF or 0x00                   */
/* parameter 1      : 	Copy_u8Port -> port name		         */
/* parameter 3      :   Copy_u8Value  -> high or low     */
/* Return           :   u8 indication for error		             */
/*****************************************************************/
u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);


/*****************************************************************/
/* name             : 	DIO_u8GetPinValue	                 */
/* discription      : 	get pin value high or low	                     */
/* parameter 1      : 	Copy_u8Port -> port name		         */
/* parameter 2      :	Copy_u8Pin  -> pin number	             */
/* parameter 3      :   Copy_pu8Value  -> returned value     */
/* Return           :   u8 indication for error		                */
/*****************************************************************/
u8 DIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin, u8* Copy_pu8Value);

#endif
