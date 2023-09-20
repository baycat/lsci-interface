%digital test
addinput(d, "Dev1", "port0/line0", "Digital");
addoutput(d, "Dev1","port0/line8", "Digital");
inScanData = readwrite(d,[1;0;1],"OutputFormat","Matrix")

