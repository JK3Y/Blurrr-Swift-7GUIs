

func IupVbox(_ child: OpaquePointer?, _ arguments: CVarArg...) -> OpaquePointer
{
	return withVaList(arguments)
	{
		IupVboxVAList(child, $0)
	}
}

func IupHbox(_ child: OpaquePointer?, _ arguments: CVarArg...) -> OpaquePointer
{
	return withVaList(arguments)
	{
		IupHboxVAList(child, $0)
	}
}

func IupZbox(_ child: OpaquePointer?, _ arguments: CVarArg...) -> OpaquePointer
{
	return withVaList(arguments)
	{
		IupZboxVAList(child, $0)
	}
}

func IupGridBox(_ child: OpaquePointer?, _ arguments: CVarArg...) -> OpaquePointer
{
	return withVaList(arguments)
	{
		IupGridBoxVAList(child, $0)
	}
}

func IupMenu(_ child: OpaquePointer?, _ arguments: CVarArg...) -> OpaquePointer
{
	return withVaList(arguments)
	{
		IupMenuVAList(child, $0)
	}
}

