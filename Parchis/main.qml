import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import Qt5Compat.GraphicalEffects

import com.fit.boardpositions 1.0

Window {
    id: window
    width: 1600
    height: 900
    color: "brown"
    visible: true
    title: "Super Parchís"

    Menu {id: menu}

    Item {
        id: mainLoader
        state: "menu"

        states: [
            State {
                name: "menu"
                PropertyChanges {target: window; color: "#07b1bd"}
                PropertyChanges {target: menu; visible: true}
            },
            State {
                name: "game"
                PropertyChanges {target: window; color: "brown"}
                PropertyChanges {target: menu; visible: false}
            }
        ]
    }
}
