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
    // int vtp_timings[] = [02, 10, 02, 02, 08, 20, 12, 02, 10, 10, 20, 02, 02, 02, 10, 10, 01, 01];
    //ns
    int vtp_timings[] = {200, 1000, 200, 200, 800, 2000, 1200, 200, 1000, 1000, 2000, 200, 200, 200, 1000, 1000, 100, 100}

    //initial binaries for the vtps
    int SH1_vtp[] = [00, 01, 01, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 01, 01, 00, 00, 00];
    int SH2_vtp[] = [00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 01, 01, 01, 00, 00, 00, 00, 00]; 
    int SH2B_vtp[] = [00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 01, 01, 01, 01, 00, 00, 00, 00]; 
    int SH3_vtp[] = [00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 01, 01, 00, 00, 00];
    int SW_vtp[] = [00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00];
    int TG_vtp[] = [00, 00, 00, 00, 01, 01, 01, 01, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00];
    int Phi1A_vtp[] = [01, 01, 01, 01, 01, 00, 00, 00, 01, 01, 01, 00, 01, 01, 01, 01, 00, 01];
    int Phi2A_vtp[] = [00, 00, 00, 00, 00, 00, 00, 01, 01, 01, 01, 01, 00, 00, 00, 00, 01, 00];
    int Phi2B_vtp[] = [00, 00, 00, 00, 00, 00, 00, 01, 01, 01, 01, 01, 00, 00, 00, 00, 01, 00];
    int RS_vtp[] = [0, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00];
    int CP_vtp[] = [0, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00];
    

    //compute control strings from vtp and characteristics of signals during vtps



// bit masks from tutorial video
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