# galaxy-explorers-benchmark
## Part 1
I chose to iteration from 2^8 to 2^24 because that suggestion seemed reasonable. I chose a vaguely decaying function for the number of iterations. I used 10000\*((0.7)\*\*i) where i is the exponent of 2 as the function for my number of iterations. This means there is an initial large iteration count for a simulation that has a small number of particles and there are less iterations as the simulation grows larger. 

I arbitrarily picked 2^15 as my repeated test number because it felt large enough to return consistent results.

## Part 2
My C++ code ran roughly 60x faster than the Python simulation using -O3 optimization. 

## Part 3
Float and int16_t were the fastest data types. Increasing the size of the int also increased the time it took to calculate each vector. 
  
  
