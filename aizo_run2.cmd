@echo off
setlocal enabledelayedexpansion

:: Stałe parametry
set "program=.\aizo.exe"
set "problem=1"
set "algorithm=0"
set "startSize=200"
set "maxSize=1400"
set "stepSize=200"

:: Lista density
set densityCount=3
set density[0]=0.25
set density[1]=0.50
set density[2]=0.99

set size=%startSize%

:outer_loop
if %size% gtr %maxSize% goto :eof

for /L %%d in (0,1,2) do (
    set currentDensity=!density[%%d]!
    
    echo === Density: !currentDensity! Size: %size% ===
    
    for /L %%i in (1,1,5) do (
        set /a param1=!random! %% %size%
        set /a param2=!random! %% %size%

        (
            echo !param1!
            echo !param2!
        ) | %program% --test %problem% %algorithm% %size% !currentDensity!
    )
)

set /a size+=%stepSize%
goto :outer_loop
