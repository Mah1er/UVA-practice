% CODE FROM LAB1 SLIDE 8 - QMULID = 210983063
ns=0;
ne=63;
n = ns:1:ne;
% Time
x1 = exp(0.2*n); % exponential signal
x2 = cos(2*pi*n/10);% sinusoidal signal
x3 = exp(j*2*pi*n/10);% complex exponential signal
x3r = real(x3);% real part of x3
x3i =imag(x3); % imaginary part of x3
x3a = abs(x3);% magnitude of x3
x3p = angle(x3);% phase of x3

%ADD THE CODE FOR PLOTTING x1, x2, x3r, x3i
stem(n,x1)
xlabel('n')
ylabel('x1[n]')
figure

stem(n,x2)
xlabel('n')
ylabel('x2[n]')
figure

stem(n,x3r)
xlabel('n')
ylabel('x3r[n]')
figure

stem(n,x3i)
xlabel('n')
ylabel('x3i[n]')
figure


% CODE FROM LAB1 SLIDE 9 - QMULID = 210983063
ts=0;
te=63;
dt=0.001;
t = ts:dt:te; % Time
x1 = exp(-0.2*t); % exponential signal
x2 = cos(2*pi*t/10); % sinusoidal signal
x3 = exp(j*2*pi*t/10); % complex exponential signal
x3r = real(x3); % real part of x3
x3i = imag(x3); % imaginary part of x3
x3a = abs(x3); % magnitude of x3
x3p = angle(x3); % angle of x3

%ADD THE CODE FOR PLOTTING x1, x2, x3r, x3i
stem(t,x1)
xlabel('n')
ylabel('x1[t]')
figure

stem(t,x2)
xlabel('n')
ylabel('x2[t]')
figure

stem(t,x3r)
xlabel('n')
ylabel('x3r[t]')
figure

stem(t,x3i)
xlabel('n')
ylabel('x3i[t]')
figure

% CODE FROM LAB1 SLIDE 11 - QMULID = 210985919
%%%%%%%%%% CAREFUL YOU NEED TO REPLACE x IN THE LINE BELOW WITH THE CORRECT SIGNAL NAME
ts=0;
te=63;
dt=0.001;
t = ts:dt:te; % Time
x1 = exp(-0.2*t); % exponential signal
x2 = cos(2*pi*t/10); % sinusoidal signal
x3 = exp(j*2*pi*t/10); % complex exponential signal
x3r = real(x3); % real part of x3
x3i = imag(x3); % imaginary part of x3
x3a = abs(x3); % magnitude of x3
x3p = angle(x3); % angle of x3

Arx=sum(x1)*dt ; % Area of x 
Avx= (sum(x1)*dt )/(length(x1)*dt ); %Average value of x
Ex= sum(x1.^2)*dt ; % Energy of x
Px= (sum(x1.^2)*dt )/(length(x1)*dt ); %Power of x

Arx=sum(x2)*dt ; % Area of x2 
Avx= (sum(x2)*dt )/(length(x2)*dt ); %Average value of x2
Ex= sum(x2.^2)*dt ; % Energy of x2
Px= (sum(x2.^2)*dt )/(length(x2)*dt ); %Power of x2

Arx=sum(x3r)*dt ; % Area of x3r 
Avx= (sum(x3r)*dt )/(length(x3r)*dt ); %Average value of x3r
Ex= sum(x3r.^2)*dt ; % Energy of x3r
Px= (sum(x3r.^2)*dt )/(length(x3r)*dt ); %Power of x3r

% CODE FROM LAB1 SLIDE 12 - QMULID = 210985919
ns=0;
ne=63;
n = ns:1:ne;
% Time
x1 = exp(0.2*n); % exponential signal
x2 = cos(2*pi*n/10);% sinusoidal signal
x3 = exp(j*2*pi*n/10);% complex exponential signal
x3r = real(x3);% real part of x3
x3i =imag(x3); % imaginary part of x3
x3a = abs(x3);% magnitude of x3
x3p = angle(x3);% phase of x3

Arx = sum(x1); % Area of x1
Avx = sum(x1)/length(x1); % Average value of x1
Ex = sum(x1.^2); % Energy of x1
Px = sum(x1.^2)/length(x1); % Mean Power of x1

Arx = sum(x2);
Avx = sum(x2)/length(x2);
Ex = sum(x2.^2);
Px = sum(x2.^2)/length(x2);

Arx = sum(x3r);
Avx = sum(x3r)/length(x3r);
Ex = sum(x3r.^2);
Px = sum(x3r.^2)/length(x3r);

