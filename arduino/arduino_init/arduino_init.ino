    void runReadPins(int numTimes) {
      // int vtp_timings[] = [02, 10, 02, 02, 08, 20, 12, 02, 10, 10, 20, 02, 02, 02, 10, 10, 01, 01];
      //ns
      int vtp_timings[] = {200, 1000, 200, 200, 800, 2000, 1200, 200, 1000, 1000, 2000, 200, 200, 200, 1000, 1000, 100, 100};

      //initial binaries for the vtps
      int SH1_vtp[] =     [0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0];
      int SH2_vtp[] =     [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0]; 
      int SH2B_vtp[] =    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0]; 
      int SH3_vtp[] =     [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0];
      int SW_vtp[] =      [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
      int TG_vtp[] =      [0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
      int Phi1A_vtp[] =   [1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1];
      int Phi2A_vtp[] =   [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0];
      int Phi2B_vtp[] =   [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0];
      int RS_vtp[] =      [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
      int CP_vtp[] =      [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
      

    // define arrays to store the state of each pin at each time step

    // scale array for every instance / step we can calculate
    int pinStates[numPins][sizeof(vtp_timings) / sizeof(vtp_timings[0])];

    // loop through the VTP timings and compute the state of each pin at each time step
    // may have to adjust time for every instance we can do while controling 10 pins
    for (int t = 0; t < step; t++) {
      // for each pin at each instance
      for (int i = 0; i < numPins; i++) {
        // check if pin status and bitmask
          if (pinStates[i][t] & bitmask) {
            pinStates[i][t] = HIGH;
          } else {
            pinStates[i][t] = LOW;
          }
        }
      }
    // pinStates array contains the state of each pin at each time step
  }

void setup() {
    //set up output pins
    const int numPins = 10;  // Number of pins to control
    const int outputPins[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};  // The pins you want to control

    // Vertical Transfer Periods Timings
    // Number of 15ns each timing period is
    const int period_t = 15 //ns
}

void loop() {

  runReadPins(5);

}
