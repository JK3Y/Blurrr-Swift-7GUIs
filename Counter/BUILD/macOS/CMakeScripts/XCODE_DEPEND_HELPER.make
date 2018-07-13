# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.MyBlurrrProject.Debug:
/Users/jamador/dev/Swift\ IUP/7GUIs/Counter/BUILD/macOS/Debug/MyBlurrrProject.app/Contents/MacOS/MyBlurrrProject:
	/bin/rm -f /Users/jamador/dev/Swift\ IUP/7GUIs/Counter/BUILD/macOS/Debug/MyBlurrrProject.app/Contents/MacOS/MyBlurrrProject


PostBuild.MyBlurrrProject.Release:
/Users/jamador/dev/Swift\ IUP/7GUIs/Counter/BUILD/macOS/Release/MyBlurrrProject.app/Contents/MacOS/MyBlurrrProject:
	/bin/rm -f /Users/jamador/dev/Swift\ IUP/7GUIs/Counter/BUILD/macOS/Release/MyBlurrrProject.app/Contents/MacOS/MyBlurrrProject


PostBuild.MyBlurrrProject.MinSizeRel:
/Users/jamador/dev/Swift\ IUP/7GUIs/Counter/BUILD/macOS/MinSizeRel/MyBlurrrProject.app/Contents/MacOS/MyBlurrrProject:
	/bin/rm -f /Users/jamador/dev/Swift\ IUP/7GUIs/Counter/BUILD/macOS/MinSizeRel/MyBlurrrProject.app/Contents/MacOS/MyBlurrrProject


PostBuild.MyBlurrrProject.RelWithDebInfo:
/Users/jamador/dev/Swift\ IUP/7GUIs/Counter/BUILD/macOS/RelWithDebInfo/MyBlurrrProject.app/Contents/MacOS/MyBlurrrProject:
	/bin/rm -f /Users/jamador/dev/Swift\ IUP/7GUIs/Counter/BUILD/macOS/RelWithDebInfo/MyBlurrrProject.app/Contents/MacOS/MyBlurrrProject




# For each target create a dummy ruleso the target does not have to exist
