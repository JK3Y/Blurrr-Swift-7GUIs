
/* Simple program:  Create a blank window, wait for keypress, quit.

   Please see the SDL documentation for details on using the SDL API:
   /Developer/Documentation/SDL/docs.html
*/
   
#include <stddef.h>

#include "iup.h"
#include "iupcbs.h"

// These are defined in BlurrrMain.swift
extern void IupSwiftEntryPoint(void);
extern void IupSwiftExitPoint(void);

void IupExitPoint()
{
	IupSwiftExitPoint();
}

void IupEntryPoint()
{
	IupSetFunction("EXIT_CB", (Icallback)IupExitPoint);
	IupSwiftEntryPoint();
}


#if !defined(__ANDROID__)
// Do not modify main(). Not all platforms use main as the entry point so your changes may have no effect.
int main(int argc, char* argv[])
{
	IupOpen(&argc, &argv); // removed because IupLua is presumably doing this.
	IupSetFunction("ENTRY_POINT", (Icallback)IupEntryPoint);
	IupMainLoop();
	return 0;
}
#endif
