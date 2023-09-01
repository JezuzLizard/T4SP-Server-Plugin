@echo off
call git submodule update --init --recursive
premake5.exe vs2022