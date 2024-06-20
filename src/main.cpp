#include "mcp_can.h"
#include <SPI.h>

// MCP2515
#define SPI_CS_PIN 10
MCP_CAN CAN(SPI_CS_PIN); // Set CS pin
/*
    Pin Mapping
        MCP -> Arduino
        sck -> 13
        si -> 11
        so -> 12
        cs -> 10
*/

void setup() {
    Serial.begin(115200);

    // Initialize MCP2515
    while(CAN.begin(MCP_ANY, CAN_1000KBPS, MCP_8MHZ) != CAN_OK) {
        Serial.println("Error Initializing MCP2515...");
        delay(1000);
    }
    Serial.println("MCP2515 Initialized Successfully!");
    CAN.setMode(MCP_NORMAL);
}

void loop() {
    byte len = 0;
    unsigned char buf[8];
    long unsigned int rxId;
    if(CAN_MSGAVAIL == CAN.checkReceive()) {
        CAN.readMsgBuf(&rxId, &len, buf);

        Serial.print("ID:");
        Serial.print(rxId, HEX);
        Serial.print("\t");
        Serial.print(buf[0]);
        Serial.print("\t");
        Serial.print(buf[1]);
        Serial.print("\t");
        Serial.print(buf[2]);
        Serial.print("\t");
        Serial.print(buf[3]);
        Serial.print("\t");
        Serial.print(buf[4]);
        Serial.print("\t");
        Serial.print(buf[5]);
        Serial.print("\t");
        Serial.print(buf[6]);
        Serial.print("\t");
        Serial.print(buf[7]);
        Serial.print("\n");
    }
}
