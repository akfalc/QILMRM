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
import DataChart 1.0



ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("QT QML with C++ Backend")




    header:
        TabBar {
        id:tabbar
        currentIndex: swipeView.currentIndex
        anchors.fill: parent

        TabButton {
            text: "Main Page"

        }

        TabButton {
            text: "BitCoin-USD"


        }
        TabButton {
            text: " Aventus-USD"


        }
        TabButton {
            text: "GameCredits-US Dollar"

        }
    }
    SwipeView { id:swipeView

        currentIndex: tabbar.currentIndex
        anchors.fill: parent
        MainPage {


            }
        FirstPage {



            }
            SecondPage {


            }
            ThirdPage {


            }








                    }


    PageIndicator {
        id: indicator

        count: view.count
        currentIndex: view.currentIndex

        anchors.bottom: view.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
