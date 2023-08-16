//Device Code (GPU) 
__global__ void addKernel(int *result) {
    *result = 5 + 2;
}
