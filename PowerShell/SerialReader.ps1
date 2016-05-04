cls
$port = New-Object System.IO.Ports.SerialPort com6,115200,none,8,one
$port.Open()
For ($i=1; $i -gt 0; $i++)
    {
        $a=$port.ReadLine()        
        $a
    }
$port.Close()