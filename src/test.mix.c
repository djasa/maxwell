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

#define LIMIT (256*1024)	// a megabyte of output

#define MUL (71+(37<<12)+(11<<19))

int main( int argc, char **argv)
{
	u32 a, b, x ;
	int i, j, k ;
	// test maxwell's mixing
	// x is an overall counter
	for( i = 0, x = 0 ; i < LIMIT ; i++ )	{
		a = 0 ;
		for( j = 0; j < 3 ; j++ )	{
			// increment x as well as k
			for( k = 0 ; k < 16 ; k++, x++ )	{
				// all the sampling replaced
				// by the counter x
				b = (x % 31) + 1 ;
				// mixing is like maxwell
				a += b * MUL ;
				// rotate left by two bits
				b = a >> 30 ;
				a = (a << 2) | b ;
			}
			// rotate left one bit
			b = a >> 31 ;
			a = (a << 1) | b ;
		}
		// write to stdout
		write(1, &a, 4) ;
	}
	exit(0) ;
}
