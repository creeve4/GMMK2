#NoEnv
SendMode Input
SetWorkingDir %A_ScriptDir%

Spotify := new Spotify_Basic()

return ; End of auto-execute

F14::Spotify.TogglePlay()
F15::Spotify.Next()
F16::Spotify.Previous()

class Spotify_Basic {

    _actions := {Next:11, Pause:47, Play:46, Previous:12, TogglePlay:14}

    __Call(Action) {
        if (!this._actions.HasKey(Action))
            throw Exception("Invalid action." Action, -1)
        DetectHiddenWindows On
        SetTitleMatchMode RegEx
        if !(hWnd := WinExist("-|Spotify ahk_exe i)Spotify.exe"))
            return
        msg := this._actions[Action] << 16
        SendMessage 0x0319,, % msg,, % "ahk_id" hWnd
    }

}
Return

F13::
{	
	Send {Volume_Up}
	SoundSet 40
}
Return

$Volume_Up::
    SoundGet, volume 
    Send {Volume_Up}
	Vol = % volume + ( 10 - Mod(volume,10) )
    SoundSet, %Vol%
Return

$Volume_Down::
    SoundGet, volume 
    Send {Volume_Down}
	Vol = % volume - ( 10 - Mod(volume,10) )
    SoundSet, %Vol%
Return