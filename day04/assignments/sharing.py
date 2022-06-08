from mpi4py import MPI
COMM = MPI.COMM_WORLD
nbOfproc = COMM.Get_size()
RANK = COMM.Get_rank()
sendb=1
recvb = 1
while recvb > 0:
    if RANK==0:
        sendb=int(input())
    recvb= COMM.bcast(sendb , root=0)
    print("Process {RANK} got {data}".format(RANK=RANK, data=recvb))
    
