#include <Wire.h>
#include "solenoidcontrol.h"

SolenoidControl lat_pos_x(4, 5);
// SolenoidControl lat_neg_x;
// SolenoidControl lat_pos_y;
// SolenoidControl lat_neg_y;
// SolenoidControl lat_pos_z;
// SolenoidControl lat_neg_z;

// SolenoidControl ccw_x;
// SolenoidControl cw_x;
// SolenoidControl ccw_y;
// SolenoidControl cw_y;
// SolenoidControl ccw_z;
// SolenoidControl cw_z;

byte pendingCommand = 0;

void setup() {
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);

  lat_pos_x.all_init();
  // lat_neg_x.all_init();
  // lat_pos_y.all_init();
  // lat_neg_y.all_init();
  // lat_pos_z.all_init();
  // lat_neg_z.all_init();
  // ccw_x.all_init();
  // cw_x.all_init();
  // ccw_y.all_init();
  // cw_y.all_init();
  // ccw_z.all_init();
  // cw_z.all_init();
}

void loop() {
  if (pendingCommand != 0) {
    byte cmd = pendingCommand;
    pendingCommand = 0;

    int valve_time = 1000; // onika burgers

      switch(cmd) {
      case 1: // test 3
      lat_pos_x.all_timed_sole(valve_time);
      break;
      case 2:
      // lat_neg_x.all_timed_sole(valve_time);
      // break;
      // case 3:
      // lat_pos_y.all_timed_sole(valve_time);
      // break;
      // case 4:
      // lat_neg_y.all_timed_sole(valve_time);
      // break;
      // case 5:
      // lat_pos_z.all_timed_sole(valve_time);
      // break;
      // case 6:
      // lat_neg_z.all_timed_sole(valve_time);
      // break;
      // case 7:
      // ccw_x.all_timed_sole(valve_time);
      // break;
      // case 8:
      // cw_x.all_timed_sole(valve_time);
      // break;
      // case 9:
      // ccw_y.all_timed_sole(valve_time);
      // break;
      // case 10:
      // cw_y.all_timed_sole(valve_time);
      // break;
      // case 11:
      // ccw_z.all_timed_sole(valve_time);
      // break;
      // case 12:
      // cw_z.all_timed_sole(valve_time);
      // break;
      default: break;
      }
  }
}

void receiveEvent(int howMany) {
  if (howMany > 0) {
    pendingCommand = Wire.read();
  }
}
