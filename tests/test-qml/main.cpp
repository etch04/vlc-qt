/****************************************************************************
* VLC-Qt - Qt and libvlc connector library
* Copyright (C) 2012 Tadej Novak <tadej@tano.si>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

#include <QtCore/QCoreApplication>
#include <QtDeclarative/QDeclarativeEngine>

#if defined(Qt5)
    #include <QtWidgets/QApplication>
#elif defined(Qt4)
    #include <QtGui/QApplication>
#endif

#include "qml/QMLVideoPlayer.h"

#include "qmlapplicationviewer/qmlapplicationviewer.h"

int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));
    QCoreApplication::setApplicationName("Test QML");

    qmlRegisterType<VlcQMLVideoPlayer>("VLCQt", 0, 6, "VlcVideoPlayer");

    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile("qml/video.qml");
    viewer.setResizeMode(QDeclarativeView::SizeViewToRootObject);
    viewer.showExpanded();

    return app->exec();
}

