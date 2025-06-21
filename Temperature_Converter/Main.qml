import QtQuick
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.15


Window {
    width: 400
    height: 200
    visible: true
    color:"#dcdcdc"
    title: qsTr("Temperature Converter")

    // property bool ctrlReady: controller !== null
    property bool ctrlReady: controller !== null && controller !== undefined

    ColumnLayout {
        id:idColumn
        anchors.centerIn: parent
        spacing: 15

        property int field_Width: 150
        property int fontSizeLabel: 12
        property int fontSizeField:10
        property int l_Padding:10
        property int r_Padding:10
        property int  max_Length: 15
        property bool isValid: false


        RowLayout{
            spacing: 20
            Layout.alignment: Qt.AlignRight

            Label{
                text:"Celsius"
                font.pointSize: idColumn.fontSizeLabel
            }
            TextField {
                Layout.preferredWidth: idColumn.field_Width
                font.pointSize: idColumn.fontSizeField
                leftPadding:idColumn.l_Padding
                rightPadding:idColumn.r_Padding
                maximumLength: idColumn.max_Length
                placeholderText: "Celsius temperatura"


                text: ctrlReady ? controller.d_celsius.toString() : ""
                 onTextChanged: {
                  if (ctrlReady) controller.updateCelsius(text)
                }


                background: Rectangle {
                    border.width: 1
                  //  border.color: ctrlReady ? (controller.celsiusValid ? "gray" : "red") : "gray"
                     border.color: controller !== null && controller.celsiusValid  ? "gray" : "red"
                    color: "white"
                }
            }

        }


        RowLayout{
            spacing:20
            Layout.alignment: Qt.AlignRight

            Label{
                text:"Fahrenheit"
                font.pointSize: idColumn.fontSizeLabel
            }
            TextField {
                Layout.preferredWidth: idColumn.field_Width
                font.pointSize: idColumn.fontSizeField
                leftPadding:idColumn.l_Padding
                rightPadding:idColumn.r_Padding
                maximumLength: idColumn.max_Length
                placeholderText: "Fahrenheit temperatura"


                text: ctrlReady ? controller.d_fahrenheit.toString() : ""
                     onTextChanged: {
                    if (ctrlReady) controller.updateFahrenheit(text)
                }


                background: Rectangle {
                    border.width: 1
                   // border.color: ctrlReady ? (controller.fahrenheitValid ? "gray" : "red") : "gray"
                    border.color: controller !== null && controller.fahrenheitValid ? "gray" : "red"
                    color: "white"
                }
            }


        }

        RowLayout {
             spacing:20
             Layout.alignment: Qt.AlignRight

            Label{
                text:"Kelvin"
                font.pointSize: idColumn.fontSizeLabel
            }
            TextField {
                Layout.preferredWidth: idColumn.field_Width
                font.pointSize: idColumn.fontSizeField
                leftPadding:idColumn.l_Padding
                rightPadding:idColumn.r_Padding
                maximumLength: idColumn.max_Length
                placeholderText: "Kelvin temperatura"



                text: ctrlReady ? controller.d_kelvin.toString() : ""
                onTextChanged: {
                    if (ctrlReady) controller.updateKelvin(text)
                }

                background: Rectangle {
                    border.width: 1
                   // border.color: controller.kelvinValid ? "gray" : "red"
                    border.color: controller !== null && controller.kelvinValid ? "gray" : "red"
                    color: "white"
                }
            }

        }
    }

    Rectangle {
        width: 200
        height: 30
        color: "transparent"

        Text {

            color: "red"
            visible: ctrlReady && !controller.celsiusValid
            text: "Invalid input type or \nTemperature cannot be below absolute zero (-273.15 °C)"
            font.pixelSize: 12
            anchors.left: parent.left
            anchors.leftMargin: 10  // отступ зліва 10 пікселів

            anchors.top: parent.top
            anchors.topMargin: 5       // Відступ зверху 5 пікселів
        }

        Text {

            color: "red"
            visible: ctrlReady && !controller.fahrenheitValid
            text: "Invalid input type or \nTemperature cannot be below absolute zero (−459.67 °F)"
            font.pixelSize: 12
            anchors.left: parent.left
            anchors.leftMargin: 10  // отступ зліва 10 пікселів

            anchors.top: parent.top
            anchors.topMargin: 5       // Відступ зверху 5 пікселів
        }

        Text {

            color: "red"
            visible: ctrlReady &&  !controller.kelvinValid
            text: "Invalid input type or \nTemperature cannot be below absolute zero (0 °K)"

            wrapMode: Text.Wrap
            width: 300

            font.pixelSize: 12
            anchors.left: parent.left
            anchors.leftMargin: 10  // Відступ зліва 10 пікселів

            anchors.top: parent.top
            anchors.topMargin: 5       // Відступ зверху 5 пікселів
        }
    }
}
