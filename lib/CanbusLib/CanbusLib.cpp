#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <mcp_can.h>

#include "CanbusLib.h"

/**
 * @file CanbusLib.cpp
 * @author Kana (René Lantzsch)
 * @version 1.0
 */

long unsigned int rxId;

unsigned long rcvTime;

unsigned char len = 0;
unsigned char buf[8];

const int SPI_CS_PIN = 10;

MCP_CAN CAN(SPI_CS_PIN);

CanbusClass::CanbusClass() {
  //Wire.begin();
}

void CanbusClass::start(BluetoothClass output) const {
    if(CAN_OK != CAN.begin(CAN_250KBPS)) {
      output.sendValue("Canbus module failed to initialize.");
    } else {
      output.sendValue("Canbus module ready\n");
      output.sendValue("Time\t\tPGN\t\tByte0\tByte1\tByte2\tByte3\tByte4\tByte5\tByte6\tByte7");
    }
}

float CanbusClass::receiveMessage(BluetoothClass output) const {
  if(CAN_MSGAVAIL == CAN.checkReceive()) {
    rcvTime = millis();
    CAN.readMsgBuf(&len, buf);

    rxId= CAN.getCanId();

    output.sendValue(rcvTime);
    output.sendValue("\t\t");
    //output.sendValue("0x");
    //output.sendValue(rxId, HEX);
    output.sendValue(rxId);
    output.sendValue("\t");

    for(int i = 0; i<len; i++) {
      if(buf[i] > 15) {
        //output.sendValue("0x");
        //output.sendValue(buf[i], HEX);
        output.sendValue(buf[i]);
      } else {
        //output.sendValue("0x0");
        //output.sendValue(buf[i], HEX);
        output.sendValue(buf[i]);
      }
      //Serial.print("0x");
      //Serial.print(buf[i], HEX);
      output.sendValue("\t");
    }
    output.sendValue("\n");
  } else {
    output.sendValue("- no CAN data -\n");
  }
}
