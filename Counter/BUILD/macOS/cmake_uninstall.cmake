IF(NOT EXISTS "/Users/jamador/dev/Swift IUP/7GUIs/Counter/BUILD/macOS/install_manifest.txt")
  MESSAGE(FATAL_ERROR "Cannot find install manifest: \"/Users/jamador/dev/Swift IUP/7GUIs/Counter/BUILD/macOS/install_manifest.txt\"")
ENDIF(NOT EXISTS "/Users/jamador/dev/Swift IUP/7GUIs/Counter/BUILD/macOS/install_manifest.txt")

FILE(READ "/Users/jamador/dev/Swift IUP/7GUIs/Counter/BUILD/macOS/install_manifest.txt" files)
STRING(REGEX REPLACE "\n" ";" files "${files}")
FOREACH(file ${files})
  MESSAGE(STATUS "Uninstalling \"$ENV{DESTDIR}${file}\"")
  #  IF(EXISTS "$ENV{DESTDIR}${file}") # Problem: EXISTS doesn't detect symbolic links
    EXEC_PROGRAM(
      "/Users/jamador/Downloads/BlurrrSDKApple/CMake/CMake.app/Contents/bin/cmake" ARGS "-E remove \"$ENV{DESTDIR}${file}\""
      OUTPUT_VARIABLE rm_out
      RETURN_VALUE rm_retval
      )
    IF(NOT "${rm_retval}" STREQUAL 0)
      MESSAGE(FATAL_ERROR "Problem when removing \"$ENV{DESTDIR}${file}\"")
    ENDIF(NOT "${rm_retval}" STREQUAL 0)
	#  ELSE(EXISTS "$ENV{DESTDIR}${file}")
	#   MESSAGE(STATUS "File \"$ENV{DESTDIR}${file}\" does not exist.")
#ENDIF(EXISTS "$ENV{DESTDIR}${file}")
ENDFOREACH(file)

