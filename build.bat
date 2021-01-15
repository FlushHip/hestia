cd %~dp0

if not exist .build mkdir .build

attrib +h .build

cd .build
cmake -G "Visual Studio 16 2019" ..\src

cd %~dp0
