@echo off
REM To compile the c++ file and run them 

:: Generate ANSI Escape character for colors
for /F "tokens=1,2 delims=#" %%a in ('"prompt #$H#$E# & echo on & for %%b in (1) do rem"') do set "ESC=%%b"

:: 1. Fail early if no arguments are provided at all
if "%~1"=="" (
    echo %ESC%[31mPlease provide the input file!%ESC%[0m
    exit /b 1
)

:: 2. Handle the Compile and Run flag (-c)
if /i "%~1"=="-c" (
    :: Inline ternary style check for the secondary missing file parameter
    if "%~2"=="" (echo %ESC%[31mPlease provide the input file!%ESC%[0m) & exit /b 1

    echo %ESC%[33mCompiling...%ESC%[0m

    g++ ./base.cpp ./tokenizer/lexer/Lexer.cpp ./print/Printer.cpp ./parser/parser/Parser.cpp ./interpreter/Interpreter.cpp -o ./build/build -std=c++17 -g

    :: Verify if g++ succeeded
    if %errorlevel% neq 0 (
        echo %ESC%[31mBuild Failed...%ESC%[0m
        exit /b %errorlevel%
    )

    echo %ESC%[32mCompiled Successfully...%ESC%[0m
    echo %ESC%[33mExecuting...%ESC%[0m
    
    .\build\build.exe "%~2"
    exit /b 0
)

:: 3. Direct Execution branch (If -c was not passed, %1 is treated as the file)
echo %ESC%[33mExecuting...%ESC%[0m
.\build\build.exe "%~1"
exit /b 0
