set /p name=

copy nul %name%.h
copy nul %name%.cpp

echo #ifndef __%name%_H__ > %name%.h
echo #define __%name%_H__ >> %name%.h
echo.>> %name%.h
echo #include "cocos2d.h" >> %name%.h
echo USING_NS_CC; >> %name%.h
echo.>> %name%.h
echo.>> %name%.h
echo class %name%{ >> %name%.h
echo.>> %name%.h
echo.>> %name%.h
echo }; >> %name%.h
echo.>> %name%.h
echo.>> %name%.h
echo #endif // __%name%_H__ >> %name%.h

echo #include "%name%.h" > %name%.cpp