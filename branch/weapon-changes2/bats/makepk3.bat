@ECHO OFF

rem ----PURPOSE----
rem - Create a .pk3 file and move to the correct location
rem ---------------------------------------------
rem Config
rem Set your path for 7zip (can be mod'd to be rar/winzip exe)
rem Set the path for et-flf
rem Set the name of the pak file
rem Set the path for assets
rem ---------------------------------------------
TITLE PK3 creator and mover
ECHO Setting up config.
ECHO ------------------------------
rem	CONFIG START
	set WOLFDIR=C:\Progra~1\Wolfen~1\et-flf
	set PAKNAME=pak0.pk3
	set ZIP=C:\Progra~1\7-zip\7z.exe
	set ZIPOPS=a -tzip %PAKNAME% -mx=9 -r %ASSETS%\*.* -x!%ASSETS%\*.svn*
	set ASSETS=C:\Pro\et-flf\assets\
rem	CONFIG END
rem ---------------------------------------------
ECHO Removing old pak file
del %WOLFDIR%\%PAKNAME%
ECHO ------------------------------
ECHO Zipping assets directory
%ZIP% %ZIPOPS%
ECHO ------------------------------
ECHO Moving %PAKNAME% to %WOLFDIR%
move %PAKNAME% %WOLFDIR%\%PAKNAME%
ECHO ------------------------------
ECHO DONE.
ECHO ------------------------------
