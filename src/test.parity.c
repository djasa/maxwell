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

void one_output() ;

int g, q ; // flags

int main(int argc, char **argv)
{
	int i, limit, forever ;
	// set defaults
	g = 0 ;
	q = 0 ;
	forever = 0 ;
	limit = 256*1024 ;	// 256 K 32-bit -> one megabyte
	for( argc--, argv++ ; argc ; argc--, argv++ )	{
		if( !strcmp(*argv, "-g") )
			g = 1 ;
		if( !strcmp(*argv, "-f") )
			forever = 1 ;
	}
	if( forever )
		// infinite loop
		for( ; ; )
			one_output() ;
	else
		// a megabyte
		for( i = 0 ; i < limit ; i++ )
			one_output() ;
	exit(0) ;
}

void one_output()
{
	int i ;
	unsigned x, y ;
	// minimum delay
	usleep(1) ;
	// for each bit position
	for( i = 0, y = 0 ; i < 32 ; i++, y <<= 1 )	{
		// get samples
		if( g )
			x = gpar() ;	// microsecond timer
		else	x = tpar() ;	// nanosecond
		y |= x ;
	}
	// output four bytes
	write( 1, &y, 4 ) ;
}
