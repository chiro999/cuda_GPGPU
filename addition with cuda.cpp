#include <iostream>
#include <cuda_runtime.h>

int main() {
    int host_result;
    int *device_result;

    // Allocate memory on the device
    cudaMalloc((void**)&device_result, sizeof(int));

    // Launch the CUDA kernel
    addKernel<<<1, 1>>>(device_result);

    // Copy the result from the device to the host
    cudaMemcpy(&host_result, device_result, sizeof(int), cudaMemcpyDeviceToHost);

    // Clean up
    cudaFree(device_result);

    // Print the result
    std::cout << "Result: " << host_result << std::endl;

    return 0;
}