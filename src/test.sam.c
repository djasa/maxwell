/*
 * Maxwell - A daemon to get entropy from timer randomness and feed it to
 * 	random(4)
 *
 * Copyright (C) 2012-2015 Sandy Harris <sandyinchina@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA  02110-1301, USA.
 */

#include "maxwell.h"
#include <assert.h>
#include <string.h>

#define OUTPUTS (128*1024)	// 128 k samples

int main(int argc, char **argv)
{
	int i, g, x ;
	if( (argc == 2) && !strcmp(argv[1], "-g") )
		g = 1 ;
	else	g = 0 ;
	for( i = 0 ; i < OUTPUTS ; i++ )	{
		usleep(97) ;		//default delay
		// get sample
		if( g )
			x = g31() ;	// microsecond timer
		else	x = t31() ;	// nanosecond
		// check it is in range
		assert( x > 0) ;
		assert( x < 32) ;
		// output as byte
		putchar( x ) ;
	}
	exit(0) ;
}
