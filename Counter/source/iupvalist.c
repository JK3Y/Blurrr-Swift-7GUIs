
#include "iup.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>

extern void** iupObjectGetParamList(void* first, va_list arglist);

Ihandle* IupVboxVAList(Ihandle* child, va_list arglist)
{
	Ihandle **children;
	Ihandle *ih;
	
	children = (Ihandle **)iupObjectGetParamList(child, arglist);
	
	ih = IupCreatev("vbox", (void**)children);
	free(children);
	
	return ih;
}

Ihandle* IupHboxVAList(Ihandle* child, va_list arglist)
{
	Ihandle **children;
	Ihandle *ih;
	
	children = (Ihandle **)iupObjectGetParamList(child, arglist);
	
	ih = IupCreatev("hbox", (void**)children);
	free(children);
	
	return ih;
}

Ihandle* IupZboxVAList(Ihandle* child, va_list arglist)
{
	Ihandle **children;
	Ihandle *ih;
	
	children = (Ihandle **)iupObjectGetParamList(child, arglist);
	
	ih = IupCreatev("zbox", (void**)children);
	free(children);
	
	return ih;
}

Ihandle* IupGridBoxVAList(Ihandle* child, va_list arglist)
{
	Ihandle **children;
	Ihandle *ih;
	
	children = (Ihandle **)iupObjectGetParamList(child, arglist);
	
	ih = IupCreatev("gridbox", (void**)children);
	free(children);
	
	return ih;
}

Ihandle* IupMenuVAList(Ihandle* child, va_list arglist)
{
	Ihandle **children;
	Ihandle *ih;
	
	children = (Ihandle **)iupObjectGetParamList(child, arglist);
	
	ih = IupCreatev("menu", (void**)children);
	free(children);
	
	return ih;
}




