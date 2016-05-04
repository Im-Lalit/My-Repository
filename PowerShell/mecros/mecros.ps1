Add-Type -AssemblyName System.Windows.Forms
$a = "C:\My_Programs\Program_Data\PowerShell\mecros\cur.txt"
$tmp = Read-Host



switch($tmp){
    r{
        for(;;){
            sleep -Milliseconds 10
            $a = [Windows.Forms.Cursor]::Position -replace  '{X=' -replace 'Y=' -replace '}'
            $a
            $a | Out-File "cur.txt" -Append}
        }

    p{
        foreach($line in [System.IO.File]::ReadLines($a)){
            sleep -Milliseconds 10
            [Windows.Forms.Cursor]::Position = $line}
        }
        
    k{
        [void] [System.Reflection.Assembly]::LoadWithPartialName("'Microsoft.VisualBasic")
        [Microsoft.VisualBasic.Interaction]::AppActivate("notepad")
        [void] [System.Reflection.Assembly]::LoadWithPartialName("'System.Windows.Forms")
        [System.Windows.Forms.SendKeys]::Sendwait('lalit')
        [Microsoft.VisualBasic.Interaction]::AppActivate("windows powershell ise")
        }
}