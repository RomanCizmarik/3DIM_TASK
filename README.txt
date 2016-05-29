AUTOR: Roman Cizmarik

Spustitelne demo Roman_Cizmarik_3DIM_TASK.exe sa nachadza v adresary bin

Zdroje kody su v adresary src

###############
#Preklad:	##
###############

Aplikaciu je mozne prelozit pouzitim nastrojov qmake + make. 
Vid.: http://doc.qt.io/qt-4.8/qmake-using.html
K uspesnemu prekladu je potrebna kniznica DCMTK 3.6.0 a je nutne nastavit cestu k nej v subore
Roman_Cizmarik_3DIM_TASK.pro (nastavit premenne DCMTK_PATH a DCMTK_BUILD_PATH), alebo ju pridat do premmenej prostredia PATH.

Pri vytvoreni aplikacie boli pouzite nasledujuce nastroje a kniznice: Qt 5.6.0, MSVC 2012 x64, DCMTK 3.6.0