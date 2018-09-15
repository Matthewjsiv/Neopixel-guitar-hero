%choice = menu('Choose your mode: ', 'Scale', 'Arpeggio');
%a = arduino();
% arduino = serial('/dev/cu.usbserial-AH05JZT5', 'BaudRate', 9600);
% fopen(arduino);
% answer = 52;
% fprintf(arduino, '%f', answer);
% fclose(arduino);

% doi = 3 ;
% arduino=serial('/dev/tty.usbserial-AH05JZT5','BaudRate',9600); % create serial communication object 
% fopen(arduino); % initiate arduino communication
% pause(2);
% fprintf(arduino, '%s', char(doi)); % send answer variable content to arduino
% fclose(arduino); 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% s = serial('/dev/tty.usbmodem450','BaudRate',9600);
% 
% 
% while(1==1)
%     fopen(s);
%     choice = menu('Options:', 'Scale', 'Arpeggio', 'Increase Speed', 'Decrease Speed');
%     fprintf(s,choice);
%     fclose(s);
% end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


clear all
clc
%Creates a serial connection
serialPort=serial('/dev/tty.usbmodem14621','BaudRate',9600);
%Change the Terminator property of the serial port to make it faster
%set(serialPort,'Terminator','CR');
%Informs about errors
%warning('off','MATLAB:serial:fscanf:unsuccessfulRead');
%Opens the serial port
UIControl_FontSize_bak = get(0, 'DefaultUIControlFontSize');
set(0, 'DefaultUIControlFontSize', 65);

set(0, 'DefaultUIControlFontSize', UIControl_FontSize_bak);
speedfactor = 5;
while(1==1)
    UIControl_FontSize_bak = get(0, 'DefaultUIControlFontSize');
    set(0, 'DefaultUIControlFontSize', 105);
    
    choice = menu('Options: ','Scale', 'Arpeggio', 'Twinkle Twinkle', 'Married Life', 'Chopsticks', 'Ode to Joy', 'Increase Speed', 'Decrease Speed');
    if choice == 7
        speedfactor = speedfactor-1;
    elseif choice == 8
        speedfactor = speedfactor+1;
    end
    choice = speedfactor*10 + choice;
    set(0, 'DefaultUIControlFontSize', UIControl_FontSize_bak);
    fopen(serialPort);
    pause(1);
    fprintf(serialPort,'%d',choice);
    
    fclose(serialPort);
end




