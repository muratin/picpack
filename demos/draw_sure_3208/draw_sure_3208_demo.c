//-----------------------------------------------------
// Pic Pack library
// 
// draw_sure_3208_demo.c
//
// Demonstration routines showing the draw library
// used with the Sure Electronics 3208 board
//
// Ian Harris 2009
// imharris [at] gmail.com
//
// Released under the "do whatever you like with this
// but if you use it send me an email" license. Oh, and
// if it breaks, you get to keep both pieces.
//-----------------------------------------------------

// Pic Pack includes
#include "config.h"
#include "pic_utils.h"
#include "pic_serial.h"

#include "draw\draw.h"
// System includes
#include "string.h"
#include "stdlib.h"
#include "ht1632.h"
#include "draw\draw_screen_buffer.h"

// max and min temps


// Interrupt routine - - - - - - - - - -
void interrupt() {
	
	serial_handle_tx_isr();
	serial_handle_rx_isr();
}


// configure_system
//
// Get the pic ready for everything we want to do

void configure_system() {
	    
	kill_interrupts();	// turn off interrupts just in case

	turn_analog_inputs_off();	// kill those pesky analogue inputs
	
	
	serial_setup(BRGH_HIGH_SPEED, SPBRG_19200);

	turn_peripheral_ints_on();
	turn_global_ints_on();

	draw_setup_io();
	draw_init();

}




void main() {

		
	configure_system();

	delay_ms(100);

	serial_print_str("\n\nPicPack Sure 3208 Led display demo\n");
	serial_print_str( "\n<");
	serial_print_str(__TIME__);
	serial_putc(' ');
	serial_print_str(__DATE__);
	serial_print_str(">\n");
	
	while (1) {
		/*delay_ms(250);
		
		draw_set_pixel(0,0,1);
		draw_paint();
		
		delay_s(1);
		draw_set_pixel(23,0,1);
		draw_paint();
		
		delay_s(1);
		draw_set_pixel(23,15,1);
		draw_paint();

		delay_s(1);
		draw_set_pixel(0,15,1);
		draw_paint();

		delay_s(1);
		draw_set_pixel(0,0,0);
		draw_paint();

		delay_s(1);
		draw_set_pixel(23,0,0);
		draw_paint();
		
		delay_s(1);
		draw_set_pixel(23,15,0);
		draw_paint();

		delay_s(1);
		draw_set_pixel(0,15,0);
		draw_paint();

		delay_s(1);
		draw_line(0, 0, 23, 15, 1);
		draw_paint();

		delay_s(1);
		draw_line(0, 15, 23, 0, 1);
		draw_paint();

		delay_s(1);
		draw_line(0, 0, 23, 15, 0);
		draw_paint();

		delay_s(1);
		draw_line(0, 15, 23, 0, 0);
		draw_paint();

		delay_s(1);
		draw_circle(12, 8, 1, 1);
		draw_paint();

		delay_s(1);
		draw_circle(12, 7, 2, 1);
		draw_paint();

		delay_s(1);
		draw_circle(12, 7, 3, 1);
		draw_paint();

		delay_s(1);
		draw_circle(12, 7, 4, 1);
		draw_paint();
		delay_s(1);
		draw_circle(12, 7, 5, 1);
		draw_paint();
		delay_s(1);
		draw_circle(12, 7, 6, 1);
		draw_paint();
		delay_s(1);
		draw_circle(12, 7, 7, 1);
		draw_paint();
		
		delay_s(1);*/
		draw_clear_screen();

		draw_set_pixel(0,0,1);
		draw_paint();
		
		delay_s(1);
		draw_set_pixel(31,0,1);
		draw_paint();
		
		delay_s(1);
		draw_set_pixel(31,7,1);
		draw_paint();

		delay_s(1);
		draw_set_pixel(0,7,1);
		draw_paint();
		delay_s(1);
		
		draw_clear_screen();

		draw_rect(1, 1, 30, 6, 1);
		draw_paint();
		delay_s(1);
		
		draw_circle(16, 4, 3, 0);
		draw_paint();
		delay_s(1);
		draw_clear_screen();
		uns8 x, width, count, start_pos;
		for (count = 0; count < 80; count++) {

			if (count < 32) {
				x = 31 - count;
				width = count + 1;
				start_pos  = 0;
			} else {
					start_pos = count - 31;
					width = 31;
					x = 0;
			}	
			draw_clear_screen();
			draw_print_str(x, 7, width, start_pos, /* colour */ 1, "Interesting!");
			draw_paint();
			delay_ms(75);
	
		}	
		delay_s(1);
		draw_clear_screen();
		

	}
	
}	// main

