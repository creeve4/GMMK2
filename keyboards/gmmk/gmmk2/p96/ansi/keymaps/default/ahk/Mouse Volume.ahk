#NoEnv
SendMode Input
SetWorkingDir %A_ScriptDir%

F13::Run C:\Users\creev\MonitorLightToggle
F14::Run C:\Users\creev\DeskLightToggle
F15::Run C:\Users\creev\OfficeLightToggle

F16::
{
	Send {Volume_Up}
	SoundSet 30
}
return

$Volume_Up::
    SoundGet, volume 
    Send {Volume_Up}
	Vol = % volume + ( 5 - Mod(volume,5) )
    SoundSet, %Vol%
Return

$Volume_Down::
    SoundGet, volume 
    Send {Volume_Down}
	Vol = % volume - ( 5 - Mod(volume,5) )
    SoundSet, %Vol%
Return