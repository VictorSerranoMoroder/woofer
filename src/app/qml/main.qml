import QtQuick 
import QtQuick.Controls.Material 

ApplicationWindow { id: window
    visible: true
    width: 480
    height: 320
    title: "Mini Spotify"

    Material.theme: Material.Light
    Material.accent: Material.Blue

    minimumWidth: 480
    maximumWidth: 480
    minimumHeight: 320
    maximumHeight: 320

    Drawer {
        id: drawer
        width: 0.33 * window.width
        height: window.height
        edge: Qt.LeftEdge

        ListView {
            id: menuList
            anchors.fill: parent
            spacing: 5
            clip: true

            model: ListModel {
                ListElement { name: "Home" }
                ListElement { name: "Playlists" }
                ListElement { name: "Search" }
                ListElement { name: "Settings" }
            }

            delegate: ItemDelegate {
                width: parent.width
                text: name
                highlighted: ListView.isCurrentItem
                onClicked: {
                    menuList.currentIndex = index
                    drawer.close()
                    console.log("Selected:", name)
                }
            }
        }
    }

    Loader { id: loader
        anchors.fill: parent
        source: "welcome.qml"
    }
}