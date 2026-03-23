#include <cuda_bf16.h>

// BFLOAT16 VECTOR FUSED MULTIPLY-ACCUMULATE
// D = A * B + C
// Each thread processes 4 × __nv_bfloat16 elements
// (Maps to one 64-bit SIMD register in your architecture)


__global__ void vecFMA_bf16(const __nv_bfloat16* A,
                            const __nv_bfloat16* B,
                            const __nv_bfloat16* C,
                            __nv_bfloat16* D,
                            int N)
{
    int idx  = blockIdx.x * blockDim.x + threadIdx.x;
    int base = idx * 4;

    if (base + 3 < N) {
        D[base + 0] = __hfma(A[base + 0], B[base + 0], C[base + 0]);
        D[base + 1] = __hfma(A[base + 1], B[base + 1], C[base + 1]);
        D[base + 2] = __hfma(A[base + 2], B[base + 2], C[base + 2]);
        D[base + 3] = __hfma(A[base + 3], B[base + 3], C[base + 3]);
    }
}