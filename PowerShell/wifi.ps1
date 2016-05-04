cls
"=========================================================="

function port_create{
    $global:port = New-Object System.IO.Ports.SerialPort com6,115200,none,8,one
}

function port_open{
    $global:port.Open()
}

function port_close{
    $global:port.Close()
}

function read_input{
    $global:read_input = Read-Host "send"
}

function read_port{
    $Global:read_port = $global:port.ReadLine()
}


function main{
    port_create

    for($i=1; $i -gt 0; $i++){
        ""
        read_input
        if($global:read_input -eq "open"){
            "ok"
            port_open
            $global:read_input
        }

        if($global:read_input -eq "close"){
            "ok"
            port_close
        }

        else{
            For ($j=0; $j -lt 10; $j++)
                {
                    $a=$global:port.ReadLine()
                    $a
                    
                }
        }
    }
}

main

<#For ($i=1; $i -gt 0; $i++)
    {
        $a=$port.ReadLine()        
        $a
    }
$port.Close()#>