#NoEnv
SendMode Input
SetWorkingDir %A_ScriptDir%

Send {Volume_Up}
SoundSet 30

#Persistent
	SetTitleMatchMode, 2
	GroupAdd, Win, ahk_class Notepad++
	SetTimer, Resize, 500
Return

Resize:
IfWinActive, ahk_group Win
{
	WinGet, id, ID
	If !%ID%
	{
    	WinRestore,
		WinMove,,,,, 974, 640
		%id% := True
	}
}
Return

F13::Run C:\Users\creev\MonitorLightToggle
F14::Run C:\Users\creev\DeskLightToggle
F15::Run C:\Users\creev\OfficeLightToggle

F16::
{
	Send {Volume_Up}
	SoundSet 30
}
return

~Volume_Up::SoundSet, +8

~Volume_Down::SoundSet, -8