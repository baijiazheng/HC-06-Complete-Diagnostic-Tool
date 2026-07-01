/*
========================================================
HC-06 Complete Diagnostic Tool
Author : JB
Target : Arduino Mega2560 + HC-06 (ZS-040)

接线:

Mega2560           HC-06
--------------------------------
TX3 (14)   ------> RXD
RX3 (15)   <------ TXD
GND        ------> GND
VCC        ------> VCC

重要说明:

本程序适用于:
  hc06V2.3_le

已验证:
  UART = 115200
  AT命令必须带 \r\n

========================================================
*/

#include <Arduino.h>

#define BT Serial3

// --------------------------------------------------
// 用户配置区域
// --------------------------------------------------

// 当前HC-06工作波特率
#define BT_BAUD 115200

// 是否修改蓝牙名称
#define CHANGE_NAME true

// 新蓝牙名称
#define NEW_NAME "JB_HC06"

// --------------------------------------------------

void SendATCommand(const char* cmd)
{
  Serial.print("\n[TX] ");
  Serial.println(cmd);

  BT.print(cmd);

  delay(1000);

  Serial.print("[RX] ");

  if (BT.available())
  {
    while (BT.available())
    {
      Serial.write(BT.read());
    }
  }
  else
  {
    Serial.print("(No Response)");
  }

  Serial.println();
}

void setup()
{
  Serial.begin(115200);
  BT.begin(BT_BAUD);

  delay(1500);

  Serial.println();
  Serial.println("================================");
  Serial.println(" HC-06 Diagnostic Tool");
  Serial.println("================================");
  Serial.println();

  // --------------------------------------------------
  // Test 1
  // --------------------------------------------------

  SendATCommand("AT\r\n");

  // --------------------------------------------------
  // Test 2
  // --------------------------------------------------

  SendATCommand("AT+VERSION\r\n");

  // --------------------------------------------------
  // Test 3
  // --------------------------------------------------

  SendATCommand("AT+NAME\r\n");

  // --------------------------------------------------
  // Test 4
  // --------------------------------------------------

  if (CHANGE_NAME)
  {
    String cmd = "AT+NAME";
    cmd += NEW_NAME;
    cmd += "\r\n";

    SendATCommand(cmd.c_str());

    Serial.println();
    Serial.println("[INFO]");
    Serial.println("Power cycle HC-06 and reconnect.");
    Serial.println("Then search for the new name.");
  }

  Serial.println();
  Serial.println("========== TEST FINISHED ==========");
}

void loop()
{
  // 串口桥

  while (Serial.available())
  {
    BT.write(Serial.read());
  }

  while (BT.available())
  {
    Serial.write(BT.read());
  }
}

//如果模块正常则输出：
//
// ================================
// HC-06 Diagnostic Tool
// ================================

// [TX] AT
// [RX] OK

// [TX] AT+VERSION
// [RX] hc06V2.3_le

// [TX] AT+NAME
// [RX] HC-06

// [TX] AT+NAMEJB_HC06
// [RX] OKsetname

// ========== TEST FINISHED ==========