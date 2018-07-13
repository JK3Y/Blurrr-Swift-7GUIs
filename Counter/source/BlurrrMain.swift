func btn_count_cb(_ ih: OpaquePointer?) -> Int32 {
    let text = IupGetHandle("Textbox")
    let count = IupGetInt(text, "VALUE")
    
    IupSetInt(text, "VALUE", count + 1)
    
    return IUP_DEFAULT
}

// Your program starts in this function
@_cdecl("IupSwiftEntryPoint")
public func IupSwiftEntryPoint()
{
	// Your code starts here...
	IupSetInt(nil, "UTF8MODE", 1);
	
	// Your code starts here...
    
    let button: OpaquePointer = IupButton("Count", nil)
    IupSetAttribute(button, "SIZE", "60")
    
    let text: OpaquePointer = IupText(nil)
    IupSetAttribute(text, "SIZE", "60")
    IupSetAttribute(text, "NAME", "TEXT")
    IupSetAttribute(text, "READONLY", "YES")
    IupSetHandle("Textbox", text)
    
    let hbox = IupHbox(text, button)
    IupSetAttribute(hbox, "MARGIN", "10x10")
    IupSetAttribute(hbox, "GAP", "10")
    
    let dlg = IupDialog(hbox)
    IupSetStrAttribute(dlg, "TITLE", "Counter")
    
    IupSetInt(text, "VALUE", 0)
    
    /* Registers callbacks */
    IupSetCallback(button, "ACTION", btn_count_cb)
    
    IupShowXY(dlg, IUP_CENTER, IUP_CENTER)
}

// This is called when your program quits
@_cdecl("IupSwiftExitPoint")
public func IupSwiftExitPoint()
{
	IupClose()
}

