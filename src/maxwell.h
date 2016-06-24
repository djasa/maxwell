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

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

typedef unsigned u32 ;

/* forward declarations of functions */

u32 qht(u32) ;
u32 idea(u32,u32) ;

u32 t5() ;
u32 t7() ;
u32 t31() ;
u32 t255() ;

u32 g5() ;
u32 g7() ;
u32 g31() ;
u32 g255() ;

u32 gpar() ;
u32 tpar() ;

u32 parity(u32) ;

void error_exit(const char *) ;
void message(const char *) ;
