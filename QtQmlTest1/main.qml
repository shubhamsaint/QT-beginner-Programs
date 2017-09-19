import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

Window {
    visible: true
    width: 360
    height: 360

    Image {
        id: parent
        source: "file:///C:/Users/Shubham/Downloads/Nature.jpg"
        width: 360
        height: 360
        MouseArea{
            anchors.fill: parent
            onClicked: parent.rotation +=90
        }

        Behavior on rotation {
            NumberAnimation{
                duration: 100
            }
        }

    }
}
