import QtQuick 2.0
//import QtDesktop 1.0
import UberComponents 1.0
import "../UI"
Canvas {


    id: workbench
    width: 100
    height: 62
    color: "#EEEEEE"
    state: "initState"

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        //propagateComposedEvents: true
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        onPressed: {
            console.debug("Pressed");
            if ( workbench.state == "showDock")
            {
                workbench.state = "hideDock"
            }
        }
        onDoubleClicked: {
            if (mouse.button == Qt.LeftButton)
            {
                var pos = System.maptoGlobal(parent)
                DockView.setX(pos.x+mouseX-DockView.width/2)
                 DockView.setY(pos.y+mouseY)
                workbench.state = "showDock"
            }
        }
    }


    Repeater {
        id: grid
        anchors.fill: parent
        model: ItemModel
        delegate: Item {
            id: multidel
            anchors.fill: parent
            Loader {
                id: loader
                source: ComplexDelegate.getDelegate(object.getClassName())
            }
        }
    }

    //------------ Custom Delegate Test Ends ----------------//
    Text {
        id: info
        text: "Double-click to make a new object"
        font.family: "Helvetica"
        font.pointSize: 24
        color: "dimgray"
        anchors.horizontalCenter: workbench.horizontalCenter
        anchors.verticalCenter: workbench.verticalCenter
    }

    TaskBar {
        anchors.bottom : workbench.bottom
    }
    states: [
        State {
            name: "initState"
            PropertyChanges { target: info; opacity: 1 }
            PropertyChanges { target: DockView; visible: false }
        },
        State {
            name: "hideDock"
            PropertyChanges { target: info; opacity: 0 }
            PropertyChanges { target: DockView; visible: false }
            //_dockView.setVisible: false
        },
        State {
            name: "showDock"
            PropertyChanges { target: info; opacity: 0 }
            PropertyChanges { target: DockView; visible: true }
           // PropertyChanges { target: _dockView; x: 100; y: 100 }
        }
    ]
}
