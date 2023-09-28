unsigned char bits[2048];

void setup() {
    //set up output pins
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);

    // Vertical Transfer Period Signals Masks
    // SH1_VTP      = 011000000000011000;
    // SH2_VTP      = 000000000011100000;
    // SH2B_VTP     = 000000000011110000;
    // SH3_VTP      = 000000000000011000;
    // SW_VTP       = 000000000000000000;
    // TG_VTP       = 000011110000000000;
    // PHI1A_VTP    = 111110001110111101;
    // PHI2AB_VTP   = 000000011111000010;
    // RS_VTP       = 000000000000000000;
    // CP_VTP       = 000000000000000000;
    // SW_VTP, RS_VTP, and CP_VTP should be kept "L" level
    // Vertical Transfer Periods Timings
    // See Table: Timing Requirements 2 (Vertical Transfer Period) (pg. 13)
    // Number of 50ns each timing period is (based on minimum requirements)
    // vtp_timings = [2, 10, 2, 2, 8, 20, 12, 2, 10, 10, 20, 2, 2, 2, 10, 10, 1, 1];

    for(int i=0; i< 2048; i++) {
        bits[i] |= 0;
        if(i>=0 && i<16)


            bits[i] |= 0b00000000;
       else    
            bits[i] |= 0b00000001;

        if(i >=2 && i <12)
            bits[i] |= 0b00010000;
        else    
            bits[i] |= 0b00000000;
    }
}