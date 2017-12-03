import QtQuick 2.4

Item {
    width: 400
    height: 400

    TextEdit {
        id: textEdit
        x: 16
        y: 63
        width: 369
        height: 141
        text: qsTr("To be able to see the time series please use above bars.")
        font.pixelSize: 18
    }
}
