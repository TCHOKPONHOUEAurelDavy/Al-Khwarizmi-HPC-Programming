from mpi4py import MPI
COMM = MPI.COMM_WORLD
nbOfproc = COMM.Get_size()
RANK = COMM.Get_rank()

print("Hello from the rank {} process".format(RANK))
if RANK==nbOfproc-1:
   print("Parallel execution of hello_world with {} process".format(nbOfproc))
