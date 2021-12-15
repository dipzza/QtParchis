import QtQuick 2.0
import QtQuick.Window
import QtQuick.Layouts
import Qt5Compat.GraphicalEffects
import QtQuick.Controls 2.15

Item {
    width: 1600
    height: 900

    visible: false




    Label {
        id: label
        x: 499
        y: 52
        width: 286
        height: 58
        text: qsTr("Settings")
        font.italic: true
        font.bold: true
        font.pointSize: 35
        font.family: "Times New Roman"
    }

    Image {
        id: image
        x: 685
        y: 31
        width: 100
        height: 100
        source: "images/ajustes1.jpg"
        fillMode: Image.PreserveAspectFit
    }

    Label {
        id: label1
        x: 150
        y: 171
        width: 226
        height: 74
        text: qsTr("Sound")
        font.pointSize: 20
    }

    Label {
        id: label2
        x: 150
        y: 285
        width: 113
        height: 59
        text: qsTr("Music")
        font.pointSize: 20
    }

    Label {
        id: label3
        x: 150
        y: 408
        width: 107
        height: 59
        text: qsTr("Notifications")
        font.pointSize: 20
    }

    Label {
        id: label4
        x: 150
        y: 529
        width: 118
        height: 59
        text: qsTr("Letter Size")
        font.pointSize: 20
    }

    Switch {
        id: switch1
        x: 408
        y: 408
        width: 212
        height: 47
        text: qsTr("Switch")
    }

    ComboBox {
        id: comboBox
        x: 1066
        y: 182
        visible: true
        Layout.fillWidth: true
        currentIndex: -1
        font.pointSize: 13
        font.family: "Tahoma"
        focus: false
        antialiasing: false
        scale: 1.3
        model: ListModel{
                ListElement{
                    text: "English"
            }
                        ListElement{
                            text: "Spanish"
                    }
                        ListElement{
                            text: "French"
                    }
                        ListElement{
                            text: "Cezch"
                    }



        }
    }

    Label {
        id: label5
        x: 869
        y: 182
        width: 121
        height: 40
        text: qsTr("Language")
        font.pointSize: 20
        font.family: "Tahoma"
    }

    Slider {
        id: slider
        x: 397
        y: 295
        value: 0.5
    }

    Slider {
        id: slider1
        x: 397
        y: 182
        value: 0.5
    }

    Slider {
        id: slider2
        x: 414
        y: 529
        value: 0.5
    }

    Button {
        id: button
        x: 117
        y: 52
        width: 127
        height: 44
        text: qsTr("Back to Menu")
        onClicked: {
            menu.visible = true
            settings.visible = false
        }
    }



}


