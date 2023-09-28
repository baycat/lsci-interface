pin_list = {'SH1' ,'SH2', 'SH2B', 'SH3', 'SW', 'TG', 'Phi1A', 'Phi2A', 'Phi2B', 'RS', 'CP'};

%% vertical transfer period
replem_vtp = [02, 10, 02, 02, 08, 20, 12, 02, 10, 10, 20, 02, 02, 02, 10, 10, 01, 01];
x_vtp = zeros(18,9);
x_vtp(:,1) = [00, 01, 01, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 01, 01, 00, 00, 00]; % SH1
x_vtp(:,2) = [00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 01, 01, 01, 00, 00, 00, 00, 00]; % SH2
x_vtp(:,3) = [00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 01, 01, 01, 01, 00, 00, 00, 00]; % SH2B
x_vtp(:,4) = [00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 01, 01, 00, 00, 00]; % SH3
x_vtp(:,5) = [00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00]; % SW
x_vtp(:,6) = [00, 00, 00, 00, 01, 01, 01, 01, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00]; % TG
x_vtp(:,7) = [01, 01, 01, 01, 01, 00, 00, 00, 01, 01, 01, 00, 01, 01, 01, 01, 00, 01]; % Phi1A
x_vtp(:,8) = [00, 00, 00, 00, 00, 00, 00, 01, 01, 01, 01, 01, 00, 00, 00, 00, 01, 00]; % Phi2A
x_vtp(:,9) = [00, 00, 00, 00, 00, 00, 00, 01, 01, 01, 01, 01, 00, 00, 00, 00, 01, 00]; % Phi2B
x_vtp(:,10) = [0, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00]; % RS
x_vtp(:,11) = [0, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00]; % CP
total_len_vtp = sum(replem_vtp(:));
X_vtp = zeros(total_len_vtp, 11);
j = 1;
for i=1:18
re = replem_vtp(i);
for k=1:re
X_vtp(j,:) = x_vtp(i,:);
j=j+1;
end
end

%% readout phase / integration time
% X_rop = zeros(24,11);
% X_rop(1:12,7) = 1;      % Phi1
% X_rop(13:24,8:9) = 1;   % Phi2A, Phi2B
% X_rop(20:21,10) = 1;    % RS
% X_rop(20:23,11) = 1;    % CP
X_rop = zeros(20,11); 
X_rop(11:20,7) = 1;      % Phi1
X_rop(1:10,8:9) = 1;   % Phi2A, Phi2B
X_rop(1:4,10) = 1;    % RS
X_rop(1:8,11) = 1;    % CP

%% power supply voltage 
OD = 10; % 10 V

%% Initialization of NI DAQ
d = daq("ni")
d.Rate = 250000; % 250 kHz, 4 us sampling time step

%% Mapping to NI DAQ input/output
outScanData_analog_vtp = OD * ones(size(X_vtp,1), 2); 
outScanData_analog_rop = OD * ones(size(X_rop,1), 2); 
outScanData_digital_vtp = zeros(size(X_vtp,1), 15); 
outScanData_digital_rop = zeros(size(X_rop,1), 15); 

addinput(d, "Dev1", "ai0", "Voltage");
addinput(d, "Dev1", "ai1", "Voltage"); 

addoutput(d, "Dev1", "ao0", "Voltage");         % OD 
addoutput(d, "Dev1", "ao1", "Voltage");         % OD

addoutput(d, "Dev1", "port0/line0", "Digital"); % SH2B
idx = find(strcmp(pin_list, 'SH2B')); 
outScanData_digital_vtp(:,1) = X_vtp(:,idx); 
outScanData_digital_rop(:,1) = X_rop(:,idx); 

addoutput(d, "Dev1", "port0/line1", "Digital"); % SH1
idx = find(strcmp(pin_list, 'SH1')); 
outScanData_digital_vtp(:,2) = X_vtp(:,idx); 
outScanData_digital_rop(:,2) = X_rop(:,idx); 

addoutput(d, "Dev1", "port0/line2", "Digital"); % Phi2A
idx = find(strcmp(pin_list, 'Phi2A')); 
outScanData_digital_vtp(:,3) = X_vtp(:,idx); 
outScanData_digital_rop(:,3) = X_rop(:,idx); 

addoutput(d, "Dev1", "port0/line3", "Digital"); % Phi1A 
idx = find(strcmp(pin_list, 'Phi1A')); 
outScanData_digital_vtp(:,4) = X_vtp(:,idx); 
outScandata_digital_rop(:,4) = X_rop(:,idx); 

addoutput(d, "Dev1", "port0/line4", "Digital"); % TG
idx = find(strcmp(pin_list, 'TG')); 
outScandata_digital_vtp(:,5) = X_vtp(:,idx); 
outScandata_digital_rop(:,5) = X_rop(:,idx); 

addoutput(d, "Dev1", "port0/line5", "Digital"); % Phi1A 
idx = find(strcmp(pin_list, 'Phi1A'));
outScandata_digital_vtp(:,6) = X_vtp(:,idx); 
outScandata_digital_rop(:,6) = X_rop(:,idx); 

addoutput(d, "Dev1", "port0/line6", "Digital"); % SW
idx = find(strcmp(pin_list, 'SW')); 
outScanData_digital_vtp(:,7) = X_vtp(:,idx); 
outScanData_digital_rop(:,7) = X_rop(:,idx); 

addoutput(d, "Dev1", "port0/line8", "Digital"); % SH2 
idx = find(strcmp(pin_list, 'SH2')); 
outScanData_digital_vtp(:,8) = X_vtp(:,idx); 
outScanData_digital_rop(:,8) = X_rop(:,idx); 

addoutput(d, "Dev1", "port0/line9", "Digital"); % SH3
idx = find(strcmp(pin_list, 'SH3')); 
outScanData_digital_vtp(:,9) = X_vtp(:,idx); 
outScanData_digital_rop(:,9) = X_rop(:,idx); 

addoutput(d, "Dev1", "port0/line10", "Digital"); % Phi2A 
idx = find(strcmp(pin_list, 'Phi2A')); 
outScanData_digital_vtp(:,10) = X_vtp(:,idx); 
outScanData_digital_rop(:,10) = X_rop(:,idx); 

addoutput(d, "Dev1", "port0/line11", "Digital"); % Phi1A 
idx = find(strcmp(pin_list, 'Phi1A')); 
outScanData_digital_vtp(:,11) = X_vtp(:,idx); 
outScanData_digital_rop(:,11) = X_rop(:,idx); 

addoutput(d, "Dev1", "port0/line12", "Digital"); % Phi2A
idx = find(strcmp(pin_list, 'Phi2A')); 
outScanData_digital_vtp(:,12) = X_vtp(:,idx); 
outScanData_digital_rop(:,12) = X_rop(:,idx); 

addoutput(d, "Dev1", "port0/line13", "Digital"); % Phi2B
idx = find(strcmp(pin_list, 'Phi2B')); 
outScanData_digital_vtp(:,13) = X_vtp(:,idx); 
outScanData_digital_rop(:,13) = X_rop(:,idx); 

addoutput(d, "Dev1", "port0/line14", "Digital"); % RS
idx = find(strcmp(pin_list, 'RS')); 
outScanData_digital_vtp(:,14) = X_vtp(:,idx); 
outScanData_digital_rop(:,14) = X_rop(:,idx); 

addoutput(d, "Dev1", "port0/line15", "Digital"); % CP 
idx = find(strcmp(pin_list, 'CP')); 
outScanData_digital_vtp(:,15) = X_vtp(:,idx); 
outScanData_digital_rop(:,15) = X_rop(:,idx); 

%% Making the test matrix
outScanData_vtp = [outScanData_analog_vtp, outScanData_digital_vtp]; 
outScanData_vtp = replicator(outScanData_vtp, 1); 
outScanData_rop = [outScanData_analog_rop, outScanData_digital_rop]; 
outScanData_rop = replicator(outScanData_rop, 1); 
outScanData_rop = repmat(outScanData_rop, [5566, 1]); 
outScanData = [zeros(1000,17); outScanData_vtp; outScanData_rop; outScanData_vtp; outScanData_rop; outScanData_vtp; outScanData_rop; zeros(1000,17)]; 

%% readwrite to/from NI DAQ 
inScanData = readwrite(d, outScanData, 'OutputFormat', 'Matrix'); 
inScanData = inScanData'; 
offset = 1000+size(outScanData_vtp,1)+size(outScanData_rop,1)+size(outScanData_vtp,1);
figure; plot(inScanData(1,offset+20*20*72+1:offset+20*20*72+(20*20*2700))); hold on; 
plot(inScanData(2,offset+20*20*72+1:offset+20*20*72+(20*20*2700)));

figure; plot(inScanData(1,offset+20*20*72+1:offset+20*20*72+(20*20*50))); hold on; 
plot(inScanData(2,offset+20*20*72+1:offset+20*20*72+(20*20*50)));

