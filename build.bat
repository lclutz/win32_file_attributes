@echo off
cd /D "%~dp0"

where /q cl || (
    echo ERROR: "cl" not found
    echo        Please run this from the MSVC x64 native tools command prompt.
    exit /B 1
)

cl.exe /FC /Zi /nologo /Fe:file_attributes.exe main.cpp
