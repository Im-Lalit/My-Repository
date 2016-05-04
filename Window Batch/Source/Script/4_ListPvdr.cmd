@echo off
cd C:\ALS\Bin\Raw

dir /b > ListDat

MOVE C:\ALS\Bin\Raw\ListDat C:\ALS\Source\Backup

cd C:\ALS\Source\Script

5_Mover.cmd