@echo off

:1
if exist 1_MainCtrl.cmd goto disp1
echo .>>a_c_1.dl
echo *****1_MC file not found ! *****

:2
if exist 2_CkLr.cmd goto disp2
echo .>>a_c_2.dl
echo  *****2_CL file not found !*****

:3
if exist 3_Fixer.cmd goto disp3
echo .>>a_c_3.dl
echo *****3_Fr file not found !*****

:4
if exist 4_ListPvdr.cmd goto disp4
echo .>>a_c_4.dl
echo *****4_LP file not found !*****

:5
if exist 5_Mover.cmd goto disp5
echo .>>a_c_5.dl
echo *****5_MR file not Found !*****

:disp1
echo 1_MC file found ! 
goto 2

:disp2
echo 2_CL file found !
goto 3

:disp3
echo 3_Fr file found !
goto 4

:disp4
echo 4_LP file found !
goto 5

:disp5
echo 5_MR file Found !
3_Fixer.cmd