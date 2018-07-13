#ifndef IUPVALIST_H
#define IUPVALIST_H

#ifdef __cplusplus
extern "C" {
#endif

#include "iup.h"
#include <stdarg.h>
Ihandle* IupVboxVAList(Ihandle* child, va_list arglist);
Ihandle* IupHboxVAList(Ihandle* child, va_list arglist);
Ihandle* IupZboxVAList(Ihandle* child, va_list arglist);
Ihandle* IupGridBoxVAList(Ihandle* child, va_list arglist);
Ihandle* IupMenuVAList(Ihandle* child, va_list arglist);

#ifdef __cplusplus
}
#endif

#endif /* IUPVALIST_H */
