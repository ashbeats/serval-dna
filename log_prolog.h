/*
Serval DNA log prolog
Copyright (C) 2017 Flinders University
 
This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.
 
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
 
You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef __SERVAL_DNA__LOG_PROLOG_H
#define __SERVAL_DNA__LOG_PROLOG_H

#include "trigger.h"

/* Whenever a log output starts a new log, such as opening the console for the
 * first time or rotating to a new log file, or even at a regular interval, it
 * emits a "prolog" that starts with the current date/time, then a series of
 * log messages generated by invoking all the log_prolog triggers.
 *
 * The log_prolog trigger functions call the standard logging API to produce
 * their output, but the logging system uses an internal trick to ensure that
 * the their messages only go to the log output that invoked them, so for
 * example, when a log file rotates, the prolog only gets written into the new
 * file, and not into the console log as well.
 */
DECLARE_TRIGGER(log_prolog);

struct log_output_iterator;

void serval_log_print_prolog(struct log_output_iterator *it);

#endif // __SERVAL_DNA__LOG_PROLOG_H