TEMPLATE = app

QT += qml quick
!android: !ios: !blackberry: qtHaveModule(widgets): QT += widgets

SOURCES += main.cpp \
    Models/ListModel.cpp \
    Models/SubListedListModel.cpp \
    Models/devicemodelitem.cpp \
    Models/groupmodelitem.cpp \
    Models/settingsmodelitem.cpp


OTHER_FILES += qml/main.qml \
               qml/pages/AndroidDelegate.qml \
               qml/pages/GroupPage.qml \
               qml/pages/SettingsPage.qml


RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    Models/ListItem.h \
    Models/ListModel.h \
    Models/SubListedListItem.h \
    Models/SubListedListModel.h \
    Models/devicemodelitem.h \
    Models/groupmodelitem.h \
    Models/settingsmodelitem.h

DISTFILES += \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/AndroidManifest.xml \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/gradlew.bat

android {
    QT += androidextras
}
ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
