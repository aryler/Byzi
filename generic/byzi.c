/*
 * byzi.c --
 *
 *	This file provides functions that implement byzi for Tk.
 *
 * Copyright 2012-2017 Stuart Cassoff
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 */

#include <tcl.h>
#include <tk.h>

#include "byziMap.h"

EXTERN int Tk_BusyObjCmd (ClientData notUsed, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[]);

static void Byzi_InterpDeleteProc (ClientData clientData, Tcl_Interp *interp);


/*
 *----------------------------------------------------------------------
 *
 * Byzi_GetChair --
 *
 *	Initialize Chair.
 *
 * Results:
 *	Chair.
 *
 * Side effects:
 *	Memory allocated for chair if needed.
 *
 *----------------------------------------------------------------------
 */

MODULE_SCOPE Tcl_HashTable *
Byzi_GetChair (
	Tcl_Interp *interp
) {
	Tcl_HashTable *hTblPtr;

        hTblPtr = (Tcl_HashTable *) Tcl_GetAssocData(interp, "ByziFurniture", NULL);
        if (hTblPtr == NULL) {
                hTblPtr = (Tcl_HashTable *) ckalloc((unsigned) sizeof(Tcl_HashTable));
                Tcl_InitHashTable(hTblPtr, TCL_ONE_WORD_KEYS);
                Tcl_SetAssocData(interp, "ByziFurniture", Byzi_InterpDeleteProc, (ClientData) hTblPtr);
        }
	return hTblPtr;
}

/*
 *----------------------------------------------------------------------
 *
 * Byzi_InterpDeleteProc --
 *
 *
 *
 * Results:
 *
 *
 * Side effects:
 *
 *
 *----------------------------------------------------------------------
 */

static void
Byzi_InterpDeleteProc (
	ClientData clientData,
	Tcl_Interp *interp
) {
	Tcl_HashTable *hTblPtr;
        hTblPtr = (Tcl_HashTable *) clientData;	
	Tcl_DeleteHashTable(hTblPtr);
	ckfree((char *) hTblPtr);
}

/*
 *----------------------------------------------------------------------
 *
 * Byzi_CommonInit --
 *
 *	Initialize Byzi.
 *
 * Results:
 *	A standard Tcl result
 *
 * Side effects:
 *	The byzi package is created.
 *	One new command "byzi" is added to the Tcl interpreter.
 *
 *----------------------------------------------------------------------
 */

static int
Byzi_CommonInit (
	Tcl_Interp *interp
) {
#ifdef USE_TCL_STUBS
	if (Tcl_InitStubs  (interp, "8.5",        0) == NULL) { return TCL_ERROR; }
#endif
	if (Tcl_PkgRequire (interp, "Tcl", "8.5", 0) == NULL) { return TCL_ERROR; }

#ifdef USE_TK_STUBS
	if (Tk_InitStubs   (interp, "8.5",        0) == NULL) { return TCL_ERROR; }
#endif
	if (Tcl_PkgRequire (interp, "Tk",  "8.5", 0) == NULL) { return TCL_ERROR; }

	if (Tcl_PkgProvide (interp, PACKAGE_NAME, PACKAGE_VERSION) != TCL_OK) { return TCL_ERROR; }

#ifdef BYZI_NAMESPACE
	if (Tcl_CreateNamespace(interp, BYZI_NAMESPACE, NULL, NULL) == NULL) { return TCL_ERROR; }
#endif

	return TCL_OK;
}

/*
 *----------------------------------------------------------------------
 *
 * Byzi_Init --
 *
 *	Initialize Byzi.
 *
 * Results:
 *	A standard Tcl result
 *
 * Side effects:
 *	The byzi package is created.
 *	One new command "byzi" is added to the Tcl interpreter.
 *
 *----------------------------------------------------------------------
 */

EXTERN int
Byzi_Init (
	Tcl_Interp *interp
) {
#ifdef BYZI_NAMESPACE
	Tcl_Namespace *ns;
#endif
	if (Byzi_CommonInit(interp) != TCL_OK) { return TCL_ERROR; }

#ifdef BYZI_NAMESPACE
	if ((ns = Tcl_FindNamespace(interp, BYZI_NAMESPACE, NULL, TCL_LEAVE_ERR_MSG)) == NULL) { return TCL_ERROR; }
#endif
	Tcl_CreateObjCommand(interp, BYZI_NAMESPACE "byzi", Tk_ByziObjCmd, NULL, NULL);

#ifdef BYZI_NAMESPACE
	if (Tcl_Export(interp, ns, "byzi", 0) != TCL_OK) { return TCL_ERROR; }
#endif
	return TCL_OK;
}

/*
 *----------------------------------------------------------------------
 *
 * Byzi_SafeInit --
 *
 *	Safe initialize Byzi.
 *
 * Results:
 *	A standard Tcl result
 *
 * Side effects:
 *	The byzi package is created.
 *	No commands are added
 *
 *----------------------------------------------------------------------
 */

EXTERN int
Byzi_SafeInit (
	Tcl_Interp *interp
) {
	return Byzi_CommonInit(interp);
}


/* EOF */
