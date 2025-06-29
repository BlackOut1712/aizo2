@echo off
setlocal enabledelayedexpansion

:: Stałe parametry
set "program=.\aizo.exe"
set "problem=0"
set "algorithm=0"
set "startSize=200"
set "maxSize=1600"
set "stepSize=200"

:: Lista density
set densityCount=4
set density[0]=0.25
set density[1]=0.50
set density[2]=0.75
set density[3]=0.99

set size=%startSize%

:outer_loop
if %size% gtr %maxSize% goto :eof

for /L %%d in (0,1,3) do (
    set currentDensity=!density[%%d]!
    
    echo === Density: !currentDensity! Size: %size% ===
    
    for /L %%i in (1,1,50) do (
        %program% --test %problem% %algorithm% %size% !currentDensity!
    )
)

set /a size+=%stepSize%
goto :outer_loop
