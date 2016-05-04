#################################################################################
# Serial Port Component - Powershell script
# © Copyright ActiveXperts Software B.V.
#
# For more information about Serial Port Component, please
# visit the online Serial Port Component page at:
# http://www.activexperts.com
#################################################################################
# Example:
# .\QueryDevice.ps1  / send commands and receive responses
#################################################################################

cls

#################################################################################
# Functions --------------------------------------------------------------------#
#################################################################################


#################################################################################
# AskDevice --------------------------------------------------------------------#
#################################################################################

function AskDevice($objComport)
{
  $strTitle = ""
  for ($i=1; $i -lt 5;$i++) 
  { 
    $strTitle = $strTitle + "  " + $i + ": COM" + $i + "`n" 
  }  
    
  for ($j=0; $j -lt $objComport.GetDeviceCount(); $j++)      
  {
    $strTitle = $strTitle + "  " + ($i + $j ) + ": " + 
    $objComport.GetDevice($j) + "`n"
  }  

  $strDevice = ""
  while($strDevice -eq "")
  {
    #$strInput = Read-Host $strTitle "Select device:" "1"
    $strInput = Read-Host $strTitle "Select device"
    if($strInput -eq "")
    {
      $strDevice = ""
    }  
    elseif([int]$strInput -lt $i)
    {
      $strDevice = "COM" + $strInput
    }  
    elseif([int]$strInput -lt $i + $j)
    {
      $strDevice = $objComport.GetDevice([int]$strInput - $i)
    }  
  }  

  Write-Host "Selected device: " $strDevice

  return $strDevice
}

#################################################################################
# Ask --------------------------------------------------------------------------#
#################################################################################

function Ask($strTitle, $strDefault, $bAllowEmpty)
  {
    do
      {
        $strInput = Read-Host $strTitle $strDefault
        if ($strInput -ne "")
          {
            $strReturn = $strInput
          }  
      }  
    until($strReturn -ne "" -or $bAllowEmpty)

    return $strReturn
  }

#################################################################################
# ReadResponse -----------------------------------------------------------------#
#################################################################################

function ReadResponse($objComport)
  {
    $str = "notempty"
    $objComport.Sleep(200)
    while ($str -ne "")
      {
        $str = $objComport.ReadString()
        if ($str -ne "")
          {
            Write-Host "  <- " $str
          }  
      }
  }

#################################################################################
# WriteCommand -----------------------------------------------------------------#
#################################################################################

function WriteCommand($objComport)
  {
    $str = Read-Host "Enter command (enter QUIT to stop the program)"
    $objComport.WriteString($str)
    if($objComport.LastError -eq 0)
      {
        Write-Host "  -> " $str
      }  
    else
      {
        Write-Host "Write failed, result: " $objComport.LastError " ("$objComport.GetErrorDescription($objComport.LastError) ")"
      }  

    if ($str -eq "QUIT")
      {
        return $false
      }  
    else
      {
        return $true
      }
  }


#################################################################################
# THE SCRIPT ITSELF ------------------------------------------------------------#
#################################################################################

$objComport       = new-object -comobject AxSerial.ComPort
Write-Host "Serial Port Component Version: " $objComport.Version
Write-Host "Serial Port Component Build  : " $objComport.Build
Write-Host "Serial Port Component Module : " $objComport.Module
Write-Host "License Status      : " $objComport.LicenseStatus

$objComport.Device = AskDevice($objComport)
# Is there a COM device attached to the PC
if($objComport.Device -eq "")
  {
    Write-Host "No COM device found"
    exit
  }
# Optionally override defaults for direct COM ports
if($objComport.Device.substring(0,3) -eq "COM")
  {
    $objComport.BaudRate  = Ask "Enter baud rate (no input means: default
    baud rate):" "9600" $true 
    # $objComport.HardwareFlowControl  = $true
    # $objComport.SoftwareFlowControl  = $false
  }

# Set Logging - for troubleshooting purposes
$objComport.LogFile = "C:\Serial Port Component.log"

# Open the port
$objComport.Open()
Write-Host "Open, result:" $objComport.LastError " (" $objComport.GetErrorDescription($objComport.LastError) ")"

if($objComport.LastError -ne 0)
  {
    exit
  }

ReadResponse($objComport)

while (WriteCommand($objComport))
  {
    ReadResponse($objComport)
  }  
  
$objComport.Close()
Write-Host "Close, result: " $objComport.LastError " (" $objComport.GetErrorDescription($objComport.LastError) ")"
Write-Host "Ready."