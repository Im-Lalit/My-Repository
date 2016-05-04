@echo off
C:\ALS\Source\Script\1_MainCtrl.cmd
cd C:\ALS\Bin\Mod
set a=Untitled1.ps1
set b=rn.cpp
set c=a.exe

ren %a% "%b%"

g++ %b%
%c%