import sys, os

print("Running sim for values 2^8 through 2^24")

size = 2
iters = 1000
for i in range(8,24):
    iter_count = str((int)(10000*((0.7)**i)))
    print("python3 update_locations.py " + str(2**i) + " " + iter_count)
    os.system("python3 update_locations.py " + str(2**i) + " " + iter_count + ">>python.dat")
    print("./update_locations " + str(2**i) + " " + iter_count)
    os.system("./update_locations " + str(2**i) + " " + iter_count + ">>cplusplus.dat")

    

