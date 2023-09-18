% analog test

daqlist
d=daq("ni")
addoutput(d, "Dev1", "ao0", "Voltage");
output=0;
write(d,output’)
output=2.*ones(1,10000);
write(d,output')
output=.5.*ones(1,10000);
write(d,output')
