#include <stddef.h>
#include "iup.h"
#include "iupcbs.h"
#include "iupweb.h"

// This function is called when the program exits.
static void IupExitPoint()
{
	IupClose();
}

// This function is the starting point for your code.
void IupEntryPoint()
{
	// This tells IUP to call IupExitPoint on exit.
	IupSetFunction("EXIT_CB", (Icallback)IupExitPoint);
	// open the IupWeb library
	IupWebBrowserOpen();              


	// Your code starts here...
	Ihandle* the_label = IupLabel("Hello World!");
	Ihandle* web_view = IupWebBrowser();
	IupSetAttribute(web_view, "VALUE", "https://www.google.com");
	Ihandle* v_box = IupVbox(the_label, web_view, NULL);
	Ihandle* the_dialog = IupDialog(v_box);
	IupSetAttribute(the_dialog, "TITLE", "Blurrr Iup C");
	IupSetAttribute(the_dialog, "SIZE", "HALFxHALF");
	// For Microsoft Windows: This will set the title bar icon to the application icon.
	IupSetAttribute(the_dialog, "ICON", "IDI_ICON1");
	IupShow(the_dialog);
}

// Do not modify main(). Not all platforms use main as the entry point so your changes may have no effect.
// Warning: Do not #include "SDL.h" for defining main. SDL does some macro tricks to redefine main to help its bootstrap, which will break normal use cases like IUP.
int main(int argc, char* argv[])
{
	IupOpen(&argc, &argv);
	IupSetFunction("ENTRY_POINT", (Icallback)IupEntryPoint);
	IupMainLoop();
	return 0;
}

