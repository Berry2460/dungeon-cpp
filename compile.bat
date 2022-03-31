@echo off

set final=0

if %final% == 0 (
g++ -Wall *.cpp -o test.exe
goto done
)

g++ -Wall -O2 *.cpp -o final.exe
strip final.exe

:done
pause
