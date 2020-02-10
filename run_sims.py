import sys, os

def compare_languages():
    # Out puts .dat files for runtimes of python and c++ versions of the sim
    print("Running sim for values 2^8 through 2^24")

    size = 2
    iters = 1000
    for i in range(8,24):
        iter_count = str((int)(10000*((0.7)**i)))
        print("python3 update_locations.py " + str(2**i) + " " + iter_count)
        os.system("python3 update_locations.py " + str(2**i) + " " + iter_count + ">>python.dat")
        print("./update_locations " + str(2**i) + " " + iter_count)
        os.system("./update_locations " + str(2**i) + " " + iter_count + ">>cplusplus.dat")

    
def cplusplus_multiple_runs(data_type):
    size = 2**15
    iter_count = 100
    for i in range(5):
        print("./update_locations " + str(data_type) + " " + str(iter_count))
        os.system("./update_locations " + str(size) + " " + str(iter_count) + ">> " + data_type + ".dat")

    
if __name__ == "__main__":
    data_t = input("Enter the vector data type: ")
    print("Running sim for datatype " + data_t)
    cplusplus_multiple_runs(data_t)
