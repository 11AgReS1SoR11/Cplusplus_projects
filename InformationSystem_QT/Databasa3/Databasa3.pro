QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DanialDatabasaLib.cpp \
    actions.cpp \
    addingallowance.cpp \
    addingcontract.cpp \
    assignallowance.cpp \
    changerate.cpp \
    contractfulfillment.cpp \
    dismissal_of_employee.cpp \
    employeeregistration.cpp \
    executioncontract.cpp \
    main.cpp \
    mainwindow.cpp \
    reports.cpp

HEADERS += \
    DanialDatabasaLib.h \
    actions.h \
    addingallowance.h \
    addingcontract.h \
    assignallowance.h \
    changerate.h \
    contractfulfillment.h \
    dismissal_of_employee.h \
    employeeregistration.h \
    executioncontract.h \
    mainwindow.h \
    reports.h

FORMS += \
    actions.ui \
    addingallowance.ui \
    addingcontract.ui \
    assignallowance.ui \
    changerate.ui \
    contractfulfillment.ui \
    dismissal_of_employee.ui \
    employeeregistration.ui \
    executioncontract.ui \
    mainwindow.ui \
    reports.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/Aspose.Words.Cpp/lib/x64/release/ -lAspose.Words.Cpp_vc14x64d
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/Aspose.Words.Cpp/lib/x64/debug/ -lAspose.Words.Cpp_vc14x64d
else:unix: LIBS += -L$$PWD/Aspose.Words.Cpp/lib/x64/ -lAspose.Words.Cpp_vc14x64d

INCLUDEPATH += $$PWD/Aspose.Words.Cpp/include
DEPENDPATH += $$PWD/Aspose.Words.Cpp/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/CodePorting.Translator.Cs2Cpp.Framework/lib/ -lcodeporting.translator.cs2cpp.framework_vc14x64
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/CodePorting.Translator.Cs2Cpp.Framework/lib/ -lcodeporting.translator.cs2cpp.framework_vc14x64d
else:unix: LIBS += -L$$PWD/CodePorting.Translator.Cs2Cpp.Framework/lib/ -lcodeporting.translator.cs2cpp.framework_vc14x64

INCLUDEPATH += $$PWD/CodePorting.Translator.Cs2Cpp.Framework/include
DEPENDPATH += $$PWD/CodePorting.Translator.Cs2Cpp.Framework/include
