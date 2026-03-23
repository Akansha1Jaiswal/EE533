#include <cuda_bf16.h>
#include <stdint.h>

///////////////////////////////////////////////////////////////
// INT16 VECTOR ADDITION
// Each thread processes 4 int16_t elements (packed in 64-bit)
///////////////////////////////////////////////////////////////

__global__ void vecAdd_int16(const int16_t* A,
                             const int16_t* B,
                             int16_t* C,
                             int N)
{
    // Each thread handles 4 elements
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    int base = idx * 4;

    if (base + 3 < N) {
        C[base + 0] = A[base + 0] + B[base + 0];
        C[base + 1] = A[base + 1] + B[base + 1];
        C[base + 2] = A[base + 2] + B[base + 2];
        C[base + 3] = A[base + 3] + B[base + 3];
    }
}