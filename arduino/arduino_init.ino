unsigned char bits[2048];

void setup() {
    //set up output pins
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);

    //Vertical Transfer Period Signals Masks
    // SH1_VTP = 0

    // Vertical Transfer Periods Timings
    // Number of 15ns each timing period is
    vtp_timings = [02, 10, 02, 02, 08, 20, 12, 02, 10, 10, 20, 02, 02, 02, 10, 10, 01, 01]

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