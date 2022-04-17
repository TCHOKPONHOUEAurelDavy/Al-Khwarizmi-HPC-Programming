 # write your program here
if __name__=="__main__":
    from pyccel.stdlib.internal.openmp import omp_get_thread_num, omp_get_num_threads

#$ omp parallel num_threads(2) privrate(rank)
    rank=omp_get_thread_num()
    print("Hello from the rank",rank,"thread")
    result = omp_get_num_threads()
#$ omp and parallel
print("Parallel execution of hello_world with",result , "threads")
