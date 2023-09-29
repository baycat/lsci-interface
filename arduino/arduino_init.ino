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
    vtp_timings = [02, 10, 02, 02, 08, 20, 12, 02, 10, 10, 20, 02, 02, 02, 10, 10, 01, 01];

    //initial binaries for the vtps
    SH1_vtp = [00, 01, 01, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 01, 01, 00, 00, 00];
    SH2_vtp = [00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 01, 01, 01, 00, 00, 00, 00, 00]; 
    SH2B_vtp = [00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 01, 01, 01, 01, 00, 00, 00, 00]; 
    SH3_vtp = [00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 01, 01, 00, 00, 00];
    SW_vtp = [00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00];
    TG_vtp = [00, 00, 00, 00, 01, 01, 01, 01, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00];
    Phi1A_vtp = [01, 01, 01, 01, 01, 00, 00, 00, 01, 01, 01, 00, 01, 01, 01, 01, 00, 01];
    Phi2A_vtp = [00, 00, 00, 00, 00, 00, 00, 01, 01, 01, 01, 01, 00, 00, 00, 00, 01, 00];
    Phi2B_vtp = [00, 00, 00, 00, 00, 00, 00, 01, 01, 01, 01, 01, 00, 00, 00, 00, 01, 00];
    RS_vtp = [0, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00];
    CP_vtp = [0, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00];
    

    //compute control strings from vtp and characteristics of signals during vtps
    

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