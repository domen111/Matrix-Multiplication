TARGET=Naive BLOCK Open MKL BLAS
CC=gcc
#OpenBlas
O_LIB=-L/opt/OpenBLAS/lib
O_INCLUDE=-I /opt/OpenBLAS/include/
export O_FLAGS=-lopenblas -lpthread --static
export OPENBLAS_NUM_THREADS=4
#INTEL
MKLROOT=~/intel/mkl
LINK= -Wl,--start-group ${MKLROOT}/lib/intel64/libmkl_intel_ilp64.a ${MKLROOT}/lib/intel64/libmkl_gnu_thread.a ${MKLROOT}/lib/intel64/libmkl_core.a -Wl,--end-group -lgomp -lpthread -lm -ldl
OPTION=-DMKL_ILP64 -m64 -I${MKLROOT}/include
I_INCLUDE=-I ${MKLROOT}/include
#BLAS
CBLASROOT=../CBLAS
BLASROOT=../BLAS
OBJ=${CBLASROOT}/testing/c_dblas3.o ${CBLASROOT}/testing/c_d3chke.o ${CBLASROOT}/testing/auxiliary.o  ${CBLASROOT}/testing/c_xerbla.o
B_INCLUDE=-I ${CBLASROOT}/include/
B_LIB=${CBLASROOT}/lib/cblas_LINUX.a ${BLASROOT}/blas_LINUX.a
all: Gen $(TARGET)

Gen: gen_matrix.cpp
	g++ gen_matrix.cpp -O2 -std=c++14 -o gen_matrix
	./gen_matrix > matrix.txt
Naive: naive.c
	$(CC) naive.c -O3 -o $@
BLOCK: block.c
	$(CC) block.c -O3 -o $@
Open: mat_open.c
	$(CC) -O3 mat_open.c $(O_LIB) $(O_INCLUDE) $(O_FLAGS) -o $@
MKL: mat_intel.c
	$(CC) -O3 mat_intel.c $(LINK) $(OPTION) $(I_INCLUDE) -o $@
BLAS: mat_blas.c
	$(CC) -O3 mat_blas.c $(OBJ) $(B_INCLUDE) $(B_LIB) -o $@
clean:
	rm $(TARGET)
	rm gen_matrix matrix.txt
