#NoEnv
SendMode Input
SetWorkingDir %A_ScriptDir%

F13::Run C:\Users\creev\MonitorLightToggle
F14::Run C:\Users\creev\DeskLightToggle
F15::Run C:\Users\creev\OfficeLightToggle

F16::
{
	Send {Volume_Down}
	SoundSet 30
}
return

$Volume_Up::
    SoundGet, volume 
    Send {Volume_Up}
	Vol = % Round(volume + 5)
    SoundSet, %Vol%
Return

$Volume_Down::
    SoundGet, volume 
    Send {Volume_Down}
	Vol = % Round(volume + -5)
    SoundSet, %Vol%
Return