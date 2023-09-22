% analog test

%list data acquisition devices
d=daqlist;

%get device info
d(1,:)
d{1,"DeviceInfo"}
dq = daq("ni")


%establish input/output
addoutput(d, "Dev1", "ao0", "Voltage");

%write to output test
output=0;
write(d,output’);
output=2.*ones(1,10000);
write(d,output');
output=.5.*ones(1,10000);
write(d,output');



% preform sensor test
% load('control_signals_test.mat','X_vtp_test'); 
% input_test_array = X_vtp_test;
