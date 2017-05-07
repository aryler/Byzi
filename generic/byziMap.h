/*
 * byziMap.h --
 *
 *	This file provides mappings from Tk functions to byzi functions
 *	in order to avoid library symbol conflicts with Tk.
 *
 * Copyright 2012-2017 Stuart Cassoff
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 */

#define Tk_BusyObjCmd  Tk_ByziObjCmd
#define TkNewWindowObj ByziTkNewWindowObj


/* EOF */
