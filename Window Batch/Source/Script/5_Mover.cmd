@echo off
title Editor

cd C:\ALS\Bin
cls

pause

set src=C:\ALS\Bin\Raw
set trg=C:\ALS\Bin\Mod
set listdat=C:\ALS\Source\Backup\ListDat

for /F "delims=" %%a in (%listdat%) do move "%src%\%%a" "%trg%"

pause