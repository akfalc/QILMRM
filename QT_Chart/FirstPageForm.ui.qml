import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtCharts 2.2

Item {
    id: item1
    property alias chartView: chartView

    Connections {
        target: downloadManager
        onPresentData: {
            y = y / 100
            series.append(x, y)
            if (x > xAxis.max) {
                xAxis.max = x
            }
            if (y > yAxis.max) {
                yAxis.max = y
            }
        }
    }

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
            title: "Bitcoin-USD-Daily"
            anchors.fill: parent
            ValueAxis {
                id: yAxis
                titleText: "USD"
                titleVisible: true
                gridVisible: true
                tickCount: 11
                min: 0
                max: 10
            }
            DateTimeAxis {
                id: xAxis
                tickCount: 20
                visible: true
                labelsAngle: 90
                gridVisible: true
                format: "yyyy-MM-dd"
                min: "2017-10-10"
                max: "2017-11-01"
            }

            LineSeries {
                id: series
                color: "red"
                axisX: xAxis
                axisY: yAxis
                name: "first time series"
                visible: true
            }
        }
    }
}
