/*
 * byziInt.h --
 *
 *	This file provides declarations found in 8.6/generic/tkInt.h.
 *
 * Copyright 2012-2017 Stuart Cassoff
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 */

#include "byziMap.h"

typedef struct Busy *TkBusy;

MODULE_SCOPE Tcl_Obj * TkNewWindowObj(Tk_Window tkwin);
MODULE_SCOPE void TkpShowBusyWindow(TkBusy busy);
MODULE_SCOPE void TkpHideBusyWindow(TkBusy busy);
MODULE_SCOPE void TkpMakeTransparentWindowExist(Tk_Window tkwin, Window parent);
MODULE_SCOPE void TkpCreateBusy(Tk_FakeWin *winPtr, Tk_Window tkRef, Window *parentPtr, Tk_Window tkParent, TkBusy busy);


/* EOF */
