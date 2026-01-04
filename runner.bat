@echo off
REM To compile the c++ file and run them 

for /F "tokens=1,2 delims=#" %%a in ('"prompt #$H#$E# & echo on & for %%b in (1) do rem"') do set "ESC=%%b"

@echo off
echo %ESC%[33mCompiling...%ESC%[0m

g++ ./base.cpp ./tokenizer/lexer/Lexer.cpp -o ./build/build -std=c++17 -g

if %errorlevel% neq 0 (
    echo %ESC%[31mBuild Failed...%ESC%[0m
    exit /b %errorlevel%
)

echo %ESC%[32mComplied Successfully...%ESC%[0m

echo %ESC%[33mExecuting...%ESC%[0m
.\build\build.exe %*
