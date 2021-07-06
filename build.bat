# build.bat
set PROJECT_NAME=thesaurus
set PYTHON_DIR=C:\Users\j715c\AppData\Local\Programs\Python\Python38
%PYTHON_DIR%\python -m cython --embed -o %PROJECT_NAME%.c %PROJECT_NAME%.py
gcc -Os -I %PYTHON_DIR%\include -o %PROJECT_NAME%.exe %PROJECT_NAME%.c -lpython38 -lm -L %PYTHON_DIR%\libs