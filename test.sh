case "$1" in
    MKL)
        export MKL_NUM_THREADS=$2
        time ./MKL < matrix.txt > MKL-t$2.out
        ;;
     
    Open)
        export OPENBLAS_NUM_THREADS=$2
        time ./Open < matrix.txt > Open-t$2.out
        ;;
     
    BLAS)
        time ./BLAS < matrix.txt > BLAS.out
        ;;

    Naive)
        time ./Naive < matrix.txt > Naive.out
        ;;
     
    *)
        echo "Usage: $0 [Program] [Thread]"
        exit 1
esac
