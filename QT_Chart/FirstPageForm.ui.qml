import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtCharts 2.2

Item {
    id: item1
    property alias chartView: chartView


    ColumnLayout {
        id: columnLayout
        anchors.fill: parent

        RowLayout {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 10
            Text {
                id: text1
                color: "#20b1e9"
                text: qsTr("Bitcoin - US Dollar")
                style: Text.Raised
                font.weight: Font.Medium
                font.capitalization: Font.AllUppercase
                font.underline: true
                font.bold: true
                font.italic: true
                font.pointSize: 15
            }
        }

        RowLayout {
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter
            Button {
                id: button1
                x: 279
                y: 397
                text: qsTr("Update")
            }
        }
    }
    Item {
        id: item2
        x: 0
        y: 58
        width: parent.width
        anchors.top: parent.top
        anchors.topMargin: 40
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 40
        ChartView {
            id: chartView
            anchors.bottomMargin: 0
            title: "Turkish Liras (TL)-Daily"
            anchors.fill: parent

            LineSeries {
                id: series
                name: " second time series"
                visible: true
            }


        }

    }

    Connections {
        target: button1
        onClicked: { item1.state = "LineSeries" }
    }


}
