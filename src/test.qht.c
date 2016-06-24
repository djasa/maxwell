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

#define LIMIT (32*1024)	// a megabit of output

int main( int argc, char **argv)
{
	u32 a ;
	int i;
	// test outer loop of maxwell
	for( i = 0 ; i < LIMIT ; i++ )	{
		// all the sampling replaced
		a = qht(i) ;
		// write to stdout
		write(1, &a, 4) ;
	}
	exit(0) ;
}
