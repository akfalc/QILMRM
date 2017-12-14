import QtQuick 2.6
import QtQuick.Window 2.2
import QtCharts 2.2
import QtQuick.Layouts 1.3
import QtQuick.Templates 2.2
import QtQuick.Controls 2.2
import QtQuick.Dialogs 1.2
import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtCharts 2.2






ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("QT QML with C++ Backend")

    Connections {
        target: downloadManager
        onPresentData: {

           series.append(x, y)
            if (x > xAxis.max) {
xAxis.max=x
            }

                if(y > yAxis.max)
                {
                    yAxis.max = y
                }


        }

    }



    ColumnLayout
    {
      id: columnLayout
      objectName: "columnLayout"
      width: parent.width
      height: parent.height

      RowLayout
      {
        id: rowLayout
        objectName: "rowLayout"
        height: 50

        ComboBox
        {
          id: comboBox_currencyID
          objectName: "comboBox_currencyID"
          textRole: "key"
          Layout.maximumWidth: 90

          model: ListModel
          {
            ListElement { key: "BTC"; value: 1 }
            ListElement { key: "AVT"; value: 2 }
            ListElement { key: "GAME"; value: 3 }
            ListElement { key: "ADK"; value: 4 }
            ListElement { key: "ANS"; value: 5 }
            ListElement { key: "ATB"; value: 6 }
            ListElement { key: "BITUSD"; value: 7 }
            ListElement { key: "CTR"; value: 8 }
            ListElement { key: "DGB"; value: 9 }
            ListElement { key: "ECN"; value: 10 }

          }
          onCurrentTextChanged:
          {series.clear();
              series.name=currentText;
              yAxis.max=0;
              if(currentText=="AVT"){
                series.color = "green"
                  chartView.theme = ChartView.ChartThemeBrownSand
                  chartView.title = "Aevuntus Coin Daily Value"
              } if(currentText=="BTC")
              {series.color = "orange"
              chartView.theme = ChartView.ChartThemeBlueCerulean
              chartView.title = "Bit-Coin Daily Value"}
              if(currentText=="GAME")
                            {series.color = "red"
              chartView.theme = ChartView.ChartThemeHighContrast
              chartView.title = "GameCredits Coin Daily Value"}
              if(currentText=="ADK")
                            {series.color = "blue"
              chartView.theme = ChartView.ChartThemeLight
              chartView.title = "ADK coin Daily Value"}
              if(currentText=="ANS")
                            {series.color = "yellow"
              chartView.theme = ChartView.ChartThemeBlueIcy
              chartView.title = "ANS Coin Daily Value"}
              if(currentText=="ATB")
                            {series.color = "pink"
              chartView.theme = ChartView.ChartThemeHighContrast
              chartView.title = "ATB Coin Daily Value"}
              if(currentText=="BITUSD")
                            {series.color = "brown"
              chartView.theme = ChartView.ChartThemeHighContrast
              chartView.title = "Bitusd coin Daily Value"}
              if(currentText=="CTR")
                            {series.color = "purple"
              chartView.theme = ChartView.ChartThemeHighContrast
              chartView.title = "Centra Coin Daily Value"}
                  if(currentText=="DGB")
                                {series.color = "grey"
                  chartView.theme = ChartView.ChartThemeBlueNcs
                  chartView.title = "DigiBythe Coin Daily Value"}
                  if(currentText=="ECN")
                                {series.color = "gold"
                  chartView.theme = ChartView.ChartThemeHighContrast
                  chartView.title = "E-Coin Daily Value"}


downloadManager.doDownload(comboBox_currencyID.currentText);






          }
        }
        Button
        {
          id: button_removeSeries
          objectName: "button_removeSeries"
          anchors.right: columnLayout.left
          anchors.rightMargin: 10
          text: qsTr("Remove All\n Series")
          Layout.maximumWidth: 100

          onClicked:
          {
            series.clear();
          }
        }// Button
        }


        ChartView {
            id: chartView
            objectName: "chartView"
            Layout.fillWidth: true
            Layout.fillHeight: true
            anchors.top: rowLayout.bottom
            antialiasing: true
            theme: ChartView.ChartThemeDark
            title: "Digital Currency Daily Change"
            ValueAxis {
                id: yAxis
                titleText: "USD"
                titleVisible: true
                gridVisible: true
                tickCount: 20
                min: 0
                max: 10
            }
            DateTimeAxis {
                id: xAxis
                tickCount: 30
                visible: true
                labelsAngle: 90
                gridVisible: true
                format: "yyyy-MM-dd"
                min: "2017-10-30"
                max: "2017-12-09"
            }

            LineSeries {
                id: series
                color: "green"
                axisX: xAxis
                axisY: yAxis
                name: "first time series"
                visible: true
                capStyle: "RoundCap"
            }
        }
    }
}
