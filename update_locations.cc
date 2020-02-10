//update_locations.cc - Author: Sebastian Simmons

#include <stdlib.h>
#include <iostream>
#include <random>
#include <vector>
#include <chrono>
//#include <numberic>

using dtype = float;

std::vector<dtype>  generate_random_list(int size, dtype bound){
	//Generates a random vector of size (size) between -bound and bound
	static std::mt19937 gen(size);
	std::uniform_real_distribution<> dis(-bound, bound);
	std::vector<dtype> random_list;
	for(int i=0; i < size; i++){
		random_list.push_back(dis(gen));
	}
	return random_list;
}

void update_coords(std::vector<dtype> xs, std::vector<dtype> ys, std::vector<dtype> zs, std::vector<dtype> vx, std::vector<dtype> vy, std::vector<dtype> vz){
	for(int i =0; i < xs.size();i++){
		xs[i] = xs[i]+vx[i];
		ys[i] = ys[i]+vy[i];
		zs[i] = zs[i]+vz[i];
	}
	return;
}

void print_vector(std::vector<dtype> v){
	// Update position by velocity, one time-step
	for(auto n : v){
		std::cout << n << ", ";
	}
	std::cout << '\n';
	return;
}

int main(int argc, char *argv[]){
	if(argc <3){
		std::cout << "Required arguments: vector_length(N) and iterations_num(M)\n";
	    exit (EXIT_FAILURE);
	}
	const int size = atoi(argv[1]);
	const int iters = atoi(argv[2]);
	auto xs = generate_random_list(size, 1000.0);
	auto ys = generate_random_list(size, 1000.0);
	auto zs = generate_random_list(size, 1000.0);
	auto vx = generate_random_list(size, 1.0);
	auto vy = generate_random_list(size, 1.0);
	auto vz = generate_random_list(size, 1.0);

	auto start = std::chrono::high_resolution_clock::now(); 
	for(int i = 0; i < iters; i++){
		update_coords(xs, ys, zs, vx, vy, vz);
	}
	auto stop = std::chrono::high_resolution_clock::now(); 
    auto t = std::chrono::duration_cast<std::chrono::microseconds>(stop - start); 

	std::cout << "Mean time per coordinate: " << t.count()/static_cast<float>(size * iters) <<'\n';

	auto chksum = std::accumulate(xs.begin(), xs.end(), 0.0);
	chksum += std::accumulate(ys.begin(), ys.end(), 0.0);
	chksum += std::accumulate(zs.begin(), zs.end(), 0.0);
	std::cout << "Final checksum is: " <<chksum << '\n';
}