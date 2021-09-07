clear;
format short eng;

N = 64*1024*1024;

printf("initializing memory\n");
idata = randg(1,1,N) + j*randg(1,1,N);  % complex vector
odata = complex(zeros(1,N));

printf("executing fft\n");
tic;
odata = fft(idata);
toc;
