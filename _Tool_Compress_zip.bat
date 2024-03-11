@echo off
setlocal

del main.zip

echo Creating zip file %ZIP_NAME%...
powershell Compress-Archive -Path "main.cpp", "include\*", "src\*" -DestinationPath "main.zip"

endlocal
