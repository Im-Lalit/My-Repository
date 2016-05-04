$read_host = Read-Host

Function encoding_data($tmp_input){
    $A = $tmp_input -replace 'A','00001'
    $B = $A -replace 'B','00010'
    $C = $B -replace 'C','00011'
    $D = $C -replace 'D','00100'
    $E = $D -replace 'E','00101'
    $F = $E -replace 'F','00110'
    $G = $F -replace 'G','00111'
    $H = $G -replace 'H','01000'
    $I = $H -replace 'I','01001'
    $J = $I -replace 'J','01010'
    $K = $J -replace 'K','01011'
    $L = $K -replace 'L','01100'
    $M = $L -replace 'M','01101'
    $N = $M -replace 'N','01110'
    $O = $N -replace 'O','01111'
    $P = $O -replace 'P','10000'
    $Q = $P -replace 'Q','10001'
    $R = $Q -replace 'R','10010'
    $S = $R -replace 'S','10011'
    $T = $S -replace 'T','10100'
    $U = $T -replace 'U','10101'
    $V = $U -replace 'V','10110'
    $W = $V -replace 'W','10111'
    $X = $W -replace 'X','11000'
    $Y = $X -replace 'Y','11001'
    $z = $Y -replace 'Z','11010'
    $global:encoding_data_output = $z -replace ' ','11011'
}

encoding_data $read_host
$global:encoding_data_output

#encoding_data
#enc $a
#dec $global:b
#$global:b

#$global:d

